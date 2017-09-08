#include "p24_setpara_sub6_dialog.h"
#include "ui_p24_setpara_sub6_dialog.h"
#include "globalhmi.h"

p24_setpara_sub6_dialog::p24_setpara_sub6_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p24_setpara_sub6_dialog)
{
    ui->setupUi(this);
}

p24_setpara_sub6_dialog::~p24_setpara_sub6_dialog()
{
    delete ui;
}

void p24_setpara_sub6_dialog::changeEvent(QEvent *e)
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


void p24_setpara_sub6_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
    btn_press();
    ui->label_code->setText(code);
   // ui->label_phone->setText(phonenum);
    //ui->label_phone_2->setText(phonenum_2);
}

void ftotime(float num,int*a,int*b)
{
    *a = (int)num;
    float temp = (num-*a)*100;
    *b =(int)temp;
}
QLineEdit *buf_line[16] = {0};
void p24_setpara_sub6_dialog::init_page_val()
{
    buf_line[0] = ui->lineEdit_t1_1;
    buf_line[1] = ui->lineEdit_p1_1;
    buf_line[2] = ui->lineEdit_f1_1;
    buf_line[3] = ui->lineEdit_g1_1;
    buf_line[4] = ui->lineEdit_t1_2;
    buf_line[5] = ui->lineEdit_p1_2;
    buf_line[6] = ui->lineEdit_f1_2;
    buf_line[7] = ui->lineEdit_g1_2;
    buf_line[8] = ui->lineEdit_t2_1;
    buf_line[9] = ui->lineEdit_p2_1;
    buf_line[10] = ui->lineEdit_f2_1;
    buf_line[11] = ui->lineEdit_g2_1;
    buf_line[12] = ui->lineEdit_t2_2;
    buf_line[13] = ui->lineEdit_p2_2;
    buf_line[14] = ui->lineEdit_f2_2;
    buf_line[15] = ui->lineEdit_g2_2;

    ui->frame_keyboard->move(110,470);
    int temp_val = 0;
    for(temp_val=0;temp_val<16;temp_val++)
    {
         buf_line[temp_val]->clearFocus();
         buf_line[temp_val]->installEventFilter(this);
    }

        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));

        t1_len=0;
        p1_len=0;
        f1_len=0;
        g1_len=0;
        t2_len=0;
        p2_len=0;
        f2_len=0;
        g2_len=0;

        t1_len_1=0;
        p1_len_1=0;
        f1_len_1=0;
        g1_len_1=0;
        t2_len_1=0;
        p2_len_1=0;
        f2_len_1=0;
        g2_len_1=0;

        t1_len_2=0;
        p1_len_2=0;
        f1_len_2=0;
        g1_len_2=0;
        t2_len_2=0;
        p2_len_2=0;
        f2_len_2=0;
        g2_len_2=0;

        ft1=0;
        fp1=0;
        ff1=0;
        fg1=0;
        ft2=0;
        fp2=0;
        ff2=0;
        fg2=0;

        ft1_1=0;
        fp1_1=0;
        ff1_1=0;
        fg1_1=0;
        ft2_1=0;
        fp2_1=0;
        ff2_1=0;
        fg2_1=0;

        ft1_2=0;
        fp1_2=0;
        ff1_2=0;
        fg1_2=0;
        ft2_2=0;
        fp2_2=0;
        ff2_2=0;
        fg2_2=0;

        memset(t1,0,sizeof(t1));
        memset(p1,0,sizeof(p1));
        memset(f1,0,sizeof(f1));
        memset(g1,0,sizeof(g1));
        memset(t2,0,sizeof(t2));
        memset(p2,0,sizeof(p2));
        memset(f2,0,sizeof(f2));
        memset(g2,0,sizeof(g2));

        memset(t1_1,0,sizeof(t1_1));
        memset(p1_1,0,sizeof(p1_1));
        memset(f1_1,0,sizeof(f1_1));
        memset(g1_1,0,sizeof(g1_1));
        memset(t2_1,0,sizeof(t2_1));
        memset(p2_1,0,sizeof(p2_1));
        memset(f2_1,0,sizeof(f2_1));
        memset(g2_1,0,sizeof(g2_1));

        memset(t1_2,0,sizeof(t1_2));
        memset(p1_2,0,sizeof(p1_2));
        memset(f1_2,0,sizeof(f1_2));
        memset(g1_2,0,sizeof(g1_2));
        memset(t2_2,0,sizeof(t2_2));
        memset(p2_2,0,sizeof(p2_2));
        memset(f2_2,0,sizeof(f2_2));
        memset(g2_2,0,sizeof(g2_2));

        float max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"top1_elecprice");
        ft1= read_profile_float(Section_name, Key_name,max_temp,config_path);
        sprintf(t1,"%0.2f",ft1);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"top2_elecprice");
        ft2= read_profile_float(Section_name, Key_name,max_temp,config_path);
        sprintf(t2,"%0.2f",ft2);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"peak1_elecprice");
        fp1= read_profile_float(Section_name, Key_name,max_temp,config_path);
        sprintf(p1,"%0.2f",fp1);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"peak2_elecprice");
        fp2= read_profile_float(Section_name, Key_name,max_temp,config_path);
        sprintf(p2,"%0.2f",fp2);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"flat1_elecprice");
        ff1= read_profile_float(Section_name, Key_name,max_temp,config_path);
        sprintf(f1,"%0.2f",ff1);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"flat2_elecprice");
        ff2= read_profile_float(Section_name, Key_name,max_temp,config_path);
        sprintf(f2,"%0.2f",ff2);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"valley1_elecprice");
        fg1= read_profile_float(Section_name, Key_name,max_temp,config_path);
        sprintf(g1,"%0.2f",fg1);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"valley2_elecprice");
        fg2= read_profile_float(Section_name, Key_name,max_temp,config_path);
        sprintf(g2,"%0.2f",fg2);

        int temp_hour = 0;
        int temp_min = 0;
         max_temp=0;
         temp_hour = 0;
         temp_min = 0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"top1_starttm");
        ft1_1= read_profile_float(Section_name, Key_name,max_temp,config_path);
        ftotime(ft1_1,&temp_hour,&temp_min);
        sprintf(t1_1,"%d:%d",temp_hour,temp_min);

        max_temp=0;
        temp_hour = 0;
        temp_min = 0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"top1_stoptm");
        ft1_2= read_profile_float(Section_name, Key_name,max_temp,config_path);
        ftotime(ft1_2,&temp_hour,&temp_min);
        sprintf(t1_2,"%d:%d",temp_hour,temp_min);

        max_temp=0;
        temp_hour = 0;
        temp_min = 0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"top2_starttm");
        ft2_1= read_profile_float(Section_name, Key_name,max_temp,config_path);
        ftotime(ft2_1,&temp_hour,&temp_min);
        sprintf(t2_1,"%d:%d",temp_hour,temp_min);

        max_temp=0;
        temp_hour = 0;
        temp_min = 0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"top2_stoptm");
        ft2_2= read_profile_float(Section_name, Key_name,max_temp,config_path);
        ftotime(ft2_2,&temp_hour,&temp_min);
        sprintf(t2_2,"%d:%d",temp_hour,temp_min);

        max_temp=0;
        temp_hour = 0;
        temp_min = 0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"peak1_starttm");
        fp1_1= read_profile_float(Section_name, Key_name,max_temp,config_path);
        ftotime(fp1_1,&temp_hour,&temp_min);
        sprintf(p1_1,"%d:%d",temp_hour,temp_min);

        max_temp=0;
        temp_hour = 0;
        temp_min = 0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"peak1_stoptm");
        fp1_2= read_profile_float(Section_name, Key_name,max_temp,config_path);
        ftotime(fp1_2,&temp_hour,&temp_min);
        sprintf(p1_2,"%d:%d",temp_hour,temp_min);

        max_temp=0;
        temp_hour = 0;
        temp_min = 0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"peak2_starttm");
        fp2_1= read_profile_float(Section_name, Key_name,max_temp,config_path);
        ftotime(fp2_1,&temp_hour,&temp_min);
        sprintf(p2_1,"%d:%d",temp_hour,temp_min);

        max_temp=0;
        temp_hour = 0;
        temp_min = 0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"peak2_stoptm");
        fp2_2= read_profile_float(Section_name, Key_name,max_temp,config_path);
        ftotime(fp2_2,&temp_hour,&temp_min);
        sprintf(p2_2,"%d:%d",temp_hour,temp_min);

        max_temp=0;
        temp_hour = 0;
        temp_min = 0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"flat1_starttm");
        ff1_1= read_profile_float(Section_name, Key_name,max_temp,config_path);
        ftotime(ff1_1,&temp_hour,&temp_min);
        sprintf(f1_1,"%d:%d",temp_hour,temp_min);

        max_temp=0;
        temp_hour = 0;
        temp_min = 0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"flat1_stoptm");
        ff1_2= read_profile_float(Section_name, Key_name,max_temp,config_path);
        ftotime(ff1_2,&temp_hour,&temp_min);
        sprintf(f1_2,"%d:%d",temp_hour,temp_min);

        max_temp=0;
        temp_hour = 0;
        temp_min = 0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"flat2_starttm");
        ff2_1= read_profile_float(Section_name, Key_name,max_temp,config_path);
        ftotime(ff2_1,&temp_hour,&temp_min);
        sprintf(f2_1,"%d:%d",temp_hour,temp_min);

        max_temp=0;
        temp_hour = 0;
        temp_min = 0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"flat2_stoptm");
        ff2_2= read_profile_float(Section_name, Key_name,max_temp,config_path);
        ftotime(ff2_2,&temp_hour,&temp_min);
        sprintf(f2_2,"%d:%d",temp_hour,temp_min);

        max_temp=0;
        temp_hour = 0;
        temp_min = 0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"valley1_starttm");
        fg1_1= read_profile_float(Section_name, Key_name,max_temp,config_path);
        ftotime(fg1_1,&temp_hour,&temp_min);
        sprintf(g1_1,"%d:%d",temp_hour,temp_min);

        max_temp=0;
        temp_hour = 0;
        temp_min = 0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"valley1_stoptm");
        fg1_2= read_profile_float(Section_name, Key_name,max_temp,config_path);
        ftotime(fg1_2,&temp_hour,&temp_min);
        sprintf(g1_2,"%d:%d",temp_hour,temp_min);

        max_temp=0;
        temp_hour = 0;
        temp_min = 0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"valley2_starttm");
        fg2_1= read_profile_float(Section_name, Key_name,max_temp,config_path);
        ftotime(fg2_1,&temp_hour,&temp_min);
        sprintf(g2_1,"%d:%d",temp_hour,temp_min);

        max_temp=0;
        temp_hour = 0;
        temp_min = 0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"valley2_stoptm");
        fg2_2= read_profile_float(Section_name, Key_name,max_temp,config_path);
        ftotime(fg2_2,&temp_hour,&temp_min);
        sprintf(g2_2,"%d:%d",temp_hour,temp_min);

}

void p24_setpara_sub6_dialog::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
}

void p24_setpara_sub6_dialog::btn_press()
{

  ui->pbtn_num0->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/0.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/0-d.png);}");

  ui->pbtn_num1->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/1.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/1-d.png);}");

  ui->pbtn_num2->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/2.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/2-d.png);}");

  ui->pbtn_num3->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/3.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/3-d.png);}");

  ui->pbtn_num4->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/4.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/4-d.png);}");

  ui->pbtn_num5->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/5.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/5-d.png);}");

  ui->pbtn_num6->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/6.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/6-d.png);}");

  ui->pbtn_num7->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/7.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/7-d.png);}");

  ui->pbtn_num8->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/8.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/8-d.png);}");

  ui->pbtn_num9->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/9.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/9-d.png);}");

  ui->pbtn_dot->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/dot.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/dot-d.png);}");

  ui->pbtn_back->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/c.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/c-d.png);}");

  ui->pbtn_enter->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/enter.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/enter-d.png);}");

  ui->pbtn_cancel->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/cancel.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/cancel-d.png);}");

  ui->pbtn_down->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/dn.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/dn-d.png);}");

  ui->pbtn_up->setStyleSheet("QPushButton{border-image: url(:/key/qrc/keyboard-b/up.png);}\
                                QPushButton:pressed{border-image: url(:/key/qrc/keyboard-b/up-d.png);}");

}

void p24_setpara_sub6_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p24_setpara_sub6_dialog::update_page_info()
{
    ui->label_t1->setText(t1);
    ui->label_p1->setText(p1);
    ui->label_f1->setText(f1);
    ui->label_g1->setText(g1);
    ui->label_t2->setText(t2);
    ui->label_p2->setText(p2);
    ui->label_f2->setText(f2);
    ui->label_g2->setText(g2);

    ui->lineEdit_t1_1->setText(t1_1);
    ui->lineEdit_t1_2->setText(t1_2);
    ui->lineEdit_t2_1->setText(t2_1);
    ui->lineEdit_t2_2->setText(t2_2);

    ui->lineEdit_p1_1->setText(p1_1);
    ui->lineEdit_p1_2->setText(p1_2);
    ui->lineEdit_p2_1->setText(p2_1);
    ui->lineEdit_p2_2->setText(p2_2);

    ui->lineEdit_f1_1->setText(f1_1);
    ui->lineEdit_f1_2->setText(f1_2);
    ui->lineEdit_f2_1->setText(f2_1);
    ui->lineEdit_f2_2->setText(f2_2);

    ui->lineEdit_g1_1->setText(g1_1);
    ui->lineEdit_g1_2->setText(g1_2);
    ui->lineEdit_g2_1->setText(g2_1);
    ui->lineEdit_g2_2->setText(g2_2);
}

void p24_setpara_sub6_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

    if(hmi_page_index != PAGEINDEX_SETPAGE_SIX)
    {
        exit_page_dlg();
    }
    else
    {

    }
}

void p24_setpara_sub6_dialog::call_p17_dlg()
{

    timer->stop();
    emit signal_timer_p24dlg();
    delete p24_dlg;
    p24_dlg = NULL;
}

void p24_setpara_sub6_dialog::call_p18_dlg()
{
#if 0
    timer->stop();
    if(p18_dlg){
            delete p18_dlg;
            p18_dlg = NULL;

    }
    p18_dlg = new  p18_setpara_sub5_dialog;
    p18_dlg->setWindowFlags(Qt::FramelessWindowHint);

    connect(this,SIGNAL(signal_enable_p18dlg_timer()),p18_dlg,SLOT(init_page_dlg()));
    connect(p18_dlg,SIGNAL(signal_exit_p18dlg()),this,SLOT(exit_page_dlg()));
    connect(p18_dlg,SIGNAL(signal_timer_p18dlg()),this,SLOT(start_timer()));
    emit signal_enable_p18dlg_timer();
    p18_dlg->exec();
#endif
}

int num_24=0;

void p24_setpara_sub6_dialog::on_pbtn_1_clicked()
{
  num_24=1;
   ui->frame_keyboard->move(110,190);
}
void p24_setpara_sub6_dialog::on_pbtn_2_clicked()
{
  num_24=2;
   ui->frame_keyboard->move(110,190);
}
void p24_setpara_sub6_dialog::on_pbtn_3_clicked()
{
  num_24=3;
   ui->frame_keyboard->move(110,40);
}
void p24_setpara_sub6_dialog::on_pbtn_4_clicked()
{
  num_24=4;
   ui->frame_keyboard->move(110,40);
}
void p24_setpara_sub6_dialog::on_pbtn_5_clicked()
{
  num_24=5;
     ui->frame_keyboard->move(110,190);
}
void p24_setpara_sub6_dialog::on_pbtn_6_clicked()
{
  num_24=6;
     ui->frame_keyboard->move(110,190);
}
void p24_setpara_sub6_dialog::on_pbtn_7_clicked()
{
  num_24=7;
   ui->frame_keyboard->move(110,40);
}
void p24_setpara_sub6_dialog::on_pbtn_8_clicked()
{
  num_24=8;
   ui->frame_keyboard->move(110,40);
}

void p24_setpara_sub6_dialog::on_pbtn_num0_clicked()
{
     switch(num_24)
    {
        case 1:
            t1[t1_len++]='0';
             break;
        case 2:
              p1[p1_len++]='0';
               break;
        case 3:
              f1[f1_len++]='0';
               break;
        case 4:
             g1[g1_len++]='0';
               break;
         case 5:
            t2[t2_len++]='0';
            break;
        case 6:
              p2[p2_len++]='0';
            break;
        case 7:
            f2[f2_len++]='0';
            break;
        case 8:
            g2[g2_len++]='0';
            break;

     case 10:
         t1_1[t1_len_1++]='0';
          break;
     case 11:
         t1_2[t1_len_2++]='0';
          break;
     case 12:
         t2_1[t2_len_1++]='0';
          break;
     case 13:
         t2_2[t2_len_2++]='0';
          break;

     case 14:
         p1_1[p1_len_1++]='0';
          break;
     case 15:
         p1_2[p1_len_2++]='0';
          break;
     case 16:
         p2_1[p2_len_1++]='0';
          break;
     case 17:
         p2_2[p2_len_2++]='0';
          break;

     case 18:
         f1_1[f1_len_1++]='0';
          break;
     case 19:
         f1_2[f1_len_2++]='0';
          break;
     case 20:
         f2_1[f2_len_1++]='0';
          break;
     case 21:
         f2_2[f2_len_2++]='0';
          break;

     case 22:
         g1_1[g1_len_1++]='0';
          break;
     case 23:
         g1_2[g1_len_2++]='0';
          break;
     case 24:
         g2_1[g2_len_1++]='0';
          break;
     case 25:
         g2_2[g2_len_2++]='0';
          break;
         // default:

                //
    }
}

void p24_setpara_sub6_dialog::on_pbtn_num1_clicked()
{
    switch(num_24)
   {
    case 1:
        t1[t1_len++]='1';
         break;
    case 2:
          p1[p1_len++]='1';
           break;
    case 3:
          f1[f1_len++]='1';
           break;
    case 4:
         g1[g1_len++]='1';
           break;
     case 5:
        t2[t2_len++]='1';
        break;
    case 6:
          p2[p2_len++]='1';
        break;
    case 7:
        f2[f2_len++]='1';
        break;
    case 8:
        g2[g2_len++]='1';
        break;

    case 10:
        t1_1[t1_len_1++]='1';
         break;
    case 11:
        t1_2[t1_len_2++]='1';
         break;
    case 12:
        t2_1[t2_len_1++]='1';
         break;
    case 13:
        t2_2[t2_len_2++]='1';
         break;

    case 14:
        p1_1[p1_len_1++]='1';
         break;
    case 15:
        p1_2[p1_len_2++]='1';
         break;
    case 16:
        p2_1[p2_len_1++]='1';
         break;
    case 17:
        p2_2[p2_len_2++]='1';
         break;

    case 18:
        f1_1[f1_len_1++]='1';
         break;
    case 19:
        f1_2[f1_len_2++]='1';
         break;
    case 20:
        f2_1[f2_len_1++]='1';
         break;
    case 21:
        f2_2[f2_len_2++]='1';
         break;

    case 22:
        g1_1[g1_len_1++]='1';
         break;
    case 23:
        g1_2[g1_len_2++]='1';
         break;
    case 24:
        g2_1[g2_len_1++]='1';
         break;
    case 25:
        g2_2[g2_len_2++]='1';
         break;
        //default:

                //

    }
}

void p24_setpara_sub6_dialog::on_pbtn_num2_clicked()
{
    switch(num_24)
   {
    case 1:
        t1[t1_len++]='2';
         break;
    case 2:
          p1[p1_len++]='2';
           break;
    case 3:
          f1[f1_len++]='2';
           break;
    case 4:
         g1[g1_len++]='2';
           break;
     case 5:
        t2[t2_len++]='2';
        break;
    case 6:
          p2[p2_len++]='2';
        break;
    case 7:
        f2[f2_len++]='2';
        break;
    case 8:
        g2[g2_len++]='2';
        break;

    case 10:
        t1_1[t1_len_1++]='2';
         break;
    case 11:
        t1_2[t1_len_2++]='2';
         break;
    case 12:
        t2_1[t2_len_1++]='2';
         break;
    case 13:
        t2_2[t2_len_2++]='2';
         break;

    case 14:
        p1_1[p1_len_1++]='2';
         break;
    case 15:
        p1_2[p1_len_2++]='2';
         break;
    case 16:
        p2_1[p2_len_1++]='2';
         break;
    case 17:
        p2_2[p2_len_2++]='2';
         break;

    case 18:
        f1_1[f1_len_1++]='2';
         break;
    case 19:
        f1_2[f1_len_2++]='2';
         break;
    case 20:
        f2_1[f2_len_1++]='2';
         break;
    case 21:
        f2_2[f2_len_2++]='2';
         break;

    case 22:
        g1_1[g1_len_1++]='2';
         break;
    case 23:
        g1_2[g1_len_2++]='2';
         break;
    case 24:
        g2_1[g2_len_1++]='2';
         break;
    case 25:
        g2_2[g2_len_2++]='2';
         break;
        //default:

                //

    }
}

void p24_setpara_sub6_dialog::on_pbtn_num3_clicked()
{
    switch(num_24)
   {
    case 1:
        t1[t1_len++]='3';
         break;
    case 2:
          p1[p1_len++]='3';
           break;
    case 3:
          f1[f1_len++]='3';
           break;
    case 4:
         g1[g1_len++]='3';
           break;
     case 5:
        t2[t2_len++]='3';
        break;
    case 6:
          p2[p2_len++]='3';
        break;
    case 7:
        f2[f2_len++]='3';
        break;
    case 8:
        g2[g2_len++]='3';
        break;

    case 10:
        t1_1[t1_len_1++]='3';
         break;
    case 11:
        t1_2[t1_len_2++]='3';
         break;
    case 12:
        t2_1[t2_len_1++]='3';
         break;
    case 13:
        t2_2[t2_len_2++]='3';
         break;

    case 14:
        p1_1[p1_len_1++]='3';
         break;
    case 15:
        p1_2[p1_len_2++]='3';
         break;
    case 16:
        p2_1[p2_len_1++]='3';
         break;
    case 17:
        p2_2[p2_len_2++]='3';
         break;

    case 18:
        f1_1[f1_len_1++]='3';
         break;
    case 19:
        f1_2[f1_len_2++]='3';
         break;
    case 20:
        f2_1[f2_len_1++]='3';
         break;
    case 21:
        f2_2[f2_len_2++]='3';
         break;

    case 22:
        g1_1[g1_len_1++]='3';
         break;
    case 23:
        g1_2[g1_len_2++]='3';
         break;
    case 24:
        g2_1[g2_len_1++]='3';
         break;
    case 25:
        g2_2[g2_len_2++]='3';
         break;
       // default:

                //

    }
}

void p24_setpara_sub6_dialog::on_pbtn_num4_clicked()
{
    switch(num_24)
   {
    case 1:
        t1[t1_len++]='4';
         break;
    case 2:
          p1[p1_len++]='4';
           break;
    case 3:
          f1[f1_len++]='4';
           break;
    case 4:
         g1[g1_len++]='4';
           break;
     case 5:
        t2[t2_len++]='4';
        break;
    case 6:
          p2[p2_len++]='4';
        break;
    case 7:
        f2[f2_len++]='4';
        break;
    case 8:
        g2[g2_len++]='4';
        break;

    case 10:
        t1_1[t1_len_1++]='4';
         break;
    case 11:
        t1_2[t1_len_2++]='4';
         break;
    case 12:
        t2_1[t2_len_1++]='4';
         break;
    case 13:
        t2_2[t2_len_2++]='4';
         break;

    case 14:
        p1_1[p1_len_1++]='4';
         break;
    case 15:
        p1_2[p1_len_2++]='4';
         break;
    case 16:
        p2_1[p2_len_1++]='4';
         break;
    case 17:
        p2_2[p2_len_2++]='4';
         break;

    case 18:
        f1_1[f1_len_1++]='4';
         break;
    case 19:
        f1_2[f1_len_2++]='4';
         break;
    case 20:
        f2_1[f2_len_1++]='4';
         break;
    case 21:
        f2_2[f2_len_2++]='4';
         break;

    case 22:
        g1_1[g1_len_1++]='4';
         break;
    case 23:
        g1_2[g1_len_2++]='4';
         break;
    case 24:
        g2_1[g2_len_1++]='4';
         break;
    case 25:
        g2_2[g2_len_2++]='4';
         break;
        //default:

                //

    }
}

void p24_setpara_sub6_dialog::on_pbtn_num5_clicked()
{
    switch(num_24)
   {
    case 1:
        t1[t1_len++]='5';
         break;
    case 2:
          p1[p1_len++]='5';
           break;
    case 3:
          f1[f1_len++]='5';
           break;
    case 4:
         g1[g1_len++]='5';
           break;
     case 5:
        t2[t2_len++]='5';
        break;
    case 6:
          p2[p2_len++]='5';
        break;
    case 7:
        f2[f2_len++]='5';
        break;
    case 8:
        g2[g2_len++]='5';
        break;

    case 10:
        t1_1[t1_len_1++]='5';
         break;
    case 11:
        t1_2[t1_len_2++]='5';
         break;
    case 12:
        t2_1[t2_len_1++]='5';
         break;
    case 13:
        t2_2[t2_len_2++]='5';
         break;

    case 14:
        p1_1[p1_len_1++]='5';
         break;
    case 15:
        p1_2[p1_len_2++]='5';
         break;
    case 16:
        p2_1[p2_len_1++]='5';
         break;
    case 17:
        p2_2[p2_len_2++]='5';
         break;

    case 18:
        f1_1[f1_len_1++]='5';
         break;
    case 19:
        f1_2[f1_len_2++]='5';
         break;
    case 20:
        f2_1[f2_len_1++]='5';
         break;
    case 21:
        f2_2[f2_len_2++]='5';
         break;

    case 22:
        g1_1[g1_len_1++]='5';
         break;
    case 23:
        g1_2[g1_len_2++]='5';
         break;
    case 24:
        g2_1[g2_len_1++]='5';
         break;
    case 25:
        g2_2[g2_len_2++]='5';
         break;
        //default:

                //

    }
}

void p24_setpara_sub6_dialog::on_pbtn_num6_clicked()
{
    switch(num_24)
   {
    case 1:
        t1[t1_len++]='6';
         break;
    case 2:
          p1[p1_len++]='6';
           break;
    case 3:
          f1[f1_len++]='6';
           break;
    case 4:
         g1[g1_len++]='6';
           break;
     case 5:
        t2[t2_len++]='6';
        break;
    case 6:
          p2[p2_len++]='6';
        break;
    case 7:
        f2[f2_len++]='6';
        break;
    case 8:
        g2[g2_len++]='6';
        break;

    case 10:
        t1_1[t1_len_1++]='6';
         break;
    case 11:
        t1_2[t1_len_2++]='6';
         break;
    case 12:
        t2_1[t2_len_1++]='6';
         break;
    case 13:
        t2_2[t2_len_2++]='6';
         break;

    case 14:
        p1_1[p1_len_1++]='6';
         break;
    case 15:
        p1_2[p1_len_2++]='6';
         break;
    case 16:
        p2_1[p2_len_1++]='6';
         break;
    case 17:
        p2_2[p2_len_2++]='6';
         break;

    case 18:
        f1_1[f1_len_1++]='6';
         break;
    case 19:
        f1_2[f1_len_2++]='6';
         break;
    case 20:
        f2_1[f2_len_1++]='6';
         break;
    case 21:
        f2_2[f2_len_2++]='6';
         break;

    case 22:
        g1_1[g1_len_1++]='6';
         break;
    case 23:
        g1_2[g1_len_2++]='6';
         break;
    case 24:
        g2_1[g2_len_1++]='6';
         break;
    case 25:
        g2_2[g2_len_2++]='6';
         break;
        //default:

                //

    }
}

void p24_setpara_sub6_dialog::on_pbtn_num7_clicked()
{

    switch(num_24)
   {
    case 1:
        t1[t1_len++]='7';
         break;
    case 2:
          p1[p1_len++]='7';
           break;
    case 3:
          f1[f1_len++]='7';
           break;
    case 4:
         g1[g1_len++]='7';
           break;
     case 5:
        t2[t2_len++]='7';
        break;
    case 6:
          p2[p2_len++]='7';
        break;
    case 7:
        f2[f2_len++]='7';
        break;
    case 8:
        g2[g2_len++]='7';
        break;

    case 10:
        t1_1[t1_len_1++]='7';
         break;
    case 11:
        t1_2[t1_len_2++]='7';
         break;
    case 12:
        t2_1[t2_len_1++]='7';
         break;
    case 13:
        t2_2[t2_len_2++]='7';
         break;

    case 14:
        p1_1[p1_len_1++]='7';
         break;
    case 15:
        p1_2[p1_len_2++]='7';
         break;
    case 16:
        p2_1[p2_len_1++]='7';
         break;
    case 17:
        p2_2[p2_len_2++]='7';
         break;

    case 18:
        f1_1[f1_len_1++]='7';
         break;
    case 19:
        f1_2[f1_len_2++]='7';
         break;
    case 20:
        f2_1[f2_len_1++]='7';
         break;
    case 21:
        f2_2[f2_len_2++]='7';
         break;

    case 22:
        g1_1[g1_len_1++]='7';
         break;
    case 23:
        g1_2[g1_len_2++]='7';
         break;
    case 24:
        g2_1[g2_len_1++]='7';
         break;
    case 25:
        g2_2[g2_len_2++]='7';
         break;
       // default:

                //

    }
}

void p24_setpara_sub6_dialog::on_pbtn_num8_clicked()
{
    switch(num_24)
   {
    case 1:
        t1[t1_len++]='8';
         break;
    case 2:
          p1[p1_len++]='8';
           break;
    case 3:
          f1[f1_len++]='8';
           break;
    case 4:
         g1[g1_len++]='8';
           break;
     case 5:
        t2[t2_len++]='8';
        break;
    case 6:
          p2[p2_len++]='8';
        break;
    case 7:
        f2[f2_len++]='8';
        break;
    case 8:
        g2[g2_len++]='8';
        break;

    case 10:
        t1_1[t1_len_1++]='8';
         break;
    case 11:
        t1_2[t1_len_2++]='8';
         break;
    case 12:
        t2_1[t2_len_1++]='8';
         break;
    case 13:
        t2_2[t2_len_2++]='8';
         break;

    case 14:
        p1_1[p1_len_1++]='8';
         break;
    case 15:
        p1_2[p1_len_2++]='8';
         break;
    case 16:
        p2_1[p2_len_1++]='8';
         break;
    case 17:
        p2_2[p2_len_2++]='8';
         break;

    case 18:
        f1_1[f1_len_1++]='8';
         break;
    case 19:
        f1_2[f1_len_2++]='8';
         break;
    case 20:
        f2_1[f2_len_1++]='8';
         break;
    case 21:
        f2_2[f2_len_2++]='8';
         break;

    case 22:
        g1_1[g1_len_1++]='8';
         break;
    case 23:
        g1_2[g1_len_2++]='8';
         break;
    case 24:
        g2_1[g2_len_1++]='8';
         break;
    case 25:
        g2_2[g2_len_2++]='8';
         break;
       // default:

                //

    }
}

void p24_setpara_sub6_dialog::on_pbtn_num9_clicked()
{
    switch(num_24)
   {
    case 1:
        t1[t1_len++]='9';
         break;
    case 2:
          p1[p1_len++]='9';
           break;
    case 3:
          f1[f1_len++]='9';
           break;
    case 4:
         g1[g1_len++]='9';
           break;
     case 5:
        t2[t2_len++]='9';
        break;
    case 6:
          p2[p2_len++]='9';
        break;
    case 7:
        f2[f2_len++]='9';
        break;
    case 8:
        g2[g2_len++]='9';
        break;

    case 10:
        t1_1[t1_len_1++]='9';
         break;
    case 11:
        t1_2[t1_len_2++]='9';
         break;
    case 12:
        t2_1[t2_len_1++]='9';
         break;
    case 13:
        t2_2[t2_len_2++]='9';
         break;

    case 14:
        p1_1[p1_len_1++]='9';
         break;
    case 15:
        p1_2[p1_len_2++]='9';
         break;
    case 16:
        p2_1[p2_len_1++]='9';
         break;
    case 17:
        p2_2[p2_len_2++]='9';
         break;

    case 18:
        f1_1[f1_len_1++]='9';
         break;
    case 19:
        f1_2[f1_len_2++]='9';
         break;
    case 20:
        f2_1[f2_len_1++]='9';
         break;
    case 21:
        f2_2[f2_len_2++]='9';
         break;

    case 22:
        g1_1[g1_len_1++]='9';
         break;
    case 23:
        g1_2[g1_len_2++]='9';
         break;
    case 24:
        g2_1[g2_len_1++]='9';
         break;
    case 25:
        g2_2[g2_len_2++]='9';
         break;
       // default:

                //

    }
}

void p24_setpara_sub6_dialog::on_pbtn_dot_clicked()
{
    switch(num_24)
   {
    case 1:
        t1[t1_len++]='.';
         break;
    case 2:
          p1[p1_len++]='.';
           break;
    case 3:
          f1[f1_len++]='.';
           break;
    case 4:
         g1[g1_len++]='.';
           break;
     case 5:
        t2[t2_len++]='.';
        break;
    case 6:
          p2[p2_len++]='.';
        break;
    case 7:
        f2[f2_len++]='.';
        break;
    case 8:
        g2[g2_len++]='.';
        break;

    case 10:
        t1_1[t1_len_1++]='.';
         break;
    case 11:
        t1_2[t1_len_2++]='.';
         break;
    case 12:
        t2_1[t2_len_1++]='.';
         break;
    case 13:
        t2_2[t2_len_2++]='.';
         break;

    case 14:
        p1_1[p1_len_1++]='.';
         break;
    case 15:
        p1_2[p1_len_2++]='.';
         break;
    case 16:
        p2_1[p2_len_1++]='.';
         break;
    case 17:
        p2_2[p2_len_2++]='.';
         break;

    case 18:
        f1_1[f1_len_1++]='.';
         break;
    case 19:
        f1_2[f1_len_2++]='.';
         break;
    case 20:
        f2_1[f2_len_1++]='.';
         break;
    case 21:
        f2_2[f2_len_2++]='.';
         break;

    case 22:
        g1_1[g1_len_1++]='.';
         break;
    case 23:
        g1_2[g1_len_2++]='.';
         break;
    case 24:
        g2_1[g2_len_1++]='.';
         break;
    case 25:
        g2_2[g2_len_2++]='.';
         break;
       // default:

                //

    }
}



void p24_setpara_sub6_dialog::on_pbtn_back_clicked()
{
    switch(num_24)
    {
        case 1:
            if(t1_len>0)
            {
                t1_len--;
                t1[t1_len]=0;
            }
            else
            {
                t1_len=0;
            }
            break;

        case 2:
            if(p1_len>0)
            {
                p1_len--;
                p1[p1_len]=0;
            }
            else
            {
                p1_len=0;
            }
            break;

        case 3:
            if(f1_len>0)
            {
                f1_len--;
                f1[f1_len]=0;
            }
            else
            {
                f1_len=0;
            }
            break;

        case 4:
            if(g1_len>0)
            {
                g1_len--;
                g1[g1_len]=0;
            }
            else
            {
                g1_len=0;
            }
            break;

         case 5:
            if(t2_len>0)
            {
                t2_len--;
                t2[t2_len]=0;
            }
            else
            {
                t2_len=0;
            }
            break;

        case 6:
            if(p2_len>0)
            {
                p2_len--;
                p2[p2_len]=0;
            }
            else
            {
                p2_len=0;
            }
            break;

        case 7:
            if(f2_len>0)
            {
                f2_len--;
                f2[f2_len]=0;
            }
            else
            {
                f2_len=0;
            }
            break;

        case 8:
            if(g2_len>0)
            {
                g2_len--;
                g2[g2_len]=0;
            }
            else
            {
                g2_len=0;
            }
            break;

        case 10:
            if(t1_len_1>0)
            {
                t1_len_1--;
                t1_1[t1_len_1]=0;
            }
            else
            {
                t1_len_1=0;
            }
            break;

    case 11:
        if(t1_len_2>0)
        {
            t1_len_2--;
            t1_2[t1_len_2]=0;
        }
        else
        {
            t1_len_2=0;
        }
        break;

    case 12:
        if(t2_len_1>0)
        {
            t2_len_1--;
            t2_1[t2_len_1]=0;
        }
        else
        {
            t2_len_1=0;
        }
        break;

    case 13:
        if(t2_len_2>0)
        {
            t2_len_2--;
            t2_2[t2_len_2]=0;
        }
        else
        {
            t2_len_2=0;
        }
        break;

    case 14:
        if(p1_len_1>0)
        {
            p1_len_1--;
            p1_1[p1_len_1]=0;
        }
        else
        {
            p1_len_1=0;
        }
        break;

case 15:
    if(p1_len_2>0)
    {
        p1_len_2--;
        p1_2[p1_len_2]=0;
    }
    else
    {
        p1_len_2=0;
    }
    break;

case 16:
    if(p2_len_1>0)
    {
        p2_len_1--;
        p2_1[p2_len_1]=0;
    }
    else
    {
        p2_len_1=0;
    }
    break;

case 17:
    if(p2_len_2>0)
    {
        p2_len_2--;
        p2_2[t2_len_2]=0;
    }
    else
    {
        p2_len_2=0;
    }
    break;

    case 18:
        if(f1_len_1>0)
        {
            f1_len_1--;
            f1_1[f1_len_1]=0;
        }
        else
        {
            f1_len_1=0;
        }
        break;

case 19:
    if(f1_len_2>0)
    {
        f1_len_2--;
        f1_2[f1_len_2]=0;
    }
    else
    {
        f1_len_2=0;
    }
    break;

case 20:
    if(f2_len_1>0)
    {
        f2_len_1--;
        f2_1[f2_len_1]=0;
    }
    else
    {
        f2_len_1=0;
    }
    break;

case 21:
    if(f2_len_2>0)
    {
        f2_len_2--;
        f2_2[f2_len_2]=0;
    }
    else
    {
        f2_len_2=0;
    }
    break;

    case 22:
        if(g1_len_1>0)
        {
            g1_len_1--;
            g1_1[g1_len_1]=0;
        }
        else
        {
            g1_len_1=0;
        }
        break;

case 23:
    if(g1_len_2>0)
    {
        g1_len_2--;
        g1_2[g1_len_2]=0;
    }
    else
    {
        g1_len_2=0;
    }
    break;

case 24:
    if(g2_len_1>0)
    {
        g2_len_1--;
        g2_1[g2_len_1]=0;
    }
    else
    {
        g2_len_1=0;
    }
    break;

case 25:
    if(g2_len_2>0)
    {
        g2_len_2--;
        g2_2[g2_len_2]=0;
    }
    else
    {
        g2_len_2=0;
    }
    break;
        default:
        break;
        //

        }

}

bool p24_setpara_sub6_dialog::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->lineEdit_t1_1)
    {
       if(event->type() == QEvent::FocusIn)
       {
            num_24 = 10;
            ui->frame_keyboard->move(110,190);
            return 1;
       }
       else if(event->type() == QEvent::FocusOut)
       {
            return 1;
       }
       else
       {
           return 0;
       }
    }

    if(obj == ui->lineEdit_t1_2)
    {
       if(event->type() == QEvent::FocusIn)
       {
            num_24 = 11;
            ui->frame_keyboard->move(110,190);
            return 1;
       }
    }


    if(obj == ui->lineEdit_t2_1)
    {
       if(event->type() == QEvent::FocusIn)
       {
            num_24 = 12;
            ui->frame_keyboard->move(110,190);
            return 1;
       }
    }


    if(obj == ui->lineEdit_t2_2)
    {
       if(event->type() == QEvent::FocusIn)
       {
            num_24 = 13;
            ui->frame_keyboard->move(110,190);
            return 1;
       }
    }

    if(obj == ui->lineEdit_p1_1)
    {
       if(event->type() == QEvent::FocusIn)
       {
            num_24 = 14;
            ui->frame_keyboard->move(110,190);
            return 1;
       }
    }

    if(obj == ui->lineEdit_p1_2)
    {
       if(event->type() == QEvent::FocusIn)
       {
            num_24 = 15;
            ui->frame_keyboard->move(110,190);
            return 1;
       }
    }


    if(obj == ui->lineEdit_p2_1)
    {
       if(event->type() == QEvent::FocusIn)
       {
            num_24 = 16;
            ui->frame_keyboard->move(110,190);
            return 1;
       }
    }


    if(obj == ui->lineEdit_p2_2)
    {
       if(event->type() == QEvent::FocusIn)
       {
            num_24 = 17;
            ui->frame_keyboard->move(110,190);
            return 1;
       }
    }


    if(obj == ui->lineEdit_f1_1)
    {
       if(event->type() == QEvent::FocusIn)
       {
            num_24 = 18;
            ui->frame_keyboard->move(110,40);
            return 1;
       }
    }

    if(obj == ui->lineEdit_f1_2)
    {
       if(event->type() == QEvent::FocusIn)
       {
            num_24 = 19;
            ui->frame_keyboard->move(110,40);
            return 1;
       }
    }

    if(obj == ui->lineEdit_f2_1)
    {
       if(event->type() == QEvent::FocusIn)
       {
            num_24 = 20;
            ui->frame_keyboard->move(110,40);
            return 1;
       }
    }

    if(obj == ui->lineEdit_f2_2)
    {
       if(event->type() == QEvent::FocusIn)
       {
            num_24 = 21;
            ui->frame_keyboard->move(110,40);
            return 1;
       }
    }

    if(obj == ui->lineEdit_g1_1)
    {
       if(event->type() == QEvent::FocusIn)
       {
            num_24 = 22;
            ui->frame_keyboard->move(110,40);
            return 1;
       }
    }

    if(obj == ui->lineEdit_g1_2)
    {
       if(event->type() == QEvent::FocusIn)
       {
            num_24 = 23;
            ui->frame_keyboard->move(110,40);
            return 1;
       }
    }

    if(obj == ui->lineEdit_g2_1)
    {
       if(event->type() == QEvent::FocusIn)
       {
            num_24 = 24;
            ui->frame_keyboard->move(110,40);
            return 1;
       }
    }

    if(obj == ui->lineEdit_g2_2)
    {
       if(event->type() == QEvent::FocusIn)
       {
            num_24 = 25;
            ui->frame_keyboard->move(110,40);
            return 1;
       }
    }
    return 0;
}

void p24_setpara_sub6_dialog::on_pbtn_ok_clicked()
{
    ui->frame_keyboard->move(110,470);
}

void p24_setpara_sub6_dialog::on_pbtn_up_clicked()
{
    hmi_button_dn_num=PAGEUP_BUTTON ;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
}

void p24_setpara_sub6_dialog::on_pbtn_down_clicked()
{
   // hmi_button_dn_num=PAGEDOWN_BUTTON ;
  //  API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
}

void p24_setpara_sub6_dialog::on_pbtn_cancel_clicked()
{
    hmi_button_dn_num=CANCEL_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
}

void p24_setpara_sub6_dialog::on_pbtn_enter_clicked()
{
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"top1_elecprice");
    if(t1_len>0)
    {
        ft1=atof(t1);
        write_profile_float(Section_name,Key_name,ft1,config_path);
        API_Write_DB_Nbyte(PL_TOP1_ELECPRICE ,(BOOL *)(&ft1),sizeof(ft1));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"top2_elecprice");
    if(t2_len>0)
    {
        ft2=atof(t2);
        write_profile_float(Section_name,Key_name,ft2,config_path);
         API_Write_DB_Nbyte(PL_TOP2_ELECPRICE ,(BOOL *)(&ft2),sizeof(ft2));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"peak1_elecprice");
    if(p1_len>0)
    {
        fp1=atof(p1);
        write_profile_float(Section_name,Key_name,fp1,config_path);
         API_Write_DB_Nbyte(PL_PEAK1_ELECPRICE ,(BOOL *)(&fp1),sizeof(fp1));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"peak2_elecprice");
    if(p2_len>0)
    {
        fp2=atof(p2);
        write_profile_float(Section_name,Key_name,fp2,config_path);
         API_Write_DB_Nbyte(PL_PEAK2_ELECPRICE ,(BOOL *)(&fp2),sizeof(fp2));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"flat1_elecprice");
    if(f1_len>0)
    {
        ff1=atof(f1);
        write_profile_float(Section_name,Key_name,ff1,config_path);
         API_Write_DB_Nbyte(PL_FLAT1_ELECPRICE ,(BOOL *)(&ff1),sizeof(ff1));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"flat2_elecprice");
    if(f2_len>0)
    {
        ff2=atof(f2);
        write_profile_float(Section_name,Key_name,ff2,config_path);
        API_Write_DB_Nbyte(PL_FLAT2_ELECPRICE ,(BOOL *)(&ff2),sizeof(ff2));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"valley1_elecprice");
    if(g1_len>0)
    {
        fg1=atof(g1);
        write_profile_float(Section_name,Key_name,fg1,config_path);
        API_Write_DB_Nbyte(PL_VALLEY1_ELECPRICE ,(BOOL *)(&fg1),sizeof(fg1));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"valley2_elecprice");
    if(g2_len>0)
    {
        fg2=atof(g2);
        write_profile_float(Section_name,Key_name,fg2,config_path);
        API_Write_DB_Nbyte(PL_VALLEY2_ELECPRICE ,(BOOL *)(&fg2),sizeof(fg2));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"top1_starttm");
    if(t1_len_1>0)
    {
        ft1_1=atof(t1_1);
        write_profile_float(Section_name,Key_name,ft1_1,config_path);
        API_Write_DB_Nbyte(PL_TOP1_STARTTM ,(BOOL *)(&ft1_1),sizeof(ft1_1));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"top1_stoptm");
    if(t1_len_2>0)
    {
        ft1_2=atof(t1_2);
        write_profile_float(Section_name,Key_name,ft1_2,config_path);
        API_Write_DB_Nbyte(PL_TOP1_STOPTM ,(BOOL *)(&ft1_2),sizeof(ft1_2));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"top2_starttm");
    if(t2_len_1>0)
    {
        ft2_1=atof(t2_1);
        write_profile_float(Section_name,Key_name,ft2_1,config_path);
        API_Write_DB_Nbyte(PL_TOP2_STARTTM ,(BOOL *)(&ft2_1),sizeof(ft2_1));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"top2_stoptm");
    if(t2_len_2>0)
    {
        ft2_2=atof(t2_2);
        write_profile_float(Section_name,Key_name,ft2_2,config_path);
        API_Write_DB_Nbyte(PL_TOP2_STOPTM ,(BOOL *)(&ft2_2),sizeof(ft2_2));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"peak1_starttm");
    if(p1_len_1>0)
    {
        fp1_1=atof(p1_1);
        write_profile_float(Section_name,Key_name,fp1_1,config_path);
        API_Write_DB_Nbyte(PL_PEAK1_STARTTM ,(BOOL *)(&fp1_1),sizeof(fp1_1));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"peak1_stoptm");
    if(p1_len_2>0)
    {
        fp1_2=atof(p1_2);
        write_profile_float(Section_name,Key_name,fp1_2,config_path);
        API_Write_DB_Nbyte(PL_PEAK1_STOPTM ,(BOOL *)(&fp1_2),sizeof(fp1_2));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"peak2_starttm");
    if(p2_len_1>0)
    {
        fp2_1=atof(p2_1);
        write_profile_float(Section_name,Key_name,fp2_1,config_path);
        API_Write_DB_Nbyte(PL_PEAK2_STARTTM ,(BOOL *)(&fp2_1),sizeof(fp2_1));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"peak2_stoptm");
    if(p2_len_2>0)
    {
        fp2_2=atof(p2_2);
        write_profile_float(Section_name,Key_name,fp2_2,config_path);
        API_Write_DB_Nbyte(PL_PEAK2_STOPTM ,(BOOL *)(&fp2_2),sizeof(fp2_2));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"flat1_starttm");
    if(f1_len_1>0)
    {
        ff1_1=atof(f1_1);
        write_profile_float(Section_name,Key_name,ff1_1,config_path);
        API_Write_DB_Nbyte(PL_FLAT1_STARTTM ,(BOOL *)(&ff1_1),sizeof(ff1_1));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"flat1_stoptm");
    if(f1_len_2>0)
    {
        ff1_2=atof(f1_2);
        write_profile_float(Section_name,Key_name,ff1_2,config_path);
        API_Write_DB_Nbyte(PL_FLAT1_STOPTM ,(BOOL *)(&ff1_2),sizeof(ff1_2));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"flat2_starttm");
    if(f2_len_1>0)
    {
        ff2_1=atof(f2_1);
        write_profile_float(Section_name,Key_name,ff2_1,config_path);
        API_Write_DB_Nbyte(PL_FLAT2_STARTTM ,(BOOL *)(&ff2_1),sizeof(ff2_1));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"flat2_stoptm");
    if(f2_len_2>0)
    {
        ff2_2=atof(f2_2);
        write_profile_float(Section_name,Key_name,ff2_2,config_path);
        API_Write_DB_Nbyte(PL_FLAT2_STOPTM ,(BOOL *)(&ff2_2),sizeof(ff2_2));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"valley1_starttm");
    if(g1_len_1>0)
    {
        fg1_1=atof(g1_1);
        write_profile_float(Section_name,Key_name,fg1_1,config_path);
        API_Write_DB_Nbyte(PL_VALLEY1_STARTTM ,(BOOL *)(&fg1_1),sizeof(fg1_1));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"valley1_stoptm");
    if(g1_len_2>0)
    {
        fg1_2=atof(g1_2);
        write_profile_float(Section_name,Key_name,fg1_2,config_path);
        API_Write_DB_Nbyte(PL_VALLEY1_STOPTM ,(BOOL *)(&fg1_2),sizeof(fg1_2));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"valley2_starttm");
    if(g2_len_1>0)
    {
        fg2_1=atof(g2_1);
        write_profile_float(Section_name,Key_name,fg2_1,config_path);
        API_Write_DB_Nbyte(PL_VALLEY2_STARTTM ,(BOOL *)(&fg2_1),sizeof(fg2_1));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"valley2_stoptm");
    if(g2_len_2>0)
    {
        fg2_2=atof(g2_2);
        write_profile_float(Section_name,Key_name,fg2_2,config_path);
        API_Write_DB_Nbyte(PL_VALLEY2_STOPTM ,(BOOL *)(&fg2_2),sizeof(fg2_2));
    }
    else
    {
         //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    float temp_total = 0;
    temp_total = ft1_2 - ft1_1 + ft2_2 - ft2_1 + fp1_2 - fp1_1 + fp2_2 - fp2_1 + ff1_2 - ff1_1 + ff2_2 - ff2_1 + fg1_2 - fg1_1 + fg2_2 - fg2_1;
    if(temp_total != 24)
    {
        ui->label_speak->setText(QString::fromUtf8("请重新设置!"));
        return;
    }

    hmi_button_dn_num=OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));

}

void p24_setpara_sub6_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p24dlg();
    //delete p24_dlg;
   // p24_dlg = NULL;
}
