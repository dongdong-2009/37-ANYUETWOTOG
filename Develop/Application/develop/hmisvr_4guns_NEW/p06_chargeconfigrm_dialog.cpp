#include "p06_chargeconfigrm_dialog.h"
#include "ui_p06_chargeconfigrm_dialog.h"
#include "globalhmi.h"

p06_chargeconfigrm_dialog::p06_chargeconfigrm_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p06_chargeconfigrm_dialog)
{
    ui->setupUi(this);
}

p06_chargeconfigrm_dialog::~p06_chargeconfigrm_dialog()
{
    delete ui;
}

void p06_chargeconfigrm_dialog::changeEvent(QEvent *e)
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

void p06_chargeconfigrm_dialog::on_pbtn_num1_clicked()
{

}

void p06_chargeconfigrm_dialog::on_pbtn_num2_clicked()
{

}

void p06_chargeconfigrm_dialog::on_pbtn_num3_clicked()
{

}

void p06_chargeconfigrm_dialog::on_pbtn_num4_clicked()
{

}


void p06_chargeconfigrm_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
   ui->label_code->setText(code);
  //  ui->label_phone->setText(phonenum);
 //   ui->label_phone_2->setText(phonenum_2);
}


void p06_chargeconfigrm_dialog::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void p06_chargeconfigrm_dialog::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
}


void p06_chargeconfigrm_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p06_chargeconfigrm_dialog::update_page_info()
{
    ui->label_code->setText(code);
    if(language_num == 1)
    {
          //ui->label_logo->setText(QString::fromUtf8("直 流 充 电 桩"));
      //    ui->label_speaker->setText(QString::fromUtf8("充 电 枪 已 连 接 !"));
          ui->label_title_2->setText(QString::fromUtf8("连 接 确 认"));
          ui->label_stubnum->setText(QString::fromUtf8(" 桩   编   号  :"));
        //  ui->pbtn_cancel->setText(QString::fromUtf8("返  回"));
        //  ui->pbtn_enter->setText(QString::fromUtf8("确  认"));
    }
    else  if(language_num == 2)
    {
       //   ui->label_logo->setText("DC charging pile");
       //   ui->label_speaker->setText("The charging gun has linked!");
          ui->label_title_2->setText("Charge sure");
          ui->label_stubnum->setText("Pile Number :");
      //   ui->pbtn_cancel->setText("Cancel");
        //  ui->pbtn_enter->setText("OK");
    }
   //   ui->label_phone->setText(phonenum);
   // FLOAT32 banlance = 0;
  //  API_Read_DB_Nbyte(PL_MAINCARD_LEFTMONEY,(INT8 *)(&banlance),sizeof(banlance));
  //  ui->lbl_left_banlance->setText(QString::number(banlance,'f',2));
}

void p06_chargeconfigrm_dialog::update_hmi_page_index()
{
        API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
        if(hmi_page_index != PAGEINDEX_CHARGESURE)
        {
            exit_page_dlg();
        }
        else
        {

        }
}
/*
void p06_chargeconfigrm_dialog::call_dlg_1()
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
void p06_chargeconfigrm_dialog::call_p07_dlg()
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

void p06_chargeconfigrm_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p06dlg();
    //delete p06_dlg;
    //p06_dlg = NULL;
}
