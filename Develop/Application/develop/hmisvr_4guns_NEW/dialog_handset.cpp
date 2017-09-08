#include "dialog_handset.h"
#include "ui_dialog_handset.h"
#include "globalhmi.h"

Dialog_handset::Dialog_handset(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_handset)
{
    ui->setupUi(this);
}

Dialog_handset::~Dialog_handset()
{
    delete ui;
}

void Dialog_handset::init_page_dlg()
{
    init_page_val();
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);
    btn_press();
    ui->label_code->setText(phonenum);
}
void Dialog_handset::btn_press()
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
    array[14] = ui->pbtn_volt;
    array[15] = ui->pbtn_current;
    int num = 0;
    for(num = 0; num < 16;num++)
    {
        array[num]->setStyleSheet("QPushButton{border-image: url(:/btn/qrc/PICS/Pbtn.png);}\
                                  QPushButton:pressed{border-image: url(:/btn/qrc/PICS/Pbtn_press.png);}");
    }
}

int num_set=0;
void Dialog_handset::init_page_val()
{
    num_set=0;
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));

    volt_len = 0;
    current_len = 0;
    memset(volt,0,sizeof(volt));
    memset(current,0,sizeof(current));

    ui->lbl_volt->setFocus();
    ui->lbl_volt->clearFocus();
    ui->lbl_current->clearFocus();

   /*
    float max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"handsethigestvolt");
    fmaxv= read_profile_float(Section_name, Key_name,max_temp,config_path);
    sprintf(maxv,"%0.2f",fmaxv);

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"handsethigestcurrent");
    fmaxi= read_profile_float(Section_name, Key_name,max_temp,config_path);
    sprintf(maxi,"%0.2f",fmaxi);
  */
}

void Dialog_handset::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);

    init_page_val();
}

void Dialog_handset::timer_handle()
{
    update_page_info();
    update_hmi_page_index();
}


void Dialog_handset::update_page_info()
{
    ui->lbl_sysdate->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    ui->lbl_systime->setText(QTime::currentTime().toString("hh:mm:ss"));

    ui->lbl_current->setText(current);
    ui->lbl_volt->setText(volt);

    if(language_num == 1)
    {
      //  ui->label_logo->setText(QString::fromUtf8("直 流 充 电 桩"));
        ui->label_title->setText(QString::fromUtf8("手 动 设 置 充 电"));

        ui->pbtn_volt->setText(QString::fromUtf8("电压值(V)"));
        ui->pbtn_current->setText(QString::fromUtf8("电流值(A)"));

        ui->pbtn_go->setText(QString::fromUtf8("返  回"));
        ui->pbtn_ok->setText(QString::fromUtf8("确  定"));
        ui->label_stubnum->setText(QString::fromUtf8("客  服  热  线  :"));
    }
    else  if(language_num == 2)
    {
     //   ui->label_logo->setText("DC charging pile");
         ui->label_title->setText("Charge By Setting");

         ui->pbtn_volt->setText("Volt(V)");
         ui->pbtn_current->setText("Current(A)");

        ui->pbtn_go->setText("Back");
        ui->pbtn_ok->setText("OK");
        ui->label_stubnum->setText("Telephone :");
    }
    else
    {

    }

}

void Dialog_handset::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
    if(hmi_page_index != PAGEINDEX_CHARGEBYHAND)
    {
        exit_page_dlg();
    }
    else
    {

    }
}

void Dialog_handset::call_p07_dlg()
{
    timer->stop();
    emit signal_timer_dlg();
    delete handset_dlg;
    handset_dlg = NULL;
}

void Dialog_handset::exit_page_dlg()
{
    timer->stop();
    emit signal_exit_dlg();
   // delete handset_dlg;
   // handset_dlg = NULL;
}

void Dialog_handset::call_p11_dlg()
{
    timer->stop();
    if(p11_dlg){
            delete p11_dlg;
            p11_dlg = NULL;

    }
    p11_dlg = new  p11_charging_dialog;
    p11_dlg->setWindowFlags(Qt::FramelessWindowHint);


    connect(this,SIGNAL(signal_enable_p11dlg_timer()),p11_dlg,SLOT(init_page_dlg()));
    connect(p11_dlg,SIGNAL(signal_exit_p11dlg()),this,SLOT(exit_page_dlg()));
    emit signal_enable_p11dlg_timer();
    p11_dlg->exec();
}

void Dialog_handset::on_pbtn_volt_clicked()
{
    num_set=1;
     ui->lbl_volt->setFocus();
      ui->lbl_current->clearFocus();
}
void Dialog_handset::on_pbtn_current_clicked()
{
    num_set=2;
     ui->lbl_current->setFocus();
      ui->lbl_volt->clearFocus();
}

void Dialog_handset::on_pbtn_num0_clicked()
{
    switch(num_set)
    {
        case 1:

            volt[volt_len++]='0';
            break;

        case 2:

              current[current_len++]='0';
               break;


       // default:

                //

    }



}

void Dialog_handset::on_pbtn_num1_clicked()
{
     switch(num_set)
    {
     case 1:

         volt[volt_len++]='1';
         break;

     case 2:

           current[current_len++]='1';
            break;



        //default:

                //

    }
}

void Dialog_handset::on_pbtn_num2_clicked()
{
    switch(num_set)
    {
    case 1:

        volt[volt_len++]='2';
        break;

    case 2:

          current[current_len++]='2';
           break;


        //default:

                //

    }
}

void Dialog_handset::on_pbtn_num3_clicked()
{
     switch(num_set)
    {
     case 1:

         volt[volt_len++]='3';
         break;

     case 2:

           current[current_len++]='3';
            break;


       // default:

                //

    }
}

void Dialog_handset::on_pbtn_num4_clicked()
{
    switch(num_set)
    {
    case 1:

        volt[volt_len++]='4';
        break;

    case 2:

          current[current_len++]='4';
           break;


        //default:

                //

    }
}

void Dialog_handset::on_pbtn_num5_clicked()
{
     switch(num_set)
    {
     case 1:

         volt[volt_len++]='5';
         break;

     case 2:

           current[current_len++]='5';
            break;



        //default:

                //

    }
}

void Dialog_handset::on_pbtn_num6_clicked()
{
    switch(num_set)
    {
    case 1:

        volt[volt_len++]='6';
        break;

    case 2:

          current[current_len++]='6';
           break;



        //default:

                //

    }
}

void Dialog_handset::on_pbtn_num7_clicked()
{

    switch(num_set)
    {
    case 1:

        volt[volt_len++]='7';
        break;

    case 2:

          current[current_len++]='7';
           break;




       // default:

                //

    }
}

void Dialog_handset::on_pbtn_num8_clicked()
{
    switch(num_set)
    {
    case 1:

        volt[volt_len++]='8';
        break;

    case 2:

          current[current_len++]='8';
           break;



       // default:

                //

    }
}

void Dialog_handset::on_pbtn_num9_clicked()
{
    switch(num_set)
    {
    case 1:

        volt[volt_len++]='9';
        break;

    case 2:

          current[current_len++]='9';
           break;



       // default:

                //

    }
}

void Dialog_handset::on_pbtn_dot_clicked()
{
   switch(num_set)
    {
   case 1:

       volt[volt_len++]='.';
       break;

   case 2:

         current[current_len++]='.';
          break;




       // default:

                //

    }
}

void Dialog_handset::on_pbtn_back_clicked()
{
        switch(num_set)
        {
        case 1:

            if(volt_len>0)
            {
                volt_len--;
                volt[volt_len]=0;
            }
            else
            {
                volt_len=0;
            }
        break;

        case 2:
        if(current_len>0)
        {
            current_len--;
            current[current_len]=0;
        }
        else
        {
            current_len=0;
        }
        break;




        default:
        break;
        //

    }

}

void Dialog_handset::on_pbtn_go_clicked()
{

    DebugMsg(hmilev,5,"on_pbtn_cancel_clicked\n");

    hmi_button_dn_num=CANCEL_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));

}


void Dialog_handset::on_pbtn_ok_clicked()
{

    DebugMsg(hmilev,5,"on_pbtn_enter_clicked\n");
    if(current_len == 0 || volt_len == 0)
    {
         return;
    }
    else
    {
        float temp_current = atof(current);
        float temp_volt = atof(volt);
        API_Write_DB_Nbyte(PL_HANDSET_CURRENT,(FLOAT32 *)(&temp_current),sizeof(FLOAT32));
        API_Write_DB_Nbyte(PL_HANDSET_VOLT,(FLOAT32 *)(&temp_volt),sizeof(FLOAT32));
    }
    hmi_button_dn_num=OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));

}

