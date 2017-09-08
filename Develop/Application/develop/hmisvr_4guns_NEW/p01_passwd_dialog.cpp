#include "p01_passwd_dialog.h"
#include "ui_p01_passwd_dialog.h"
#include "globalhmi.h"

p01_passwd_dialog::p01_passwd_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p01_passwd_dialog)
{
    ui->setupUi(this);

}

p01_passwd_dialog::~p01_passwd_dialog()
{
    delete ui;
}

void p01_passwd_dialog::changeEvent(QEvent *e)
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

void p01_passwd_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);
    //timer->start(300);
    init_page_val();
    btn_press();
    ui->label_code->setText(phonenum);
            ui->label_code_2->setText(phonenum_2);
    //ui->label_phone->setText(phonenum);
    //ui->label_phone_2->setText(phonenum_2);
}
static int time_add;
UINT8 jump_num;
BOOL enter_clc;
void p01_passwd_dialog::init_page_val()
{
    jump_num=0;
    enter_clc=FALSE;
    btn_passwd_pos=0;
    memset(btn_passwd,0,sizeof(btn_passwd));
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p01_passwd_dialog::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
    //timer->start(300);
    init_page_val();
}

void p01_passwd_dialog::timer_handle()
{
    update_page_info();
    update_hmi_page_index();

}

void p01_passwd_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p01dlg();
    //delete p01_dlg;
    //p01_dlg = NULL;
}


//#define DEF_DEBUG_PASSWD_BY_NUM
void p01_passwd_dialog::btn_press()
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
                                  QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/0-d.png);}");
    }
}

void p01_passwd_dialog::update_page_info()
{
    //passwd information
    DebugMsg(hmilev,8,"btn_passwd[%s][%d]\n",btn_passwd,btn_passwd_pos);
    memset(btn_passwd_disp,0,sizeof(btn_passwd_disp));
    #ifdef DEF_DEBUG_PASSWD_BY_NUM
    strcpy(btn_passwd_disp,btn_passwd);
    #else
    memset(btn_passwd_disp,'*',btn_passwd_pos);
    #endif
    ui->label_passwd->setText(btn_passwd_disp);

    //main card information
    BOOL get_maincard_flag = FALSE;

    API_Read_DB_Nbyte(PL_GETMAINCARD_FLAG,(INT8 *)(&get_maincard_flag),sizeof(get_maincard_flag));
    if(get_maincard_flag==TRUE)
    {
    API_Read_DB_Nbyte(PL_MAINCARD_SN,(INT8 *)(&main_card_sn),sizeof(main_card_sn));
    ui->label_card_sn->setText(main_card_sn);
    // ErrMsg("$$$$$$$$$[%s]\n",main_card_sn);
    }

    if(language_num == 1)
    {
          //ui->label_logo->setText(QString::fromUtf8("直 流 充 电 桩"));
          ui->label_speaker->setText(QString::fromUtf8("请  输  入  密  码"));
          ui->label_stubnum->setText(QString::fromUtf8(" 客  服  热  线  :"));

          ui->label_cardnum->setText(QString::fromUtf8("卡    号  :"));
          ui->label_pass->setText(QString::fromUtf8("密    码  :"));
          ui->pbtn_go->setText(QString::fromUtf8("返  回"));
          ui->pbtn_ok->setText(QString::fromUtf8("确  定"));

          //speaker info
          if(jump_num==0)
          {
          //ui->label_speaker->setText(QString::fromUtf8("安全提示:请注意遮挡键盘!"));
          }
          else if(jump_num==6)
          {
          ui->label_speaker->setText(QString::fromUtf8("密码不能为空,请重新输入!"));
          }
          else if(jump_num==8)
          {
          ui->label_speaker->setText(QString::fromUtf8("密码错误,请重新输入!"));
          }
          else
          {
              UINT8 num_add=0;
              time_add++;
              if(time_add>5)
              {
                  API_Read_DB_Nbyte(PL_CHRPASSWRDERR_FLAG,(UINT8 *)(&num_add),sizeof(num_add));
                  time_add=0;
              }

              // ErrMsg("$$$$$$$$$$$$=%d\n",num_add);

              if((num_add==1)&&enter_clc)
              {
              btn_passwd_pos=0;
              memset(btn_passwd,0,sizeof(btn_passwd));
              enter_clc=FALSE;
              ui->label_speaker->setText(QString::fromUtf8("密码验证失败,请重新输入!"));
              }
              else if(num_add==2)
              {
              ui->label_speaker->setText(QString::fromUtf8("正在验证密码,请耐心等待!"));
              }
              else if(num_add==3)
              {
              ui->label_speaker->setText(QString::fromUtf8("密码验证成功!"));
              }
              else if(num_add==4)
              {
              ui->label_speaker->setText(QString::fromUtf8("正在结束充电,请耐心等待!"));
              }
              else if(num_add==5)
              {
              ui->label_speaker->setText(QString::fromUtf8("获取结算信息中,请耐心等待!"));
              }
              else if(num_add==6)
              {
              ui->label_speaker->setText(QString::fromUtf8("获取结算信息失败!"));
              }
              else
              {
              // ErrMsg("jump_num=%d\n",num_add);
              }
          }
    }
    else  if(language_num == 2)
    {
         // ui->label_logo->setText("DC charging pile");
          ui->label_speaker->setText("Please enter the password");
          ui->label_stubnum->setText("Pile Number :");

          ui->label_cardnum->setText("Card Num:");
          ui->label_pass->setText("Password:");
          ui->pbtn_go->setText("Back");
          ui->pbtn_ok->setText("OK");

          //speaker info
          if(jump_num==0)
          {
          //ui->label_speaker->setText("Tips: shield the keyboard!");
          }
          else if(jump_num==6)
          {
          ui->label_speaker->setText(QString::fromUtf8("Password cannot be blank!"));
          }
          else if(jump_num==8)
          {
          ui->label_speaker->setText(QString::fromUtf8("Password is wrong!"));
          }
          else
          {
              UINT8 num_add=0;
              time_add++;
              if(time_add>5)
              {
                  API_Read_DB_Nbyte(PL_CHRPASSWRDERR_FLAG,(UINT8 *)(&num_add),sizeof(num_add));
                  time_add=0;
              }

              // ErrMsg("$$$$$$$$$$$$=%d\n",num_add);

              if((num_add==1)&&enter_clc)
              {
              btn_passwd_pos=0;
              memset(btn_passwd,0,sizeof(btn_passwd));
              enter_clc=FALSE;
              ui->label_speaker->setText(QString::fromUtf8("Verification failed!"));
              }
              else if(num_add==2)
              {
              ui->label_speaker->setText(QString::fromUtf8("Wait for validating password!"));
              }
              else if(num_add==3)
              {
              ui->label_speaker->setText(QString::fromUtf8("Password authentication is ok!"));
              }
              else if(num_add==4)
              {
              ui->label_speaker->setText(QString::fromUtf8("Stop charging , wait patiently!"));
              }
              else if(num_add==5)
              {
              ui->label_speaker->setText(QString::fromUtf8("To obtain the settlement information, please wait patiently!"));
              }
              else if(num_add==6)
              {
              ui->label_speaker->setText(QString::fromUtf8("Gets the settlement information failed!"));
              }
              else
              {
              // ErrMsg("jump_num=%d\n",num_add);
              }
          }
    }
}

void p01_passwd_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
    if(hmi_page_index != PAGEINDEX_PASSWD)
    {
        exit_page_dlg();
    }
    else
    {

    }
}
/*
void p01_passwd_dialog::call_dlg_1()
{
    timer->stop();
    if(dlg_1){
            delete dlg_1;
            dlg_1 = NULL;

    }

    dlg_1 = new dialog_1 ;
    dlg_1->setWindowFlags(Qt::FramelessWindowHint);
    connect(this,SIGNAL(signal_enable_dlg_1_timer()),dlg_1,SLOT(init_page_dlg()));
    connect(dlg_1,SIGNAL(signal_exit_dlg_1()),this,SLOT(exit_page_dlg()));
    emit signal_enable_dlg_1_timer();
    dlg_1->exec();
}
*/
void p01_passwd_dialog::call_dlg_gun()
{
    timer->stop();
    if(dlg_gun){
            delete dlg_gun;
            dlg_gun = NULL;
    }
    dlg_gun = new  Dialog_gunselect;
    dlg_gun->setWindowFlags(Qt::FramelessWindowHint);

    connect(this,SIGNAL(signal_enable_dlg_gun_timer()),dlg_gun,SLOT(init_page_dlg()));
    connect(dlg_gun,SIGNAL(signal_exit_dlg_gun()),this,SLOT(exit_page_dlg()));

    emit signal_enable_dlg_gun_timer();
    dlg_gun->exec();
}

void p01_passwd_dialog::call_p02_dlg()
{
    timer->stop();
    if(p02_dlg){
            delete p02_dlg;
            p02_dlg = NULL;
            handle_dlg_p02--;
    }
    p02_dlg = new  p02_servchoose_dialog;
    p02_dlg->setWindowFlags(Qt::FramelessWindowHint);
    handle_dlg_p02++;
    connect(this,SIGNAL(signal_enable_p02dlg_timer()),p02_dlg,SLOT(init_page_dlg()));
    connect(p02_dlg,SIGNAL(signal_exit_p02dlg()),this,SLOT(exit_page_dlg()));
    emit signal_enable_p02dlg_timer();
    p02_dlg->exec();
}


void p01_passwd_dialog::on_pbtn_num0_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='0';
    }
}

void p01_passwd_dialog::on_pbtn_num1_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='1';
    }
}

void p01_passwd_dialog::on_pbtn_num2_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='2';
    }
}

void p01_passwd_dialog::on_pbtn_num3_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='3';
    }
}

void p01_passwd_dialog::on_pbtn_num4_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='4';
    }
}

void p01_passwd_dialog::on_pbtn_num5_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='5';
    }
}

void p01_passwd_dialog::on_pbtn_num6_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='6';
    }
}

void p01_passwd_dialog::on_pbtn_num7_clicked()
{

    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='7';
    }
}

void p01_passwd_dialog::on_pbtn_num8_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='8';
    }
}

void p01_passwd_dialog::on_pbtn_num9_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='9';
    }
}

void p01_passwd_dialog::on_pbtn_dot_clicked()
{
    if(btn_passwd_pos>=MAX_PASSWD_LEN)
    {
        btn_passwd_pos=MAX_PASSWD_LEN;
    }else{
        btn_passwd[btn_passwd_pos++]='.';
    }
}

void p01_passwd_dialog::on_pbtn_back_clicked()
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

void p01_passwd_dialog::on_pbtn_go_clicked()
{

    DebugMsg(hmilev,5,"on_pbtn_cancel_clicked\n");

    btn_passwd_pos=0;
    memset(btn_passwd,0,sizeof(btn_passwd));

    hmi_button_dn_num=CANCEL_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
}


void p01_passwd_dialog::on_pbtn_ok_clicked()
{

    DebugMsg(hmilev,5,"on_pbtn_enter_clicked\n");

    if(btn_passwd_pos==0)
    {
        jump_num=6;
      // ErrMsg("hmi_page_index error[%d]\n",0);
       // return;
    }
    else if(btn_passwd_pos<6)
    {
        jump_num=8;
        btn_passwd_pos=0;
        memset(btn_passwd,0,sizeof(btn_passwd));
      // ErrMsg("hmi_page_index error[%d]\n",0);
       // return;
    }
    else
    {
    //    API_Read_DB_Nbyte(PL_CHRPASSWRDERR_FLAG,(UINT8 *)(&num_add),sizeof(num_add));

        jump_num=7;
        enter_clc=TRUE;

        API_Write_DB_Nbyte(PL_HMI_CARD_PASSWD,(INT8 *)(&btn_passwd),sizeof(btn_passwd));

        hmi_button_dn_num=OK_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
    }
}










