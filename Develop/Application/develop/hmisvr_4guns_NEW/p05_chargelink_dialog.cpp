#include "p05_chargelink_dialog.h"
#include "ui_p05_chargelink_dialog.h"
#include "globalhmi.h"

p05_chargelink_dialog::p05_chargelink_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p05_chargelink_dialog)
{
    ui->setupUi(this);
}

p05_chargelink_dialog::~p05_chargelink_dialog()
{
    delete ui;
}

void p05_chargelink_dialog::changeEvent(QEvent *e)
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

void p05_chargelink_dialog::on_pushButton_14_clicked()
{
    hmi_button_dn_num=CANCEL_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),
                       sizeof(hmi_button_dn_num));
}


void p05_chargelink_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
    ui->label_code->setText(code);
   // ui->label_phone->setText(phonenum);
    //ui->label_phone_2->setText(phonenum_2);
}

BOOL chrg_flg;
static int add_num;
static int Timer;

void p05_chargelink_dialog::init_page_val()
{
        add_num=0;
        Timer=180;
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p05_chargelink_dialog::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
}


void p05_chargelink_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

int num_move_5 = 0;
int move_flag_5 = 0;
void p05_chargelink_dialog::update_page_info()
{
    add_num++;
    if(add_num==30)
    {
        add_num=0;
        Timer--;
        if(Timer<=0)
        {
            hmi_button_dn_num=CANCEL_BUTTON;
            API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),
                               sizeof(hmi_button_dn_num));
        }
    }

    ui->lbl_time->setText(QString::number(Timer,'f',0));
    if(language_num == 1)
    {
         //ui->label_logo->setText(QString::fromUtf8("直 流 充 电 桩"));
          ui->label_stubnum->setText(QString::fromUtf8(" 桩   编   号  :"));
          ui->pushButton_14->setText(QString::fromUtf8("返       回"));
        ui->label_11->setText(QString::fromUtf8("正在检查连接状态..."));
        API_Read_DB_Nbyte(PL_CHRGUNLINKERR_FLAG,(BOOL *)(&chrg_flg),sizeof(chrg_flg));
        if(chrg_flg)
        {
            ui->label_11->setText(QString::fromUtf8("充电枪连接出错,请拔枪重试!"));
        }
    }
    else if(language_num == 2)
    {
         // ui->label_logo->setText("DC charging pile");
          ui->label_stubnum->setText("Pile Number :");
          ui->pushButton_14->setText("Back");
        ui->label_11->setText(QString::fromUtf8("Checking the connection status ..."));
        API_Read_DB_Nbyte(PL_CHRGUNLINKERR_FLAG,(BOOL *)(&chrg_flg),sizeof(chrg_flg));
        if(chrg_flg)
        {
            ui->label_11->setText(QString::fromUtf8("Connect error,try again !"));
        }
    }
    num_move_5++;
    if(num_move_5 == 40)
    {
        num_move_5 = 0;
        move_flag_5 ++;
        ui->label->move(400,250);
    }

    if(move_flag_5 == 2)
    {
        move_flag_5 = 0;
        ui->label->move(450,210);
    }
}

void p05_chargelink_dialog::update_hmi_page_index()
{
        API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
        if(hmi_page_index != PAGEINDEX_CHARGELINK)
        {
            exit_page_dlg();
        }
        else
        {

        }
}
/*
void p05_chargelink_dialog::call_p07_dlg()
{
    timer->stop();
    if(p07_dlg){
            delete p07_dlg;
            p07_dlg = NULL;
            handle_dlg_p07--;
    }
    p07_dlg = new  p07_chargetypechoose_dialog;
    p07_dlg->setWindowFlags(Qt::FramelessWindowHint);
    handle_dlg_p07++;

    connect(this,SIGNAL(signal_enable_p07dlg_timer()),p07_dlg,SLOT(init_page_dlg()));
    connect(p07_dlg,SIGNAL(signal_exit_p07dlg()),this,SLOT(exit_page_dlg()));
    emit signal_enable_p07dlg_timer();
    p07_dlg->exec();

}
*/
void p05_chargelink_dialog::call_p06_dlg()
{
    timer->stop();
    if(p06_dlg){
            delete p06_dlg;
            p06_dlg = NULL;
            handle_dlg_p06--;
    }
    p06_dlg = new  p06_chargeconfigrm_dialog;
    p06_dlg->setWindowFlags(Qt::FramelessWindowHint);
    handle_dlg_p06++;

    connect(this,SIGNAL(signal_enable_p06dlg_timer()),p06_dlg,SLOT(init_page_dlg()));
    connect(p06_dlg,SIGNAL(signal_exit_p06dlg()),this,SLOT(exit_page_dlg()));
    emit signal_enable_p06dlg_timer();
    p06_dlg->exec();

}

/*
void p05_chargelink_dialog::call_dlg_1()
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
void p05_chargelink_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p05dlg();
    //delete p05_dlg;
    //p05_dlg = NULL;
}
