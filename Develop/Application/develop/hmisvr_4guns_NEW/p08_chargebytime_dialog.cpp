#include "p08_chargebytime_dialog.h"
#include "ui_p08_chargebytime_dialog.h"
#include "globalhmi.h"

p08_chargebytime_dialog::p08_chargebytime_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p08_chargebytime_dialog)
{
    ui->setupUi(this);
}

p08_chargebytime_dialog::~p08_chargebytime_dialog()
{
    delete ui;
}

void p08_chargebytime_dialog::changeEvent(QEvent *e)
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

static char btn_passwd[5]={};
static int btn_passwd_pos;
BOOL time_error_flg;
static BOOL num_flg;
static int num_time;

void p08_chargebytime_dialog::on_pbtn_30min_clicked()
{
    num_time=30;
    UINT8 data=30;
    API_Write_DB_Nbyte(PL_HMI_CHARG_BY_TIME_TYPE,(INT8 *)(&data),sizeof(data));

    data = OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));

}

void p08_chargebytime_dialog::on_pbtn_60min_clicked()
{
    num_time=60;
    UINT8 data=60;
    API_Write_DB_Nbyte(PL_HMI_CHARG_BY_TIME_TYPE,(INT8 *)(&data),sizeof(data));

    data = OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p08_chargebytime_dialog::on_pbtn_120min_clicked()
{
    num_time=120;
    UINT8 data=120;
    API_Write_DB_Nbyte(PL_HMI_CHARG_BY_TIME_TYPE,(INT8 *)(&data),sizeof(data));

    data = OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p08_chargebytime_dialog::on_pbtn_180min_clicked()
{
    num_time=90;
    UINT8 data=90;
    API_Write_DB_Nbyte(PL_HMI_CHARG_BY_TIME_TYPE,(INT8 *)(&data),sizeof(data));

    data = OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}


void p08_chargebytime_dialog::on_pbtn_go_clicked()
{
        UINT8 data = CANCEL_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p08_chargebytime_dialog::on_pbtn_ok_clicked()
{
        num_time=atof(btn_passwd);       
        if(num_time<=0||num_time>180)
        {
            time_error_flg=TRUE;
            btn_passwd_pos=0;
            memset(btn_passwd,0,sizeof(btn_passwd));
            return;
        }
        UINT8 data=num_time;
        ErrMsg("$$$$$$[%d]\n",data);
        API_Write_DB_Nbyte(PL_HMI_CHARG_BY_TIME_TYPE,(INT8 *)(&data),sizeof(data));
        data = OK_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}


void p08_chargebytime_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
    ui->label_code->setText(code);
    //ui->label_phone->setText(phonenum);
    //ui->label_phone_2->setText(phonenum_2);
    btn_press();
}

void p08_chargebytime_dialog::btn_press()
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

void p08_chargebytime_dialog::on_pbtn_num0_clicked()
{
    if(num_flg)
    {
        if(btn_passwd_pos>=MAX_PASSWD_LEN)
        {
            btn_passwd_pos=MAX_PASSWD_LEN;
        }else{
            btn_passwd[btn_passwd_pos++]='0';
        }
    }
}

void p08_chargebytime_dialog::on_pbtn_num1_clicked()
{
    if(num_flg)
    {
        if(btn_passwd_pos>=MAX_PASSWD_LEN)
        {
            btn_passwd_pos=MAX_PASSWD_LEN;
        }else{
            btn_passwd[btn_passwd_pos++]='1';
        }
    }
}

void p08_chargebytime_dialog::on_pbtn_num2_clicked()
{
    if(num_flg)
    {
        if(btn_passwd_pos>=MAX_PASSWD_LEN)
        {
            btn_passwd_pos=MAX_PASSWD_LEN;
        }else{
            btn_passwd[btn_passwd_pos++]='2';
        }
    }
}

void p08_chargebytime_dialog::on_pbtn_num3_clicked()
{
    if(num_flg)
    {
        if(btn_passwd_pos>=MAX_PASSWD_LEN)
        {
            btn_passwd_pos=MAX_PASSWD_LEN;
        }else{
            btn_passwd[btn_passwd_pos++]='3';
        }
    }
}

void p08_chargebytime_dialog::on_pbtn_num4_clicked()
{
    if(num_flg)
    {
        if(btn_passwd_pos>=MAX_PASSWD_LEN)
        {
            btn_passwd_pos=MAX_PASSWD_LEN;
        }else{
            btn_passwd[btn_passwd_pos++]='4';
        }
    }
}

void p08_chargebytime_dialog::on_pbtn_num5_clicked()
{
    if(num_flg)
    {
        if(btn_passwd_pos>=MAX_PASSWD_LEN)
        {
            btn_passwd_pos=MAX_PASSWD_LEN;
        }else{
            btn_passwd[btn_passwd_pos++]='5';
        }
    }
}

void p08_chargebytime_dialog::on_pbtn_num6_clicked()
{
    if(num_flg)
    {
        if(btn_passwd_pos>=MAX_PASSWD_LEN)
        {
            btn_passwd_pos=MAX_PASSWD_LEN;
        }else{
            btn_passwd[btn_passwd_pos++]='6';
        }
    }
}

void p08_chargebytime_dialog::on_pbtn_num7_clicked()
{

    if(num_flg)
    {
        if(btn_passwd_pos>=MAX_PASSWD_LEN)
        {
            btn_passwd_pos=MAX_PASSWD_LEN;
        }else{
            btn_passwd[btn_passwd_pos++]='7';
        }
    }
}

void p08_chargebytime_dialog::on_pbtn_num8_clicked()
{
    if(num_flg)
    {
        if(btn_passwd_pos>=MAX_PASSWD_LEN)
        {
            btn_passwd_pos=MAX_PASSWD_LEN;
        }else{
            btn_passwd[btn_passwd_pos++]='8';
        }
    }
}

void p08_chargebytime_dialog::on_pbtn_num9_clicked()
{
    if(num_flg)
    {
        if(btn_passwd_pos>=MAX_PASSWD_LEN)
        {
            btn_passwd_pos=MAX_PASSWD_LEN;
        }else{
            btn_passwd[btn_passwd_pos++]='9';
        }
    }
}

void p08_chargebytime_dialog::on_pbtn_dot_clicked()
{
    if(num_flg)
    {
        if(btn_passwd_pos>=MAX_PASSWD_LEN)
        {
            btn_passwd_pos=MAX_PASSWD_LEN;
        }else{
            btn_passwd[btn_passwd_pos++]='.';
        }
    }
}

void p08_chargebytime_dialog::on_pbtn_back_clicked()
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

void p08_chargebytime_dialog::init_page_val()
{
        num_flg=TRUE;
        time_error_flg=FALSE;
        memset(btn_passwd,0,sizeof(btn_passwd));
        btn_passwd_pos=0;
        num_time=0;
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
     //   data=CHARGEBYTIME_BUTTON_30;
     //   API_Write_DB_Nbyte(PL_HMI_CHARG_BY_TIME_TYPE,(INT8 *)(&data),sizeof(data));

}

void p08_chargebytime_dialog::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
}


void p08_chargebytime_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p08_chargebytime_dialog::update_page_info()
{
    ui->lbl_time_chose->setText(btn_passwd);

    if(language_num == 1)
    {
         // ui->label_logo->setText(QString::fromUtf8("直 流 充 电 桩"));
          ui->label_stubnum->setText(QString::fromUtf8(" 桩   编   号  :"));
          ui->pbtn_go->setText(QString::fromUtf8("返  回"));
          ui->pbtn_ok->setText(QString::fromUtf8("确  定"));

          if(time_error_flg)
          {
             ui->lbl_speaker->setText(QString::fromUtf8("请选择1至180之间任意数字!"));
          }
          else
          {
              ui->lbl_speaker->setText(QString::fromUtf8("请输入您所需的充电时间!"));
          }
    }
    else  if(language_num == 2)
    {
         // ui->label_logo->setText("DC charging pile");
          ui->label_stubnum->setText("Pile Number :");
          ui->pbtn_go->setText("Back");
          ui->pbtn_ok->setText("OK");

          if(time_error_flg)
          {
             ui->lbl_speaker->setText("Choose random numbers between 1 to 180 !");
          }
          else
          {
              ui->lbl_speaker->setText("Please enter the charging time you need !");
          }
    }

     if(num_flg)
     {
          ui->lbl_time_chose->setFocus();
     }
     else
     {
          ui->lbl_time_chose->clearFocus();
     }
}

void p08_chargebytime_dialog::update_hmi_page_index()
{
        API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
        if(hmi_page_index != PAGEINDEX_CHARGEBYTIME)
        {
            exit_page_dlg();
        }
        else
        {

        }
}
/*
void p08_chargebytime_dialog::call_dlg_1()
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
void p08_chargebytime_dialog::call_p07_dlg()
{

    timer->stop();
    emit signal_timer_p08dlg();
    delete p08_dlg;
    p08_dlg = NULL;
}

void p08_chargebytime_dialog::call_p11_dlg()
{
    timer->stop();
    if(p11_dlg){
            delete p11_dlg;
            p11_dlg = NULL;
            handle_dlg_p11--;
    }
    p11_dlg = new  p11_charging_dialog;
    p11_dlg->setWindowFlags(Qt::FramelessWindowHint);
    handle_dlg_p11++;

    connect(this,SIGNAL(signal_enable_p11dlg_timer()),p11_dlg,SLOT(init_page_dlg()));
    connect(p11_dlg,SIGNAL(signal_exit_p11dlg()),this,SLOT(exit_page_dlg()));
    emit signal_enable_p11dlg_timer();
    p11_dlg->exec();
}

void p08_chargebytime_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p08dlg();
    //delete p08_dlg;
   // p08_dlg = NULL;
}
