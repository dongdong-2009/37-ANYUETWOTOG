#include "dialog_err.h"
#include "ui_dialog_err.h"
#include "globalhmi.h"

Dialog_err::Dialog_err(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_err)
{
    ui->setupUi(this);
}

Dialog_err::~Dialog_err()
{
    delete ui;
}

void Dialog_err::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
}

char temp_buf[30][50]={0};
int temp_add = 0;
int num_sum = 0;
void Dialog_err::init_page_val()
{
 //    ui->label_code->setText(code);
    temp_add = 0;
    num_sum = 0;
    memset(temp_buf,0,sizeof(temp_buf));
    ui->label_code->setText(phonenum);
    ui->label_code_2->setText(phonenum_2);

    lbl_num=1;
    lbl_num_2=2;
    lbl_num_3=3;
    lbl_num_4=4;
    lbl_num_5=5;

    memset(lbl_txt, 0,sizeof(lbl_txt));
    memset(lbl_txt_2, 0,sizeof(lbl_txt_2));
    memset(lbl_txt_3, 0,sizeof(lbl_txt_3));
    memset(lbl_txt_4, 0,sizeof(lbl_txt_4));
    memset(lbl_txt_5, 0,sizeof(lbl_txt_5));


    ui->label_num->setText(NULL);
    ui->label_num_2->setText(NULL);
    ui->label_num_3->setText(NULL);
    ui->label_num_4->setText(NULL);
    ui->label_num_5->setText(NULL);
    ui->label_txt->setText(NULL);
    ui->label_txt_2->setText(NULL);
    ui->label_txt_3->setText(NULL);
    ui->label_txt_4->setText(NULL);
    ui->label_txt_5->setText(NULL);

    if(language_num == 1)
    {
      //   ui->label_logo->setText(QString::fromUtf8("直 流 充 电 桩"));
        ui->label_state->setText(QString::fromUtf8("设备故障，暂停使用"));
        ui->pbtn_err->setText(QString::fromUtf8("故障详情"));
        ui->pbtn_up->setText(QString::fromUtf8("上一页"));
        ui->pbtn_down->setText(QString::fromUtf8("下一页"));
        ui->pbtn_back->setText(QString::fromUtf8("返 回"));
        ui->label_stubnum->setText(QString::fromUtf8("客  服  热  线  :"));

        ui->lbl_num->setText(QString::fromUtf8("故障序号"));
        ui->lbl_infor->setText(QString::fromUtf8(" 故障信息"));
    }
    else  if(language_num == 2)
    {
      //  ui->label_logo->setText("DC charging pile");
        ui->label_state->setText("Equipment Error");
        ui->pbtn_err->setText("Error Detail");
        ui->pbtn_up->setText("Page Up");
        ui->pbtn_down->setText("Page Down");
        ui->pbtn_back->setText("back");
        ui->label_stubnum->setText("Telephone :");
        ui->lbl_num->setText("Num");
        ui->lbl_infor->setText("ErrInfor");

    }
    else
    {

    }

    ui->label_state->move(30,190);
    ui->frame->move(34,610);

    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));

    int state_flag = 0;
     API_Write_DB_Nbyte(PL_STUBERRSTATE_FLAG,(int *)(&state_flag),sizeof(state_flag));
}

void Dialog_err::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
}

void Dialog_err::timer_handle()
{
    update_page_info();
    update_hmi_page_index();
}

 void Dialog_err::on_pbtn_err_clicked()
 {
    ui->label_state->move(150,590);
    ui->label_web1->move(33,590);
    ui->label_web2->move(193,590);
    ui->frame->move(34,85);
 }

 void Dialog_err::on_pbtn_back_clicked()
 {
     ui->label_state->move(30,190);
     ui->label_web1->move(33,400);
     ui->label_web2->move(193,400);
      ui->frame->move(34,610);
 }

 void Dialog_err::on_pbtn_up_clicked()
 {
      if(lbl_num-5>0)
      {
              lbl_num=lbl_num-5;
              lbl_num_2=lbl_num_2-5;
              lbl_num_3=lbl_num_3-5;
              lbl_num_4=lbl_num_4-5;
              lbl_num_5=lbl_num_5-5;
     }
     else
     {

     }
 }

 void Dialog_err::on_pbtn_down_clicked()
 {
     if(lbl_num_5+5<num_sum)
     {
             lbl_num=lbl_num+5;
             lbl_num_2=lbl_num_2+5;
             lbl_num_3=lbl_num_3+5;
             lbl_num_4=lbl_num_4+5;
             lbl_num_5=lbl_num_5+5;
    }
    else
    {

    }
 }


 int   Err_anasys()
 {
     if(language_num == 1)
     {


         temp_add = 0;
         if( (error_state_flag & (1<<0)) || (error_state_flag &(1<<24)) || (error_state_flag & (1<<1))  || (error_state_flag & (1<<25)) )
         {

             memcpy(&temp_buf[temp_add++],"读 卡 器 故 障",sizeof("读 卡 器 故 障"));
         }
         if( (error_state_flag & (1<<20)) )
         {
             memcpy(&temp_buf[temp_add++],"电 表 通 讯 故 障",sizeof("电 表 通 讯 故 障"));
         }

         if( (error_state_flag & (1<<23)) )
         {
             memcpy(&temp_buf[temp_add++],"网 络 连 接 故 障",sizeof("网 络 连 接 故 障"));
         }

         if( (error_state_flag & (1<<8)) )
         {
             memcpy(&temp_buf[temp_add++],"主 板 软 件 故 障",sizeof("主 板 软 件 故 障"));
         }
         if( (error_state_flag & (1<<21)) )
         {
             memcpy(&temp_buf[temp_add++],"急停按钮被按下,请恢复",sizeof("急停按钮被按下,请恢复"));
         }
         if( (error_state_flag & (1<<7)) )
         {
             memcpy(&temp_buf[temp_add++],"主 板 硬 件 故 障",sizeof("主 板 硬 件 故 障"));
         }
         if( (error_state_flag & (1<<4)) ||(error_state_flag & (1<<5)))
         {
             memcpy(&temp_buf[temp_add++],"交流接触器故障",sizeof("交流接触器故障"));
         }
         if( (error_state_flag & (1<<10)) )
         {
             memcpy(&temp_buf[temp_add++],"模块通讯故障",sizeof("模块通讯故障"));
         }
     }
     else  if(language_num == 2)
     {

         temp_add = 0;
         if( (error_state_flag & (1<<0)) || (error_state_flag &(1<<24)) || (error_state_flag & (1<<1))  || (error_state_flag & (1<<25)) )
         {
             memcpy(&temp_buf[temp_add++],"card reader error",sizeof("card reader error"));
         }
         if( (error_state_flag & (1<<23)) )
         {
             memcpy(&temp_buf[temp_add++],"net link error",sizeof("net link error"));
         }
         if( (error_state_flag & (1<<20)) )
         {
             memcpy(&temp_buf[temp_add++],"meter error",sizeof("meter error"));
         }
         if( (error_state_flag & (1<<8)) )
         {
             memcpy(&temp_buf[temp_add++],"software in board error",sizeof("software in board error"));
         }
         if( (error_state_flag & (1<<21)) )
         {
             memcpy(&temp_buf[temp_add++],"emergency is pressed,please recover it",sizeof("emergency is pressed,please recover it"));
         }
         if( (error_state_flag & (1<<7)) )
         {
             memcpy(&temp_buf[temp_add++],"hardware in board error",sizeof("hardware in board error"));
         }
         if( (error_state_flag & (1<<4)) ||(error_state_flag & (1<<5)))
         {
             memcpy(&temp_buf[temp_add++],"ac contactor error",sizeof("ac contactor error"));
         }
     }
     else
     {

     }
     return temp_add;
 }


 int temp_error_state = 0;
void Dialog_err::update_page_info()
{
    ui->lbl_sysdate->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    ui->lbl_systime->setText(QTime::currentTime().toString("hh:mm:ss"));

    API_Read_DB_Nbyte(PL_STUBERRSTATE_FLAG,(int *)(&error_state_flag),sizeof(error_state_flag));
    //if(temp_error_state != error_state_flag)
    {
        temp_error_state = error_state_flag;
        memset(temp_buf,0,sizeof(temp_buf));
        num_sum = Err_anasys();
    }

#if 1
    memcpy(lbl_txt, &temp_buf[lbl_num-1],sizeof(temp_buf[lbl_num-1]));
    memcpy(lbl_txt_2,& temp_buf[lbl_num_2-1],sizeof(temp_buf[lbl_num_2-1]));
    memcpy(lbl_txt_3, &temp_buf[lbl_num_3-1],sizeof(temp_buf[lbl_num_3-1]));
    memcpy(lbl_txt_4, &temp_buf[lbl_num_4-1],sizeof(temp_buf[lbl_num_4-1]));
    memcpy(lbl_txt_5, &temp_buf[lbl_num_5-1],sizeof(temp_buf[lbl_num_5-1]));


    ui->label_txt->setText(QString::fromUtf8(lbl_txt));
    ui->label_txt_2->setText(QString::fromUtf8(lbl_txt_2));
    ui->label_txt_3->setText(QString::fromUtf8(lbl_txt_3));
    ui->label_txt_4->setText(QString::fromUtf8(lbl_txt_4));
    ui->label_txt_5->setText(QString::fromUtf8(lbl_txt_5));

    if(lbl_txt[0])
    {
         ui->label_num->setNum(lbl_num);
    }
    else
    {
         ui->label_num->setText(NULL);
    }

    if(lbl_txt_2[0])
    {
       ui->label_num_2->setNum(lbl_num_2);
    }
    else
    {
        ui->label_num_2->setText(NULL);
    }

    if(lbl_txt_3[0])
    {
         ui->label_num_3->setNum(lbl_num_3);
    }
    else
    {
         ui->label_num_3->setText(NULL);
    }

    if(lbl_txt_4[0])
    {
        ui->label_num_4->setNum(lbl_num_4);
    }
    else
    {
         ui->label_num_4->setText(NULL);
    }

    if(lbl_txt_5[0])
    {
       ui->label_num_5->setNum(lbl_num_5);
    }
    else
    {
         ui->label_num_5->setText(NULL);
    }
#endif
 }

void Dialog_err::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
    if(hmi_page_index != PAGEINDEX_ERRORCHECK)
    {
        exit_page_dlg();
    }
    else
    {

    }
}

void Dialog_err::exit_page_dlg()
{
    init_page_val();
    timer->stop();
    emit  signal_exit_errdlg();
    //delete err_dlg;
   // err_dlg = NULL;
}
