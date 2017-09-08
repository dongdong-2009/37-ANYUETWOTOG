#include "p22_elecprice_dialog.h"
#include "ui_p22_elecprice_dialog.h"
#include "globalhmi.h"

p22_ElecPrice_dialog::p22_ElecPrice_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p22_ElecPrice_dialog)
{
    ui->setupUi(this);
}

p22_ElecPrice_dialog::~p22_ElecPrice_dialog()
{
    delete ui;
}

void p22_ElecPrice_dialog::on_pbtn_cancel_clicked()
{
        hmi_button_dn_num=CANCEL_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),
                           sizeof(hmi_button_dn_num));
}



void p22_ElecPrice_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
    ui->label_code->setText(code);
   // ui->label_phone->setText(phonenum);
   // ui->label_phone_2->setText(phonenum_2);
}

float float_22 = 0;
char buf_22[8]={0};
void p22_ElecPrice_dialog::init_page_val()
{
        float_22 = 0;
        memset(buf_22,0,8);
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p22_ElecPrice_dialog::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
}

void p22_ElecPrice_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void ftobuf(const float num,char*buf)
{
    int temp_1 = (int)num;
    float temp_2 = (num - temp_1)*60;
    sprintf(buf,"%d:%d",temp_1,(int)temp_2);
}

void p22_ElecPrice_dialog::update_page_info()
{

      if(language_num == 1)
      {
         //   ui->label_logo->setText(QString::fromUtf8("直 流 充 电 桩"));
            ui->label_title->setText(QString::fromUtf8("电 价 查 询"));
            ui->label_stubnum->setText(QString::fromUtf8(" 桩   编   号  :"));
            ui->pbtn_cancel->setText(QString::fromUtf8("返        回"));
      }
      else  if(language_num == 2)
      {
         //   ui->label_logo->setText("DC charging pile");
            ui->label_title->setText("Query Electricity Price");
            ui->label_stubnum->setText("Pile Number :");
            ui->pbtn_cancel->setText("Back");
      }

      API_Read_DB_Nbyte(PL_TOP1_ELECPRICE,(float *)(&float_22),sizeof(float_22));
      ui->label_t1->setText(QString::number(float_22,'f',2));
      API_Read_DB_Nbyte(PL_TOP2_ELECPRICE,(float *)(&float_22),sizeof(float_22));
      ui->label_t2->setText(QString::number(float_22,'f',2));
      API_Read_DB_Nbyte(PL_PEAK1_ELECPRICE,(float *)(&float_22),sizeof(float_22));
      ui->label_p1->setText(QString::number(float_22,'f',2));
      API_Read_DB_Nbyte(PL_PEAK2_ELECPRICE,(float *)(&float_22),sizeof(float_22));
      ui->label_p2->setText(QString::number(float_22,'f',2));
      API_Read_DB_Nbyte(PL_FLAT1_ELECPRICE,(float *)(&float_22),sizeof(float_22));
      ui->label_f1->setText(QString::number(float_22,'f',2));
      API_Read_DB_Nbyte(PL_FLAT2_ELECPRICE,(float *)(&float_22),sizeof(float_22));
      ui->label_f2->setText(QString::number(float_22,'f',2));
      API_Read_DB_Nbyte(PL_VALLEY1_ELECPRICE,(float *)(&float_22),sizeof(float_22));
      ui->label_g1->setText(QString::number(float_22,'f',2));
      API_Read_DB_Nbyte(PL_VALLEY2_ELECPRICE,(float *)(&float_22),sizeof(float_22));
      ui->label_g2->setText(QString::number(float_22,'f',2));

      API_Read_DB_Nbyte(PL_TOP1_STARTTM,(float *)(&float_22),sizeof(float_22));
      ftobuf(float_22,buf_22);
      ui->label_t1_1->setText(buf_22);
      API_Read_DB_Nbyte(PL_TOP1_STOPTM,(float *)(&float_22),sizeof(float_22));
      ftobuf(float_22,buf_22);
      ui->label_t1_2->setText(buf_22);
      API_Read_DB_Nbyte(PL_TOP2_STARTTM,(float *)(&float_22),sizeof(float_22));
      ftobuf(float_22,buf_22);
      ui->label_t1_3->setText(buf_22);
      API_Read_DB_Nbyte(PL_TOP2_STOPTM,(float *)(&float_22),sizeof(float_22));
      ftobuf(float_22,buf_22);
      ui->label_t1_4->setText(buf_22);

      API_Read_DB_Nbyte(PL_PEAK1_STARTTM,(float *)(&float_22),sizeof(float_22));
      ftobuf(float_22,buf_22);
      ui->label_p1_1->setText(buf_22);
      API_Read_DB_Nbyte(PL_PEAK1_STOPTM,(float *)(&float_22),sizeof(float_22));
      ftobuf(float_22,buf_22);
      ui->label_p1_2->setText(buf_22);
      API_Read_DB_Nbyte(PL_PEAK2_STARTTM,(float *)(&float_22),sizeof(float_22));
      ftobuf(float_22,buf_22);
      ui->label_p1_3->setText(buf_22);
      API_Read_DB_Nbyte(PL_PEAK2_STOPTM,(float *)(&float_22),sizeof(float_22));
      ftobuf(float_22,buf_22);
      ui->label_p1_4->setText(buf_22);

      API_Read_DB_Nbyte(PL_FLAT1_STARTTM,(float *)(&float_22),sizeof(float_22));
      ftobuf(float_22,buf_22);
      ui->label_f1_1->setText(buf_22);
      API_Read_DB_Nbyte(PL_FLAT1_STOPTM,(float *)(&float_22),sizeof(float_22));
      ftobuf(float_22,buf_22);
      ui->label_f1_2->setText(buf_22);
      API_Read_DB_Nbyte(PL_FLAT2_STARTTM,(float *)(&float_22),sizeof(float_22));
      ftobuf(float_22,buf_22);
      ui->label_f1_3->setText(buf_22);
      API_Read_DB_Nbyte(PL_FLAT2_STOPTM,(float *)(&float_22),sizeof(float_22));
      ftobuf(float_22,buf_22);
      ui->label_f1_4->setText(buf_22);

      API_Read_DB_Nbyte(PL_VALLEY1_STARTTM,(float *)(&float_22),sizeof(float_22));
      ftobuf(float_22,buf_22);
      ui->label_g1_1->setText(buf_22);
      API_Read_DB_Nbyte(PL_VALLEY1_STOPTM,(float *)(&float_22),sizeof(float_22));
      ftobuf(float_22,buf_22);
      ui->label_g1_2->setText(buf_22);
      API_Read_DB_Nbyte(PL_VALLEY2_STARTTM,(float *)(&float_22),sizeof(float_22));
      ftobuf(float_22,buf_22);
      ui->label_g1_3->setText(buf_22);
      API_Read_DB_Nbyte(PL_VALLEY2_STOPTM,(float *)(&float_22),sizeof(float_22));
      ftobuf(float_22,buf_22);
      ui->label_g1_4->setText(buf_22);

}

void p22_ElecPrice_dialog::update_hmi_page_index()
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

void p22_ElecPrice_dialog::exit_page_dlg()
{
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
    timer->stop();
    emit signal_exit_p22dlg();
    delete p22_dlg;
    p22_dlg = NULL;
}
