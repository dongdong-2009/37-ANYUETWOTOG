#include "p21_leftmoney_dialog.h"
#include "ui_p21_leftmoney_dialog.h"
#include "globalhmi.h"

p21_leftmoney_dialog::p21_leftmoney_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p21_leftmoney_dialog)
{
    ui->setupUi(this);
}

p21_leftmoney_dialog::~p21_leftmoney_dialog()
{
    delete ui;
}





void p21_leftmoney_dialog::on_pbtn_cancel_clicked()
{
        hmi_button_dn_num=CANCEL_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),
                           sizeof(hmi_button_dn_num));
}



void p21_leftmoney_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
    ui->label_code->setText(code);
   // ui->label_phone->setText(phonenum);
   // ui->label_phone_2->setText(phonenum_2);
}

float float_32 = 0;
void p21_leftmoney_dialog::init_page_val()
{
        float_32 = 0;
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p21_leftmoney_dialog::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
}

void p21_leftmoney_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p21_leftmoney_dialog::update_page_info()
{

      if(language_num == 1)
      {
            //ui->label_logo->setText(QString::fromUtf8("直 流 充 电 桩"));
            ui->label_title->setText(QString::fromUtf8("余 额 查 询"));
            ui->label_stubnum->setText(QString::fromUtf8(" 桩   编   号  :"));
            ui->pbtn_cancel->setText(QString::fromUtf8("返        回"));
      }
      else  if(language_num == 2)
      {
           // ui->label_logo->setText("DC charging pile");
            ui->label_title->setText("Balance Inquire");
            ui->label_stubnum->setText("Pile Number :");
            ui->pbtn_cancel->setText("Back");
      }

       API_Read_DB_Nbyte(PL_MAINCARD_LEFTMONEY,(float *)(&float_32),sizeof(float_32));
       ui->label_leftmoney->setText(QString::number(float_32,'f',2));
}

void p21_leftmoney_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX_CUR,(INT8 *)(&hmi_page_index_cur),sizeof(hmi_page_index_cur));
    DebugMsg(hmilev,8,"hmi_page_index=[%d]cur[%d]\n",hmi_page_index,hmi_page_index_cur);
    if(hmi_page_index!=hmi_page_index_cur)
    {
        API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX_CUR,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
        if(hmi_page_index==PAGEINDEX_SERVICECHOICE)
        {
                exit_page_dlg();
        }else{
                ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
                exit(1);
        }

    }
}

void p21_leftmoney_dialog::exit_page_dlg()
{
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
    timer->stop();
    emit signal_exit_p21dlg();
    delete p21_dlg;
    p21_dlg = NULL;
}
