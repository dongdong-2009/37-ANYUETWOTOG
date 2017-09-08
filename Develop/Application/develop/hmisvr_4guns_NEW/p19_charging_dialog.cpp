#include "p19_charging_dialog.h"
#include "ui_p19_charging_dialog.h"
#include "globalhmi.h"

#define DEF_SUPPORT_FLUSH_PIC

p19_charging_dialog::p19_charging_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p19_charging_dialog)
{
    ui->setupUi(this);
}

p19_charging_dialog::~p19_charging_dialog()
{
    delete ui;
}

void p19_charging_dialog::changeEvent(QEvent *e)
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

void p19_charging_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(2000);

  /* timer1 = new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(timer1_handle()));
#ifdef DEF_SUPPORT_FLUSH_PIC
    timer1->start(3000);
#endif
    */
    init_page_val();
}

void p19_charging_dialog::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));

        FLOAT32 f32_data = 0;
        UINT16 u16_data=0;
        UINT8 tempvalue=0;
        API_Read_DB_Nbyte(PL_CARDPROMPT_FLAG,(char*)&tempvalue,sizeof(tempvalue));
        ui->label_10->setText(QString::fromUtf8("如需结束本次充电,请刷卡!"));
        if(tempvalue)
        {
            ui->label_10->setText(QString::fromUtf8("刷卡不正确,请刷本次提供服务的加电卡!"));
        }

        API_Read_DB_Nbyte(PL_CHRTOTALUSE_TIME,(INT8 *)(&u16_data),sizeof(u16_data));
        ui->lbl_time_hour->setText(QString::number(u16_data/60,'f',0));
        ui->lbl_time_min->setText(QString::number(u16_data%60,'f',0));

        API_Read_DB_Nbyte(PL_CHROUTPT_VOLT,(INT8 *)(&f32_data),sizeof(f32_data));
        ui->lbl_output_voltage->setText(QString::number(f32_data,'f',1));

        API_Read_DB_Nbyte(PL_CHROUTPT_CURRENT,(INT8 *)(&f32_data),sizeof(f32_data));
        ui->lbl_ouput_current->setText(QString::number(f32_data,'f',1));

        API_Read_DB_Nbyte(PL_CHRUSED_KWH,(INT8 *)(&f32_data),sizeof(f32_data));
        ui->lbl_caculate_energy->setText(QString::number(f32_data,'f',2));
     //   s_pic_count=PIC_MIN_COUNT;
        update_page_info();
        ui->label_code->setText(code);
        ui->label_phone->setText(phonenum);
        ui->label_phone_2->setText(phonenum_2);
}

void p19_charging_dialog::start_timer()
{
    timer->start(2000);
    /*
#ifdef  DEF_SUPPORT_FLUSH_PIC
    timer1->start(3000);
#endif
    */
}


void p19_charging_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p19_charging_dialog::update_page_info()
{
 //   ui->label_phone->setText(phonenum);
 //    ui->label_code->setText(code);
 //   UINT16 u16_data = 0;
    FLOAT32 f32_data = 0;
    UINT16 u16_data=0;
    UINT8 tempvalue=0;
    API_Read_DB_Nbyte(PL_CARDPROMPT_FLAG,(char*)&tempvalue,sizeof(tempvalue));
    ui->label_10->setText(QString::fromUtf8("如需结束本次充电,请刷卡!"));
    if(tempvalue)
    {
        ui->label_10->setText(QString::fromUtf8("刷卡不正确,请刷本次提供服务的加电卡!"));
    }

    API_Read_DB_Nbyte(PL_CHRTOTALUSE_TIME,(INT8 *)(&u16_data),sizeof(u16_data));
    ui->lbl_time_hour->setText(QString::number(u16_data/60,'f',0));
    ui->lbl_time_min->setText(QString::number(u16_data%60,'f',0));


    API_Read_DB_Nbyte(PL_CHROUTPT_VOLT,(INT8 *)(&f32_data),sizeof(f32_data));

   // ErrMsg("$$$$VOLT=[%f]\n",f32_data);

    ui->lbl_output_voltage->setText(QString::number(f32_data,'f',1));

    API_Read_DB_Nbyte(PL_CHROUTPT_CURRENT,(INT8 *)(&f32_data),sizeof(f32_data));

   // ErrMsg("$$$$Current=[%f]\n",f32_data);

    ui->lbl_ouput_current->setText(QString::number(f32_data,'f',1));

    API_Read_DB_Nbyte(PL_CHRUSED_KWH,(INT8 *)(&f32_data),sizeof(f32_data));
    ui->lbl_caculate_energy->setText(QString::number(f32_data,'f',2));

    /*
    API_Read_DB_Nbyte(PL_CHR_STATE,(INT8 *)(&u16_data),sizeof(u16_data));
    if(u16_data==CUR_CHG_STAT_CHARGING)
    {
        ui->lbl_chg_cur_stat->setText(QString::fromUtf8("充电中"));

    }else
    if(u16_data==CUR_CHG_STAT_STOP)
    {
        ui->lbl_chg_cur_stat->setText(QString::fromUtf8("充电结束"));
    }else{
        ui->lbl_chg_cur_stat->setText(QString::fromUtf8("充电出错"));
    }

    API_Read_DB_Nbyte(PL_CHRSTART_KWH,(INT8 *)(&f32_data),sizeof(f32_data));
    ui->lbl_init_energy->setText(QString::number(f32_data,'f',2));

    API_Read_DB_Nbyte(PL_CHRCURRRENT_KWH,(INT8 *)(&f32_data),sizeof(f32_data));
    ui->lbl_current_energy->setText(QString::number(f32_data,'f',2));
*/
}

void p19_charging_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX_CUR,(INT8 *)(&hmi_page_index_cur),sizeof(hmi_page_index_cur));
    DebugMsg(hmilev,8,"hmi_page_index=[%d]cur[%d]\n",hmi_page_index,hmi_page_index_cur);
    if(hmi_page_index!=hmi_page_index_cur)
    {
        API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX_CUR,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
        if(hmi_page_index==PAGEINDEX_ACCHARGEPROCESS)
        {
                DebugMsg(hmilev,8,"hmi_page_index=[%d]cur[%d]\n",hmi_page_index,hmi_page_index_cur);
        }else
        if(hmi_page_index==PAGEINDEX_PASSWD_TWO)
        {
                call_dlg_2();
        }
        else
        if(hmi_page_index==PAGEINDEX_ACPAYOFF)
        {
            call_p20_dlg();
        }
        /*
        else
        if(hmi_page_index==PAGEINDEX_LITTLEWINDOW_ONE)
        {
                call_dlg_1();
        }
        */
        else
        {
                ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
                exit(1);
        }
    }
}

void p19_charging_dialog::call_p20_dlg()
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

/*
void p19_charging_dialog::call_dlg_1()
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
void p19_charging_dialog::call_dlg_2()
{
    timer->stop();
    if(dlg_2){
            delete dlg_2;
            dlg_2 = NULL;
    }
    dlg_2 = new  dialog_2;
    dlg_2->setWindowFlags(Qt::FramelessWindowHint);

    connect(this,SIGNAL(signal_enable_dlg_2_timer()),dlg_2,SLOT(init_page_dlg()));
    connect(dlg_2,SIGNAL(signal_exit_dlg_2()),this,SLOT(exit_page_dlg()));
    connect(dlg_2,SIGNAL(signal_timer_dlg_2()),this,SLOT(start_timer()));
    emit signal_enable_dlg_2_timer();
    dlg_2->exec();
}

void p19_charging_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p19dlg();
    delete p19_dlg;
    p19_dlg = NULL;
}

