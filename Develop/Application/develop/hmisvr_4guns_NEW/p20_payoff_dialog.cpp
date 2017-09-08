#include "p20_payoff_dialog.h"
#include "ui_p20_payoff_dialog.h"
#include "globalhmi.h"

p20_payoff_dialog::p20_payoff_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p20_payoff_dialog)
{
    ui->setupUi(this);
}

p20_payoff_dialog::~p20_payoff_dialog()
{
    delete ui;
}

void p20_payoff_dialog::changeEvent(QEvent *e)
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

void p20_payoff_dialog::on_pbtn_cancel_clicked()
{
    hmi_button_dn_num=PRINTCANCEL_ACBUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
}


void p20_payoff_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
    ui->label_code->setText(code);
    ui->label_phone->setText(phonenum);
    ui->label_phone_2->setText(phonenum_2);
}
static int add_numb;
static int Timer;
void p20_payoff_dialog::init_page_val()
{
        add_numb=0;
        Timer=60;
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p20_payoff_dialog::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
}

void p20_payoff_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
     add_numb++;
     if(add_numb==10)
     {
         add_numb=0;
         if(Timer>0)
         {
             Timer--;
         }
     }
     if(Timer<=0)
     {
         hmi_button_dn_num=PRINTCANCEL_ACBUTTON;
         API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
     }
}

void p20_payoff_dialog::update_page_info()
{
  //  ui->label_phone->setText(phonenum);
  //   ui->label_code->setText(code);
  //   UINT16 u16_data = 0;
     FLOAT32 f32_data = 0;
     UINT16 u16_data=0;

     API_Read_DB_Nbyte(PL_CHRTOTALUSE_TIME,(INT8 *)(&u16_data),sizeof(u16_data));
     ui->lbl_time_hour->setText(QString::number(u16_data/60,'f',0));
     ui->lbl_time_min->setText(QString::number(u16_data%60,'f',0));

     API_Read_DB_Nbyte(PL_CHRUSED_KWH,(INT8 *)(&f32_data),sizeof(f32_data));
     ui->lbl_caclulate_energy->setText(QString::number(f32_data,'f',2));

     API_Read_DB_Nbyte(PL_CHRUSED_TOTALMONEY,(INT8 *)(&f32_data),sizeof(f32_data));
     ui->lbl_money_total->setText(QString::number(f32_data,'f',2));

     API_Read_DB_Nbyte(PL_CHARGESEVICE_MONEY,(INT8 *)(&f32_data),sizeof(f32_data));
     ui->lbl_money_service->setText(QString::number(f32_data,'f',2));
   //  ErrMsg("$$$$[%0.2f]$$$\n",f32_data);

     API_Read_DB_Nbyte(PL_ELECTRIC_MONEY,(INT8 *)(&f32_data),sizeof(f32_data));
     ui->lbl_money_electric->setText(QString::number(f32_data,'f',2));
}

void p20_payoff_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX_CUR,(INT8 *)(&hmi_page_index_cur),sizeof(hmi_page_index_cur));
    DebugMsg(hmilev,8,"hmi_page_index=[%d]cur[%d]\n",hmi_page_index,hmi_page_index_cur);
    if(hmi_page_index!=hmi_page_index_cur)
    {
        API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX_CUR,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
        if(hmi_page_index==PAGEINDEX_PAYOFF)
        {
                DebugMsg(hmilev,8,"hmi_page_index=[%d]cur[%d]\n",hmi_page_index,hmi_page_index_cur);
        }else
        if(hmi_page_index==PAGEINDEX_MAIN)
        {
                exit_page_dlg();
        }else
        {
                ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
                exit(1);
        }
    }
}
/*
void p20_payoff_dialog::call_dlg_1()
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
void p20_payoff_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p20dlg();
    delete p20_dlg;
    p20_dlg = NULL;
}
