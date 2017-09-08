#include "main_dialog.h"
#include "ui_main_dialog.h"
#include "globalhmi.h"

main_dialog::main_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::main_dialog)
{
    ui->setupUi(this);
    init_main_dlg();
}

main_dialog::~main_dialog()
{
    delete ui;
}

void main_dialog::changeEvent(QEvent *e)
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

void main_dialog::init_main_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_database();
    ui->pbtn_setpara->setStyleSheet("QPushButton{border-image: url(:/btn/qrc/PICS/manager.png);background-image: url(:/background/qrc/background/mainlab_phonenum.png);}\
                              QPushButton:pressed{border-image: url(:/icon/qrc/icon/Buddy Chat.png);background-image: url(:/background/qrc/background/mainlab_phonenum.png);}");
  }



int add_num=0;
char web[25]={};
struct _ChrProcessShow_DataStruct  ChrProcessShow_DataStruct[4];

void main_dialog::init_database()
{
    void *fp;
    DebugMsg(hmilev,8,"init_database\n");
    if((fp=dlopen("libdatabase.so",RTLD_LAZY))==NULL)
    {
        fputs(dlerror(),stderr);
        printf("\n");
        printf("can not open the library\n");
        exit(1);
    }
    API_Read_DB_Nbyte = (INT16 (*)(UINT32,void*,UINT16))dlsym(fp,"API_Read_DB_Nbyte");
    API_Write_DB_Nbyte = (INT16 (*)(UINT32,void*,UINT16))dlsym(fp,"API_Write_DB_Nbyte");
    API_DB_Initial = (void (*)())dlsym(fp,"API_DB_Initial");

    API_DB_Initial();

    UINT8 data = PAGEINDEX_MAIN;
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&data),sizeof(data));
    API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX_CUR,(INT8 *)(&data),sizeof(data));
    data = NO_BUTTON;

    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
    API_Write_DB_Nbyte(PL_SHOWCHARGEGUN_INDEX,(UINT8 *)(&data),sizeof(data));

    int num_ad_show = 0;
    for(num_ad_show;num_ad_show<TOTALBOARD_GUN_NUM;num_ad_show++)
    {
        memset(&ChrProcessShow_DataStruct[num_ad_show],0,sizeof(ChrProcessShow_DataStruct[num_ad_show]));
    }

    int net_flg;
    net_flg=0;
    int temp_net;
    temp_net=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"networkservice");
    net_flg=read_profile_int(Section_name,Key_name,temp_net,config_path);
    API_Write_DB_Nbyte(PL_NEEDNETWORK_FLAG ,(BOOL *)(&net_flg),sizeof(net_flg));

    float max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"top1_starttm");
    ft1= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_TOP1_STARTTM ,(BOOL *)(&ft1),sizeof(ft1));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"top1_stoptm");
    ft1_1= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_TOP1_STOPTM ,(BOOL *)(&ft1_1),sizeof(ft1_1));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"top2_starttm");
    ft2= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_TOP2_STARTTM ,(BOOL *)(&ft2),sizeof(ft2));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"top2_stoptm");
    ft2_1= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_TOP2_STOPTM ,(BOOL *)(&ft2_1),sizeof(ft2_1));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"peak1_starttm");
    fp1= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_PEAK1_STARTTM ,(BOOL *)(&fp1),sizeof(fp1));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"peak1_stoptm");
    fp1_1= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_PEAK1_STOPTM ,(BOOL *)(&fp1_1),sizeof(fp1_1));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"peak2_starttm");
    fp2= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_PEAK2_STARTTM ,(BOOL *)(&fp2),sizeof(fp2));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"peak2_stoptm");
    fp2_1= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_PEAK2_STOPTM ,(BOOL *)(&fp2_1),sizeof(fp2_1));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"flat1_starttm");
    ff1= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_FLAT1_STARTTM ,(BOOL *)(&ff1),sizeof(ff1));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"flat1_stoptm");
    ff1_1= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_FLAT1_STOPTM ,(BOOL *)(&ff1_1),sizeof(ff1_1));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"flat2_starttm");
    ff2= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_FLAT2_STARTTM ,(BOOL *)(&ff2),sizeof(ff2));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"flat2_stoptm");
    ff2_1= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_FLAT2_STOPTM ,(BOOL *)(&ff2_1),sizeof(ff2_1));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"valley1_starttm");
    fg1= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_VALLEY1_STARTTM ,(BOOL *)(&fg1),sizeof(fg1));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"valley1_stoptm");
    fg1_1= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_VALLEY1_STOPTM ,(BOOL *)(&fg1_1),sizeof(fg1_1));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"valley2_starttm");
    fg2= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_VALLEY2_STARTTM ,(BOOL *)(&fg2),sizeof(fg2));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"valley2_stoptm");
    fg2_1= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_VALLEY2_STOPTM ,(BOOL *)(&fg2_1),sizeof(fg2_1));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"top1_elecprice");
    fg1= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_TOP1_ELECPRICE ,(BOOL *)(&fg1),sizeof(fg1));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"top2_elecprice");
    fg1_1= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_TOP2_ELECPRICE ,(BOOL *)(&fg1_1),sizeof(fg1_1));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"peak1_elecprice");
    fg2= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_PEAK1_ELECPRICE ,(BOOL *)(&fg2),sizeof(fg2));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"peak2_elecprice");
    fg2_1= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_PEAK2_ELECPRICE ,(BOOL *)(&fg2_1),sizeof(fg2_1));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"flat1_elecprice");
    fg1= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_FLAT1_ELECPRICE ,(BOOL *)(&fg1),sizeof(fg1));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"flat2_elecprice");
    fg1_1= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_FLAT2_ELECPRICE ,(BOOL *)(&fg1_1),sizeof(fg1_1));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"valley1_elecprice");
    fg2= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_VALLEY1_ELECPRICE ,(BOOL *)(&fg2),sizeof(fg2));

    max_temp=0;
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"valley2_elecprice");
    fg2_1= read_profile_float(Section_name, Key_name,max_temp,config_path);
    API_Write_DB_Nbyte(PL_VALLEY2_ELECPRICE ,(BOOL *)(&fg2_1),sizeof(fg2_1));

    memset(code,0,sizeof(code));
    memset(Tempor_name,0,sizeof(Tempor_name));
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"stubcode");
    char buf_code[100]={0};
    if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
    {
        memcpy(code,Tempor_name,sizeof(code));
       snprintf(buf_code,100,"/usr/APP/qrencode -o 1.png -s 5 %s",code);
        system(buf_code);
        memset(buf_code,0,100);
         snprintf(buf_code,100,"pkill qrencode");
                 system(buf_code);
    }
    else
    {
        memset(code,0,sizeof(code));
    }

    ui->label_piccode->setPixmap(QPixmap("/usr/APP/1.png"));
}

void main_dialog::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
}


void read_process_infor_main()
{
    int num_ad_show = 0;
    for(num_ad_show=0;num_ad_show<TOTALBOARD_GUN_NUM;num_ad_show++)
    {
        API_Read_DB_Nbyte(PL_STUBISCHARGING_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct[num_ad_show].stubischarging),sizeof(UINT8));
     //   API_Read_DB_Nbyte(PL_GETSTARTSOC_FLAG_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct[num_ad_show].GetStartSoc_Flag),sizeof(UINT8));
        API_Read_DB_Nbyte(PL_STARTSOC_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct[num_ad_show].Start_Soc),sizeof(UINT8));
        API_Read_DB_Nbyte(PL_TOTALSOC_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct[num_ad_show].Total_SOC),sizeof(UINT8));
      //  API_Read_DB_Nbyte(PL_GETSTOPSOC_FLAG_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct[num_ad_show].GetStopSoc_Flag),sizeof(UINT8));
        //API_Read_DB_Nbyte(PL_STOPSOC_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct[num_ad_show].Stop_SOC),sizeof(UINT8));
       // API_Read_DB_Nbyte(PL_CELLTYPE_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct[num_ad_show].Cell_type),sizeof(UINT8));
      //  API_Read_DB_Nbyte(PL_HAVESTARTKWH_FLAG_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct[num_ad_show].HaveStartKWH_Flag),sizeof(UINT8));
      //  API_Read_DB_Nbyte(PL_USERCHARGESUCESS_FLAG_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct[num_ad_show].UserCharge_sucess_flag),sizeof(UINT8));
       // API_Read_DB_Nbyte(PL_OLDSTUBISCHARGING_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct[num_ad_show].Oldstubischarging),sizeof(UINT8));
       // API_Read_DB_Nbyte(PL_HAVESTARTCHARTM_FLAG_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct[num_ad_show].HaveStartChrTm_Flag),sizeof(UINT8));
      //  API_Read_DB_Nbyte(PL_HAVESTOPCHARTM_FLAG_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct[num_ad_show].HaveStopChrTm_Flag),sizeof(UINT8));
         API_Read_DB_Nbyte(PL_CHARGEGUNLINKSTATE_1+num_ad_show,(UINT8 *)(&ChrProcessShow_DataStruct[num_ad_show].ChargeGunLinkState),sizeof(UINT8));

         API_Read_DB_Nbyte(CHRVOLTMESURVALUE_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct[num_ad_show].ChrVoltMesurValue),sizeof(FLOAT32));
        API_Read_DB_Nbyte(CHRCURMESURVALUE_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct[num_ad_show].ChrCurrentMesurValue),sizeof(FLOAT32));
       // API_Read_DB_Nbyte(BMS_VOLTNEED_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct[num_ad_show].BMS_VoltNeed),sizeof(FLOAT32));
      //  API_Read_DB_Nbyte(BMS_CURNEED_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct[num_ad_show].BMS_CurrentNeed),sizeof(FLOAT32));
     //   API_Read_DB_Nbyte(START_KWH_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct[num_ad_show].Start_KWH),sizeof(FLOAT32));
       // API_Read_DB_Nbyte(CURRENT_KWH_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct[num_ad_show].Current_KWH),sizeof(FLOAT32));
        API_Read_DB_Nbyte(USED_KWH_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct[num_ad_show].Used_KWH),sizeof(FLOAT32));
      //  API_Read_DB_Nbyte(STOP_KWH_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct[num_ad_show].Stop_KWH),sizeof(FLOAT32));
        API_Read_DB_Nbyte(HIGESTSINGLEVOLT_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct[num_ad_show].Higestsinglevolt),sizeof(FLOAT32));
      //  API_Read_DB_Nbyte(HIGESTSINGLETEMP_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct[num_ad_show].HigestsingleTemp),sizeof(FLOAT32));
     //   API_Read_DB_Nbyte(OUTPUTPOWER_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct[num_ad_show].OutPutPower),sizeof(FLOAT32));
      // API_Read_DB_Nbyte(USERNEEDCHAR_KWH_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct[num_ad_show].UserNeedChr_KWH),sizeof(FLOAT32));
     //  API_Read_DB_Nbyte(USERCARD_LEFTMONEY_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct[num_ad_show].UserCard_LeftMoney),sizeof(FLOAT32));
     //  API_Read_DB_Nbyte(USERCARD_USEDTOTALMONEY_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct[num_ad_show].UserCard_UsedTotalMoney),sizeof(FLOAT32));
     //  API_Read_DB_Nbyte(CHARGESERVICE_MONEY_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct[num_ad_show].ChargeService_Money),sizeof(FLOAT32));
     //  API_Read_DB_Nbyte(USEDELECTRIC_MONEY_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct[num_ad_show].UsedElectric_Money),sizeof(FLOAT32));
     //  API_Read_DB_Nbyte(CHARGEKWH_FRMNETWORK_1+num_ad_show,(FLOAT32 *)(&ChrProcessShow_DataStruct[num_ad_show].chargekwh_frmnetwork),sizeof(FLOAT32));

       API_Read_DB_Nbyte(PL_CHRLEFTTM_1+num_ad_show,(UINT16 *)(&ChrProcessShow_DataStruct[num_ad_show].ChrLeftTm),sizeof(UINT16));
       API_Read_DB_Nbyte(PL_CHRUSEDTM_1+num_ad_show,(UINT16 *)(&ChrProcessShow_DataStruct[num_ad_show].ChrUsedTm),sizeof(UINT16));
     //  API_Read_DB_Nbyte(PL_TOTALAH_1+num_ad_show,(UINT16 *)(&ChrProcessShow_DataStruct[num_ad_show].Total_AH),sizeof(UINT16));

      //  API_Read_DB_Nbyte(PL_USERNEED_TIME_1+num_ad_show,(UINT32 *)(&ChrProcessShow_DataStruct[num_ad_show].UserNeed_Time),sizeof(UINT32));
       // API_Read_DB_Nbyte(PL_STOPSOCFRMNETWORK_1+num_ad_show,(UINT32 *)(&ChrProcessShow_DataStruct[num_ad_show].stopsoc_frmnetwork),sizeof(UINT32));
      //  API_Read_DB_Nbyte(PL_CHARGETIME_FRMNETWORK_1+num_ad_show,(UINT32 *)(&ChrProcessShow_DataStruct[num_ad_show].chargetime_frmnetwork),sizeof(UINT32));
       // API_Read_DB_Nbyte(PL_STARTCHR_TM_1+num_ad_show,(UINT32 *)(&ChrProcessShow_DataStruct[num_ad_show].StartChargeTm.tv_sec),sizeof(UINT32));
       // API_Read_DB_Nbyte(PL_CURCHR_TM_1+num_ad_show,(UINT32 *)(&ChrProcessShow_DataStruct[num_ad_show].CurrentChargeTm.tv_sec),sizeof(UINT32));
        //API_Read_DB_Nbyte(PL_STOPCHR_TM_1+num_ad_show,(UINT32 *)(&ChrProcessShow_DataStruct[num_ad_show].Stopcharge_TM.tv_sec),sizeof(UINT32));
    }
}

int num_move = 0;
int move_flag = 0;
int num_add_main=0;
void main_dialog::timer_handle()
{
    ui->lbl_sysdate->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    ui->lbl_systime->setText(QTime::currentTime().toString("hh:mm:ss"));
    num_add_main++;
    if(num_add_main >= 252)
    {
        num_add_main = 0;
        read_process_infor_main();
        ui->cur_soc_1->setText(QString::number(ChrProcessShow_DataStruct[0].Total_SOC,'f',0));
        ui->cur_soc_2->setText(QString::number(ChrProcessShow_DataStruct[1].Total_SOC,'f',0));
        ui->cur_soc_3->setText(QString::number(ChrProcessShow_DataStruct[2].Total_SOC,'f',0));
        ui->cur_soc_4->setText(QString::number(ChrProcessShow_DataStruct[3].Total_SOC,'f',0));

        ui->left_time_min_1->setText(QString::number(ChrProcessShow_DataStruct[0].ChrLeftTm,'f',0));
        ui->left_time_min_2->setText(QString::number(ChrProcessShow_DataStruct[1].ChrLeftTm,'f',0));
        ui->left_time_min_3->setText(QString::number(ChrProcessShow_DataStruct[2].ChrLeftTm,'f',0));
        ui->left_time_min_4->setText(QString::number(ChrProcessShow_DataStruct[3].ChrLeftTm,'f',0));

        memset(code,0,sizeof(code));
        memset(Tempor_name,0,sizeof(Tempor_name));
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"stubcode");

        if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
        {
            memcpy(code,Tempor_name,sizeof(code));
        }
        else
        {
            memset(code,0,sizeof(code));
        }
    /*
        memset(Tempor_name,0,sizeof(Tempor_name));
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"websize");

        if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
        {
            memcpy(web,Tempor_name,sizeof(web));
        }
        else
        {
            memset(web,0,sizeof(web));
        }
    */
        memset(phonenum,0,sizeof(phonenum));
        memset(Tempor_name,0,sizeof(Tempor_name));
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"oneemergencycall");
        if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
        {
            memcpy(phonenum,Tempor_name,sizeof(phonenum));
            //sprintf(phonenum,"%c%c%c-%c%c%c%c-%c%c%c",phonenum[0],phonenum[1],phonenum[2],phonenum[3],phonenum[4],phonenum[5],phonenum[6],phonenum[7],phonenum[8],phonenum[9]);
        }
        else
        {
            memset(phonenum,0,sizeof(phonenum));
        }

        memset(phonenum_2,0,sizeof(phonenum_2));
        memset(Tempor_name,0,sizeof(Tempor_name));
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"twoemergencycall");
        if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
        {
            memcpy(phonenum_2,Tempor_name,sizeof(phonenum_2));
           // sprintf(phonenum_2,"%c%c%c-%c%c%c%c-%c%c%c%c",phonenum_2[0],phonenum_2[1],phonenum_2[2],phonenum_2[3],phonenum_2[4],phonenum_2[5],phonenum_2[6],phonenum_2[7],phonenum_2[8],phonenum_2[9],phonenum_2[10]);
        }
        else
        {
            memset(phonenum_2,0,sizeof(phonenum_2));
        }

     // BOOL net_flg=0;
      ui->label_code->setText(phonenum);
      ui->label_code_2->setText(phonenum_2);
    //  ui->label_websize->setText(web);



      #if 0
      ui->pbtn_setnet->setStyleSheet("background-image: url(:/background/qrc/background/mainlab_phonenum.png);border-image: url(:/icon/qrc/icon/0.png);");

      API_Read_DB_Nbyte(PL_NETWORKLINKSTATE_FLAG,(BOOL *)(&net_flg),sizeof(net_flg));
      if(net_flg)
      {
       add_num=0;
       ui->pbtn_setnet->setStyleSheet("background-image: url(:/background/qrc/background/mainlab_phonenum.png);border-image: url(:/icon/qrc/icon/1.png);");

      }
      else
      {
        add_num++;
        if(add_num>=750)
        {
            ui->pbtn_setnet->setStyleSheet("background-image: url(:/background/qrc/background/mainlab_phonenum.png);border-image: url(:/icon/qrc/icon/0.png);");
            add_num=0;
        }
      }
    #endif

    #if 1

    QPushButton * pbtn_array[4]={ui->pbtn_1,ui->pbtn_2,ui->pbtn_3,ui->pbtn_4};
    int pbtn_add = 0;
    UINT8 link_state = 0;
    for(pbtn_add = 0; pbtn_add <4; pbtn_add++)
    {
        pbtn_array[pbtn_add]->setStyleSheet("border-image: url(:/btn/qrc/PICS/main_2.png);");

        API_Read_DB_Nbyte(PL_CHARGEGUNLINKSTATE_1+pbtn_add,(BOOL *)(&link_state),sizeof(link_state));
        if(link_state)
        {
             add_num=0;
             pbtn_array[pbtn_add]->setStyleSheet("border-image: url(:/btn/qrc/PICS/main_1.png);");
        }
        else
        {
              add_num++;
              if(add_num>=750)
              {
                  pbtn_array[pbtn_add]->setStyleSheet("border-image: url(:/btn/qrc/PICS/main_2.png);");
                  add_num=0;
              }
         }
    }

    #endif
    }


  if(language_num == 1)
  {
        //ui->label_logo->setText(QString::fromUtf8("直 流 充 电 桩"));
        //ui->label_state->setText(QString::fromUtf8("读 卡 器 故 障"));
       // ui->label_title_2->setText(QString::fromUtf8("请   刷   卡"));
        ui->label_stubnum->setText(QString::fromUtf8("客服热线 :"));
  }
  else  if(language_num == 2)
  {
        //ui->label_logo->setText("DC charging pile");
       // ui->label_state->setText("free");
       // ui->label_title_2->setText("Please swipe the card");
        ui->label_stubnum->setText("Pile Number :");
  }
/*
  num_move++;
  if(num_move == 100)
  {
      num_move = 0;
      move_flag ++;
      ui->frame_rfid->move(340,280);
  }

  if(move_flag == 2)
  {
      move_flag = 0;
      ui->frame_rfid->move(340,330);
  }
*/
  check_hmi_page_index();
}

 int page_add = 0;
void main_dialog::check_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));

#if 0
    page_add ++;
    if(page_add > 10)
    {
        page_add = 0;
        printf("\n@@@@@@@@@@@@@@Now We In (%d)\r\n",hmi_page_index);
    }
#endif

    if(hmi_page_index==PAGEINDEX_MAIN)
    {
        if(dlg_err){
                delete dlg_err;
                dlg_err = NULL;
        }
        if(dlg_stop){
                delete dlg_stop;
                dlg_stop = NULL;
        }
        if(dlg_gun){
                delete dlg_gun;
                dlg_gun = NULL;
        }
        if(dlg_infor){
                delete dlg_infor;
                dlg_infor = NULL;
        }
        if(p01_dlg){
                delete p01_dlg;
                p01_dlg = NULL;
        }
        if(p02_dlg){
                delete p02_dlg;
                p02_dlg = NULL;
        }
        if(p03_dlg){
                delete p03_dlg;
                p03_dlg = NULL;
        }
        if(p05_dlg){
                delete p05_dlg;
                p05_dlg = NULL;
        }
        if(p07_dlg){
                delete p07_dlg;
                p07_dlg = NULL;
        }
        if(p08_dlg){
                delete p08_dlg;
                p08_dlg = NULL;
        }
        if(p09_dlg){
                delete p09_dlg;
                p09_dlg = NULL;
        }
        if(p19_dlg){
                delete p19_dlg;
                p19_dlg = NULL;
        }        
        if(p13_dlg){
                delete p13_dlg;
                p13_dlg = NULL;
        }
        if(p14_dlg){
                delete p14_dlg;
                p14_dlg = NULL;
        }
        if(p15_dlg){
                delete p15_dlg;
                p15_dlg = NULL;
        }
        if(p16_dlg){
                delete p16_dlg;
                p16_dlg = NULL;
        }
        if(p17_dlg){
                delete p17_dlg;
                p17_dlg = NULL;
        }
        if(p18_dlg){
                delete p18_dlg;
                p18_dlg = NULL;
        }
        if(p24_dlg){
                delete p24_dlg;
                p24_dlg = NULL;
        }
        if(p20_dlg){
                delete p20_dlg;
                p20_dlg = NULL;
        }
        if(p21_dlg){
                delete p21_dlg;
                p21_dlg = NULL;
        }
        if(dlg_2){
                delete dlg_2;
                dlg_2 = NULL;
        }
        if(diff_card_dlg){
                delete diff_card_dlg;
                diff_card_dlg = NULL;
        }
    }
    else
    if(hmi_page_index==PAGEINDEX_STOPCHARGE_SURE)
    {
    //    printf("@@@@Go to PAGE_PASSWD!\r\n");
        call_dlg_stop();
    }
    else
    if(hmi_page_index==PAGEINDEX_USERACTION)
    {
    //    printf("@@@@Go to PAGE_PASSWD!\r\n");
        call_dlg_gun();
    }
    else
    if(hmi_page_index==PAGEINDEX_CHARGE_INFO)
    {
    //    printf("@@@@Go to PAGE_PASSWD!\r\n");
        call_dlg_info();
    }
    else
    if(hmi_page_index==PAGEINDEX_PASSWD)
    {
    //    printf("@@@@Go to PAGE_PASSWD!\r\n");
        call_p01_dlg();
    }else
    if(hmi_page_index==PAGEINDEX_CHARGETYPECHOSE)
    {
   //     printf("@@@@Go to PAGEINDEX_CHARGELINK!\r\n");
        call_p07_dlg();
    }else
    if(hmi_page_index==PAGEINDEX_CHARGEBYTIME)
    {
   //     printf("@@@@Go to PAGEINDEX_CHARGELINK!\r\n");
        call_p08_dlg();
    }else
    if(hmi_page_index==PAGEINDEX_CHARGEBYCAPA)
    {
   //     printf("@@@@Go to PAGEINDEX_CHARGELINK!\r\n");
        call_p09_dlg();
    }else
    if(hmi_page_index==PAGEINDEX_SETPASSWRDIPT)
    {
   //     printf("@@@@Go to PAGEINDEX_SETPASSWRDIPT!\r\n");
        call_p13_dlg();
    }else
    if(hmi_page_index==PAGEINDEX_SETPAGE_ONE)
    {
        //     printf("@@@@Go to PAGEINDEX_SETPASSWRDIPT!\r\n");
        call_p14_dlg();
    }else
    if(hmi_page_index==PAGEINDEX_SETPAGE_TWO)
    {
        //     printf("@@@@Go to PAGEINDEX_SETPASSWRDIPT!\r\n");
        call_p15_dlg();
    }else
    if(hmi_page_index==PAGEINDEX_SETPAGE_THR)
    {
        //     printf("@@@@Go to PAGEINDEX_SETPASSWRDIPT!\r\n");
        call_p16_dlg();
    }else
    if(hmi_page_index==PAGEINDEX_SETPAGE_FOUR)
    {
        //     printf("@@@@Go to PAGEINDEX_SETPASSWRDIPT!\r\n");
        call_p17_dlg();
    }else
    if(hmi_page_index==PAGEINDEX_SETPAGE_FIVE)
    {
        //     printf("@@@@Go to PAGEINDEX_SETPASSWRDIPT!\r\n");
        call_p18_dlg();
    }else
    if(hmi_page_index==PAGEINDEX_SETPAGE_SIX)
    {
    //     printf("@@@@Go to PAGEINDEX_SETPASSWRDIPT!\r\n");
        call_p24_dlg();
    }else
    if(hmi_page_index==PAGEINDEX_CHARGEPROCESS)
    {
    //    printf("@@@@Go to PAGEINDEX_ACCHARGEPROCESS!\r\n");
            call_p11_dlg();
    }else
    if(hmi_page_index==PAGEINDEX_PAYOFF)
    {
      //  printf("@@@@Go to PAGEINDEX_ACPAYOFF!\r\n");
        call_p12_dlg();
    }else
    if(hmi_page_index==PAGEINDEX_ERRORCHECK)
    {
  //      printf("@@@@Go to PAGEINDEX_ERRORCHECK!\r\n");
        call_dlg_err();
    }else
    if(hmi_page_index==PAGEINDEX_DIFFERENT_CARD)
    {
    //    printf("@@@@Go to PAGEINDEX_DIFFERENT_CARD!\r\n");
        call_diff_card_dlg();
    }
    else
    {
        ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

}

void main_dialog::call_diff_card_dlg()
{
    timer->stop();
    if(diff_card_dlg){
            delete diff_card_dlg;
            diff_card_dlg = NULL;
    }
    diff_card_dlg = new  Dialog_diff_card;
    diff_card_dlg->setWindowFlags(Qt::FramelessWindowHint);

    connect(this,SIGNAL(signal_enable_diff_card_timer()),diff_card_dlg,SLOT(init_page_dlg()));
    connect(diff_card_dlg,SIGNAL(signal_exit_diff_card()),this,SLOT(start_timer()));

    emit signal_enable_diff_card_timer();
    diff_card_dlg->exec();
}

void main_dialog::call_dlg_stop()
{
    timer->stop();
    if(dlg_stop){
            delete dlg_stop;
            dlg_stop = NULL;
    }
    dlg_stop = new  Dialog_stop;
    dlg_stop->setWindowFlags(Qt::FramelessWindowHint);

    connect(this,SIGNAL(signal_enable_dlg_stop_timer()),dlg_stop,SLOT(init_page_dlg()));
    connect(dlg_stop,SIGNAL(signal_exit_dlg()),this,SLOT(start_timer()));

    emit signal_enable_dlg_stop_timer();
    dlg_stop->exec();
}

void main_dialog::call_dlg_gun()
{
    timer->stop();
    if(dlg_gun){
            delete dlg_gun;
            dlg_gun = NULL;
    }
    dlg_gun = new  Dialog_gunselect;
    dlg_gun->setWindowFlags(Qt::FramelessWindowHint);

    connect(this,SIGNAL(signal_enable_dlg_gun_timer()),dlg_gun,SLOT(init_page_dlg()));
    connect(dlg_gun,SIGNAL(signal_exit_dlg_gun()),this,SLOT(start_timer()));

    emit signal_enable_dlg_gun_timer();
    dlg_gun->exec();
}

void main_dialog::call_dlg_info()
{
    timer->stop();
    if(dlg_infor){
            delete dlg_infor;
            dlg_infor = NULL;
    }
    dlg_infor = new  Dialog_infor;
    dlg_infor->setWindowFlags(Qt::FramelessWindowHint);

    connect(this,SIGNAL(signal_enable_dlg_info_timer()),dlg_infor,SLOT(init_page_dlg()));
    connect(dlg_infor,SIGNAL(signal_exit_dlg_info()),this,SLOT(start_timer()));

    emit signal_enable_dlg_info_timer();
    dlg_infor->exec();
}

void main_dialog::call_dlg_err()
{
    timer->stop();
    if(dlg_err){
            delete dlg_err;
            dlg_err = NULL;
    }
    dlg_err = new  Dialog_err;
    dlg_err->setWindowFlags(Qt::FramelessWindowHint);

    connect(this,SIGNAL(signal_enable_err_timer()),dlg_err,SLOT(init_page_dlg()));
    connect(dlg_err,SIGNAL(signal_exit_errdlg()),this,SLOT(start_timer()));

    emit signal_enable_err_timer();
    dlg_err->exec();
}

void main_dialog::call_p01_dlg()
{
    timer->stop();
    if(p01_dlg){
            delete p01_dlg;
            p01_dlg = NULL;
            handle_dlg_p01--;
    }
    p01_dlg = new  p01_passwd_dialog;
    p01_dlg->setWindowFlags(Qt::FramelessWindowHint);
    handle_dlg_p01++;

    connect(this,SIGNAL(signal_enable_p01dlg_timer()),p01_dlg,SLOT(init_page_dlg()));
    connect(p01_dlg,SIGNAL(signal_exit_p01dlg()),this,SLOT(start_timer()));

    emit signal_enable_p01dlg_timer();
    p01_dlg->exec();
}

void main_dialog::call_p07_dlg()
{
    timer->stop();
    if(p07_dlg){
            delete p07_dlg;
            p07_dlg = NULL;
    }
    p07_dlg = new  p07_chargetypechoose_dialog;
    p07_dlg->setWindowFlags(Qt::FramelessWindowHint);

    connect(this,SIGNAL(signal_enable_p07dlg_timer()),p07_dlg,SLOT(init_page_dlg()));
    connect(p07_dlg,SIGNAL(signal_exit_p07dlg()),this,SLOT(start_timer()));

    emit signal_enable_p07dlg_timer();
    p07_dlg->exec();
}

void main_dialog::call_p08_dlg()
{
    timer->stop();
    if(p08_dlg){
            delete p08_dlg;
            p08_dlg = NULL;
    }
    p08_dlg = new  p08_chargebytime_dialog;
    p08_dlg->setWindowFlags(Qt::FramelessWindowHint);

    connect(this,SIGNAL(signal_enable_p08dlg_timer()),p08_dlg,SLOT(init_page_dlg()));
    connect(p08_dlg,SIGNAL(signal_exit_p08dlg()),this,SLOT(start_timer()));

    emit signal_enable_p08dlg_timer();
    p08_dlg->exec();
}


void main_dialog::call_p09_dlg()
{
    timer->stop();
    if(p09_dlg){
            delete p09_dlg;
            p09_dlg = NULL;
    }
    p09_dlg = new  p09_chargebyenergy_dialog;
    p09_dlg->setWindowFlags(Qt::FramelessWindowHint);

    connect(this,SIGNAL(signal_enable_p09dlg_timer()),p09_dlg,SLOT(init_page_dlg()));
    connect(p09_dlg,SIGNAL(signal_exit_p09dlg()),this,SLOT(start_timer()));

    emit signal_enable_p09dlg_timer();
    p09_dlg->exec();
}


void main_dialog::call_p11_dlg()
{
    timer->stop();
    if(p11_dlg){
            delete p11_dlg;
            p11_dlg = NULL;
    }
    p11_dlg = new  p11_charging_dialog;
    p11_dlg->setWindowFlags(Qt::FramelessWindowHint);

    connect(this,SIGNAL(signal_enable_p11dlg_timer()),p11_dlg,SLOT(init_page_dlg()));
    connect(p11_dlg,SIGNAL(signal_exit_p11dlg()),this,SLOT(start_timer()));

    emit signal_enable_p11dlg_timer();
    p11_dlg->exec();
}

void main_dialog::call_p12_dlg()
{
    timer->stop();
    if(p12_dlg){
            delete p12_dlg;
            p12_dlg = NULL;
    }
    p12_dlg = new  p12_payoff_dialog;
    p12_dlg->setWindowFlags(Qt::FramelessWindowHint);

    connect(this,SIGNAL(signal_enable_p12dlg_timer()),p12_dlg,SLOT(init_page_dlg()));
    connect(p12_dlg,SIGNAL(signal_exit_p12dlg()),this,SLOT(start_timer()));

    emit signal_enable_p12dlg_timer();
    p12_dlg->exec();
}

void main_dialog::call_p13_dlg()
{
    timer->stop();
    if(p13_dlg){
            delete p13_dlg;
            p13_dlg = NULL;
            handle_dlg_p13--;
    }
    p13_dlg = new  p13_setpara_dialog;
    p13_dlg->setWindowFlags(Qt::FramelessWindowHint);
    handle_dlg_p13++;

    connect(this,SIGNAL(signal_enable_p13dlg_timer()),p13_dlg,SLOT(init_page_dlg()));
    connect(p13_dlg,SIGNAL(signal_exit_p13dlg()),this,SLOT(start_timer()));

    emit signal_enable_p13dlg_timer();
    p13_dlg->exec();
}

void main_dialog::call_p14_dlg()
{
    timer->stop();
    if(p14_dlg){
            delete p14_dlg;
            p14_dlg = NULL;
    }
    p14_dlg = new  p14_setpara_sub1_dialog;
    p14_dlg->setWindowFlags(Qt::FramelessWindowHint);

    connect(this,SIGNAL(signal_enable_p14dlg_timer()),p14_dlg,SLOT(init_page_dlg()));
    connect(p14_dlg,SIGNAL(signal_exit_p14dlg()),this,SLOT(start_timer()));
    emit signal_enable_p14dlg_timer();
    p14_dlg->exec();
}

void main_dialog::call_p15_dlg()
{
    timer->stop();
    if(p15_dlg){
            delete p15_dlg;
            p15_dlg = NULL;
    }
    p15_dlg = new  p15_setpara_sub2_dialog;
    p15_dlg->setWindowFlags(Qt::FramelessWindowHint);

    connect(this,SIGNAL(signal_enable_p15dlg_timer()),p15_dlg,SLOT(init_page_dlg()));
    connect(p15_dlg,SIGNAL(signal_exit_p15dlg()),this,SLOT(start_timer()));
    emit signal_enable_p15dlg_timer();
    p15_dlg->exec();
}

void main_dialog::call_p16_dlg()
{
    timer->stop();
    if(p16_dlg){
            delete p16_dlg;
            p16_dlg = NULL;
    }
    p16_dlg = new  p16_setpara_sub3_dialog;
    p16_dlg->setWindowFlags(Qt::FramelessWindowHint);

    connect(this,SIGNAL(signal_enable_p16dlg_timer()),p16_dlg,SLOT(init_page_dlg()));
    connect(p16_dlg,SIGNAL(signal_exit_p16dlg()),this,SLOT(start_timer()));
    emit signal_enable_p16dlg_timer();
    p16_dlg->exec();
}

void main_dialog::call_p17_dlg()
{
    timer->stop();
    if(p17_dlg){
            delete p17_dlg;
            p17_dlg = NULL;
    }
    p17_dlg = new  p17_setpara_sub4_dialog;
    p17_dlg->setWindowFlags(Qt::FramelessWindowHint);

    connect(this,SIGNAL(signal_enable_p17dlg_timer()),p17_dlg,SLOT(init_page_dlg()));
    connect(p17_dlg,SIGNAL(signal_exit_p17dlg()),this,SLOT(start_timer()));
    emit signal_enable_p17dlg_timer();
    p17_dlg->exec();
}

void main_dialog::call_p18_dlg()
{
    timer->stop();
    if(p18_dlg){
            delete p18_dlg;
            p18_dlg = NULL;
    }
    p18_dlg = new  p18_setpara_sub5_dialog;
    p18_dlg->setWindowFlags(Qt::FramelessWindowHint);

    connect(this,SIGNAL(signal_enable_p18dlg_timer()),p18_dlg,SLOT(init_page_dlg()));
    connect(p18_dlg,SIGNAL(signal_exit_p18dlg()),this,SLOT(start_timer()));
    emit signal_enable_p18dlg_timer();
    p18_dlg->exec();
}

void main_dialog::call_p24_dlg()
{
    timer->stop();
    if(p24_dlg){
            delete p24_dlg;
            p24_dlg = NULL;
    }
    p24_dlg = new  p24_setpara_sub6_dialog;
    p24_dlg->setWindowFlags(Qt::FramelessWindowHint);

    connect(this,SIGNAL(signal_enable_p24dlg_timer()),p24_dlg,SLOT(init_page_dlg()));
    connect(p24_dlg,SIGNAL(signal_exit_p24dlg()),this,SLOT(start_timer()));
    emit signal_enable_p24dlg_timer();
    p24_dlg->exec();
}


void main_dialog::on_pbtn_setpara_clicked()
{
   hmi_button_dn_num=SET_PARA_BUTTON;
   API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
}

void main_dialog::on_pbtn_language_clicked()
{
    if(1 == language_num)
    {
        language_num = 2;
        return;
    }

    if(2 == language_num)
    {
        language_num = 1;
        return;
    }
}

void main_dialog::on_pbtn_1_clicked()
{
   stub_num=1;
   API_Write_DB_Nbyte(PL_SHOWCHARGEGUN_INDEX,(UINT8 *)(&stub_num),sizeof(stub_num));
}
void main_dialog::on_pbtn_2_clicked()
{
   stub_num=2;
   API_Write_DB_Nbyte(PL_SHOWCHARGEGUN_INDEX,(UINT8 *)(&stub_num),sizeof(stub_num));
}
void main_dialog::on_pbtn_3_clicked()
{
   stub_num=3;
   API_Write_DB_Nbyte(PL_SHOWCHARGEGUN_INDEX,(UINT8 *)(&stub_num),sizeof(stub_num));
}
void main_dialog::on_pbtn_4_clicked()
{
   stub_num=4;
   API_Write_DB_Nbyte(PL_SHOWCHARGEGUN_INDEX,(UINT8 *)(&stub_num),sizeof(stub_num));
}
