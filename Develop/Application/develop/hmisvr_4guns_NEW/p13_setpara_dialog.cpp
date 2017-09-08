#include "p13_setpara_dialog.h"
#include "ui_p13_setpara_dialog.h"
#include "globalhmi.h"

p13_setpara_dialog::p13_setpara_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p13_setpara_dialog)
{
    ui->setupUi(this);

}

p13_setpara_dialog::~p13_setpara_dialog()
{
    delete ui;
}

void p13_setpara_dialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void p13_setpara_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
    btn_press();
    ui->label_code->setText(phonenum);
    //ui->label_phone->setText(phonenum);
    //ui->label_phone_2->setText(phonenum_2);
}
UINT8 jump_num_13;
BOOL enter_clc_13;


void p13_setpara_dialog::init_page_val()
{
    jump_num_13=0;
    enter_clc_13=FALSE;

        btn_passwd_pos=0;
        memset(btn_passwd,0,sizeof(btn_passwd));
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));

        memset(Set_paswd,0,sizeof(Set_paswd));
        memset(Tempor_name,0,sizeof(Tempor_name));
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"settingpwd");
        if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
        {
            memcpy(Set_paswd,Tempor_name,sizeof(Set_paswd));
        }
        else
        {
            memset(Set_paswd,0,sizeof(Set_paswd));
        }
}

void p13_setpara_dialog::btn_press()
{
        QPushButton* array[14]={0};
        array[0] = ui->pbtn_num0;
        array[1] = ui->pbtn_num1;
        array[2] = ui->pbtn_num2;
        array[3] = ui->pbtn_num3;
        array[4] = ui->pbtn_num4;
        array[5] = ui->pbtn_num5;
        array[6] = ui->pbtn_num6;
        array[7] = ui->pbtn_num7;
        array[8] = ui->pbtn_num8;
        array[9] = ui->pbtn_num9;
        array[10] = ui->pbtn_dot;
        array[11] = ui->pbtn_back;
        array[12] = ui->pbtn_go;
        array[13] = ui->pbtn_ok;

        int num = 0;
        for(num = 0; num < 14;num++)
        {
            array[num]->setStyleSheet("QPushButton{border-image: url(:/btn/qrc/PICS/Pbtn.png);}\
                                      QPushButton:pressed{border-image: url(:/btn/qrc/PICS/Pbtn_press.png);}");
        }
}


void p13_setpara_dialog::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
}

void p13_setpara_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();

}

void p13_setpara_dialog::update_page_info()
{
    ui->lbl_sysdate->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    ui->lbl_systime->setText(QTime::currentTime().toString("hh:mm:ss"));
    if(language_num == 1)
    {
        //  ui->label_logo->setText(QString::fromUtf8("交 流 充 电 桩"));
          ui->label_stubnum->setText(QString::fromUtf8("客  服  热  线  :"));
    }
    else  if(language_num == 2)
    {
      //    ui->label_logo->setText("AC charging pile");
          ui->label_stubnum->setText("Telephone :");
    }

   // ui->label_code->setText(code);
  //  ui->label_phone->setText(phonenum);
  //  ui->label_phone_2->setText(phonenum_2);
    DebugMsg(hmilev,8,"btn_passwd[%s][%d]\n",btn_passwd,btn_passwd_pos);
    memset(btn_passwd_disp,0,sizeof(btn_passwd_disp));
    #ifdef DEF_DEBUG_PASSWD_BY_NUM
    strcpy(btn_passwd_disp,btn_passwd);
    #else
    memset(btn_passwd_disp,'*',btn_passwd_pos);
    #endif

    ui->label_passwd->setText(btn_passwd_disp);



    if(jump_num_13==0)
    {
         ui->label_speaker->setText(QString::fromUtf8("安全提示:请注意遮挡键盘!"));
    }
    else if(jump_num_13==1&&enter_clc_13)
    {

        ui->label_speaker->setText(QString::fromUtf8("密码验证失败,请重新输入!"));
        btn_passwd_pos=0;
        memset(btn_passwd,0,sizeof(btn_passwd));
        enter_clc_13=FALSE;
    }
    else if(jump_num_13==2)
    {
        ui->label_speaker->setText(QString::fromUtf8("密码不能为空,请重新输入!"));

    }

}

void p13_setpara_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
    if(hmi_page_index != PAGEINDEX_SETPASSWRDIPT)
    {
        exit_page_dlg();
    }
    else
    {

    }
}

void p13_setpara_dialog::call_p14_dlg()
{
    timer->stop();
    if(p14_dlg){
            delete p14_dlg;
            p14_dlg = NULL;
            handle_dlg_p14--;
    }
    p14_dlg = new  p14_setpara_sub1_dialog;
    p14_dlg->setWindowFlags(Qt::FramelessWindowHint);
    handle_dlg_p14++;

    connect(this,SIGNAL(signal_enable_p14dlg_timer()),p14_dlg,SLOT(init_page_dlg()));
    connect(p14_dlg,SIGNAL(signal_exit_p14dlg()),this,SLOT(exit_page_dlg()));

    emit signal_enable_p14dlg_timer();

    p14_dlg->exec();



}


void p13_setpara_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p13dlg();
    //delete p13_dlg;
    //p13_dlg = NULL;
}


void p13_setpara_dialog::on_pbtn_num0_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='0';
    }
}

void p13_setpara_dialog::on_pbtn_num1_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='1';
    }
}

void p13_setpara_dialog::on_pbtn_num2_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='2';
    }
}

void p13_setpara_dialog::on_pbtn_num3_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='3';
    }
}

void p13_setpara_dialog::on_pbtn_num4_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='4';
    }
}

void p13_setpara_dialog::on_pbtn_num5_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='5';
    }
}

void p13_setpara_dialog::on_pbtn_num6_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='6';
    }
}

void p13_setpara_dialog::on_pbtn_num7_clicked()
{

    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='7';
    }
}

void p13_setpara_dialog::on_pbtn_num8_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='8';
    }
}

void p13_setpara_dialog::on_pbtn_num9_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='9';
    }
}

void p13_setpara_dialog::on_pbtn_dot_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='.';
    }
}

void p13_setpara_dialog::on_pbtn_back_clicked()
{
    if(btn_passwd_pos>0)
    {
        btn_passwd_pos--;
        btn_passwd[btn_passwd_pos]=0;
    }
    else
    {
        btn_passwd_pos=0;
    }
}

void p13_setpara_dialog::on_pbtn_go_clicked()
{

    DebugMsg(hmilev,5,"on_pbtn_cancel_clicked\n");

    btn_passwd_pos=0;
    memset(btn_passwd,0,sizeof(btn_passwd));

    hmi_button_dn_num=CANCEL_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
}



void p13_setpara_dialog::on_pbtn_ok_clicked()
{
    DebugMsg(hmilev,5,"on_pbtn_enter_clicked\n");
     enter_clc_13=TRUE;
     if(btn_passwd_pos==0)
     {
         jump_num_13=2;
         return;
     }
    if(memcmp(Set_paswd,btn_passwd,sizeof(btn_passwd))!=0)
    {
        jump_num_13=1;
        return;
    }


    API_Write_DB_Nbyte(PL_HMI_CARD_PASSWD,(INT8 *)(&btn_passwd),sizeof(btn_passwd));
    hmi_button_dn_num=OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));



}

void p13_setpara_dialog::on_pbtn_dateout_clicked()
{
    system("cp /usr/data/* /media/sda1/");
    system("cp /usr/data/* /media/sda2/");
    system("cp /usr/data/* /media/sda3/");
    system("cp /usr/data/* /media/sda4/");
}
