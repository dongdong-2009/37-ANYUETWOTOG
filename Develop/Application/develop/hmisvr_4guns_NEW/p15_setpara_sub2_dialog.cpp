#include "p15_setpara_sub2_dialog.h"
#include "ui_p15_setpara_sub2_dialog.h"
#include "globalhmi.h"

p15_setpara_sub2_dialog::p15_setpara_sub2_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p15_setpara_sub2_dialog)
{
    ui->setupUi(this);
}

p15_setpara_sub2_dialog::~p15_setpara_sub2_dialog()
{
    delete ui;
}

void p15_setpara_sub2_dialog::changeEvent(QEvent *e)
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

void p15_setpara_sub2_dialog::init_page_dlg()
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

int num_15=0;

  //char Section_name[BUFFERLEN_32];
  //char Key_name[BUFFERLEN_32];
  //char Tempor_name[BUFFERLEN_32];


BOOL farip_flg=FALSE;
BOOL port_flg=FALSE;
BOOL localip_flg=FALSE;
BOOL mask_flg=FALSE;
BOOL guan_flg=FALSE;
BOOL mac_flg=FALSE;

void p15_setpara_sub2_dialog::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));

         farip_len=0;
         localip_len=0;
         art_len=0;
         ma_len=0;
         guan_len=0;
         mac_len=0;

         memset(farip,0,sizeof(farip));
         memset(localip,0,sizeof(localip));
         memset(art,0,sizeof(art));
         memset(guan,0,sizeof(guan));
         memset(ma,0,sizeof(ma));
         memset(mac,0,sizeof(mac));

        memset(Tempor_name,0,sizeof(Tempor_name));
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"serverip");

        if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
        {
            memcpy(farip,Tempor_name,sizeof(farip));
            farip_flg=TRUE;
        }
        else
        {
            memset(farip,0,sizeof(farip));
        }

        memset(Tempor_name,0,sizeof(Tempor_name));
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"serverport");

        if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
        {
            memcpy(art,Tempor_name,sizeof(art));
            port_flg=TRUE;
        }
        else
        {
            memset(art,0,sizeof(art));
        }

        memset(Tempor_name,0,sizeof(Tempor_name));
        Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
        Inibuf_init(Key_name,BUFFERLEN_32,"ipaddr");

        if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
        {
            memcpy(localip,Tempor_name,sizeof(localip));
            localip_flg=TRUE;
        }
        else
        {
            memset(localip,0,sizeof(localip));
        }

        memset(Tempor_name,0,sizeof(Tempor_name));
        Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
        Inibuf_init(Key_name,BUFFERLEN_32,"mask");

        if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
        {
            memcpy(ma,Tempor_name,sizeof(ma));
            mask_flg=TRUE;
        }
        else
        {
            memset(ma,0,sizeof(ma));
        }

         memset(Tempor_name,0,sizeof(Tempor_name));
        Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
        Inibuf_init(Key_name,BUFFERLEN_32,"getway");

        if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
        {
            memcpy(guan,Tempor_name,sizeof(guan));
            guan_flg=TRUE;
        }
        else
        {
            memset(guan,0,sizeof(guan));
        }

        memset(Tempor_name,0,sizeof(Tempor_name));
        Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
        Inibuf_init(Key_name,BUFFERLEN_32,"sysmac");

        if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
        {
            memcpy(mac,Tempor_name,sizeof(mac));
            mac_flg=TRUE;
        }
        else
        {
            memset(ma,0,sizeof(mac));
        }
}

void p15_setpara_sub2_dialog::start_timer()
{
    init_page_val();
    timer->start(PAGE_FLUSH_TIMER);
}


void p15_setpara_sub2_dialog::timer_handle()
{

     update_page_info();
     update_hmi_page_index();
     //ui->lbl_sysdate->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    // ui->lbl_systime->setText(QTime::currentTime().toString("hh:mm:ss"));
}


void p15_setpara_sub2_dialog::btn_press()
{

    QPushButton* array[22]={0};
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
    array[19] = ui->btn_5;
    array[20] = ui->btn_6;
    array[21] = ui->btn_7;
    int num = 0;
    for(num = 0; num < 22;num++)
    {
        array[num]->setStyleSheet("QPushButton{border-image: url(:/btn/qrc/PICS/Pbtn.png);}\
                                  QPushButton:pressed{border-image: url(:/btn/qrc/PICS/Pbtn_press.png);}");
    }

}

void p15_setpara_sub2_dialog::update_page_info()
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
          //ui->label_logo->setText("AC charging pile");
          ui->label_stubnum->setText("Telephone :");
    }
 //   ui->label_code->setText(code);
 //   ui->label_phone->setText(phonenum);
 //   ui->label_phone_2->setText(phonenum_2);
    ui->lbl_farip->setText(farip);
    ui->lbl_art->setText(art);
    ui->lbl_localip->setText(localip);
    ui->lbl_ma->setText(ma);
    ui->lbl_guan->setText(guan);
    ui->lbl_mac->setText(mac);

}

void p15_setpara_sub2_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_SETPAGE_TWO)
    {
        exit_page_dlg();
    }
    else
    {

    }
}

void p15_setpara_sub2_dialog::call_p14_dlg()
{
    /*
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
    */   
    timer->stop();
    emit signal_timer_p15dlg();
    //init_page_val();
   // delete ui->pbtn_down;
   // ui->pbtn_down=NULL;
    delete p15_dlg;
    p15_dlg = NULL;
}

void p15_setpara_sub2_dialog::call_p16_dlg()
{
    timer->stop();
    if(p16_dlg){
            delete p16_dlg;
            p16_dlg = NULL;
            handle_dlg_p16--;
    }
    p16_dlg = new  p16_setpara_sub3_dialog;
    p16_dlg->setWindowFlags(Qt::FramelessWindowHint);
    handle_dlg_p16++;

    connect(this,SIGNAL(signal_enable_p16dlg_timer()),p16_dlg,SLOT(init_page_dlg()));
    connect(p16_dlg,SIGNAL(signal_exit_p16dlg()),this,SLOT(exit_page_dlg()));
    connect(p16_dlg,SIGNAL(signal_timer_p16dlg()),this,SLOT(start_timer()));
    emit signal_enable_p16dlg_timer();

    p16_dlg->exec();
}

void p15_setpara_sub2_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p15dlg();
   // delete p15_dlg;
    //p15_dlg = NULL;
}


void p15_setpara_sub2_dialog::on_btn_1_clicked()
{
  num_15=1;

}
void p15_setpara_sub2_dialog::on_btn_3_clicked()
{
  num_15=2;

}
void p15_setpara_sub2_dialog::on_btn_4_clicked()
{
  num_15=3;

}
void p15_setpara_sub2_dialog::on_btn_5_clicked()
{
  num_15=4;

}
void p15_setpara_sub2_dialog::on_btn_6_clicked()
{
  num_15=5;

}
void p15_setpara_sub2_dialog::on_btn_7_clicked()
{
  num_15=6;

}

void p15_setpara_sub2_dialog::on_pbtn_num0_clicked()
{
    switch(num_15)
    {
        case 1:
        if(farip_flg)
        {
            memset(farip,0,sizeof(farip));
            farip_flg=FALSE;
        }
            farip[farip_len++]='0';
            break;

        case 2:
        if(port_flg)
        {
            memset(art,0,sizeof(art));
            port_flg=FALSE;
        }
              art[art_len++]='0';
               break;

        case 3:
        if(localip_flg)
        {
            memset(localip,0,sizeof(localip));
            localip_flg=FALSE;
        }
                  localip[localip_len++]='0';
                   break;

        case 4:
        if(mask_flg)
        {
            memset(ma,0,sizeof(ma));
            mask_flg=FALSE;
        }
                  ma[ma_len++]='0';
                   break;

        case 5:
        if(guan_flg)
        {
            memset(guan,0,sizeof(guan));
            guan_flg=FALSE;
        }
                  guan[guan_len++]='0';
                   break;

        case 6:
        if(mac_flg)
        {
            memset(mac,0,sizeof(mac));
            mac_flg=FALSE;
        }
                  mac[mac_len++]='0';
                   break;
       // default:

                //

    }



}

void p15_setpara_sub2_dialog::on_pbtn_num1_clicked()
{
     switch(num_15)
    {
     case 1:
     if(farip_flg)
     {
         memset(farip,0,sizeof(farip));
         farip_flg=FALSE;
     }
         farip[farip_len++]='1';
         break;

     case 2:
     if(port_flg)
     {
         memset(art,0,sizeof(art));
         port_flg=FALSE;
     }
           art[art_len++]='1';
            break;

     case 3:
     if(localip_flg)
     {
         memset(localip,0,sizeof(localip));
         localip_flg=FALSE;
     }
               localip[localip_len++]='1';
                break;

     case 4:
     if(mask_flg)
     {
         memset(ma,0,sizeof(ma));
         mask_flg=FALSE;
     }
               ma[ma_len++]='1';
                break;

     case 5:
     if(guan_flg)
     {
         memset(guan,0,sizeof(guan));
         guan_flg=FALSE;
     }
               guan[guan_len++]='1';
                break;
     case 6:
     if(mac_flg)
     {
         memset(mac,0,sizeof(mac));
         mac_flg=FALSE;
     }
               mac[mac_len++]='1';
                break;

        //default:

                //

    }
}

void p15_setpara_sub2_dialog::on_pbtn_num2_clicked()
{
    switch(num_15)
    {
    case 1:
    if(farip_flg)
    {
        memset(farip,0,sizeof(farip));
        farip_flg=FALSE;
    }
        farip[farip_len++]='2';
        break;

    case 2:
    if(port_flg)
    {
        memset(art,0,sizeof(art));
        port_flg=FALSE;
    }
          art[art_len++]='2';
           break;

    case 3:
    if(localip_flg)
    {
        memset(localip,0,sizeof(localip));
        localip_flg=FALSE;
    }
              localip[localip_len++]='2';
               break;

    case 4:
    if(mask_flg)
    {
        memset(ma,0,sizeof(ma));
        mask_flg=FALSE;
    }
              ma[ma_len++]='2';
               break;

    case 5:
    if(guan_flg)
    {
        memset(guan,0,sizeof(guan));
        guan_flg=FALSE;
    }
              guan[guan_len++]='2';
               break;

    case 6:
    if(mac_flg)
    {
        memset(mac,0,sizeof(mac));
        mac_flg=FALSE;
    }
              mac[mac_len++]='2';
               break;
        //default:

                //

    }
}

void p15_setpara_sub2_dialog::on_pbtn_num3_clicked()
{
     switch(num_15)
    {
     case 1:
     if(farip_flg)
     {
         memset(farip,0,sizeof(farip));
         farip_flg=FALSE;
     }
         farip[farip_len++]='3';
         break;

     case 2:
     if(port_flg)
     {
         memset(art,0,sizeof(art));
         port_flg=FALSE;
     }
           art[art_len++]='3';
            break;

     case 3:
     if(localip_flg)
     {
         memset(localip,0,sizeof(localip));
         localip_flg=FALSE;
     }
               localip[localip_len++]='3';
                break;

     case 4:
     if(mask_flg)
     {
         memset(ma,0,sizeof(ma));
         mask_flg=FALSE;
     }
               ma[ma_len++]='3';
                break;

     case 5:
     if(guan_flg)
     {
         memset(guan,0,sizeof(guan));
         guan_flg=FALSE;
     }
               guan[guan_len++]='3';
                break;
     case 6:
     if(mac_flg)
     {
         memset(mac,0,sizeof(mac));
         mac_flg=FALSE;
     }
               mac[mac_len++]='3';
                break;
       // default:

                //

    }
}

void p15_setpara_sub2_dialog::on_pbtn_num4_clicked()
{
    switch(num_15)
    {
    case 1:
    if(farip_flg)
    {
        memset(farip,0,sizeof(farip));
        farip_flg=FALSE;
    }
        farip[farip_len++]='4';
        break;

    case 2:
    if(port_flg)
    {
        memset(art,0,sizeof(art));
        port_flg=FALSE;
    }
          art[art_len++]='4';
           break;

    case 3:
    if(localip_flg)
    {
        memset(localip,0,sizeof(localip));
        localip_flg=FALSE;
    }
              localip[localip_len++]='4';
               break;

    case 4:
    if(mask_flg)
    {
        memset(ma,0,sizeof(ma));
        mask_flg=FALSE;
    }
              ma[ma_len++]='4';
               break;

    case 5:
    if(guan_flg)
    {
        memset(guan,0,sizeof(guan));
        guan_flg=FALSE;
    }
              guan[guan_len++]='4';
               break;
    case 6:
    if(mac_flg)
    {
        memset(mac,0,sizeof(mac));
        mac_flg=FALSE;
    }
              mac[mac_len++]='4';
               break;
        //default:

                //

    }
}

void p15_setpara_sub2_dialog::on_pbtn_num5_clicked()
{
     switch(num_15)
    {
     case 1:
     if(farip_flg)
     {
         memset(farip,0,sizeof(farip));
         farip_flg=FALSE;
     }
         farip[farip_len++]='5';
         break;

     case 2:
     if(port_flg)
     {
         memset(art,0,sizeof(art));
         port_flg=FALSE;
     }
           art[art_len++]='5';
            break;

     case 3:
     if(localip_flg)
     {
         memset(localip,0,sizeof(localip));
         localip_flg=FALSE;
     }
               localip[localip_len++]='5';
                break;

     case 4:
     if(mask_flg)
     {
         memset(ma,0,sizeof(ma));
         mask_flg=FALSE;
     }
               ma[ma_len++]='5';
                break;

     case 5:
     if(guan_flg)
     {
         memset(guan,0,sizeof(guan));
         guan_flg=FALSE;
     }
               guan[guan_len++]='5';
                break;

     case 6:
     if(mac_flg)
     {
         memset(mac,0,sizeof(mac));
         mac_flg=FALSE;
     }
               mac[mac_len++]='5';
                break;
        //default:

                //

    }
}

void p15_setpara_sub2_dialog::on_pbtn_num6_clicked()
{
    switch(num_15)
    {
    case 1:
    if(farip_flg)
    {
        memset(farip,0,sizeof(farip));
        farip_flg=FALSE;
    }
        farip[farip_len++]='6';
        break;

    case 2:
    if(port_flg)
    {
        memset(art,0,sizeof(art));
        port_flg=FALSE;
    }
          art[art_len++]='6';
           break;

    case 3:
    if(localip_flg)
    {
        memset(localip,0,sizeof(localip));
        localip_flg=FALSE;
    }
              localip[localip_len++]='6';
               break;

    case 4:
    if(mask_flg)
    {
        memset(ma,0,sizeof(ma));
        mask_flg=FALSE;
    }
              ma[ma_len++]='6';
               break;

    case 5:
    if(guan_flg)
    {
        memset(guan,0,sizeof(guan));
        guan_flg=FALSE;
    }
              guan[guan_len++]='6';
               break;

    case 6:
    if(mac_flg)
    {
        memset(mac,0,sizeof(mac));
        mac_flg=FALSE;
    }
              mac[mac_len++]='6';
               break;
        //default:

                //

    }
}

void p15_setpara_sub2_dialog::on_pbtn_num7_clicked()
{

    switch(num_15)
    {
    case 1:
    if(farip_flg)
    {
        memset(farip,0,sizeof(farip));
        farip_flg=FALSE;
    }
        farip[farip_len++]='7';
        break;

    case 2:
    if(port_flg)
    {
        memset(art,0,sizeof(art));
        port_flg=FALSE;
    }
          art[art_len++]='7';
           break;

    case 3:
    if(localip_flg)
    {
        memset(localip,0,sizeof(localip));
        localip_flg=FALSE;
    }
              localip[localip_len++]='7';
               break;

    case 4:
    if(mask_flg)
    {
        memset(ma,0,sizeof(ma));
        mask_flg=FALSE;
    }
              ma[ma_len++]='7';
               break;

    case 5:
    if(guan_flg)
    {
        memset(guan,0,sizeof(guan));
        guan_flg=FALSE;
    }
              guan[guan_len++]='7';
               break;
    case 6:
    if(mac_flg)
    {
        memset(mac,0,sizeof(mac));
        mac_flg=FALSE;
    }
              mac[mac_len++]='7';
               break;

       // default:

                //

    }
}

void p15_setpara_sub2_dialog::on_pbtn_num8_clicked()
{
    switch(num_15)
    {
    case 1:
    if(farip_flg)
    {
        memset(farip,0,sizeof(farip));
        farip_flg=FALSE;
    }
        farip[farip_len++]='8';
        break;

    case 2:
    if(port_flg)
    {
        memset(art,0,sizeof(art));
        port_flg=FALSE;
    }
          art[art_len++]='8';
           break;

    case 3:
    if(localip_flg)
    {
        memset(localip,0,sizeof(localip));
        localip_flg=FALSE;
    }
              localip[localip_len++]='8';
               break;

    case 4:
    if(mask_flg)
    {
        memset(ma,0,sizeof(ma));
        mask_flg=FALSE;
    }
              ma[ma_len++]='8';
               break;

    case 5:
    if(guan_flg)
    {
        memset(guan,0,sizeof(guan));
        guan_flg=FALSE;
    }
              guan[guan_len++]='8';
               break;

    case 6:
    if(mac_flg)
    {
        memset(mac,0,sizeof(mac));
        mac_flg=FALSE;
    }
              mac[mac_len++]='8';
               break;
       // default:

                //

    }
}

void p15_setpara_sub2_dialog::on_pbtn_num9_clicked()
{
    switch(num_15)
    {
    case 1:
    if(farip_flg)
    {
        memset(farip,0,sizeof(farip));
        farip_flg=FALSE;
    }
        farip[farip_len++]='9';
        break;

    case 2:
    if(port_flg)
    {
        memset(art,0,sizeof(art));
        port_flg=FALSE;
    }
          art[art_len++]='9';
           break;

    case 3:
    if(localip_flg)
    {
        memset(localip,0,sizeof(localip));
        localip_flg=FALSE;
    }
              localip[localip_len++]='9';
               break;

    case 4:
    if(mask_flg)
    {
        memset(ma,0,sizeof(ma));
        mask_flg=FALSE;
    }
              ma[ma_len++]='9';
               break;

    case 5:
    if(guan_flg)
    {
        memset(guan,0,sizeof(guan));
        guan_flg=FALSE;
    }
              guan[guan_len++]='9';
               break;
    case 6:
    if(mac_flg)
    {
        memset(mac,0,sizeof(mac));
        mac_flg=FALSE;
    }
              mac[mac_len++]='9';
               break;
       // default:

                //

    }
}

void p15_setpara_sub2_dialog::on_pbtn_dot_clicked()
{
   switch(num_15)
    {
   case 1:
   if(farip_flg)
   {
       memset(farip,0,sizeof(farip));
       farip_flg=FALSE;
   }
       farip[farip_len++]='.';
       break;

   case 2:
   if(port_flg)
   {
       memset(art,0,sizeof(art));
       port_flg=FALSE;
   }
         art[art_len++]='.';
          break;

   case 3:
   if(localip_flg)
   {
       memset(localip,0,sizeof(localip));
       localip_flg=FALSE;
   }
             localip[localip_len++]='.';
              break;

   case 4:
   if(mask_flg)
   {
       memset(ma,0,sizeof(ma));
       mask_flg=FALSE;
   }
             ma[ma_len++]='.';
              break;

   case 5:
   if(guan_flg)
   {
       memset(guan,0,sizeof(guan));
       guan_flg=FALSE;
   }
             guan[guan_len++]='.';
              break;
   case 6:
   if(mac_flg)
   {
       memset(mac,0,sizeof(mac));
       mac_flg=FALSE;
   }
             mac[mac_len++]='.';
              break;

       // default:

                //

    }
}

void p15_setpara_sub2_dialog::on_pbtn_back_clicked()
{
        switch(num_15)
        {
        case 1:

            if(farip_len>0)
            {
                farip_len--;
                farip[farip_len]=0;
            }
            else
            {
                farip_len=0;
            }
        break;

        case 2:
        if(art_len>0)
        {
            art_len--;
            art[art_len]=0;
        }
        else
        {
            art_len=0;
        }
        break;

        case 3:
        if(localip_len>0)
        {
            localip_len--;
            localip[localip_len]=0;
        }
        else
        {
            localip_len=0;
        }
        break;

        case 4:
        if(ma_len>0)
        {
            ma_len--;
            ma[ma_len]=0;
        }
        else
        {
            ma_len=0;
        }
        break;

        case 5:
        if(guan_len>0)
        {
            guan_len--;
            guan[guan_len]=0;
        }
        else
        {
            guan_len=0;
        }
        break;

        case 6:
        if(mac_len>0)
        {
            mac_len--;
            mac[mac_len]=0;
        }
        else
        {
            mac_len=0;
        }
        break;

        default:
        break;
        //

    }

}

void p15_setpara_sub2_dialog::on_pbtn_up_clicked()
{

     DebugMsg(hmilev,5,"on_pbtn_up_clicked\n");

    hmi_button_dn_num=PAGEUP_BUTTON ;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));


}

void p15_setpara_sub2_dialog::on_pbtn_down_clicked()
{

     DebugMsg(hmilev,5,"on_pbtn_down_clicked\n");

     Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
     Inibuf_init(Key_name,BUFFERLEN_32,"serverip");
     if(farip_len>0)
     {
         write_profile_string(Section_name,Key_name,farip,config_path);
     }
     else
     {
          //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
     }

     Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
     Inibuf_init(Key_name,BUFFERLEN_32,"serverport");
     if(art_len>0)
     {
         write_profile_string(Section_name,Key_name,art,config_path);
     }
     else
     {
          //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
     }

     static char buf_sys[64]={};

     Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
     Inibuf_init(Key_name,BUFFERLEN_32,"ipaddr");
     if(localip_len>0)
     {
         write_profile_string(Section_name,Key_name,localip,config_path);
         sprintf(buf_sys,"ifconfig eth0 %s",localip);
         system(buf_sys);
     }
     else
     {
          //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
     }

     Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
     Inibuf_init(Key_name,BUFFERLEN_32,"mask");
     if(ma_len>0)
     {
         write_profile_string(Section_name,Key_name,ma,config_path);
         sprintf(buf_sys,"ifconfig eth0 netmask %s",ma);
         system(buf_sys);
     }
     else
     {
          //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
     }

     Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
     Inibuf_init(Key_name,BUFFERLEN_32,"getway");
     if(guan_len>0)
     {
         write_profile_string(Section_name,Key_name,guan,config_path);
         sprintf(buf_sys,"route add default gw %s",guan);
         system(buf_sys);
     }
     else
     {
         // ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
     }

     Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
     Inibuf_init(Key_name,BUFFERLEN_32,"sysmac");
     if(mac_len>0)
     {
         write_profile_string(Section_name,Key_name,mac,config_path);
        // sprintf(buf_sys,"ifconfig eth0 netmask %s",mac);
        // system(buf_sys);
     }
     else
     {
         // ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
     }

    hmi_button_dn_num=PAGEDOWN_BUTTON ;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));


}

void p15_setpara_sub2_dialog::on_pbtn_go_clicked()
{

    DebugMsg(hmilev,5,"on_pbtn_cancel_clicked\n");

    //btn_passwd_pos=0;
    //memset(btn_passwd,0,sizeof(btn_passwd));

    hmi_button_dn_num=CANCEL_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));


}

void p15_setpara_sub2_dialog::on_pbtn_ok_clicked()
{

    DebugMsg(hmilev,5,"on_pbtn_enter_clicked\n");

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"serverip");
    if(farip_len>0)
    {
        write_profile_string(Section_name,Key_name,farip,config_path);
    }
    else
    {
         ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"serverport");
    if(art_len>0)
    {
        write_profile_string(Section_name,Key_name,art,config_path);
    }
    else
    {
         ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    static char buf_sys[64]={};

    Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
    Inibuf_init(Key_name,BUFFERLEN_32,"ipaddr");
    if(localip_len>0)
    {
        write_profile_string(Section_name,Key_name,localip,config_path);
        sprintf(buf_sys,"ifconfig eth0 %s",localip);
        system(buf_sys);
    }
    else
    {
         ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
    Inibuf_init(Key_name,BUFFERLEN_32,"mask");
    if(ma_len>0)
    {
        write_profile_string(Section_name,Key_name,ma,config_path);
        sprintf(buf_sys,"ifconfig eth0 netmask %s",ma);
        system(buf_sys);
    }
    else
    {
         ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
    Inibuf_init(Key_name,BUFFERLEN_32,"getway");
    if(guan_len>0)
    {
        write_profile_string(Section_name,Key_name,guan,config_path);
        sprintf(buf_sys,"route add default gw %s",guan);
        system(buf_sys);
    }
    else
    {
         ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
    Inibuf_init(Key_name,BUFFERLEN_32,"sysmac");
    if(mac_len>0)
    {
        write_profile_string(Section_name,Key_name,mac,config_path);
/*
        system("ifconfig eth0 down");
        memset(buf_sys,0,100);
        snprintf(buf_sys,100,"ifconfig eth0 hw  ether %s",mac);
        system(buf_sys);
        system("ifconfig eth0 up");
  */
  }
    else
    {
         ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }
    hmi_button_dn_num=OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));


    //API_Write_DB_Nbyte(PL_HMI_CARD_PASSWD,(INT8 *)(&btn_passwd),sizeof(btn_passwd));
}
