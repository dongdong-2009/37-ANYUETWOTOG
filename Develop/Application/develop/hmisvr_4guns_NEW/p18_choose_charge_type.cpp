#include "p18_choose_charge_type.h"
#include "ui_p18_choose_charge_type.h"
#include "globalhmi.h"

p18_choose_charge_type::p18_choose_charge_type(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p18_choose_charge_type)
{
    ui->setupUi(this);
}

p18_choose_charge_type::~p18_choose_charge_type()
{
    delete ui;
}

void p18_choose_charge_type::changeEvent(QEvent *e)
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

void p18_choose_charge_type::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
}

void p18_choose_charge_type::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p18_choose_charge_type::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
}


void p18_choose_charge_type::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p18_choose_charge_type::update_page_info()
{
    //ui->label_passwd->setText(btn_passwd_disp);
      ui->label_phone->setText(phonenum);
       ui->label_code->setText(code);
}

void p18_choose_charge_type::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX_CUR,(INT8 *)(&hmi_page_index_cur),sizeof(hmi_page_index_cur));
    DebugMsg(hmilev,8,"hmi_page_index=[%d]cur[%d]\n",hmi_page_index,hmi_page_index_cur);
    if(hmi_page_index!=hmi_page_index_cur)
    {
        API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX_CUR,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
        if(hmi_page_index==PAGEINDEX_CHOOSE_CHG_TYPE)
        {
                DebugMsg(hmilev,8,"hmi_page_index=[%d]cur[%d]\n",hmi_page_index,hmi_page_index_cur);
        }else
        if(hmi_page_index==PAGEINDEX_SERVICECHOICE)
        {
                call_p02_dlg();
        }else
        if(hmi_page_index==PAGEINDEX_ACCHARGEPROCESS)
        {
                call_p19_dlg();
        }
        else
        {
                ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
                exit(1);
        }
    }
}

void p18_choose_charge_type::call_p02_dlg()
{
    timer->stop();
    if(p02_dlg){
            delete p02_dlg;
            p02_dlg = NULL;
            handle_dlg_p02--;
    }
    p02_dlg = new  p02_servchoose_dialog;
    p02_dlg->setWindowFlags(Qt::FramelessWindowHint);
    handle_dlg_p02++;

    connect(this,SIGNAL(signal_enable_p02dlg_timer()),p02_dlg,SLOT(init_page_dlg()));
    connect(p02_dlg,SIGNAL(signal_exit_p02dlg()),this,SLOT(exit_page_dlg()));
    emit signal_enable_p02dlg_timer();
    p02_dlg->exec();
}

void p18_choose_charge_type::call_p19_dlg()
{
    timer->stop();
    if(p19_dlg){
            delete p19_dlg;
            p19_dlg = NULL;
            handle_dlg_p19--;
    }
    p19_dlg = new  p19_charging_dialog;
    p19_dlg->setWindowFlags(Qt::FramelessWindowHint);
    handle_dlg_p19++;

    connect(this,SIGNAL(signal_enable_p19dlg_timer()),p19_dlg,SLOT(init_page_dlg()));
    connect(p19_dlg,SIGNAL(signal_exit_p19dlg()),this,SLOT(exit_page_dlg()));
    emit signal_enable_p19dlg_timer();
    p19_dlg->exec();
}

void p18_choose_charge_type::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p18dlg();
    delete p18_dlg;
    p18_dlg = NULL;
}

void p18_choose_charge_type::on_pbtn_type_dc_clicked()
{
    UINT8 data = CHOOSE_CHG_TYPE_DC;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p18_choose_charge_type::on_pbtn_type_ac_clicked()
{
    UINT8 data = CHOOSE_CHG_TYPE_AC;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}
