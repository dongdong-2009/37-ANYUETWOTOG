#include "p12_payoff_dialog.h"
#include "ui_p12_payoff_dialog.h"
#include "globalhmi.h"

p12_payoff_dialog::p12_payoff_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p12_payoff_dialog)
{
    ui->setupUi(this);
}

p12_payoff_dialog::~p12_payoff_dialog()
{
    delete ui;
}

void p12_payoff_dialog::changeEvent(QEvent *e)
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

void p12_payoff_dialog::on_pbtn_cancel_clicked()
{
    hmi_button_dn_num=PRINTCANCEL_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
}


void p12_payoff_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
    ui->label_code->setText(code);
    ui->label_phone->setText(phonenum);
    ui->label_phone_2->setText(phonenum_2);
}
static int add_numb=0;
static int Timer;
void p12_payoff_dialog::init_page_val()
{
        Timer=60;
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p12_payoff_dialog::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
}

void p12_payoff_dialog::timer_handle()
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
         hmi_button_dn_num=PRINTCANCEL_BUTTON;
         API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
     }
}

void p12_payoff_dialog::update_page_info()
{
      ui->label_code->setText(code);
 //   ui->label_phone->setText(phonenum);
  //  ui->label_phone_2->setText(phonenum_2);
    UINT16 u16_data = 0;
    FLOAT32 f32_data = 0;
    static UINT8 num_add=0;


    if(language_num == 1)
    {
          ui->pbtn_cancel->setText(QString::fromUtf8("确  定"));
      //    ui->label_logo->setText(QString::fromUtf8("直 流 充 电 桩"));
          ui->label_title_2->setText(QString::fromUtf8("结 算 信 息"));
          ui->label_stubnum->setText(QString::fromUtf8(" 桩   编   号  :"));

          ui->label_time->setText(QString::fromUtf8("充电用时:"));
          ui->label_energy->setText(QString::fromUtf8("消耗电量:"));
          ui->label_server->setText(QString::fromUtf8("服务金额:"));
          ui->label_total->setText(QString::fromUtf8("总计金额:"));
           ui->label_elec->setText(QString::fromUtf8("电费金额:"));
          ui->label_soc->setText(QString::fromUtf8("停止SOC:"));


          API_Read_DB_Nbyte(PL_CHRPASSWRDERR_FLAG,(UINT8 *)(&num_add),sizeof(num_add));
          if(num_add==6)
          {
              ui->lbl_result->setText(QString::fromUtf8("结算失败!"));
          }
    }
    else  if(language_num == 2)
    {
         ui->pbtn_cancel->setText("OK");
    //   ui->label_logo->setText("DC charging pile");
        ui->label_title_2->setText("Clearing Information");
        ui->label_stubnum->setText("Pile Number :");

        ui->label_time->setText("Charge Time:");
        ui->label_energy->setText("Energy consumption:");
        ui->label_server->setText("Service amount:");
        ui->label_total->setText("Total amount:");
        ui->label_elec->setText("Electricity fees:");
        ui->label_soc->setText("Stop SOC:");


        API_Read_DB_Nbyte(PL_CHRPASSWRDERR_FLAG,(UINT8 *)(&num_add),sizeof(num_add));
        if(num_add==6)
        {
            ui->lbl_result->setText("Clearing Failed!");
        }
    }

        API_Read_DB_Nbyte(PL_CHRTOTALUSE_TIME,(INT8 *)(&u16_data),sizeof(u16_data));
        ui->lbl_time_min->setText(QString::number(u16_data,'f',0));

        API_Read_DB_Nbyte(PL_CHR_STOPSOC,(INT8 *)(&u16_data),sizeof(u16_data));
        ui->lbl_stop_soc->setText(QString::number(u16_data,'f',0));

        API_Read_DB_Nbyte(PL_CHRUSED_KWH,(INT8 *)(&f32_data),sizeof(f32_data));
        ui->lbl_caclulate_energy->setText(QString::number(f32_data,'f',2));

        API_Read_DB_Nbyte(PL_CHRUSED_TOTALMONEY,(INT8 *)(&f32_data),sizeof(f32_data));
        ui->lbl_money_total->setText(QString::number(f32_data,'f',2));

        API_Read_DB_Nbyte(PL_CHARGESEVICE_MONEY,(INT8 *)(&f32_data),sizeof(f32_data));
        ui->lbl_money_service->setText(QString::number(f32_data,'f',2));

        API_Read_DB_Nbyte(PL_ELECTRIC_MONEY,(INT8 *)(&f32_data),sizeof(f32_data));
        ui->lbl_money_electric->setText(QString::number(f32_data,'f',2));


}

void p12_payoff_dialog::update_hmi_page_index()
{

        API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
        if(hmi_page_index != PAGEINDEX_PAYOFF)
        {
            exit_page_dlg();
        }
        else
        {

        }
}
/*
void p12_payoff_dialog::call_dlg_1()
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
void p12_payoff_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p12dlg();
    //delete p12_dlg;
    //p12_dlg = NULL;
}
