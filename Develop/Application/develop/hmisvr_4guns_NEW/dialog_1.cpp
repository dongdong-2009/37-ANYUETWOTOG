#include "dialog_1.h"
#include "ui_dialog_1.h"
#include "globalhmi.h"

dialog_1::dialog_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_1)
{
    ui->setupUi(this);
}

dialog_1::~dialog_1()
{
    delete ui;
}

void dialog_1::changeEvent(QEvent *e)
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

void dialog_1::init_page_dlg()
{
    init_page_val();
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);

    ui->label_code->setText(code);
    ui->label_phone->setText(phonenum);
    ui->label_phone_2->setText(phonenum_2);
}

int add_numb;
int Timer;
BOOL timer_flg;

void dialog_1::init_page_val()
{
    timer_flg=FALSE;
    //Timer=80;
    Timer=15;
    add_numb=0;
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void dialog_1::timer_handle()
{
    UINT8 data=0;
    API_Read_DB_Nbyte(PL_CHRGUNLINKSTATE_FLAG,(UINT8 *)(&data),sizeof(data));

    if(data==0)
    {
        timer_flg=TRUE;
    }

    if(timer_flg)
    {
        ui->label_timer->setText(QString::number(Timer,'f',0));
        ui->label_timer_2->setText(QString::fromUtf8("秒"));
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
            hmi_button_dn_num=OK_BUTTON;
            API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
        }
    }

 // ui->label->setText(QString::fromUtf8("请将充电枪归位!"));
    update_hmi_page_index();
}

void dialog_1::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    timer->stop();
    emit signal_exit_dlg_1();
    delete dlg_1;
    dlg_1 = NULL;
}

void dialog_1::update_hmi_page_index()
{


    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX_CUR,(INT8 *)(&hmi_page_index_cur),sizeof(hmi_page_index_cur));
    DebugMsg(hmilev,8,"hmi_page_index=[%d]cur[%d]\n",hmi_page_index,hmi_page_index_cur);
    if(hmi_page_index!=hmi_page_index_cur)
    {
        API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX_CUR,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
        if(hmi_page_index==PAGEINDEX_MAIN)
        {
            exit_page_dlg();
        }
        /*
        else
        if(hmi_page_index==PAGEINDEX_PAYOFF)
        {
            call_p12_dlg();
        }

        else
        if(hmi_page_index==PAGEINDEX_ACPAYOFF)
        {
            call_p20_dlg();
        }
        */
    }
}
/*
void dialog_1::call_p12_dlg()
{
    timer->stop();
    if(p12_dlg){
            delete p12_dlg;
            p12_dlg = NULL;
            handle_dlg_p12--;
    }
    p12_dlg = new  p12_payoff_dialog;
    p12_dlg->setWindowFlags(Qt::FramelessWindowHint);
    handle_dlg_p12++;

    connect(this,SIGNAL(signal_enable_p12dlg_timer()),p12_dlg,SLOT(init_page_dlg()));
    connect(p12_dlg,SIGNAL(signal_exit_p12dlg()),this,SLOT(exit_page_dlg()));
    emit signal_enable_p12dlg_timer();
    p12_dlg->exec();
}

void dialog_1::call_p20_dlg()
{
    timer->stop();
    if(p20_dlg){
            delete p20_dlg;
            p20_dlg = NULL;
            handle_dlg_p20--;
    }
    p20_dlg = new  p20_payoff_dialog;
    p20_dlg->setWindowFlags(Qt::FramelessWindowHint);
    handle_dlg_p20++;

    connect(this,SIGNAL(signal_enable_p20dlg_timer()),p20_dlg,SLOT(init_page_dlg()));
    connect(p20_dlg,SIGNAL(signal_exit_p20dlg()),this,SLOT(exit_page_dlg()));
    emit signal_enable_p20dlg_timer();
    p20_dlg->exec();

}
*/
void dialog_1::on_pushButton_ok_clicked()
{
    timer_flg=TRUE;
}
