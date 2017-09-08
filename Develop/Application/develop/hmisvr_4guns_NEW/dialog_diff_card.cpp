#include "dialog_diff_card.h"
#include "ui_dialog_diff_card.h"
#include "globalhmi.h"
Dialog_diff_card::Dialog_diff_card(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_diff_card)
{
    ui->setupUi(this);
}

Dialog_diff_card::~Dialog_diff_card()
{
    delete ui;
}

void Dialog_diff_card::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
}

void Dialog_diff_card::init_page_val()
{
    // ui->label_code->setText(code);
      ui->label_code->setText(phonenum);
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void Dialog_diff_card::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
}

static int  num_add_end = 0;
void Dialog_diff_card::timer_handle()
{
    update_page_info();
    update_hmi_page_index();
}

void Dialog_diff_card::update_page_info()
{
    ui->lbl_sysdate->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    ui->lbl_systime->setText(QTime::currentTime().toString("hh:mm:ss"));
    if(language_num == 1)
    {
          //ui->label_logo->setText(QString::fromUtf8("交 流 充 电 桩"));
          ui->label_end->setText(QString::fromUtf8("卡号不一致,请确认"));
          ui->label_end_2->setText(QString::fromUtf8("3秒后返回交易界面"));
          ui->label_stubnum->setText(QString::fromUtf8("客  服  电  话  :"));
    }
    else  if(language_num == 2)
    {
         // ui->label_logo->setText("AC charging pile");
          ui->label_end->setText("Number of inconsistencies, please confirm");
          ui->label_end_2->setText("3 seconds after the return ");
          ui->label_stubnum->setText("Telephone :");
    }
    else
    {

    }
}

void Dialog_diff_card::update_hmi_page_index(void)
{
        API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
       if(hmi_page_index != PAGEINDEX_DIFFERENT_CARD)
       {
           exit_page_dlg();
       }
       else
       {

       }
}

void Dialog_diff_card::exit_page_dlg()
{
    init_page_val();
    timer->stop();
    emit  signal_exit_diff_card();
    //delete diff_card_dlg;
    //diff_card_dlg = NULL;
}
