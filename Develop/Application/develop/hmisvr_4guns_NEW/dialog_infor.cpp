#include "dialog_infor.h"
#include "ui_dialog_infor.h"
#include "globalhmi.h"

Dialog_infor::Dialog_infor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_infor)
{
    ui->setupUi(this);
}

Dialog_infor::~Dialog_infor()
{
    delete ui;
}

void Dialog_infor::on_pushButton_ok_clicked()
{
        hmi_button_dn_num=OK_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),
                           sizeof(hmi_button_dn_num));
}

void Dialog_infor::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
    ui->label_code->setText(phonenum);
        ui->label_code_2->setText(phonenum_2);
}

struct _ChrProcessShow_DataStruct  ChrProcessShow_DataStruct_infor[4];
void Dialog_infor::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));

        int num_ad_show = 0;
        for(num_ad_show;num_ad_show<TOTALBOARD_GUN_NUM;num_ad_show++)
        {
            memset(&ChrProcessShow_DataStruct_infor[num_ad_show],0,sizeof(ChrProcessShow_DataStruct_infor[num_ad_show]));
        }
}

void Dialog_infor::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
}

void Dialog_infor::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void read_process_infor()
{
    int num_ad_show = 0;
    for(num_ad_show=0;num_ad_show<TOTALBOARD_GUN_NUM;num_ad_show++)
    {
        API_Read_DB_Nbyte(PL_STUBISCHARGING_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].stubischarging),sizeof(UINT8));
        API_Read_DB_Nbyte(PL_GETSTARTSOC_FLAG_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].GetStartSoc_Flag),sizeof(UINT8));
        API_Read_DB_Nbyte(PL_STARTSOC_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].Start_Soc),sizeof(UINT8));
        API_Read_DB_Nbyte(PL_TOTALSOC_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].Total_SOC),sizeof(UINT8));
        API_Read_DB_Nbyte(PL_GETSTOPSOC_FLAG_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].GetStopSoc_Flag),sizeof(UINT8));
        API_Read_DB_Nbyte(PL_STOPSOC_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].Stop_SOC),sizeof(UINT8));
        API_Read_DB_Nbyte(PL_CELLTYPE_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].Cell_type),sizeof(UINT8));
        API_Read_DB_Nbyte(PL_HAVESTARTKWH_FLAG_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].HaveStartKWH_Flag),sizeof(UINT8));
        API_Read_DB_Nbyte(PL_USERCHARGESUCESS_FLAG_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].UserCharge_sucess_flag),sizeof(UINT8));
        API_Read_DB_Nbyte(PL_OLDSTUBISCHARGING_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].Oldstubischarging),sizeof(UINT8));
        API_Read_DB_Nbyte(PL_HAVESTARTCHARTM_FLAG_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].HaveStartChrTm_Flag),sizeof(UINT8));
        API_Read_DB_Nbyte(PL_HAVESTOPCHARTM_FLAG_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].HaveStopChrTm_Flag),sizeof(UINT8));
         API_Read_DB_Nbyte(PL_CHARGEGUNLINKSTATE_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].ChargeGunLinkState),sizeof(UINT8));

         API_Read_DB_Nbyte(CHRVOLTMESURVALUE_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].ChrVoltMesurValue),sizeof(FLOAT32));
        API_Read_DB_Nbyte(CHRCURMESURVALUE_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].ChrCurrentMesurValue),sizeof(FLOAT32));
        API_Read_DB_Nbyte(BMS_VOLTNEED_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].BMS_VoltNeed),sizeof(FLOAT32));
        API_Read_DB_Nbyte(BMS_CURNEED_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].BMS_CurrentNeed),sizeof(FLOAT32));
        API_Read_DB_Nbyte(START_KWH_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].Start_KWH),sizeof(FLOAT32));
        API_Read_DB_Nbyte(CURRENT_KWH_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].Current_KWH),sizeof(FLOAT32));
        API_Read_DB_Nbyte(USED_KWH_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].Used_KWH),sizeof(FLOAT32));
        API_Read_DB_Nbyte(STOP_KWH_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].Stop_KWH),sizeof(FLOAT32));
        API_Read_DB_Nbyte(HIGESTSINGLEVOLT_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].Higestsinglevolt),sizeof(FLOAT32));
        API_Read_DB_Nbyte(HIGESTSINGLETEMP_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].HigestsingleTemp),sizeof(FLOAT32));
        API_Read_DB_Nbyte(OUTPUTPOWER_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].OutPutPower),sizeof(FLOAT32));
       API_Read_DB_Nbyte(USERNEEDCHAR_KWH_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].UserNeedChr_KWH),sizeof(FLOAT32));
       API_Read_DB_Nbyte(USERCARD_LEFTMONEY_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].UserCard_LeftMoney),sizeof(FLOAT32));
       API_Read_DB_Nbyte(USERCARD_USEDTOTALMONEY_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].UserCard_UsedTotalMoney),sizeof(FLOAT32));
       API_Read_DB_Nbyte(CHARGESERVICE_MONEY_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].ChargeService_Money),sizeof(FLOAT32));
       API_Read_DB_Nbyte(USEDELECTRIC_MONEY_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].UsedElectric_Money),sizeof(FLOAT32));
       API_Read_DB_Nbyte(CHARGEKWH_FRMNETWORK_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].chargekwh_frmnetwork),sizeof(FLOAT32));

       API_Read_DB_Nbyte(PL_CHRLEFTTM_1+num_ad_show,(UINT16 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].ChrLeftTm),sizeof(UINT16));
       API_Read_DB_Nbyte(PL_CHRUSEDTM_1+num_ad_show,(UINT16 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].ChrUsedTm),sizeof(UINT16));
       API_Read_DB_Nbyte(PL_TOTALAH_1+num_ad_show,(UINT16 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].Total_AH),sizeof(UINT16));

        API_Read_DB_Nbyte(PL_USERNEED_TIME_1+num_ad_show,(UINT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].UserNeed_Time),sizeof(UINT32));
        API_Read_DB_Nbyte(PL_STOPSOCFRMNETWORK_1+num_ad_show,(UINT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].stopsoc_frmnetwork),sizeof(UINT32));
        API_Read_DB_Nbyte(PL_CHARGETIME_FRMNETWORK_1+num_ad_show,(UINT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].chargetime_frmnetwork),sizeof(UINT32));
        API_Read_DB_Nbyte(PL_STARTCHR_TM_1+num_ad_show,(UINT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].StartChargeTm.tv_sec),sizeof(UINT32));
        API_Read_DB_Nbyte(PL_CURCHR_TM_1+num_ad_show,(UINT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].CurrentChargeTm.tv_sec),sizeof(UINT32));
        API_Read_DB_Nbyte(PL_STOPCHR_TM_1+num_ad_show,(UINT32 *)(&ChrProcessShow_DataStruct_infor[num_ad_show].Stopcharge_TM.tv_sec),sizeof(UINT32));
    }
}

void Dialog_infor::update_page_info()
{
    ui->lbl_sysdate->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    ui->lbl_systime->setText(QTime::currentTime().toString("hh:mm:ss"));
      read_process_infor();
      ui->label_num->setText(QString::number(stub_num,'f',0));
      ui->label_volt->setText(QString::number(ChrProcessShow_DataStruct_infor[stub_num-1].ChrVoltMesurValue,'f',1));
      ui->label_current->setText(QString::number(ChrProcessShow_DataStruct_infor[stub_num-1].ChrCurrentMesurValue,'f',1));
      ui->char_time_min->setText(QString::number(ChrProcessShow_DataStruct_infor[stub_num-1].ChrUsedTm,'f',0));
      ui->left_time_min->setText(QString::number(ChrProcessShow_DataStruct_infor[stub_num-1].ChrLeftTm,'f',0));
      ui->label_kwh->setText(QString::number(ChrProcessShow_DataStruct_infor[stub_num-1].Used_KWH,'f',2));
      ui->label_soc->setText(QString::number(ChrProcessShow_DataStruct_infor[stub_num-1].Total_SOC,'f',0));

      if(language_num == 1)
      {
           // ui->label_logo->setText(QString::fromUtf8("直 流 充 电 桩"));
          //  ui->label_title->setText(QString::fromUtf8("余 额 查 询"));
            ui->label_stubnum->setText(QString::fromUtf8(" 客  服  热  线  :"));
          //  ui->pbtn_cancel->setText(QString::fromUtf8("返        回"));
      }
      else  if(language_num == 2)
      {
          //  ui->label_logo->setText("DC charging pile");
           // ui->label_title->setText("Balance Inquire");
            ui->label_stubnum->setText("Pile Number :");
         //   ui->pbtn_cancel->setText("Back");
      }
}

void Dialog_infor::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
    if(hmi_page_index != PAGEINDEX_CHARGE_INFO)
    {
        exit_page_dlg();
    }
    else
    {

    }
}

void Dialog_infor::exit_page_dlg()
{
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
    timer->stop();
    emit signal_exit_dlg_info();
    //delete dlg_infor;
    //dlg_infor = NULL;
}
