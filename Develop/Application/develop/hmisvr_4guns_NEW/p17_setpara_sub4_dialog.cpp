#include "p17_setpara_sub4_dialog.h"
#include "ui_p17_setpara_sub4_dialog.h"
#include "globalhmi.h"

p17_setpara_sub4_dialog::p17_setpara_sub4_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p17_setpara_sub4_dialog)
{
    ui->setupUi(this);
}

p17_setpara_sub4_dialog::~p17_setpara_sub4_dialog()
{
    delete ui;
}

void p17_setpara_sub4_dialog::changeEvent(QEvent *e)
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




void p17_setpara_sub4_dialog::init_page_dlg()
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

BOOL flg=TRUE;
BOOL web_flg=FALSE;
 int num_temp_17;
void p17_setpara_sub4_dialog::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));

        ac_len=0;
        maxv_len=0;
        maxi_len=0;
        cost_len=0;
        cost_len_serv=0;
        websize_len=0;

        meter_rate_len = 0;
        moudle_sum_len = 0;
        moudle_cur_len = 0;

        fac=0;
        fmaxv=0;
        fmaxi=0;
        fcost=0;
        fcost_serv=0;

        meter_rate_num = 0;
        moudle_cur_num = 0;
        moudle_sum_num = 0;

        memset(ac,0,sizeof(ac));
        memset(maxv,0,sizeof(maxv));
        memset(maxi,0,sizeof(maxi));
        memset(cost,0,sizeof(cost));
        memset(cost_serv,0,sizeof(cost_serv));
        memset(websize,0,sizeof(websize));

        memset(meter_rate,0,sizeof(meter_rate));
        memset(moudle_cur,0,sizeof(moudle_cur));
        memset(moudle_sum,0,sizeof(moudle_sum));

        num_temp_17=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"maxmodnum");
        moudle_sum_num = read_profile_int(Section_name, Key_name,num_temp_17,config_path);
        sprintf(moudle_sum,"%02d",moudle_sum_num);

        num_temp_17=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"currentmodnum");
        moudle_cur_num = read_profile_int(Section_name, Key_name,num_temp_17,config_path);
        sprintf(moudle_cur,"%02d",moudle_cur_num);

        num_temp_17=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"meterspeed");
        meter_rate_num = read_profile_int(Section_name, Key_name,num_temp_17,config_path);
        sprintf(meter_rate,"%02d",meter_rate_num);

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

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"carchecklen");
        fcost= read_profile_float(Section_name, Key_name,max_temp,config_path);
        sprintf(cost,"%d",(int)fcost);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"historysaveinterval");
        fcost_serv= read_profile_float(Section_name, Key_name,max_temp,config_path);
        sprintf(cost_serv,"%d",(int)fcost_serv);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"aclimitcurrent");
        fac= read_profile_float(Section_name, Key_name,max_temp,config_path);
        sprintf(ac,"%0.2f",fac);

        memset(Tempor_name,0,sizeof(Tempor_name));
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"websize");

        if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
        {
            memcpy(websize,Tempor_name,sizeof(websize));
            web_flg=TRUE;
        }
        else
        {
            memset(websize,0,sizeof(websize));
        }

}

void p17_setpara_sub4_dialog::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
}

void p17_setpara_sub4_dialog::btn_press()
{
    QPushButton* array[24]={0};
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
    array[16] = ui->pbtn_1;
    array[17] = ui->pbtn_2;
    array[18] = ui->pbtn_3;
    array[19] = ui->pbtn_4;
    array[20] = ui->pbtn_5;
    array[21] = ui->pbtn_6;
    array[22] = ui->pbtn_7;
    array[23] = ui->pbtn_8;
    int num = 0;
    for(num = 0; num < 24;num++)
    {
        array[num]->setStyleSheet("QPushButton{border-image: url(:/btn/qrc/PICS/Pbtn.png);}\
                                  QPushButton:pressed{border-image: url(:/btn/qrc/PICS/Pbtn_press.png);}");
    }

}

void p17_setpara_sub4_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
    // ui->lbl_sysdate->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    // ui->lbl_systime->setText(QTime::currentTime().toString("hh:mm:ss"));
}

void p17_setpara_sub4_dialog::update_page_info()
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
    ui->label_maxv->setText(maxv);
    ui->label_maxi->setText(maxi);
    ui->lbl_cost->setText(cost);
    ui->lbl_cost_serv->setText(cost_serv);
    ui->lbl_accurrent->setText(ac);

    ui->lbl_moudle_cur->setText(moudle_cur);
    ui->lbl_moudle_sum->setText(moudle_sum);
    ui->lbl_meterrate->setText(meter_rate);

   // ui->lbl_websize->setText(websize);
}

void p17_setpara_sub4_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_SETPAGE_FOUR)
    {
        exit_page_dlg();
    }
    else
    {

    }
}

void p17_setpara_sub4_dialog::call_p16_dlg()
{
    timer->stop();
    emit signal_timer_p17dlg();
    delete p17_dlg;
    p17_dlg = NULL;
}

void p17_setpara_sub4_dialog::call_p18_dlg()
{
    timer->stop();
    if(p18_dlg){
            delete p18_dlg;
            p18_dlg = NULL;

    }
    p18_dlg = new p18_setpara_sub5_dialog;
    p18_dlg->setWindowFlags(Qt::FramelessWindowHint);

    connect(this,SIGNAL(signal_enable_p18dlg_timer()),p18_dlg,SLOT(init_page_dlg()));
    connect(p18_dlg,SIGNAL(signal_exit_p18dlg()),this,SLOT(exit_page_dlg()));
    connect(p18_dlg,SIGNAL(signal_timer_p18dlg()),this,SLOT(start_timer()));
    emit signal_enable_p18dlg_timer();
    p18_dlg->exec();
}

void p17_setpara_sub4_dialog::call_p24_dlg()
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

int num_17=0;

void p17_setpara_sub4_dialog::on_pbtn_1_clicked()
{
  num_17=1;

}
void p17_setpara_sub4_dialog::on_pbtn_2_clicked()
{
  num_17=2;

}
void p17_setpara_sub4_dialog::on_pbtn_3_clicked()
{
  num_17=3;

}
void p17_setpara_sub4_dialog::on_pbtn_4_clicked()
{
  num_17=4;

}
void p17_setpara_sub4_dialog::on_pbtn_5_clicked()
{
  num_17=5;

}

void p17_setpara_sub4_dialog::on_pbtn_6_clicked()
{
  num_17=6;

}

void p17_setpara_sub4_dialog::on_pbtn_7_clicked()
{
  num_17=7;

}

void p17_setpara_sub4_dialog::on_pbtn_8_clicked()
{
  num_17=8;

}


void p17_setpara_sub4_dialog::on_pbtn_num0_clicked()
{
     switch(num_17)
    {
        case 1:

            maxv[maxv_len++]='0';
             break;

        case 2:

              maxi[maxi_len++]='0';
               break;

        case 3:

                  cost[cost_len++]='0';
                   break;

        case 4:

                 cost_serv[cost_len_serv++]='0';
                   break;

         case 5:

                ac[ac_len++]='0';
                break;

     case 6:
            meter_rate[meter_rate_len++]='0';
            break;
     case 7:
            moudle_sum[moudle_sum_len++]='0';
            break;
     case 8:
            moudle_cur[moudle_cur_len++]='0';
            break;
       // default:

                //

    }



}

void p17_setpara_sub4_dialog::on_pbtn_num1_clicked()
{
    switch(num_17)
   {
       case 1:

           maxv[maxv_len++]='1';
            break;

       case 2:

             maxi[maxi_len++]='1';
              break;

       case 3:

                 cost[cost_len++]='1';
                  break;

       case 4:

                cost_serv[cost_len_serv++]='1';
                  break;

        case 5:
                 ac[ac_len++]='1';
               break;
    case 6:
           meter_rate[meter_rate_len++]='1';
           break;
    case 7:
           moudle_sum[moudle_sum_len++]='1';
           break;
    case 8:
           moudle_cur[moudle_cur_len++]='1';
           break;
        //default:

                //

    }
}

void p17_setpara_sub4_dialog::on_pbtn_num2_clicked()
{
    switch(num_17)
   {
       case 1:

           maxv[maxv_len++]='2';
            break;

       case 2:

             maxi[maxi_len++]='2';
              break;

       case 3:

                 cost[cost_len++]='2';
                  break;

       case 4:

                cost_serv[cost_len_serv++]='2';
                  break;

        case 5:
                 ac[ac_len++]='2';
               break;
    case 6:
           meter_rate[meter_rate_len++]='2';
           break;
    case 7:
           moudle_sum[moudle_sum_len++]='2';
           break;
    case 8:
           moudle_cur[moudle_cur_len++]='2';
           break;
        //default:

                //

    }
}

void p17_setpara_sub4_dialog::on_pbtn_num3_clicked()
{
    switch(num_17)
   {
       case 1:

           maxv[maxv_len++]='3';
            break;

       case 2:

             maxi[maxi_len++]='3';
              break;

       case 3:

                 cost[cost_len++]='3';
                  break;

       case 4:

                cost_serv[cost_len_serv++]='3';
                  break;

        case 5:
                ac[ac_len++]='3';
               break;
    case 6:
           meter_rate[meter_rate_len++]='3';
           break;
    case 7:
           moudle_sum[moudle_sum_len++]='3';
           break;
    case 8:
           moudle_cur[moudle_cur_len++]='3';
           break;
       // default:

                //

    }
}

void p17_setpara_sub4_dialog::on_pbtn_num4_clicked()
{
    switch(num_17)
   {
       case 1:

           maxv[maxv_len++]='4';
            break;

       case 2:

             maxi[maxi_len++]='4';
              break;

       case 3:

                 cost[cost_len++]='4';
                  break;

       case 4:

                cost_serv[cost_len_serv++]='4';
                  break;

        case 5:
               ac[ac_len++]='4';
               break;
    case 6:
           meter_rate[meter_rate_len++]='4';
           break;
    case 7:
           moudle_sum[moudle_sum_len++]='4';
           break;
    case 8:
           moudle_cur[moudle_cur_len++]='4';
           break;
        //default:

                //

    }
}

void p17_setpara_sub4_dialog::on_pbtn_num5_clicked()
{
    switch(num_17)
   {
       case 1:

           maxv[maxv_len++]='5';
            break;

       case 2:

             maxi[maxi_len++]='5';
              break;

       case 3:

                 cost[cost_len++]='5';
                  break;

       case 4:

                cost_serv[cost_len_serv++]='5';
                  break;

        case 5:
                ac[ac_len++]='5';
               break;
    case 6:
           meter_rate[meter_rate_len++]='5';
           break;
    case 7:
           moudle_sum[moudle_sum_len++]='5';
           break;
    case 8:
           moudle_cur[moudle_cur_len++]='5';
           break;
        //default:

                //

    }
}

void p17_setpara_sub4_dialog::on_pbtn_num6_clicked()
{
    switch(num_17)
   {
       case 1:

           maxv[maxv_len++]='6';
            break;

       case 2:

             maxi[maxi_len++]='6';
              break;

       case 3:

                 cost[cost_len++]='6';
                  break;

       case 4:

                cost_serv[cost_len_serv++]='6';
                  break;

        case 5:
                 ac[ac_len++]='6';
               break;
    case 6:
           meter_rate[meter_rate_len++]='6';
           break;
    case 7:
           moudle_sum[moudle_sum_len++]='6';
           break;
    case 8:
           moudle_cur[moudle_cur_len++]='6';
           break;
        //default:

                //

    }
}

void p17_setpara_sub4_dialog::on_pbtn_num7_clicked()
{

    switch(num_17)
   {
       case 1:

           maxv[maxv_len++]='7';
            break;

       case 2:

             maxi[maxi_len++]='7';
              break;

       case 3:

                 cost[cost_len++]='7';
                  break;

       case 4:

                cost_serv[cost_len_serv++]='7';
                  break;

        case 5:
                ac[ac_len++]='7';
               break;
    case 6:
           meter_rate[meter_rate_len++]='7';
           break;
    case 7:
           moudle_sum[moudle_sum_len++]='7';
           break;
    case 8:
           moudle_cur[moudle_cur_len++]='7';
           break;
       // default:

                //

    }
}

void p17_setpara_sub4_dialog::on_pbtn_num8_clicked()
{
    switch(num_17)
   {
       case 1:

           maxv[maxv_len++]='8';
            break;

       case 2:

             maxi[maxi_len++]='8';
              break;

       case 3:

                 cost[cost_len++]='8';
                  break;

       case 4:

                cost_serv[cost_len_serv++]='8';
                  break;

        case 5:
                ac[ac_len++]='8';
               break;
    case 6:
           meter_rate[meter_rate_len++]='8';
           break;
    case 7:
           moudle_sum[moudle_sum_len++]='8';
           break;
    case 8:
           moudle_cur[moudle_cur_len++]='8';
           break;
       // default:

                //

    }
}

void p17_setpara_sub4_dialog::on_pbtn_num9_clicked()
{
    switch(num_17)
   {
       case 1:

           maxv[maxv_len++]='9';
            break;

       case 2:

             maxi[maxi_len++]='9';
              break;

       case 3:

                 cost[cost_len++]='9';
                  break;

       case 4:

                cost_serv[cost_len_serv++]='9';
                  break;

        case 5:
                 ac[ac_len++]='9';
               break;
    case 6:
           meter_rate[meter_rate_len++]='9';
           break;
    case 7:
           moudle_sum[moudle_sum_len++]='9';
           break;
    case 8:
           moudle_cur[moudle_cur_len++]='9';
           break;
       // default:

                //

    }
}

void p17_setpara_sub4_dialog::on_pbtn_dot_clicked()
{
    switch(num_17)
   {
       case 1:

           maxv[maxv_len++]='.';
            break;

       case 2:

             maxi[maxi_len++]='.';
              break;

       case 3:

                 cost[cost_len++]='.';
                  break;

       case 4:

                cost_serv[cost_len_serv++]='.';
                  break;

        case 5:
                 ac[ac_len++]='.';
               break;
    case 6:
           meter_rate[meter_rate_len++]='.';
           break;
    case 7:
           moudle_sum[moudle_sum_len++]='.';
           break;
    case 8:
           moudle_cur[moudle_cur_len++]='.';
           break;
       // default:

                //

    }
}



void p17_setpara_sub4_dialog::on_pbtn_back_clicked()
{
        switch(num_17)
        {
        case 1:

        maxv_len=0;
        memset(maxv,0,sizeof(maxv));

        break;

        case 2:

        maxi_len=0;
        memset(maxi,0,sizeof(maxi));

        break;

        case 3:

        cost_len=0;
        memset(cost,0,sizeof(cost));

        break;

        case 4:

        cost_len_serv=0;
        memset(cost_serv,0,sizeof(cost_serv));

         break;

         case 5:

        ac_len=0;
        memset(ac,0,sizeof(ac));
         break;

        case 6:
               meter_rate_len = 0;
               memset(meter_rate,0,sizeof(meter_rate));
               break;
        case 7:
               moudle_sum_len = 0;
              memset(moudle_sum,0,sizeof(moudle_sum));
              break;
        case 8:
             moudle_cur_len = 0;
             memset(moudle_cur,0,sizeof(moudle_cur));
             break;
        default:
        break;
        //

        }

}

void p17_setpara_sub4_dialog::on_pbtn_up_clicked()
{
     DebugMsg(hmilev,5,"on_pbtn_up_clicked\n");

    hmi_button_dn_num=PAGEUP_BUTTON ;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
}

void p17_setpara_sub4_dialog::on_pbtn_down_clicked()
{
   // DebugMsg(hmilev,5,"on_pbtn_down_clicked\n");

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"maxmodnum");
    if(moudle_sum_len>0)
    {
        moudle_sum_num = atoi(moudle_sum);
        write_profile_int(Section_name,Key_name,moudle_sum_num,config_path);
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"currentmodnum");
    if(moudle_cur_len>0)
    {
        moudle_cur_num = atoi(moudle_cur);
        write_profile_int(Section_name,Key_name,moudle_cur_num,config_path);
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"meterspeed");
    if(meter_rate_len>0)
    {
        meter_rate_num = atoi(meter_rate);
        write_profile_int(Section_name,Key_name,meter_rate_num,config_path);
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"handsethigestvolt");
    if(maxv_len>0)
    {
        fmaxv=atof(maxv);
        write_profile_float(Section_name,Key_name,fmaxv,config_path);
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"handsethigestcurrent");
    if(maxi_len>0)
    {
        fmaxi=atof(maxi);
        write_profile_float(Section_name,Key_name,fmaxi,config_path);
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"carchecklen");
    if(cost_len>0)
    {
        fcost=atof(cost);
        write_profile_int(Section_name,Key_name,fcost,config_path);
        //write_profile_float(Section_name,Key_name,fcost,config_path);
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"servicemoney");
    if(cost_len_serv>0)
    {
         fcost_serv=atof(cost_serv);
        write_profile_float(Section_name,Key_name,fcost_serv,config_path);
    }
    else
    {

        // ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"aclimitcurrent");
    if(ac_len>0)
    {
        fac=atof(ac);
        write_profile_float(Section_name,Key_name,fac,config_path);
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    hmi_button_dn_num=PAGEDOWN_BUTTON ;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));

}

void p17_setpara_sub4_dialog::on_pbtn_go_clicked()
{
    DebugMsg(hmilev,5,"on_pbtn_cancel_clicked\n");
    hmi_button_dn_num=CANCEL_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));

}

void p17_setpara_sub4_dialog::on_pbtn_ok_clicked()
{

    DebugMsg(hmilev,5,"on_pbtn_enter_clicked\n");

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"maxmodnum");
    if(moudle_sum_len>0)
    {
        moudle_sum_num = atoi(moudle_sum);
        write_profile_int(Section_name,Key_name,moudle_sum_num,config_path);
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"currentmodnum");
    if(moudle_cur_len>0)
    {
        moudle_cur_num = atoi(moudle_cur);
        write_profile_int(Section_name,Key_name,moudle_cur_num,config_path);
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"meterspeed");
    if(meter_rate_len>0)
    {
        meter_rate_num = atoi(meter_rate);
        write_profile_int(Section_name,Key_name,meter_rate_num,config_path);
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"handsethigestvolt");
    if(maxv_len>0)
    {
        fmaxv=atof(maxv);
        write_profile_float(Section_name,Key_name,fmaxv,config_path);
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"handsethigestcurrent");
    if(maxi_len>0)
    {
        fmaxi=atof(maxi);
        write_profile_float(Section_name,Key_name,fmaxi,config_path);
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"carchecklen");
    if(cost_len>0)
    {
        fcost=atof(cost);
        write_profile_int(Section_name,Key_name,fcost,config_path);
        //write_profile_float(Section_name,Key_name,fcost,config_path);
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"servicemoney");
    if(cost_len_serv>0)
    {
         fcost_serv=atof(cost_serv);
        write_profile_float(Section_name,Key_name,fcost_serv,config_path);
    }
    else
    {

        // ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"aclimitcurrent");
    if(ac_len>0)
    {
        fac=atof(ac);
        write_profile_float(Section_name,Key_name,fac,config_path);
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    hmi_button_dn_num=OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));

}

void p17_setpara_sub4_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p17dlg();
  //  delete p17_dlg;
 //   p17_dlg = NULL;
}
