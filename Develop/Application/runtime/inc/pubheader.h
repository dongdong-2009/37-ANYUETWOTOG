/*
 * pubheader.h
 *
 *  Created on: 2013-9-16
 *      Author: lijb
 */

#ifndef PUBHEADER_H_
#define PUBHEADER_H_

#include <pthread.h>
#include<time.h>  
#include<sys/time.h>
#include "boardinter.h"
#include <stdbool.h>
//#include "usart.h"
//#define _MAINNOARD_GUN_TWO   (1)
#define _MAINNOARD_GUN_FOUR   (1)
#define SINGLEWAY_CHARGE   (1)
#define MULTIWAY_CHARGE   (2)
#define RETURN_FALSE   (0)
#define RETURN_TRUE   (1)
#define RETURN_STOPCHARGE   (2)

#define  CHARGETYPE_NOCHOISE   	(0)
#define  CHARGETYPE_BYTIME   	(1)
#define  CHARGETYPE_BYTCAPA  	 (2)
#define  CHARGETYPE_BYAUTO   	(3)
#define  CHARGETYPE_MONEY   	(4)
#define  CHARGETYPE_HAND  	 	(5)

#define   SWIPE_CARD		(0)
#define   CARD_IS_DIFFRENCE		(1)

//#define MODULEINTER_BYCAN     (1) 
#define MODULEINTER_BYCOM     (1) 

#define  CANDATALEN_0   (0)
#define  CANDATALEN_1   (1)
#define  CANDATALEN_2   (2)
#define  CANDATALEN_3   (3)
#define  CANDATALEN_4   (4)
#define  CANDATALEN_5   (5)
#define  CANDATALEN_6   (6)
#define  CANDATALEN_7   (7)
#define  CANDATALEN_8   (8)

#define  MOD_CODE_PF_0x01    (0x01)
#define  MOD_CODE_PF_0x03    (0x03)
#define  MOD_CODE_PF_0x04    (0x04)
#define  MOD_CODE_PF_0x05    (0x05)

#define  MOD_CODE_PF_0xF1    (0xF1)
#define  MOD_CODE_PF_0xF2    (0xF2)
#define  MOD_CODE_PF_0xF3    (0xF3)
#define  MOD_CODE_PF_0xF4    (0xF4)
#define  MOD_CODE_PF_0xF5    (0xF5)


#define BMS_INTER_INIT	(0)
#define BMS_INTER_OK	(1)
#define ERR_CMD512		(2)
#define ERR_CMD1536		(3)
#define ERR_CMD2304		(4)
#define ERR_CMD4352		(5)
#define ERR_CMD4096		(6)
#define ERR_CM6400		(7)
#define ERR_CMD7168		(8)

#define ERR_CMD256_00		(9)
#define ERR_CMD256_AA		(10)
#define ERR_CMD1792_2048		(11)
#define ERR_CMD2560			(12)
#define ERR_CMD4608			(13)
#define ERR_CM6656			(14)
#define ERR_CMD7424			(15)
#define EMERGENCY_PRESSED		(16)
#define  MODLEREPLYSTARTCMD_FAILE (17)
#define  SNDMOD_STARTCMD 	(18)
#define  SNDMOD_STOPCMD 	(19)
#define  WAITBMSCONNECT 	(20)
#define  WAITDIRECTCONTACTOR_OPEN 	(21)
#define  WAITDIRECTCONTACTOR_CLOSE 	(22)
#define  BMS_CONNECTFAILED 	(23)
#define  CHRGEGUN_REMOVED 	(24)
#define  DIRECTCONTACTOR_ERR 	(25)
#define MODEXC_SUCCES    (0x01)
#define MODEXC_FAILE    (0x02)

#define TOTALMOD_GROUP          (0x2)
#ifndef	TRUE
	#define  TRUE (1)
#endif

#ifndef	FALSE
	#define  FALSE (0)
#endif

#ifndef	NULL
	#define NULL 	(void*)0
#endif
#define CANCEE_LBUTTON  	 (1)
#define OK_BUTTON   			(2)
//whether the stub work need networksupport
#define  WORK_WITHOUTNETWORK   (0)
#define  WORK_WITHNETWORK   (1)

#define BUFFERLEN_32   (32)
#define INIFILE_LININBUF_SIZE (256)
//five millisecond delay
#define  ONEMSC   (1000)
#define DELAYTM_BYMSEC_5 	(5)
//TEN millisecond delay
#define DELAYTM_BYMSEC_10 	(10)
//20 millisecond delay
#define DELAYTM_BYMSEC_20 	(20)

//30 millisecond delay
#define DELAYTM_BYMSEC_30 	(30)

//40 millisecond delay
#define DELAYTM_BYMSEC_40 	(40)

//50 millisecond delay
#define DELAYTM_BYMSEC_50 	(50)
//100 millisecond delay
#define DELAYTM_BYMSEC_200 	(200)

#if 0
extern const int DELAY_MSEC_5;
extern const int DELAY_MSEC_10;
extern const int DELAY_MSEC_20;
extern const int DELAY_MSEC_30;
extern const int DELAY_MSEC_40;
extern const int DELAY_MSEC_50;
extern const int DELAY_MSEC_100;
extern const int DELAY_MSEC_200;
extern const int DELAY_MSEC_250;
extern const int DELAY_MSEC_500;
#endif
#if 1
#define 	 DELAY_MSEC_5 		 (5)
#define	 DELAY_MSEC_10 	(10)
#define	 DELAY_MSEC_20 	(20)
#define	 DELAY_MSEC_30 	(30)
#define	 DELAY_MSEC_40 	(40)
#define 	DELAY_MSEC_50 		(50)
#define 	DELAY_MSEC_100 	 (100)
#define 	DELAY_MSEC_150 	 (150)
#define   DELAY_MSEC_200 	 (200)
#define   DELAY_MSEC_250 	 (250)
#define	 DELAY_MSEC_500 	 (500)
#endif
#define HANDCHARGE_YES     (1)
#define HANDCHARGE_NO     (0)

#define STUBNUMBER_LEN  (8)
/*
extern float singlerated_current; 
extern float largestopt_current;
extern float largestopt_volt;
extern float lowestopt_volt;
extern int totalmodnum;
*/
#pragma pack(push) //
#pragma pack(1)

union _type_int
{

	unsigned int int_value;
	unsigned char value_buff[4];
	
};

union _type_short
{

	short  short_value;
	unsigned char value_buff[2];
	
};

typedef struct SYNCHRO_TIME
{
	unsigned short uwYear;
	unsigned char ucMonth;
	unsigned char ucDay;
	unsigned char ucHour;
	unsigned char ucMinute;
	unsigned char ucSecond;
	unsigned char ucReserve;
} SYNCHRO_TIME_S;
struct _modinforstruct
{
	float singlerated_current;
	float largestopt_current;
	float largestopt_volt;
	float lowestopt_volt;
	//int maxmodnum;
	int totalmodnum;
	unsigned char modlinkstate;
};
//extern struct _modinforstruct  modinforstruct[TOTALMOD_GROUP];;
//error  add by mj_1_24

struct _check_flag
{
	unsigned char car_check;//��λ���
	unsigned char car_cc;
	unsigned char save_warning_flag;
	unsigned char save_battery_err_flag;
	unsigned char save_system_err_flag;
	unsigned char save_moudle_err_flag;
	unsigned char temp1;//�����Ӵ����¶ȡ�
	unsigned char temp2;//�����¶ȡ�
	unsigned char car_link;
	unsigned int delay_idle1;
	unsigned int delay_idle2;
	unsigned int check_car_len;
};
struct _error_flag
{
	unsigned char rfid_noreply_1;//������ͨ�Ź���
	unsigned char rfid_noreply_3;
	unsigned char rfid_timeout_1;//�����ذ�ͨ�ų�ʱ����		!!!����
	unsigned char rfid_timeout_3;
	unsigned char led_hardware_1;//��ʾ��Ӳ����
	unsigned char led_timeout_1;//�����ذ�ͨ�ų�ʱ����
	unsigned char keyboard_hardware_2;//����Ӳ����
	unsigned char keyboard_timeout_2;//�����ذ�ͨ�Ź���
	unsigned char print_hardware_3;//��ӡ��Ӳ����
	unsigned char print_pageout_3;//ȱֽ״̬
	unsigned char print_timeout_3;//�����ذ�ͨ�Ź���
	unsigned char lock_error_2;//��������
	unsigned char meter_error_2;//���Ӳ������	
	unsigned char meter_timeout_2;//�����ذ�ͨ�Ź���			!!!����
	unsigned char emergency_error_2;//��ͣ״̬���                           !!!����
	unsigned char ac_contactor_state_1;//�����Ӵ���״̬���        !!!����
	unsigned char ac_contactor_error_1;//�����Ӵ����������         !!!����
	unsigned char low_volt_power_1;//BMS���Ƿѹ

	unsigned char pack_loss_rate_3;//��ݶ�����					
	unsigned char pack_loss_rate_2;
	unsigned char pack_loss_rate_1;
	unsigned char net_cut_2;//ͨѶ����								!!!����
	unsigned char board_hardware_error_1;//���ذ�Ӳ������		!!!�����ж�cp���㣬��ѹ������
	unsigned char board_soft_error_1;//���ذ�����쳣			!!!�����ж�open�ļ��ȹ���

	unsigned char moudle_unstable_1;//ͨѶ���ȶ�					
	unsigned char moudle_recv_error_1;//ģ��ͨѶ���ն˹���     

	/********һ���ޱ���********/
	unsigned char AC_max_volt_power_1;//�����ѹ            @@
	unsigned char AC_low_volt_power_1;//����Ƿѹ            @@
	unsigned char AC_max_ele_power_1;//�������            @@
	unsigned char AC_freq_power_1;//г�����ޣ�Ԥ����������������
	
};
extern struct _error_flag error_flag;

struct _moudle_flag
{
	unsigned char PFC_high_1;
	unsigned char PFC_low_1;
	unsigned char PFC_err_1;
	unsigned char DC_err_1;
	unsigned char IGBT_cur_1;
	unsigned char IGBT_volt_1;
	unsigned char Volt_changer_1;
	unsigned char Temperature_3;
	unsigned char Temperature_2;
	unsigned char Fan_1;
	unsigned char Non_output_1;
	unsigned char Intemp_high_3;
	unsigned char Winout_high_2;
	unsigned char Winin_high_1;
	unsigned char DCcontactor_statue_1;
	unsigned char DCcontactor_touch_1;
	unsigned char Soft_start_1;
};
extern struct _moudle_flag moudle_flag;

struct _system_flag
{
	unsigned char Insulation_r_1;
	unsigned char Insulation_err_1;
	unsigned char Fan_err_3;
	unsigned char Winout_high_2;
	unsigned char Winin_high_1;
	unsigned char Read_err_3;
	unsigned char Store_err_3;
	unsigned char InVolt_high_1;
	unsigned char InVolt_low_1;
	unsigned char In_lost_1;
	unsigned char InCur_high_1;
	unsigned char Wave_1;
	unsigned char OutVlot_high_1;
	unsigned char OutVlot_low_1;
	unsigned char OutCur_high_1;
	unsigned char Out_err_1;
	unsigned char Out_non_1;
};
extern struct _system_flag system_flag;

struct _battery_flag
{
	unsigned char SignalVolt_high_1;
	unsigned char SignalTemp_high_1;
	unsigned char BMS_err_1;
	unsigned char BMS_timeout_1;
	unsigned char Battery_against_1;
	unsigned char Battery_non_1;
	unsigned char TotalVolt_high_1;
	unsigned char TotalVolt_low_1;
	unsigned char SOC_high_1;
	unsigned char Battery_insulation_1;
	unsigned char Battery_contactor_1;
	unsigned char CC1_error_1;
};
extern struct _battery_flag battery_flag;


struct _ElecPriceSet_Struct
{
	float starttm_high_1;
	float stoptm_high_1;
	float per_high_1;
	float starttm_peak_1;
	float stoptm_peak_1;
	float per_peak_1;
	float starttm_flat_1;
	float stoptm_flat_1;
	float per_flat_1;
	float starttm_low_1;
	float stoptm_low_1;
	float per_low_1;
	float starttm_high_2;
	float stoptm_high_2;
	float per_high_2;
	float starttm_peak_2;
	float stoptm_peak_2;
	float per_peak_2;
	float starttm_flat_2;
	float stoptm_flat_2;
	float per_flat_2;
	float starttm_low_2;
	float stoptm_low_2;
	float per_low_2;
};



struct _ElecPrice_Struct
{
	unsigned char flagGethighStartTm_1;
	struct timeval highstarttm_1;
	struct timeval highnowtm_1;
	unsigned char flaggethigh_startEnegy_1;
	float high_startEnegy_1;
	float high_nowEnegy_1;
	
	unsigned char flagGetpeakStartTm_1;
	struct timeval peakstarttm_1;
	struct timeval peaknowtm_1;
	unsigned char flaggetpeak_startEnegy_1;
	float peak_startEnegy_1;
	float peak_nowEnegy_1;

	unsigned char flagGetflatStartTm_1;
	struct timeval flatstarttm_1;
	struct timeval flatnowtm_1;
	unsigned char flaggetflat_startEnegy_1;
	float flat_startEnegy_1;
	float flat_nowEnegy_1;

	unsigned char flagGetlowStartTm_1;
	struct timeval lowstarttm_1;
	struct timeval lownowtm_1;
	unsigned char flaggetlow_startEnegy_1;
	float low_startEnegy_1;
	float low_nowEnegy_1;

	unsigned char flagGethighStartTm_2;
	struct timeval highstarttm_2;
	struct timeval highnowtm_2;
	unsigned char flaggethigh_startEnegy_2;
	float high_startEnegy_2;
	float high_nowEnegy_2;
	
	unsigned char flagGetpeakStartTm_2;
	struct timeval peakstarttm_2;
	struct timeval peaknowtm_2;
	unsigned char flaggetpeak_startEnegy_2;
	float peak_startEnegy_2;
	float peak_nowEnegy_2;

	unsigned char flagGetflatStartTm_2;
	struct timeval flatstarttm_2;
	struct timeval flatnowtm_2;
	unsigned char flaggetflat_startEnegy_2;
	float flat_startEnegy_2;
	float flat_nowEnegy_2;

	unsigned char flagGetlowStartTm_2;
	struct timeval lowstarttm_2;
	struct timeval lownowtm_2;
	unsigned char flaggetlow_startEnegy_2;
	float low_startEnegy_2;
	float low_nowEnegy_2;
};
struct _ChrProcessShow_DataStruct
{
	unsigned char  stubischarging;
	unsigned char GetStartSoc_Flag;
	unsigned char  Start_Soc;
	unsigned char Total_SOC;
	unsigned char GetStopSoc_Flag;
	unsigned char Stop_SOC;
	unsigned char Cell_type;
	unsigned char HaveStartKWH_Flag;
	unsigned char  UserCharge_sucess_flag;
	unsigned char Oldstubischarging;
	//BOOL StopCharge_flag;
	//charge by time 
	unsigned char HaveStartChrTm_Flag;
	unsigned char HaveStopChrTm_Flag;
	unsigned char ChargeGunLinkState;
	unsigned char modstate;
	float  ChrVoltMesurValue;
	float  ChrCurrentMesurValue;
	float BMS_VoltNeed;
	float BMS_CurrentNeed;
	float  Start_KWH;
	float  Current_KWH;
	float  Used_KWH;
	float Stop_KWH;
	float Higestsinglevolt;
	float HigestsingleTemp;
	float OutPutPower;
	float  UserNeedChr_KWH;
	float UserCard_LeftMoney;
	float UserCard_UsedTotalMoney;
	float ChargeService_Money;
	float UsedElectric_Money;
	float  chargekwh_frmnetwork;
	
	short ChrLeftTm;
	short ChrUsedTm;
	short Total_AH;
	
	unsigned int UserNeed_Time;//in sec
	unsigned int stopsoc_frmnetwork;
	unsigned int chargetime_frmnetwork;
	
	struct timeval  StartChargeTm;
	struct timeval  CurrentChargeTm;
	struct timeval  Stopcharge_TM;
	SYNCHRO_TIME_S Startcharge_SystemTM;
	SYNCHRO_TIME_S Stopcharge_SystemTM;
	
};
//extern struct _ChrProcessShow_DataStruct  ChrProcessShow_DataStruct_Last[TOTALBOARD_GUN_NUM];;
//extern struct _ChrProcessShow_DataStruct  ChrProcessShow_DataStruct[TOTALBOARD_GUN_NUM];;
#if 1
struct _UserInfor_Struct
{
	unsigned char getmaincard_flag;
	unsigned char  Chargeing_flag;
	//unsigned char gun_needcharge;
	int chargetype_ac_dc;
	int acstopcharge_count;
	//storecerrent card number
	unsigned char chargetype;
	unsigned char OldCardNumber_one[17];
	unsigned char OldCardNumber_two[17];
	unsigned char CurrentCardNumber[17];
	unsigned char tempcardnumber[17];
	//storecerrent card PASSWORD
	unsigned char CurrentCardPassword[17];
	unsigned char Car_plate[8];
	unsigned char PassWdIdentify_OK_Flag;
	unsigned char  UserChargeVarity;
	//flag stands for whether it is charging
	unsigned char getbookchargeflag;//ԤԼ����ʶ
	unsigned char stopchargeflag;//ֹͣ����ʶ
	float handsetvolt;
	float handsetcurrent;
	
};
extern struct _UserInfor_Struct 	UserInfor_Struct;

struct _sysconfigstruct
{
	//���׮���
	
	//use for 0x46
	unsigned int   Carchecklen;
	unsigned char Stub_number[STUBNUMBER_LEN];
	unsigned char Stub_Type;//���׮����?	unsigned char CanSvrCellType;//�ͷ���������
	unsigned char canservecelltype;
	unsigned char Chr_GunNum;//���ǹ����?
	unsigned char ServerIp[20];//���ķ�������ַ
	unsigned int ServerPort;//���ķ������˿�
	//use for 0x10
	//系统设备资产编号
	unsigned char PoropertyInfor[20];
	//软件版本
	unsigned char SoftWare_Version[4];
	//启动次数
	unsigned int Start_Number;
	//0x41
	unsigned int  repeatlogininterval;
	//x049
	unsigned char  heartbeatsndinterval;
	unsigned char hearbeattimeouttimes;
	//0xe0
	unsigned char communicationmode;
	unsigned char  settimesndpackinterval;

	//sys start time use for 0x10
	SYNCHRO_TIME_S   SysStartTime;
	struct timeval      timeval_starttime;

	//the network transfor link road
	int DataPackTranformWay;
	unsigned char NeedNetWorkSuppot;
	float HandsetLargestVoltOpt;
	float HandsetLargestCurrentOpt;
	float SysElectricityPrice;
	float SysSeviceMoney;
	float  Ac_LimitCurrent;
	char LocalIpAddr[20];
	char LocalMask[20];
	char LocalGetWay[20];
	char LocalMac[20];
	char SocketConnectNeedReboot;
	char GprsConnectNeedReboot;
	char  sysfirst_syntime;
	int historysave_interval;
	int chargebyhand;
	unsigned int stub_power_kw;
	unsigned char charge_linkway;
	
	
};
struct _subdevicestate
{
	unsigned char chargegun_linkstate :1;
	unsigned char bms_allowcharge :1;
	unsigned char assistenpower_state :1;
	unsigned char contactor_active_state :1;
	unsigned char contactor_nagative_state :1;
	unsigned char bms_stopcharge :1;
};
#endif

#pragma pack(pop)//
#if 0
float  setstarttm[MAXPERIOD_NUM];
float  setstoptm[MAXPERIOD_NUM];
float  perprice[MAXPERIOD_NUM];
unsigned char  getstarttm_flag[MAXPERIOD_NUM];
unsigned char  getstarttm_flag[MAXPERIOD_NUM];
unsigned char  getstarttm_flag[MAXPERIOD_NUM];
#endif
enum
{
	HIGH_1=0,
	PEAK_1,
	FLAT_1,
	LOW_1,
	HIGH_2,
	PEAK_2,
	FLAT_2,
	LOW_2,
	MAXPERIOD_NUM,
	
};

//timer count manager
extern struct _tickmanegerstruct	tickmanegerstruct;
struct  _MYLOCK_STRUCT
{
	 unsigned char  ReadLock_EmergencyState;
	 unsigned char  ReadLock_ModuleInter;
	 unsigned char  ReadLock_NetWorkInter;
	 
};

struct _mutex_lock_struct 
{
	pthread_mutex_t mutex_4096;
	pthread_mutex_t mutex_4352;
	pthread_mutex_t mutex_1536;
	
	
};

struct _modmutex_lock
{
	pthread_mutex_t mutex_modstate;
	
};

struct _mutexmodopt_struct 
{
	pthread_mutex_t readlock_modoutput;
	pthread_mutex_t readlock_modset;
	pthread_mutex_t lock_getstatecount;
	
};
struct _boardiner_manager
{
	unsigned char tick_boardiner_count;
	bool boardlinkstate_err;
	pthread_mutex_t lock_boardinter_count;
};
extern struct _modmutex_lock  modmutex_lock;
//extern struct _mutex_lock_struct mutex_lock_struct[TOTALMOD_GROUP];
extern struct _devicesate_watch devicesate_watch;

#endif /* PUBHEADER_H_ */
