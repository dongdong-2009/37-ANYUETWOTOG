 #include "p11_charging_dialog.h"
#include "ui_p11_charging_dialog.h"
#include "globalhmi.h"

#define DEF_SUPPORT_FLUSH_PIC

p11_charging_dialog::p11_charging_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p11_charging_dialog)
{
    ui->setupUi(this);
}

p11_charging_dialog::~p11_charging_dialog()
{
    delete ui;
}

void p11_charging_dialog::changeEvent(QEvent *e)
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


void p11_charging_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(3000);
    ui->label_code->setText(code);
    //ui->label_phone->setText(phonenum);
   // ui->label_phone_2->setText(phonenum_2);
/*
    timer1 = new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(timer1_handle()));
#ifdef DEF_SUPPORT_FLUSH_PIC
    timer1->start(3000);
#endif
*/
    init_page_val();
}

void p11_charging_dialog::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
        s_pic_count=PIC_MIN_COUNT;
        update_page_info();


}

void p11_charging_dialog::start_timer()
{
    timer->start(3000);
    /*
#ifdef  DEF_SUPPORT_FLUSH_PIC
    timer1->start(3000);
#endif
*/
}


void p11_charging_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}
/*
int p11_charging_dialog::caculate_pic_count(int soc)
{
    int div = (int)(100/(PIC_MAX_COUNT-PIC_MIN_COUNT))+1;
    if(soc<0||soc>100)
    {
        printf("ErrMsg:current soc(%d) error!\n",soc);
        return -1;
    }
    if(soc==100)
    {
        return PIC_MAX_COUNT;
    }else{
        return (soc/div)+PIC_MIN_COUNT;
    }
    return 0;
}

void p11_charging_dialog::timer1_handle()
{
    INT8 charg_pic[256]={0};
    UINT16 u16_data = 0;
    memset(charg_pic,0,sizeof(charg_pic));
    if(s_pic_count>=PIC_MAX_COUNT-1)
    {
        s_pic_count=PIC_MIN_COUNT;
    }
    else{
        s_pic_count++;
    }
    //printf("p11:s_pic_count=%d\n",s_pic_count);
    API_Read_DB_Nbyte(PL_CHR_STATE,(INT8 *)(&u16_data),sizeof(u16_data));
    if(u16_data==CUR_CHG_STAT_CHARGING)
    {
        sprintf(charg_pic,"border-image: url(:/bat-h/qrc/battery-h/BatteryBG_%d.png);",s_pic_count);
        ui->lbl_pic_battery->setStyleSheet(charg_pic);
    }else{
        API_Read_DB_Nbyte(PL_CHR_CURRENTSOC,(INT8 *)(&u16_data),sizeof(u16_data));
        s_pic_count = caculate_pic_count(u16_data);
        sprintf(charg_pic,"border-image: url(:/bat-h/qrc/battery-h/BatteryBG_%d.png);",s_pic_count);
        ui->lbl_pic_battery->setStyleSheet(charg_pic);
    }
}
*/
/*
void p11_charging_dialog::timer1_handle()
{

    UINT16 u16_data = 0;
    UINT16 u_data =0;
    API_Read_DB_Nbyte(PL_CHR_CURRENTSOC,(INT8 *)(&u16_data),sizeof(u16_data));

    INT8 charg_pic[256]={0};
    memset(charg_pic,0,sizeof(charg_pic));

    switch((int)u16_data/10)
    {
        case 0:
                s_pic_count=1;
                break;
        case 1:
                s_pic_count=2;
                break;
        case 2:
                s_pic_count=3;
                break;
        case 3:
                s_pic_count=4;
                break;
        case 4:
                s_pic_count=5;
                break;
        case 5:
                s_pic_count=6;
                break;
        case 6:
                s_pic_count=7;
                break;
        case 7:
                s_pic_count=8;
                break;
        case 8:
                s_pic_count=9;
                break;
        case 9:

                API_Read_DB_Nbyte(PL_CHR_STATE,(INT8 *)(&u_data),sizeof(u_data));
                if(u_data==CUR_CHG_STAT_STOP)
                {
                    s_pic_count=11;
                }
                else
                {
                   s_pic_count=10;
                }
                break;
        case 10:
                s_pic_count=11;
                break;
        default:
                break;
    }

    sprintf(charg_pic,"border-image: url(:/bat-h/qrc/  ui->label_phone->setText(phonenum);
     ui->label_code->setText(code);battery-h/BatteryBG_%d.png);",s_pic_count);
    ui->lbl_pic_battery->setStyleSheet(charg_pic);
}
*/

void p11_charging_dialog::update_page_info()
{
    UINT16 u16_data = 0;
    FLOAT32 f32_data = 0;
    UINT8  tempvalue = 0;
   // ui->label_phone->setText(phonenum);
    ui->label_code->setText(code);
    if(language_num == 1)
    {
          //ui->label_logo->setText(QString::fromUtf8("直 流 充 电 桩"));
         // ui->label_title_2->setText(QString::fromUtf8("充  电  中"));
          ui->label_stubnum->setText(QString::fromUtf8(" 桩   编   号  :"));

          ui->label_time->setText(QString::fromUtf8("充电时间:"));
          ui->label_energy->setText(QString::fromUtf8("消耗电量:"));
          ui->label_volt->setText(QString::fromUtf8("输出电压:"));
          ui->label_current->setText(QString::fromUtf8("输出电流:"));
          ui->label_soc->setText(QString::fromUtf8("当前SOC:"));
          ui->label_lefttime->setText(QString::fromUtf8("预计剩余时间:"));
          ui->label_state->setText(QString::fromUtf8("工作状态:"));
          ui->label_state_2->setText(QString::fromUtf8("设备状态:"));
          ui->label_highvlot->setText(QString::fromUtf8("最高单体电压:"));
          ui->label_lowvolt->setText(QString::fromUtf8("最低单体电压:"));
          ui->label_hightemp->setText(QString::fromUtf8("最高单体温度:"));
          ui->label_moudletemp->setText(QString::fromUtf8("模块最高温度:"));
     //     ui->label_equipment->setText(QString::fromUtf8(":"));

          API_Read_DB_Nbyte(PL_CARDPROMPT_FLAG,(char*)&tempvalue,sizeof(tempvalue));
          ui->label_title_2->setText(QString::fromUtf8("如需结束本次充电,请刷卡!"));
          if(tempvalue)
          {
              ui->label_title_2->setText(QString::fromUtf8("刷卡不正确,请刷本次提供服务的加电卡!"));
          }
    }
    else  if(language_num == 2)
    {
      //  ui->label_logo->setText("DC charging pile");
    //    ui->label_title_2->setText("Charge process");
        ui->label_stubnum->setText("Pile Number :");

        ui->label_time->setText("Charge Time:");
        ui->label_energy->setText("Energy consumption :");
        ui->label_volt->setText("Output Volt:");
        ui->label_current->setText("Output Current:");
        ui->label_soc->setText("Current SOC:");
        ui->label_lefttime->setText("Estimated time remaining:");
        ui->label_state->setText("Work State:");
        ui->label_state_2->setText("Equipment State:");
        ui->label_highvlot->setText("Highest signal volt:");
        ui->label_lowvolt->setText("Lowest signal volt:");
        ui->label_hightemp->setText("Highest signal temperature:");
        ui->label_moudletemp->setText("Highest moudlel temperature:");
      //  ui->label_equipment->setText("Equipment State:");

        API_Read_DB_Nbyte(PL_CARDPROMPT_FLAG,(char*)&tempvalue,sizeof(tempvalue));
         ui->label_title_2->setText("Please swipe the same card if you wan to stop charging!");
        if(tempvalue)
        {
            ui->label_title_2->setText("Should swipe the same card you charge!");
        }

    }

    API_Read_DB_Nbyte(PL_SINGLE_HIGHVOLT,(FLOAT32 *)(&f32_data),sizeof(f32_data));
    ui->lbl_h_volt->setText(QString::number(f32_data,'f',1));

    API_Read_DB_Nbyte(PL_SINGLE_LOWVOLT,(FLOAT32 *)(&f32_data),sizeof(f32_data));
    ui->lbl_l_volt->setText(QString::number(f32_data,'f',1));

    API_Read_DB_Nbyte(PL_HIGESTCELL_TEMP,(FLOAT32 *)(&f32_data),sizeof(f32_data));
    ui->lbl_h_temp->setText(QString::number(f32_data,'f',1));

    API_Read_DB_Nbyte(PL_MODULE_HIGH_TEMP,(FLOAT32 *)(&f32_data),sizeof(f32_data));
    ui->lbl_h_moudle->setText(QString::number(f32_data,'f',1));


    API_Read_DB_Nbyte(PL_CHRTOTALUSE_TIME,(INT8 *)(&u16_data),sizeof(u16_data));
    ui->lbl_time_hour->setText(QString::number(u16_data/60,'f',0));
    ui->lbl_time_min->setText(QString::number(u16_data%60,'f',0));

    API_Read_DB_Nbyte(PL_CHROUTPT_VOLT,(FLOAT32 *)(&f32_data),sizeof(f32_data));
    ui->lbl_output_voltage->setText(QString::number(f32_data,'f',1));

    API_Read_DB_Nbyte(PL_CHROUTPT_CURRENT,(FLOAT32 *)(&f32_data),sizeof(f32_data));
    ui->lbl_ouput_current->setText(QString::number(f32_data,'f',1));

    //ui->lbl_ouput_current->setText(QString::number(30.2,'f',1));

    /*
    if((f32_data+(float)1.5)<30){
         ui->lbl_ouput_current->setText(QString::number((f32_data+(float)1.5),'f',1));
    }
    else if((f32_data+(float)1.5)>=30){
         ui->lbl_ouput_current->setText(QString::number(30,'f',1));
    }
    */

    API_Read_DB_Nbyte(PL_CHR_STATE,(UINT8 *)(&u16_data),sizeof(u16_data));

    if(u16_data==CUR_CHG_STAT_CHARGING)
    {
        ui->lbl_chg_cur_stat->setText(QString::fromUtf8("充 电 中"));

    }else
    if(u16_data==CUR_CHG_STAT_STOP)
    {
        ui->lbl_chg_cur_stat->setText(QString::fromUtf8("充 电 结 束"));
    }else
    if(u16_data==3)
    {
        ui->lbl_chg_cur_stat->setText(QString::fromUtf8("充电准备中"));
    }else{
        ui->lbl_chg_cur_stat->setText(QString::fromUtf8("充 电 出 错"));
    }


    API_Read_DB_Nbyte(PL_CHRERROR_STATE,(char*)&tempvalue,sizeof(tempvalue));


    switch(tempvalue)
    {
        case 0:
        ui->label_14->setText(QString::fromUtf8("良好!"));
        break;
        case 1:
        ui->label_14->setText(QString::fromUtf8("接受 SPN2560=0x00 的充电机辨识报文超时!"));
        break;
    case 2:
        ui->label_14->setText(QString::fromUtf8("接受 SPN2560=0xAA 的充电机辨识报文超时!"));
        break;
    case 3:
        ui->label_14->setText(QString::fromUtf8("接受充电机的时间同步和充电机最大输出能力报文超时!"));
        break;
    case 4:
        ui->label_14->setText(QString::fromUtf8("接受充电机完成充电准备报文超时!"));
        break;
    case 5:
        ui->label_14->setText(QString::fromUtf8("接受充电机充电状态报文超时!"));
        break;
    case 6:
        ui->label_14->setText(QString::fromUtf8("接受充电机中止充电报文超时!"));
        break;
    case 7:
        ui->label_14->setText(QString::fromUtf8("接受充电机充电统计报文超时!"));
        break;
    case 8:
        ui->label_14->setText(QString::fromUtf8("接受BMS和车辆的辨识报文超时!"));
        break;
    case 9:
        ui->label_14->setText(QString::fromUtf8("接受电池充电参数报文超时!"));
        break;
    case 10:
        ui->label_14->setText(QString::fromUtf8("接受BMS完成充电准备报文超时!"));
        break;
    case 11:
        ui->label_14->setText(QString::fromUtf8("接受电池充电总状态报文超时!"));
        break;
    case 12:
        ui->label_14->setText(QString::fromUtf8("接受电池充电要求报文超时!"));
        break;
    case 13:
        ui->label_14->setText(QString::fromUtf8("接受BMS中止充电报文超时!"));
        break;
    case 14:
        ui->label_14->setText(QString::fromUtf8("接受BMS中止充电统计报文超时!"));
        break;
    case 15:
        ui->label_14->setText(QString::fromUtf8("BMS没有准备好充电!"));
        break;
    case 16:
        ui->label_14->setText(QString::fromUtf8("充电机没有准备好充电!"));
        break;
    case 17:
        ui->label_14->setText(QString::fromUtf8("请求充电服务失败!"));
        break;
    case 18:
        ui->label_14->setText(QString::fromUtf8("绝缘失败!"));
        break;
    case 19:
        ui->label_14->setText(QString::fromUtf8("模块开始命令失败!"));
        break;
    case 20:
        ui->label_14->setText(QString::fromUtf8("急停故障!"));
        break;
    default:
         ErrMsg("$$$$$$$$$$$$$$$$$$$$$[%d]\n",tempvalue);
            break;
    }


/*
    API_Read_DB_Nbyte(PL_CELLTYPE_FLAG,(char*)&tempvalue,sizeof(tempvalue));
    switch(tempvalue)
    {
    case 0:
        ui->lbl_cell_type->setText(QString::fromUtf8("正在获取..."));
        break;
    case 1:
        ui->lbl_cell_type->setText(QString::fromUtf8("铅酸电池!"));
        break;
    case 2:
        ui->lbl_cell_type->setText(QString::fromUtf8("镍氢电池!"));
        break;
    case 3:
        ui->lbl_cell_type->setText(QString::fromUtf8("磷酸铁锂电池!"));
        break;
    case 4:
        ui->lbl_cell_type->setText(QString::fromUtf8("锰酸锂电池!"));
        break;
    case 5:
        ui->lbl_cell_type->setText(QString::fromUtf8("钴酸锂电池!"));
        break;
    case 6:
        ui->lbl_cell_type->setText(QString::fromUtf8("三元电池!"));
        break;
    case 7:
        ui->lbl_cell_type->setText(QString::fromUtf8("聚合物锂电池!"));
        break;
    case 8:
        ui->lbl_cell_type->setText(QString::fromUtf8("钛酸锂电池!"));
        break;
    default:
        ui->lbl_cell_type->setText(QString::fromUtf8("其他电池!"));
        break;
    }

    API_Read_DB_Nbyte(PL_LOWESTCELL_TEMP,(INT8 *)(&f32_data),sizeof(f32_data));
    ui->lbl_lowest->setText(QString::number(f32_data,'f',1));

    API_Read_DB_Nbyte(PL_HIGESTCELL_TEMP,(INT8 *)(&f32_data),sizeof(f32_data));
    ui->lbl_higest->setText(QString::number(f32_data,'f',1));

    API_Read_DB_Nbyte(PL_OUTPUT_POWER,(INT8 *)(&f32_data),sizeof(f32_data));
    ui->lbl_output->setText(QString::number(f32_data,'f',1));

    API_Read_DB_Nbyte(PL_CHRSTART_KWH,(INT8 *)(&f32_data),sizeof(f32_data));
    ui->lbl_init_energy->setText(QString::number(f32_data,'f',2));

    API_Read_DB_Nbyte(PL_CHRCURRRENT_KWH,(INT8 *)(&f32_data),sizeof(f32_data));
    ui->lbl_current_energy->setText(QString::number(f32_data,'f',2));
*/
    API_Read_DB_Nbyte(PL_CHR_CURRENTSOC,(INT8 *)(&u16_data),sizeof(u16_data));
    ui->lbl_current_soc->setText(QString::number(u16_data,'f',0));

    API_Read_DB_Nbyte(PL_CHR_LFTTIME,(INT8 *)(&u16_data),sizeof(u16_data));
    ui->lbl_left_time->setText(QString::number(u16_data,'f',0));

    API_Read_DB_Nbyte(PL_CHRUSED_KWH,(INT8 *)(&f32_data),sizeof(f32_data));
    ui->lbl_caculate_energy->setText(QString::number(f32_data,'f',2));

}

void p11_charging_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
    if(hmi_page_index != PAGEINDEX_CHARGEPROCESS)
    {
        exit_page_dlg();
    }
    else
    {

    }
}


/*
void p11_charging_dialog::call_dlg_1()
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
void p11_charging_dialog::call_p12_dlg()
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

void p11_charging_dialog::call_dlg_2()
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

void p11_charging_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p11dlg();
    //delete p11_dlg;
    //p11_dlg = NULL;
}

