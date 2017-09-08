#include "p10_chargebyauto_dialog.h"
#include "ui_p10_chargebyauto_dialog.h"
#include "globalhmi.h"

p10_chargebyauto_dialog::p10_chargebyauto_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p10_chargebyauto_dialog)
{
    ui->setupUi(this);
}

p10_chargebyauto_dialog::~p10_chargebyauto_dialog()
{
    delete ui;
}

void p10_chargebyauto_dialog::changeEvent(QEvent *e)
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

void p10_chargebyauto_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
}

void p10_chargebyauto_dialog::init_page_val()
{
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p10_chargebyauto_dialog::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
}


void p10_chargebyauto_dialog::timer_handle()
{
    update_page_info();
    update_hmi_page_index();
}

void p10_chargebyauto_dialog::update_page_info()
{
    //ui->label_passwd->setText(btn_passwd_disp);
}

void p10_chargebyauto_dialog::update_hmi_page_index()
{


}

void p10_chargebyauto_dialog::call_p11_dlg()
{
    timer->stop();
    if(p11_dlg){
            delete p11_dlg;
            p11_dlg = NULL;
            handle_dlg_p11--;
    }
    p11_dlg = new  p11_charging_dialog;
    p11_dlg->setWindowFlags(Qt::FramelessWindowHint);
    handle_dlg_p11++;

    connect(this,SIGNAL(signal_enable_p11dlg_timer()),p11_dlg,SLOT(init_page_dlg()));
    connect(p11_dlg,SIGNAL(signal_exit_p11dlg()),this,SLOT(exit_page_dlg()));
    emit signal_enable_p11dlg_timer();
    p11_dlg->exec();
}


void p10_chargebyauto_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p10dlg();
    delete p10_dlg;
    p10_dlg = NULL;
}
