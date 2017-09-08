#include "p18_setpara_sub5_dialog.h"
#include "ui_p18_setpara_sub5_dialog.h"
#include "globalhmi.h"

p18_setpara_sub5_dialog::p18_setpara_sub5_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p18_setpara_sub5_dialog)
{
    ui->setupUi(this);
}

p18_setpara_sub5_dialog::~p18_setpara_sub5_dialog()
{
    delete ui;
}

void p18_setpara_sub5_dialog::changeEvent(QEvent *e)
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

void p18_setpara_sub5_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
    btn_press();
    ui->label_code->setText(phonenum);
   // ui->label_phone->setText(phonenum);
    //ui->label_phone_2->setText(phonenum_2);
}

//BOOL flg=TRUE;
//BOOL web_flg=FALSE;
 int num_temp_18;
void p18_setpara_sub5_dialog::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));

        type_len = 0;
        memset(type_buf,0,sizeof(type_buf));
        num_temp_18=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"stub_type");
        type= read_profile_int(Section_name, Key_name,num_temp_18,config_path);
        snprintf(type_buf,sizeof(type_buf),"%d",type);
        type_len = strlen(type_buf);
}

void p18_setpara_sub5_dialog::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
}

void p18_setpara_sub5_dialog::btn_press()
{
    QPushButton* array[16]={0};
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
    array[14] = ui->pbtn_up;
    array[15] = ui->pbtn_down;
    array[16] = ui->pbtn;
    //array[16] = ui->pbtn_1;
    //array[17] = ui->pbtn_2;
    //array[18] = ui->pbtn_3;
    int num = 0;
    for(num = 0; num < 16;num++)
    {
        array[num]->setStyleSheet("QPushButton{border-image: url(:/btn/qrc/PICS/Pbtn.png);}\
                                  QPushButton:pressed{border-image: url(:/btn/qrc/PICS/Pbtn_press.png);}");
    }

}

void p18_setpara_sub5_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p18_setpara_sub5_dialog::update_page_info()
{
    ui->lbl_sysdate->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    ui->lbl_systime->setText(QTime::currentTime().toString("hh:mm:ss"));
    if(language_num == 1)
    {
         // ui->label_logo->setText(QString::fromUtf8("交 流 充 电 桩"));
          ui->label_stubnum->setText(QString::fromUtf8(" 客  服  热  线  :"));
    }
    else  if(language_num == 2)
    {
        //  ui->label_logo->setText("AC charging pile");
          ui->label_stubnum->setText("Telephone :");
    }

    ui->lbl_type->setText(type_buf);
}

void p18_setpara_sub5_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_SETPAGE_FIVE)
    {
        exit_page_dlg();
    }
    else
    {

    }
}

void p18_setpara_sub5_dialog::call_p17_dlg()
{
    timer->stop();
    emit signal_timer_p18dlg();
    delete p18_dlg;
    p18_dlg = NULL;
}

void p18_setpara_sub5_dialog::call_p24_dlg()
{
    timer->stop();
    if(p24_dlg){
            delete p24_dlg;
            p24_dlg = NULL;

    }
    p24_dlg = new  p24_setpara_sub6_dialog;
    p24_dlg->setWindowFlags(Qt::FramelessWindowHint);

    connect(this,SIGNAL(signal_enable_p24dlg_timer()),p24_dlg,SLOT(init_page_dlg()));
    connect(p24_dlg,SIGNAL(signal_exit_p24dlg()),this,SLOT(exit_page_dlg()));
    connect(p24_dlg,SIGNAL(signal_timer_p24dlg()),this,SLOT(start_timer()));
    emit signal_enable_p24dlg_timer();
    p24_dlg->exec();
}

int num_18=0;

void p18_setpara_sub5_dialog::on_pbtn_clicked()
{
  num_18=1;
}

void p18_setpara_sub5_dialog::on_pbtn_num0_clicked()
{
     switch(num_18)
    {
        case 1:

            type_buf[type_len++]='0';
             break;

       default:
            break;
    }
}

void p18_setpara_sub5_dialog::on_pbtn_num1_clicked()
{
    switch(num_18)
   {
       case 1:

           type_buf[type_len++]='1';
            break;

      default:
           break;
   }
}

void p18_setpara_sub5_dialog::on_pbtn_num2_clicked()
{
    switch(num_18)
   {
       case 1:

           type_buf[type_len++]='2';
            break;

      default:
           break;
   }
}

void p18_setpara_sub5_dialog::on_pbtn_num3_clicked()
{
    switch(num_18)
   {
       case 1:

           type_buf[type_len++]='3';
            break;

      default:
           break;
   }
}

void p18_setpara_sub5_dialog::on_pbtn_num4_clicked()
{
    switch(num_18)
   {
       case 1:

           type_buf[type_len++]='4';
            break;

      default:
           break;
   }
}

void p18_setpara_sub5_dialog::on_pbtn_num5_clicked()
{
    switch(num_18)
   {
       case 1:

           type_buf[type_len++]='5';
            break;

      default:
           break;
   }
}

void p18_setpara_sub5_dialog::on_pbtn_num6_clicked()
{
    switch(num_18)
   {
       case 1:

           type_buf[type_len++]='6';
            break;

      default:
           break;
   }
}

void p18_setpara_sub5_dialog::on_pbtn_num7_clicked()
{
    switch(num_18)
   {
       case 1:

           type_buf[type_len++]='7';
            break;

      default:
           break;
   }
}

void p18_setpara_sub5_dialog::on_pbtn_num8_clicked()
{
    switch(num_18)
   {
       case 1:

           type_buf[type_len++]='8';
            break;

      default:
           break;
   }
}

void p18_setpara_sub5_dialog::on_pbtn_num9_clicked()
{
    switch(num_18)
   {
       case 1:

           type_buf[type_len++]='9';
            break;

      default:
           break;
   }
}

void p18_setpara_sub5_dialog::on_pbtn_dot_clicked()
{
    switch(num_18)
   {
       case 1:
           type_buf[type_len++]='.';
            break;

      default:
           break;
   }
}



void p18_setpara_sub5_dialog::on_pbtn_back_clicked()
{
    switch(num_18)
   {
       case 1:
        if(type_len>0)
        {
            type_len--;
            type_buf[type_len]=0;
        }
        else
        {
            type_len=0;
        }
        break;

      default:
           break;
   }
}

void p18_setpara_sub5_dialog::on_pbtn_up_clicked()
{
     DebugMsg(hmilev,5,"on_pbtn_up_clicked\n");

    hmi_button_dn_num=PAGEUP_BUTTON ;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
}

void p18_setpara_sub5_dialog::on_pbtn_down_clicked()
{
   // DebugMsg(hmilev,5,"on_pbtn_down_clicked\n");

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"stub_type");
    if(type_len>0)
    {
        type = atoi(type_buf);
        write_profile_int(Section_name,Key_name,type,config_path);
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }
    hmi_button_dn_num=PAGEDOWN_BUTTON ;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));

}

void p18_setpara_sub5_dialog::on_pbtn_go_clicked()
{
    DebugMsg(hmilev,5,"on_pbtn_cancel_clicked\n");
    hmi_button_dn_num=CANCEL_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
}

void p18_setpara_sub5_dialog::on_pbtn_ok_clicked()
{
    DebugMsg(hmilev,5,"on_pbtn_enter_clicked\n");

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"stub_type");
    if(type_len>0)
    {
        type = atoi(type_buf);
        write_profile_int(Section_name,Key_name,type,config_path);
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }
    hmi_button_dn_num=OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
}

void p18_setpara_sub5_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p18dlg();
    //delete p18_dlg;
   // p18_dlg = NULL;
}
