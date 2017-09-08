#include "p02_servchoose_dialog.h"
#include "ui_p02_servchoose_dialog.h"
#include "globalhmi.h"

p02_servchoose_dialog::p02_servchoose_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p02_servchoose_dialog)
{
    ui->setupUi(this);

}

p02_servchoose_dialog::~p02_servchoose_dialog()
{
    delete ui;
}

void p02_servchoose_dialog::changeEvent(QEvent *e)
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

void p02_servchoose_dialog::on_pbtn_charge_clicked()
{
        hmi_button_dn_num=CHOOSE_CHG_TYPE_DC;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),
                           sizeof(hmi_button_dn_num));
}

void p02_servchoose_dialog::on_pbtn_cancel_clicked()
{
        hmi_button_dn_num=CANCEL_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),
                           sizeof(hmi_button_dn_num));
}

void p02_servchoose_dialog::on_pbtn_query_clicked()
{
        hmi_button_dn_num=HISTORYCHECK_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),
                           sizeof(hmi_button_dn_num));
}

void p02_servchoose_dialog::on_pbtn_money_clicked()
{
        hmi_button_dn_num=LEFTMONEY_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),
                           sizeof(hmi_button_dn_num));
}

void p02_servchoose_dialog::on_pbtn_meter_clicked()
{
        hmi_button_dn_num=ELECPRICE_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),
                           sizeof(hmi_button_dn_num));
}
/*
 *
 void p02_servchoose_dialog::on_pbtn_charge_ac_clicked()
{
        hmi_button_dn_num=CHOOSE_CHG_TYPE_AC;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),
                           sizeof(hmi_button_dn_num));
}

void p02_servchoose_dialog::on_pbtn_alarm_query_clicked()
{
        hmi_button_dn_num=ERRORCHECK_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),
                           sizeof(hmi_button_dn_num));
}
*/

void p02_servchoose_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
    ui->label_code->setText(code);
   // ui->label_phone->setText(phonenum);
   // ui->label_phone_2->setText(phonenum_2);
}

void p02_servchoose_dialog::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p02_servchoose_dialog::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
   // init_page_val();
   //  ErrMsg("$$$ come in serve page from history $$$\n");
}

void p02_servchoose_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p02_servchoose_dialog::update_page_info()
{

    //  ui->label_cost->setText(cost);
 //     ui->label_phone->setText(phonenum);
  //   ui->label_code->setText(code);
      if(language_num == 1)
      {
            //ui->label_logo->setText(QString::fromUtf8("直 流 充 电 桩"));
            ui->label_title->setText(QString::fromUtf8("服  务  选  择"));
            ui->label_stubnum->setText(QString::fromUtf8(" 桩   编   号  :"));

            ui->pbtn_cancel->setText(QString::fromUtf8("返        回"));
            ui->pbtn_charge->setText(QString::fromUtf8("充   电   类   型"));
            ui->pbtn_meter->setText(QString::fromUtf8("电   价   查   询"));
            ui->pbtn_money->setText(QString::fromUtf8("余   额   查   询"));
            ui->pbtn_query->setText(QString::fromUtf8("历 史 记 录 查 询"));
      }
      else  if(language_num == 2)
      {
           // ui->label_logo->setText("DC charging pile");
            ui->label_title->setText("Servce  Choose");
            ui->label_stubnum->setText("Pile Number :");

            ui->pbtn_cancel->setText("Back");
            ui->pbtn_charge->setText("ChargeType");
            ui->pbtn_meter->setText("ElectricityPrice");
            ui->pbtn_money->setText("BalanceInquire");
            ui->pbtn_query->setText("HistoryInquire");
      }

      char cost[25]={};
      memset(cost,0,sizeof(cost));
      float max_temp=0;
      float fcost=0;
      Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
      Inibuf_init(Key_name,BUFFERLEN_32,"electricityprice");
      fcost= read_profile_float(Section_name, Key_name,max_temp,config_path);
      sprintf(cost,"%0.2f",fcost);

}

void p02_servchoose_dialog::update_hmi_page_index()
{
        API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
        if(hmi_page_index != PAGEINDEX_SERVICECHOICE)
        {
            exit_page_dlg();
        }
        else
        {

        }
}
/*
void p02_servchoose_dialog::call_dlg_1()
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
void p02_servchoose_dialog::call_p03_dlg()
{
    timer->stop();
    if(p03_dlg){
            delete p03_dlg;
            p03_dlg = NULL;
    }
    p03_dlg = new  p03_historyquery_dialog;
    p03_dlg->setWindowFlags(Qt::FramelessWindowHint);
    connect(this,SIGNAL(signal_enable_p03dlg_timer()),p03_dlg,SLOT(init_page_dlg()));
    connect(p03_dlg,SIGNAL(signal_exit_p03dlg()),this,SLOT(start_timer()));
    emit signal_enable_p03dlg_timer();
    p03_dlg->exec();
}

void p02_servchoose_dialog::call_p19_dlg()
{
    timer->stop();
    if(p19_dlg){
            delete p19_dlg;
            p19_dlg = NULL;
    }
    p19_dlg = new  p19_charging_dialog;
    p19_dlg->setWindowFlags(Qt::FramelessWindowHint);
    connect(this,SIGNAL(signal_enable_p19dlg_timer()),p19_dlg,SLOT(init_page_dlg()));
    connect(p19_dlg,SIGNAL(signal_exit_p19dlg()),this,SLOT(exit_page_dlg()));
    emit signal_enable_p19dlg_timer();
    p19_dlg->exec();
}

void p02_servchoose_dialog::call_p05_dlg()
{
    timer->stop();
    if(p05_dlg){
            delete p05_dlg;
            p05_dlg = NULL;
            handle_dlg_p05--;
    }
    p05_dlg = new  p05_chargelink_dialog;
    p05_dlg->setWindowFlags(Qt::FramelessWindowHint);
    handle_dlg_p05++;

    connect(this,SIGNAL(signal_enable_p05dlg_timer()),p05_dlg,SLOT(init_page_dlg()));
    connect(p05_dlg,SIGNAL(signal_exit_p05dlg()),this,SLOT(exit_page_dlg()));
    emit signal_enable_p05dlg_timer();
    p05_dlg->exec();
}

void p02_servchoose_dialog::call_p21_dlg()
{
    timer->stop();
    if(p21_dlg){
            delete p21_dlg;
            p21_dlg = NULL;
    }
    p21_dlg = new  p21_leftmoney_dialog;
    p21_dlg->setWindowFlags(Qt::FramelessWindowHint);
    connect(this,SIGNAL(signal_enable_p21dlg_timer()),p21_dlg,SLOT(init_page_dlg()));
    connect(p21_dlg,SIGNAL(signal_exit_p21dlg()),this,SLOT(start_timer()));
    emit signal_enable_p21dlg_timer();
    p21_dlg->exec();
}

void p02_servchoose_dialog::call_p22_dlg()
{
    timer->stop();
    if(p22_dlg){
            delete p22_dlg;
            p22_dlg = NULL;
    }
    p22_dlg = new  p22_ElecPrice_dialog;
    p22_dlg->setWindowFlags(Qt::FramelessWindowHint);
    connect(this,SIGNAL(signal_enable_p22dlg_timer()),p22_dlg,SLOT(init_page_dlg()));
    connect(p22_dlg,SIGNAL(signal_exit_p22dlg()),this,SLOT(start_timer()));
    emit signal_enable_p22dlg_timer();
    p22_dlg->exec();
}

void p02_servchoose_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p02dlg();
    //delete p02_dlg;
    //p02_dlg = NULL;
}




