 #include "p16_setpara_sub3_dialog.h"
#include "ui_p16_setpara_sub3_dialog.h"
#include "globalhmi.h"


p16_setpara_sub3_dialog::p16_setpara_sub3_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p16_setpara_sub3_dialog)
{
    ui->setupUi(this);

}
p16_setpara_sub3_dialog::~p16_setpara_sub3_dialog()
{
    delete ui;
}

void p16_setpara_sub3_dialog::changeEvent(QEvent *e)
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




void p16_setpara_sub3_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
    btn_press();
   // ui->label_code->setText(code);
    //ui->label_phone->setText(phonenum);
   // ui->label_phone_2->setText(phonenum_2);
}

BOOL soft_flg=FALSE;
BOOL source_flg=FALSE;
BOOL dev_flg=FALSE;

void p16_setpara_sub3_dialog::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));

         soft_len=0;
         btn_devwd_len=0;
         cost_len=0;
         source_len=0;
         memset(soft,0,sizeof(soft));
         memset(cost,0,sizeof(cost));
         memset(source,0,sizeof(source));
         memset(btn_devwd,0,sizeof(btn_devwd));

         int net_temp;
         net_temp=0;
         Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
         Inibuf_init(Key_name,BUFFERLEN_32,"networkservice");
         net_check= read_profile_int(Section_name, Key_name,net_temp,config_path);
       // net_check=net_temp;

         net_temp=0;
         Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
         Inibuf_init(Key_name,BUFFERLEN_32,"chargebyhand");
         hand_check= read_profile_int(Section_name, Key_name,net_temp,config_path);

        net_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"DataPackTranformWay");
        line_check= read_profile_int(Section_name, Key_name,net_temp,config_path);

        memset(Tempor_name,0,sizeof(Tempor_name));
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"stubcode");

        if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
        {
            memcpy(btn_devwd,Tempor_name,sizeof(btn_devwd));
            dev_flg=TRUE;
        }
        else
        {
            memset(btn_devwd,0,sizeof(btn_devwd));
        }

        memset(Tempor_name,0,sizeof(Tempor_name));
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"softwareversion");

        if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
        {
            char temp_soft[5]={0};
            memcpy(temp_soft,Tempor_name,sizeof(temp_soft));

           // printf("%x   %x   %x  %x \r\n",temp_soft[0],temp_soft[1],temp_soft[2],temp_soft[3]);

            sprintf(soft,"%d.%d.%d.%d",temp_soft[0],temp_soft[1],temp_soft[2],temp_soft[3]);
            /*
            int temp_a,temp_b,temp_c,temp_d;
            temp_a = toInt(0,16);
            sprintf(soft,"%d.%d.%d.%d",temp_a,temp_b,temp_c,temp_d);
*/
            soft_flg=TRUE;
        }
        else
        {
            memset(soft,0,sizeof(soft));
        }

        memset(Tempor_name,0,sizeof(Tempor_name));
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"meterfactor");

        if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
        {
            memcpy(cost,Tempor_name,sizeof(cost));
        }
        else
        {
            memset(cost,0,sizeof(cost));
        }

        memset(Tempor_name,0,sizeof(Tempor_name));
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"propertycode");

        if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
        {
            memcpy(source,Tempor_name,sizeof(source));
            source_flg=TRUE;
        }
        else
        {
            memset(source,0,sizeof(source));
        }

}

void p16_setpara_sub3_dialog::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
}


void p16_setpara_sub3_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p16_setpara_sub3_dialog::btn_press()
{

    QPushButton* array[19]={0};
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
    array[16] = ui->btn_1;
    array[17] = ui->btn_3;
    array[18] = ui->btn_4;
    int num = 0;
    for(num = 0; num < 19;num++)
    {
        array[num]->setStyleSheet("QPushButton{border-image: url(:/btn/qrc/PICS/Pbtn.png);}\
                                  QPushButton:pressed{border-image: url(:/btn/qrc/PICS/Pbtn_press.png);}");
    }

}

void p16_setpara_sub3_dialog::update_page_info()
{
    ui->lbl_sysdate->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    ui->lbl_systime->setText(QTime::currentTime().toString("hh:mm:ss"));
    if(language_num == 1)
    {
       //   ui->label_logo->setText(QString::fromUtf8("交 流 充 电 桩"));
         ui->label_stubnum->setText(QString::fromUtf8(" 客  服  热  线  :"));
    }
    else  if(language_num == 2)
    {
        //  ui->label_logo->setText("AC charging pile");
          ui->label_stubnum->setText("Telephone :");
    }
       ui->label_code->setText(phonenum);
      //  ui->label_phone->setText(phonenum);
     //   ui->label_phone_2->setText(phonenum_2);
        ui->lbl_dev_sn->setText(btn_devwd);

        ui->lbl_soft_ver->setText(soft);

   //     ui->lbl_cost_rate->setText(cost);
        ui->lbl_source_sn->setText(source);

       // ErrMsg("<<<<<<<<<<<<<<hmi_page_index error[%d]\n",net_check);

        if(hand_check)
        {
            ui->btn_hand_on->setChecked(TRUE);
            ui->btn_hand_off->setChecked(FALSE);
        }
        else
        {
            ui->btn_hand_on->setChecked(FALSE);
            ui->btn_hand_off->setChecked(TRUE);

        }

        if(net_check)
        {
            ui->start_btn->setChecked(TRUE);
            ui->cancle_btn->setChecked(FALSE);
        }
        else
        {
            ui->start_btn->setChecked(FALSE);
            ui->cancle_btn->setChecked(TRUE);

        }

        if(line_check)
        {
            if(line_check==10)
            {
                ui->wifi_btn->setChecked(TRUE);
                ui->liantong_btn->setChecked(FALSE);
                ui->yidong_btn->setChecked(FALSE);
                ui->dianxin_btn->setChecked(FALSE);
                ui->online_btn->setChecked(FALSE);
            }
            else  if(line_check==11)
            {
                ui->wifi_btn->setChecked(FALSE);
                ui->liantong_btn->setChecked(FALSE);
                ui->yidong_btn->setChecked(TRUE);
                ui->dianxin_btn->setChecked(FALSE);
                ui->online_btn->setChecked(FALSE);
            }
            else  if(line_check==12)
            {
                ui->wifi_btn->setChecked(FALSE);
                ui->liantong_btn->setChecked(TRUE);
                ui->yidong_btn->setChecked(FALSE);
                ui->dianxin_btn->setChecked(FALSE);
                ui->online_btn->setChecked(FALSE);
            }
            else  if(line_check==13)
            {
                ui->wifi_btn->setChecked(FALSE);
                ui->liantong_btn->setChecked(FALSE);
                ui->yidong_btn->setChecked(FALSE);
                ui->dianxin_btn->setChecked(TRUE);
                ui->online_btn->setChecked(FALSE);
            }
            else  if(line_check==2)
            {
                ui->wifi_btn->setChecked(FALSE);
                ui->liantong_btn->setChecked(FALSE);
                ui->yidong_btn->setChecked(FALSE);
                ui->dianxin_btn->setChecked(FALSE);
                ui->online_btn->setChecked(TRUE);
            }
            else
            {

            }
        }
}

void p16_setpara_sub3_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_SETPAGE_THR)
    {
        exit_page_dlg();
    }
    else
    {

    }
}

void p16_setpara_sub3_dialog::call_p15_dlg()
{

    timer->stop();
    emit signal_timer_p16dlg();
    delete p16_dlg;
    p16_dlg = NULL;
}

void p16_setpara_sub3_dialog::call_p17_dlg()
{
    timer->stop();
    if(p17_dlg){
            delete p17_dlg;
            p17_dlg = NULL;
            handle_dlg_p17--;
    }
    p17_dlg = new  p17_setpara_sub4_dialog;
    p17_dlg->setWindowFlags(Qt::FramelessWindowHint);
    handle_dlg_p17++;

    connect(this,SIGNAL(signal_enable_p17dlg_timer()),p17_dlg,SLOT(init_page_dlg()));
    connect(p17_dlg,SIGNAL(signal_exit_p17dlg()),this,SLOT(exit_page_dlg()));
    connect(p17_dlg,SIGNAL(signal_timer_p17dlg()),this,SLOT(start_timer()));
    emit signal_enable_p17dlg_timer();
    p17_dlg->exec();
}

void p16_setpara_sub3_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p16dlg();
    //delete p16_dlg;
    //p16_dlg = NULL;
}

BOOL neednet_flg;

void p16_setpara_sub3_dialog::on_btn_hand_on_clicked()
{
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"chargebyhand");
    hand_check=1;
    write_profile_int(Section_name,Key_name,hand_check,config_path);
}

void p16_setpara_sub3_dialog::on_btn_hand_off_clicked()
{
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"chargebyhand");
    hand_check=0;
    write_profile_int(Section_name,Key_name,hand_check,config_path);
}

void p16_setpara_sub3_dialog::on_start_btn_clicked()
{
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"networkservice");
    net_check=1;
    write_profile_int(Section_name,Key_name,net_check,config_path);
    neednet_flg=1;
    API_Write_DB_Nbyte(PL_NEEDNETWORK_FLAG ,(BOOL *)(&neednet_flg),sizeof(neednet_flg));
}

void p16_setpara_sub3_dialog::on_cancle_btn_clicked()
{
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"networkservice");
    net_check=0;
    write_profile_int(Section_name,Key_name,net_check,config_path);
    neednet_flg=0;
    API_Write_DB_Nbyte(PL_NEEDNETWORK_FLAG ,(BOOL *)(&neednet_flg),sizeof(neednet_flg));
}

void p16_setpara_sub3_dialog::on_wifi_btn_clicked()
{
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"DataPackTranformWay");
    line_check=10;
    write_profile_int(Section_name,Key_name,line_check,config_path);
}
void p16_setpara_sub3_dialog::on_yidong_btn_clicked()
{
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"DataPackTranformWay");
    line_check=11;
    write_profile_int(Section_name,Key_name,line_check,config_path);
}
 void p16_setpara_sub3_dialog::on_liantong_btn_clicked()
 {
     Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
     Inibuf_init(Key_name,BUFFERLEN_32,"DataPackTranformWay");
     line_check=12;
     write_profile_int(Section_name,Key_name,line_check,config_path);
 }
  void p16_setpara_sub3_dialog::on_dianxin_btn_clicked()
  {
      Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
      Inibuf_init(Key_name,BUFFERLEN_32,"DataPackTranformWay");
      line_check=13;
      write_profile_int(Section_name,Key_name,line_check,config_path);
  }

void p16_setpara_sub3_dialog::on_online_btn_clicked()
{
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"DataPackTranformWay");
    line_check=2;
    write_profile_int(Section_name,Key_name,line_check,config_path);
}

int num_16=0;

void p16_setpara_sub3_dialog::on_btn_1_clicked()
{
  //num_16=1;

}
void p16_setpara_sub3_dialog::on_btn_3_clicked()
{
  num_16=3;

}
void p16_setpara_sub3_dialog::on_btn_4_clicked()
{
  num_16=4;

}


void p16_setpara_sub3_dialog::on_pbtn_num0_clicked()
{
     switch(num_16)
    {
        case 1:
         if(soft_flg)
         {
             memset(soft,0,sizeof(soft));
             soft_flg=FALSE;
         }
            soft[soft_len++]='0';
             break;

        case 2:

            cost[cost_len++]='0';
               break;

        case 3:
         if(dev_flg)
         {
             memset(btn_devwd,0,sizeof(btn_devwd));
             dev_flg=FALSE;
         }
                  btn_devwd[btn_devwd_len++]='0';
                   break;

        case 4:
         if(source_flg)
         {
             memset(source,0,sizeof(source));
             source_flg=FALSE;
         }
                 source[source_len++]='0';
                   break;

       // default:

                //

    }



}

void p16_setpara_sub3_dialog::on_pbtn_num1_clicked()
{
    switch(num_16)
    {
    case 1:
     if(soft_flg)
     {
         memset(soft,0,sizeof(soft));
         soft_flg=FALSE;
     }
        soft[soft_len++]='1';
         break;

    case 2:

        cost[cost_len++]='1';
           break;

    case 3:
     if(dev_flg)
     {
         memset(btn_devwd,0,sizeof(btn_devwd));
         dev_flg=FALSE;
     }
              btn_devwd[btn_devwd_len++]='1';
               break;

    case 4:
     if(source_flg)
     {
         memset(source,0,sizeof(source));
         source_flg=FALSE;
     }
             source[source_len++]='1';
               break;

        //default:

                //

    }
}

void p16_setpara_sub3_dialog::on_pbtn_num2_clicked()
{
   switch(num_16)
    {
   case 1:
    if(soft_flg)
    {
        memset(soft,0,sizeof(soft));
        soft_flg=FALSE;
    }
       soft[soft_len++]='2';
        break;

   case 2:

       cost[cost_len++]='2';
          break;

   case 3:
    if(dev_flg)
    {
        memset(btn_devwd,0,sizeof(btn_devwd));
        dev_flg=FALSE;
    }
             btn_devwd[btn_devwd_len++]='2';
              break;

   case 4:
    if(source_flg)
    {
        memset(source,0,sizeof(source));
        source_flg=FALSE;
    }
            source[source_len++]='2';
              break;


        //default:

                //

    }
}

void p16_setpara_sub3_dialog::on_pbtn_num3_clicked()
{
     switch(num_16)
    {
     case 1:
      if(soft_flg)
      {
          memset(soft,0,sizeof(soft));
          soft_flg=FALSE;
      }
         soft[soft_len++]='3';
          break;

     case 2:

         cost[cost_len++]='3';
            break;

     case 3:
      if(dev_flg)
      {
          memset(btn_devwd,0,sizeof(btn_devwd));
          dev_flg=FALSE;
      }
               btn_devwd[btn_devwd_len++]='3';
                break;

     case 4:
      if(source_flg)
      {
          memset(source,0,sizeof(source));
          source_flg=FALSE;
      }
              source[source_len++]='3';
                break;


       // default:

                //

    }
}

void p16_setpara_sub3_dialog::on_pbtn_num4_clicked()
{
    switch(num_16)
    {
    case 1:
     if(soft_flg)
     {
         memset(soft,0,sizeof(soft));
         soft_flg=FALSE;
     }
        soft[soft_len++]='4';
         break;

    case 2:

        cost[cost_len++]='4';
           break;

    case 3:
     if(dev_flg)
     {
         memset(btn_devwd,0,sizeof(btn_devwd));
         dev_flg=FALSE;
     }
              btn_devwd[btn_devwd_len++]='4';
               break;

    case 4:
     if(source_flg)
     {
         memset(source,0,sizeof(source));
         source_flg=FALSE;
     }
             source[source_len++]='4';
               break;

        //default:

                //

    }
}

void p16_setpara_sub3_dialog::on_pbtn_num5_clicked()
{
    switch(num_16)
    {
    case 1:
     if(soft_flg)
     {
         memset(soft,0,sizeof(soft));
         soft_flg=FALSE;
     }
        soft[soft_len++]='5';
         break;

    case 2:

        cost[cost_len++]='5';
           break;

    case 3:
     if(dev_flg)
     {
         memset(btn_devwd,0,sizeof(btn_devwd));
         dev_flg=FALSE;
     }
              btn_devwd[btn_devwd_len++]='5';
               break;

    case 4:
     if(source_flg)
     {
         memset(source,0,sizeof(source));
         source_flg=FALSE;
     }
             source[source_len++]='5';
               break;

        //default:

                //

    }
}

void p16_setpara_sub3_dialog::on_pbtn_num6_clicked()
{
    switch(num_16)
    {
    case 1:
     if(soft_flg)
     {
         memset(soft,0,sizeof(soft));
         soft_flg=FALSE;
     }
        soft[soft_len++]='6';
         break;

    case 2:

        cost[cost_len++]='6';
           break;

    case 3:
     if(dev_flg)
     {
         memset(btn_devwd,0,sizeof(btn_devwd));
         dev_flg=FALSE;
     }
              btn_devwd[btn_devwd_len++]='6';
               break;

    case 4:
     if(source_flg)
     {
         memset(source,0,sizeof(source));
         source_flg=FALSE;
     }
             source[source_len++]='6';
               break;

        //default:

                //

    }
}

void p16_setpara_sub3_dialog::on_pbtn_num7_clicked()
{

    switch(num_16)
    {
    case 1:
     if(soft_flg)
     {
         memset(soft,0,sizeof(soft));
         soft_flg=FALSE;
     }
        soft[soft_len++]='7';
         break;

    case 2:

        cost[cost_len++]='7';
           break;

    case 3:
     if(dev_flg)
     {
         memset(btn_devwd,0,sizeof(btn_devwd));
         dev_flg=FALSE;
     }
              btn_devwd[btn_devwd_len++]='7';
               break;

    case 4:
     if(source_flg)
     {
         memset(source,0,sizeof(source));
         source_flg=FALSE;
     }
             source[source_len++]='7';
               break;

       // default:

                //

    }
}

void p16_setpara_sub3_dialog::on_pbtn_num8_clicked()
{
     switch(num_16)
    {
     case 1:
      if(soft_flg)
      {
          memset(soft,0,sizeof(soft));
          soft_flg=FALSE;
      }
         soft[soft_len++]='8';
          break;

     case 2:

         cost[cost_len++]='8';
            break;

     case 3:
      if(dev_flg)
      {
          memset(btn_devwd,0,sizeof(btn_devwd));
          dev_flg=FALSE;
      }
               btn_devwd[btn_devwd_len++]='8';
                break;

     case 4:
      if(source_flg)
      {
          memset(source,0,sizeof(source));
          source_flg=FALSE;
      }
              source[source_len++]='8';
                break;


       // default:

                //

    }
}

void p16_setpara_sub3_dialog::on_pbtn_num9_clicked()
{
   switch(num_16)
    {
   case 1:
    if(soft_flg)
    {
        memset(soft,0,sizeof(soft));
        soft_flg=FALSE;
    }
       soft[soft_len++]='9';
        break;

   case 2:

       cost[cost_len++]='9';
          break;

   case 3:
    if(dev_flg)
    {
        memset(btn_devwd,0,sizeof(btn_devwd));
        dev_flg=FALSE;
    }
             btn_devwd[btn_devwd_len++]='9';
              break;

   case 4:
    if(source_flg)
    {
        memset(source,0,sizeof(source));
        source_flg=FALSE;
    }
            source[source_len++]='9';
              break;

       // default:

                //

    }
}

void p16_setpara_sub3_dialog::on_pbtn_dot_clicked()
{
   switch(num_16)
    {
   case 1:
    if(soft_flg)
    {
        memset(soft,0,sizeof(soft));
        soft_flg=FALSE;
    }
       soft[soft_len++]='.';
        break;

   case 2:

       cost[cost_len++]='.';
          break;

   case 3:
    if(dev_flg)
    {
        memset(btn_devwd,0,sizeof(btn_devwd));
        dev_flg=FALSE;
    }
             btn_devwd[btn_devwd_len++]='.';
              break;

   case 4:
    if(source_flg)
    {
        memset(source,0,sizeof(source));
        source_flg=FALSE;
    }
            source[source_len++]='.';
              break;


       // default:

                //

    }
}



void p16_setpara_sub3_dialog::on_pbtn_back_clicked()
{
        switch(num_16)
        {
        case 1:
        if(soft_len>0)
        {
            soft_len--;
            soft[soft_len]=0;
        }
        else
        {
            soft_len=0;
        }
        break;

        case 2:
        if(cost_len>0)
        {
            cost_len--;
            cost[cost_len]=0;
        }
        else
        {
            cost_len=0;
        }
        break;

        case 3:
        if(btn_devwd_len>0)
        {
            btn_devwd_len--;
            btn_devwd[btn_devwd_len]=0;
        }
        else
        {
            btn_devwd_len=0;
        }

        break;

        case 4:
        if(source_len>0)
        {
            source_len--;
            source[source_len]=0;
        }
        else
        {
            source_len=0;
        }

        break;
        default:
        break;
        //

        }

}

void p16_setpara_sub3_dialog::on_pbtn_up_clicked()
{

     DebugMsg(hmilev,5,"on_pbtn_up_clicked\n");

    hmi_button_dn_num=PAGEUP_BUTTON ;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
}

void p16_setpara_sub3_dialog::on_pbtn_down_clicked()
{
    DebugMsg(hmilev,5,"on_pbtn_down_clicked\n");

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"stubcode");
    if(btn_devwd_len>0)
    {
        write_profile_string(Section_name,Key_name,btn_devwd,config_path);
    }
    else
    {
       //  ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"softwareversion");
    if(soft_len>0)
    {
        write_profile_string(Section_name,Key_name,soft,config_path);
    }
    else
    {
        // ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"propertycode");
    if(source_len>0)
    {
        write_profile_string(Section_name,Key_name,source,config_path);
    }
    else
    {
      //   ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"meterfactor");
    if(cost_len>0)
    {
        write_profile_string(Section_name,Key_name,cost,config_path);
    }
    else
    {
      //   ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    hmi_button_dn_num=PAGEDOWN_BUTTON ;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));

}

void p16_setpara_sub3_dialog::on_pbtn_go_clicked()
{

    DebugMsg(hmilev,5,"on_pbtn_cancel_clicked\n");

    hmi_button_dn_num=CANCEL_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));

}

void p16_setpara_sub3_dialog::on_pbtn_ok_clicked()
{
    DebugMsg(hmilev,5,"on_pbtn_enter_clicked\n");

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"stubcode");
    if(btn_devwd_len>0)
    {
        write_profile_string(Section_name,Key_name,btn_devwd,config_path);
    }
    else
    {
     //    ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"softwareversion");
    if(soft_len>0)
    {
        write_profile_string(Section_name,Key_name,soft,config_path);
    }
    else
    {
      //   ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"propertycode");
    if(source_len>0)
    {
        write_profile_string(Section_name,Key_name,source,config_path);
    }
    else
    {
      //   ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"meterfactor");
    if(cost_len>0)
    {
        write_profile_string(Section_name,Key_name,cost,config_path);
    }
    else
    {
      //   ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    hmi_button_dn_num=OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
}
