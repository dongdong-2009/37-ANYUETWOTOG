#include "p14_setpara_sub1_dialog.h"
#include "ui_p14_setpara_sub1_dialog.h"
#include "globalhmi.h"

p14_setpara_sub1_dialog::p14_setpara_sub1_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p14_setpara_sub1_dialog)
{
    ui->setupUi(this);
}


p14_setpara_sub1_dialog::~p14_setpara_sub1_dialog()
{
    delete ui;
}

void p14_setpara_sub1_dialog::changeEvent(QEvent *e)
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

void p14_setpara_sub1_dialog::init_page_dlg()
{
    init_page_val();
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    btn_press();
    ui->label_code->setText(phonenum);
    //ui->label_phone->setText(phonenum);
    //ui->label_phone_2->setText(phonenum_2);
}

void GetsysTime(SYNCHRO_TIME_S*OutStrctTm)
{
   struct tm *GetTime;
   time_t timep;
   time(&timep);
   GetTime=localtime(&timep);
   OutStrctTm->uwYear=GetTime->tm_year+1900;
   OutStrctTm->ucMonth=GetTime->tm_mon+1;
   OutStrctTm->ucDay=GetTime->tm_mday;
   OutStrctTm->ucHour=GetTime->tm_hour;
   OutStrctTm->ucMinute=GetTime->tm_min;
   OutStrctTm->ucSecond=GetTime->tm_sec;
}

int SetSystemTime( SYNCHRO_TIME_S *setsyntime)
{
        char cmd[100];
        memset(cmd,0,sizeof(cmd));
        sprintf(cmd,"time_sync %04d-%02d-%02d-%02d-%02d-%02d",setsyntime->uwYear,setsyntime->ucMonth,
        setsyntime->ucDay,setsyntime->ucHour,setsyntime->ucMinute,setsyntime->ucSecond);
        system(cmd);
        return TRUE;
}

BOOL setpaswd_flg;
BOOL phone_flg;
BOOL phone_flg_1;
BOOL time_flg;
void p14_setpara_sub1_dialog::init_page_val()
{
        setpaswd_flg=TRUE;
        phone_flg=FALSE;
        phone_flg_1=FALSE;
        time_flg=TRUE;
         UINT8 data = NO_BUTTON;
         API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
         time_len=0;
         phone_len=0;
         stime_len=0;
         pswd_len=0;
         pswd_sure_len=0;
         memset(phone,0,sizeof(phone));
         memset(time,0,sizeof(time));
         memset(stime,0,sizeof(stime));
         memset(pswd,0,sizeof(pswd));
         memset(pswd_sure,0,sizeof(pswd_sure));

         memset(Tempor_name,0,sizeof(Tempor_name));
         Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
         Inibuf_init(Key_name,BUFFERLEN_32,"twoemergencycall");

         if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
         {
             memcpy(phone,Tempor_name,sizeof(phone));
             phone_flg=TRUE;
         }
         else
         {
             memset(phone,0,sizeof(phone));
         }

         memset(Tempor_name,0,sizeof(Tempor_name));
         Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
         Inibuf_init(Key_name,BUFFERLEN_32,"oneemergencycall");

         if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
         {
             memcpy(stime,Tempor_name,sizeof(stime));
             phone_flg_1=TRUE;
         }
         else
         {
             memset(stime,0,sizeof(stime));
         }

         SYNCHRO_TIME_S systm;
         GetsysTime(&systm);     
         sprintf(time,"%04d.%02d.%02d.%02d.%02d.%02d",systm.uwYear,systm.ucMonth,systm.ucDay,systm.ucHour,systm.ucMinute,systm.ucSecond);
}

void p14_setpara_sub1_dialog::start_timer()
{
    init_page_val();
    timer->start(PAGE_FLUSH_TIMER);
}


void p14_setpara_sub1_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
     //ui->lbl_sysdate->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    // ui->lbl_systime->setText(QTime::currentTime().toString("hh:mm:ss"));
}

void p14_setpara_sub1_dialog::btn_press()
{
    QPushButton* array[21]={0};
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
    array[16] = ui->btn_2;
    array[17] = ui->btn_3;
    array[18] = ui->btn_4;
    array[19] = ui->btn_5;
    array[20] = ui->btn_6;


    int num = 0;
    for(num = 0; num < 21;num++)
    {
        array[num]->setStyleSheet("QPushButton{border-image: url(:/btn/qrc/PICS/Pbtn.png);}\
                                  QPushButton:pressed{border-image: url(:/btn/qrc/PICS/Pbtn_press.png);}");
    }
}


void p14_setpara_sub1_dialog::update_page_info()
{
    ui->lbl_sysdate->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    ui->lbl_systime->setText(QTime::currentTime().toString("hh:mm:ss"));
    if(language_num == 1)
    {
        //  ui->label_logo->setText(QString::fromUtf8("交 流 充 电 桩"));
          ui->label_stubnum->setText(QString::fromUtf8(" 客  服  热  线  :"));
    }
    else  if(language_num == 2)
    {
       //   ui->label_logo->setText("AC charging pile");
          ui->label_stubnum->setText("Telephone :");
    }
  //  ui->label_code->setText(code);
 //   ui->label_phone->setText(phonenum);
 //   ui->label_phone_2->setText(phonenum_2);
    ui->lbl_phone_number->setText(phone);
    ui->lbl_time->setText(time);
    ui->lbl_stime->setText(stime);
    ui->lbl_pswd->setText(pswd);
    ui->lbl_pswd_sure->setText(pswd_sure);
    if(setpaswd_flg==FALSE)
    {
        ui->label_speaker->setText(QString::fromUtf8("两次密码不一致,请重新设置!"));
        pswd_len=0;
        memset(pswd,0,sizeof(pswd));
        pswd_sure_len=0;
        memset(pswd_sure,0,sizeof(pswd_sure));
        setpaswd_flg=TRUE;
    }
}

void p14_setpara_sub1_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
    if(hmi_page_index != PAGEINDEX_SETPAGE_ONE)
    {
        exit_page_dlg();
    }
    else
    {

    }
}

void p14_setpara_sub1_dialog::call_p15_dlg()
{
    timer->stop();
    if(p15_dlg){
            delete p15_dlg;
            p15_dlg = NULL;
            handle_dlg_p15--;
    }
    p15_dlg = new  p15_setpara_sub2_dialog;
    p15_dlg->setWindowFlags(Qt::FramelessWindowHint);
    handle_dlg_p15++;

    connect(this,SIGNAL(signal_enable_p15dlg_timer()),p15_dlg,SLOT(init_page_dlg()));
    connect(p15_dlg,SIGNAL(signal_exit_p15dlg()),this,SLOT(exit_page_dlg()));
    connect(p15_dlg,SIGNAL(signal_timer_p15dlg()),this,SLOT(start_timer()));
    emit signal_enable_p15dlg_timer();
    p15_dlg->exec();

}


void p14_setpara_sub1_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p14dlg();
    //delete p14_dlg;
    //p14_dlg = NULL;
}

int num_14=0;

void p14_setpara_sub1_dialog::on_btn_6_clicked()
{
  num_14=6;

}

void p14_setpara_sub1_dialog::on_btn_2_clicked()
{
  num_14=2;

}
void p14_setpara_sub1_dialog::on_btn_3_clicked()
{
  num_14=3;

}
void p14_setpara_sub1_dialog::on_btn_4_clicked()
{
  num_14=4;

}
void p14_setpara_sub1_dialog::on_btn_5_clicked()
{
  num_14=5;

}


void p14_setpara_sub1_dialog::on_pbtn_num0_clicked()
{

    switch(num_14)
    {
        case 2:
            if(time_flg)
            {
                memset(time,0,sizeof(time));
                time_flg=FALSE;
            }
             time[time_len++]='0';
               break;

        case 3:
            if(phone_flg_1)
            {
                memset(stime,0,sizeof(stime));
                phone_flg_1=FALSE;
            }
            stime[stime_len++]='0';
            break;

        case 4:

           pswd[pswd_len++]='0';
           break;

        case 5:

           pswd_sure[pswd_sure_len++]='0';
           break;

        case 6:
            if(phone_flg)
            {
                memset(phone,0,sizeof(phone));
                phone_flg=FALSE;
            }
            phone[phone_len++]='0';
            break;

        default:
                //
                break;

    }



}

void p14_setpara_sub1_dialog::on_pbtn_num1_clicked()
{
     switch(num_14)
    {
        case 1:

            //date[date_len++]='1';
            break;

        case 2:
         if(time_flg)
         {
             memset(time,0,sizeof(time));
             time_flg=FALSE;
         }
             time[time_len++]='1';
               break;

        case 3:
         if(phone_flg_1)
         {
             memset(stime,0,sizeof(stime));
             phone_flg_1=FALSE;
         }
                  stime[stime_len++]='1';
                   break;

        case 4:

                  pswd[pswd_len++]='1';
                   break;

        case 5:

                  pswd_sure[pswd_sure_len++]='1';
                   break;
     case 6:
         if(phone_flg)
         {
             memset(phone,0,sizeof(phone));
             phone_flg=FALSE;
         }
         phone[phone_len++]='1';
         break;

        //default:

                //

    }
}

void p14_setpara_sub1_dialog::on_pbtn_num2_clicked()
{
    switch(num_14)
    {
        case 1:

            //date[date_len++]='2';
            break;

        case 2:
        if(time_flg)
        {
            memset(time,0,sizeof(time));
            time_flg=FALSE;
        }
             time[time_len++]='2';
               break;

        case 3:
        if(phone_flg_1)
        {
            memset(stime,0,sizeof(stime));
            phone_flg_1=FALSE;
        }
                  stime[stime_len++]='2';
                   break;

        case 4:

                  pswd[pswd_len++]='2';
                   break;

        case 5:

                  pswd_sure[pswd_sure_len++]='2';
                   break;
    case 6:
        if(phone_flg)
        {
            memset(phone,0,sizeof(phone));
            phone_flg=FALSE;
        }
        phone[phone_len++]='2';
        break;

        //default:

                //

    }
}

void p14_setpara_sub1_dialog::on_pbtn_num3_clicked()
{
     switch(num_14)
    {
        case 1:

            //date[date_len++]='3';
            break;

        case 2:
         if(time_flg)
         {
             memset(time,0,sizeof(time));
             time_flg=FALSE;
         }
             time[time_len++]='3';
               break;

        case 3:
         if(phone_flg_1)
         {
             memset(stime,0,sizeof(stime));
             phone_flg_1=FALSE;
         }
                  stime[stime_len++]='3';
                   break;

        case 4:

                  pswd[pswd_len++]='3';
                   break;

        case 5:

                  pswd_sure[pswd_sure_len++]='3';
                   break;

     case 6:
         if(phone_flg)
         {
             memset(phone,0,sizeof(phone));
             phone_flg=FALSE;
         }
         phone[phone_len++]='3';
         break;

       // default:

                //

    }
}

void p14_setpara_sub1_dialog::on_pbtn_num4_clicked()
{
    switch(num_14)
    {
        case 1:

            //date[date_len++]='4';
            break;

        case 2:
        if(time_flg)
        {
            memset(time,0,sizeof(time));
            time_flg=FALSE;
        }
             time[time_len++]='4';
               break;

        case 3:
        if(phone_flg_1)
        {
            memset(stime,0,sizeof(stime));
            phone_flg_1=FALSE;
        }
                  stime[stime_len++]='4';
                   break;

        case 4:

                  pswd[pswd_len++]='4';
                   break;

        case 5:

                  pswd_sure[pswd_sure_len++]='4';
                   break;

    case 6:
        if(phone_flg)
        {
            memset(phone,0,sizeof(phone));
            phone_flg=FALSE;
        }
        phone[phone_len++]='4';
        break;

        //default:

                //

    }
}

void p14_setpara_sub1_dialog::on_pbtn_num5_clicked()
{
    switch(num_14)
    {
        case 1:

            //date[date_len++]='5';
            break;

        case 2:
        if(time_flg)
        {
            memset(time,0,sizeof(time));
            time_flg=FALSE;
        }
             time[time_len++]='5';
               break;

        case 3:
        if(phone_flg_1)
        {
            memset(stime,0,sizeof(stime));
            phone_flg_1=FALSE;
        }
                  stime[stime_len++]='5';
                   break;

        case 4:

                  pswd[pswd_len++]='5';
                   break;

        case 5:

                  pswd_sure[pswd_sure_len++]='5';
                   break;

    case 6:
        if(phone_flg)
        {
            memset(phone,0,sizeof(phone));
            phone_flg=FALSE;
        }
        phone[phone_len++]='5';
        break;

        //default:

                //

    }
}

void p14_setpara_sub1_dialog::on_pbtn_num6_clicked()
{
   switch(num_14)
    {
        case 1:

           // date[date_len++]='6';
            break;

        case 2:
       if(time_flg)
       {
           memset(time,0,sizeof(time));
           time_flg=FALSE;
       }
             time[time_len++]='6';
               break;

        case 3:
       if(phone_flg_1)
       {
           memset(stime,0,sizeof(stime));
           phone_flg_1=FALSE;
       }
                  stime[stime_len++]='6';
                   break;

        case 4:

                  pswd[pswd_len++]='6';
                   break;

        case 5:

                  pswd_sure[pswd_sure_len++]='6';
                   break;

   case 6:
       if(phone_flg)
       {
           memset(phone,0,sizeof(phone));
           phone_flg=FALSE;
       }
       phone[phone_len++]='6';
       break;

        //default:

                //

    }
}

void p14_setpara_sub1_dialog::on_pbtn_num7_clicked()
{

    switch(num_14)
    {
        case 1:

           // date[date_len++]='7';
            break;

        case 2:
        if(time_flg)
        {
            memset(time,0,sizeof(time));
            time_flg=FALSE;
        }
             time[time_len++]='7';
               break;

        case 3:
        if(phone_flg_1)
        {
            memset(stime,0,sizeof(stime));
            phone_flg_1=FALSE;
        }
                  stime[stime_len++]='7';
                   break;

        case 4:

                  pswd[pswd_len++]='7';
                   break;

        case 5:

                  pswd_sure[pswd_sure_len++]='7';
                   break;

    case 6:
        if(phone_flg)
        {
            memset(phone,0,sizeof(phone));
            phone_flg=FALSE;
        }
        phone[phone_len++]='7';
        break;

       // default:

                //

    }
}

void p14_setpara_sub1_dialog::on_pbtn_num8_clicked()
{
    switch(num_14)
    {
        case 1:

            //date[date_len++]='8';
            break;

        case 2:
        if(time_flg)
        {
            memset(time,0,sizeof(time));
            time_flg=FALSE;
        }
             time[time_len++]='8';
               break;

        case 3:
        if(phone_flg_1)
        {
            memset(stime,0,sizeof(stime));
            phone_flg_1=FALSE;
        }
                  stime[stime_len++]='8';
                   break;

        case 4:

                  pswd[pswd_len++]='8';
                   break;

        case 5:

                  pswd_sure[pswd_sure_len++]='8';
                   break;
    case 6:
        if(phone_flg)
        {
            memset(phone,0,sizeof(phone));
            phone_flg=FALSE;
        }
        phone[phone_len++]='8';
        break;

       // default:

                //

    }
}

void p14_setpara_sub1_dialog::on_pbtn_num9_clicked()
{
    switch(num_14)
    {
        case 1:

           // date[date_len++]='9';
            break;

        case 2:
        if(time_flg)
        {
            memset(time,0,sizeof(time));
            time_flg=FALSE;
        }
             time[time_len++]='9';
               break;

        case 3:
        if(phone_flg_1)
        {
            memset(stime,0,sizeof(stime));
            phone_flg_1=FALSE;
        }
                  stime[stime_len++]='9';
                   break;

        case 4:

                  pswd[pswd_len++]='9';
                   break;

        case 5:

                  pswd_sure[pswd_sure_len++]='9';
                   break;

    case 6:
        if(phone_flg)
        {
            memset(phone,0,sizeof(phone));
            phone_flg=FALSE;
        }
        phone[phone_len++]='9';
        break;

       // default:

                //

    }
}

void p14_setpara_sub1_dialog::on_pbtn_dot_clicked()
{
   switch(num_14)
    {
        case 1:

            //date[date_len++]='.';
            break;

        case 2:
       if(time_flg)
       {
           memset(time,0,sizeof(time));
           time_flg=FALSE;
       }
             time[time_len++]='.';
               break;

        case 3:
       if(phone_flg_1)
       {
           memset(stime,0,sizeof(stime));
           phone_flg_1=FALSE;
       }
                  stime[stime_len++]='-';
                   break;

        case 4:

                  pswd[pswd_len++]='.';
                   break;

        case 5:

                  pswd_sure[pswd_sure_len++]='.';
                   break;
   case 6:
       if(phone_flg)
       {
           memset(phone,0,sizeof(phone));
           phone_flg=FALSE;
       }
       phone[phone_len++]='-';
       break;

       // default:

                //

    }
}

void p14_setpara_sub1_dialog::on_pbtn_back_clicked()
{
     switch(num_14)
    {
        case 1:

        // date_len=0;
        // memset(date,0,sizeof(date));
        break;

        case 2:

         if(time_len>0)
         {
             time_len--;
             time[time_len]=0;
         }
         else
         {
             time_len=0;
         }

        break;

        case 3:

         if(stime_len>0)
         {
             stime_len--;
             stime[stime_len]=0;
         }
         else
         {
             stime_len=0;
         }

        break;

        case 4:

        if(pswd_len>0)
        {
            pswd_len--;
            pswd[pswd_len]=0;
        }
        else
        {
            pswd_len=0;
        }
        break;

        case 5:

         if(pswd_sure_len>0)
         {
             pswd_sure_len--;
             pswd_sure[pswd_sure_len]=0;
         }
         else
         {
             pswd_sure_len=0;
         }
        break;

        case 6:

        phone_len=0;
        memset(phone,0,sizeof(phone));
        break;

        default:
        break;
                //

    }

}

void TimeAnanisis_p01(SYNCHRO_TIME_S *OutTm,char *INputBuf)
{
        int strbuflen=0;
        int startpos=0;
        int timeslipt=0;
        unsigned char tempbuf[20];
        unsigned int Temppos=0;
        memset(OutTm,0,sizeof(SYNCHRO_TIME_S));
        strbuflen=strlen(INputBuf);
        if(strbuflen<=0)
        {
                return ;
        }

        memset(tempbuf,0,20);
        for(startpos=0;startpos<strbuflen;startpos++)
        {

                if(INputBuf[startpos]=='.')
                {
                        if(timeslipt==0)
                        {
                               OutTm->uwYear=atoi((char *)tempbuf);
                        // printf("OutTm.uwYea=%d",OutTm->uwYear);
                        }
                        else if(timeslipt==1)
                        {
                               OutTm->ucMonth=atoi((char *)tempbuf);
                        // printf("OutTm.ucMonth=%d",OutTm->ucMonth);
                        }
                        else if(timeslipt==2)
                        {
                               OutTm->ucDay=atoi((char *)tempbuf);
                        //printf("OutTm.ucDay=%d",OutTm->ucDay);
                        }
                        else if(timeslipt==3)
                        {
                             OutTm->ucHour=atoi((char *)tempbuf);
                        // printf("OutTm.uwYea=%d",OutTm->uwYear);

                        }
                        else if(timeslipt==4)
                        {
                             OutTm->ucMinute=atoi((char *)tempbuf);
                        // printf("OutTm.ucMonth=%d",OutTm->ucMonth);

                        }
                        else if(timeslipt==5)
                        {
                             OutTm->ucSecond=atoi((char *)tempbuf);
                        //printf("OutTm.ucDay=%d",OutTm->ucDay);

                        }

                        timeslipt++;
                        Temppos=0;
                        memset(tempbuf,0,20);
                }
                else
                {
                  if(Temppos<20)
                        {
                         tempbuf[Temppos++]=INputBuf[startpos];
                        }
                }
    }
}

void p14_setpara_sub1_dialog::on_pbtn_up_clicked()
{
}

void p14_setpara_sub1_dialog::on_pbtn_down_clicked()
{
     DebugMsg(hmilev,5,"on_pbtn_down_clicked\n");
     Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
     Inibuf_init(Key_name,BUFFERLEN_32,"twoemergencycall");
     if(phone_len>=0)
     {
       //  ErrMsg("$$$$$$[%s]$$$$$\n",phone);
         write_profile_string(Section_name,Key_name,phone,config_path);
     }
     else
     {
          ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
     }

     Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
     Inibuf_init(Key_name,BUFFERLEN_32,"oneemergencycall");
     if(stime_len>=0)
     {
        // ErrMsg("$$$$$$[%s]$$$$$\n",stime);
         write_profile_string(Section_name,Key_name,stime,config_path);
     }
     else
     {
          ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
     }

     SYNCHRO_TIME_S sytm;
     strcat(time,".");
     TimeAnanisis_p01(&sytm,time);
     SetSystemTime(&sytm);

     if(memcmp(pswd,pswd_sure,sizeof(pswd_sure))!=0)
     {
         setpaswd_flg=FALSE;
         return;
     }
     if(pswd_len!=0)
     {
         memset(Set_paswd,0,sizeof(Set_paswd));
         memcpy(Set_paswd,pswd_sure,sizeof(pswd_sure));

         memset(Tempor_name,0,sizeof(Tempor_name));
         Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
         Inibuf_init(Key_name,BUFFERLEN_32,"settingpwd");
         write_profile_string(Section_name,Key_name,pswd_sure,config_path);
     }


    hmi_button_dn_num=PAGEDOWN_BUTTON ;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));

    //this->close();
}

void p14_setpara_sub1_dialog::on_pbtn_go_clicked()
{

    DebugMsg(hmilev,5,"on_pbtn_cancel_clicked\n");

    //btn_passwd_pos=0;
    //memset(btn_passwd,0,sizeof(btn_passwd));

    hmi_button_dn_num=CANCEL_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));


}



void p14_setpara_sub1_dialog::on_pbtn_ok_clicked()
{

    DebugMsg(hmilev,5,"on_pbtn_enter_clicked\n");
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"twoemergencycall");
    if(phone_len>=0)
    {
      //  ErrMsg("$$$$$$[%s]$$$$$\n",phone);
        write_profile_string(Section_name,Key_name,phone,config_path);
    }
    else
    {
         ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"oneemergencycall");
    if(stime_len>=0)
    {
       // ErrMsg("$$$$$$[%s]$$$$$\n",stime);
        write_profile_string(Section_name,Key_name,stime,config_path);
    }
    else
    {
         ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    SYNCHRO_TIME_S sytm;
    strcat(time,".");
    TimeAnanisis_p01(&sytm,time);
    SetSystemTime(&sytm);

    if(memcmp(pswd,pswd_sure,sizeof(pswd_sure))!=0)
    {
        setpaswd_flg=FALSE;
        return;
    }
    if(pswd_len!=0)
    {
        memset(Set_paswd,0,sizeof(Set_paswd));
        memcpy(Set_paswd,pswd_sure,sizeof(pswd_sure));

        memset(Tempor_name,0,sizeof(Tempor_name));
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"settingpwd");
        write_profile_string(Section_name,Key_name,pswd_sure,config_path);
    }

    hmi_button_dn_num=OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
    //API_Write_DB_Nbyte(PL_HMI_CARD_PASSWD,(INT8 *)(&btn_passwd),sizeof(btn_passwd));
}

void p14_setpara_sub1_dialog::on_pbtn_setpoint_clicked()
{
   system("/usr/bin/ts_calibrate&");
   system("sleep 10");
   system("reboot");
}
void p14_setpara_sub1_dialog::on_pbtn_dateout_clicked()
{
    system("cp /usr/data/* /media/sda1/");
    system("cp /usr/data/* /media/sda2/");
    system("cp /usr/data/* /media/sda3/");
    system("cp /usr/data/* /media/sda4/");
}
