#include "dialog_stop.h"
#include "ui_dialog_stop.h"
#include "globalhmi.h"

Dialog_stop::Dialog_stop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_stop)
{
    ui->setupUi(this);
}

Dialog_stop::~Dialog_stop()
{
    delete ui;
}

void Dialog_stop::on_pushButton_ok_clicked()
{
        hmi_button_dn_num=OK_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),
                           sizeof(hmi_button_dn_num));
}

void Dialog_stop::on_pushButton_cancel_clicked()
{
        hmi_button_dn_num=CANCEL_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),
                           sizeof(hmi_button_dn_num));
}

void Dialog_stop::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
    ui->label_code->setText(phonenum);
        ui->label_code_2->setText(phonenum_2);
   // ui->label_phone->setText(phonenum);
   // ui->label_phone_2->setText(phonenum_2);
}

void Dialog_stop::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void Dialog_stop::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
}

void Dialog_stop::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void Dialog_stop::update_page_info()
{

      if(language_num == 1)
      {
           // ui->label_logo->setText(QString::fromUtf8("直 流 充 电 桩"));
          //  ui->label_title->setText(QString::fromUtf8("余 额 查 询"));
            ui->label_stubnum->setText(QString::fromUtf8(" 客  服  热  线  :"));
          //  ui->pbtn_cancel->setText(QString::fromUtf8("返        回"));
      }
      else  if(language_num == 2)
      {
          //  ui->label_logo->setText("DC charging pile");
           // ui->label_title->setText("Balance Inquire");
            ui->label_stubnum->setText("Pile Number :");
         //   ui->pbtn_cancel->setText("Back");
      }
}

void Dialog_stop::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
    if(hmi_page_index != PAGEINDEX_STOPCHARGE_SURE)
    {
        exit_page_dlg();
    }
    else
    {

    }
}

void Dialog_stop::exit_page_dlg()
{
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
    timer->stop();
    emit signal_exit_dlg();
    //delete dlg_stop;
    //dlg_stop = NULL;
}
