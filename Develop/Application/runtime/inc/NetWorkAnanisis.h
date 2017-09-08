/* 
 *  �ļ���:NetWorkAnanisis.H
 *
 *  �޸�����: 2015-1-13
 *
 *  �汾V1.0
 *
 *  ά����:eves
 */

#ifndef NETWORKANANISIS_H_
#define NETWORKANANISIS_H_
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<time.h>  
#include<sys/time.h>
#include<string.h>
#include "pubheader.h"
#include <sys/stat.h>
#include <fcntl.h>              // open
#include "DB_Unity.h"
#include <stdlib.h>             // exit
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "businter.h"
#ifndef	TRUE
	#define  TRUE (1)
#endif

#ifndef	FALSE
	#define  FALSE (0)
#endif

#define NETWORK_DEBUG 1

#define STUBNUMBER_LEN  (8)
#define BOOK_SURE   (0x01)
#define BOOK_CANCELL  (0x02)
#define BOOK_STOP    (0x03)

//modify by libo2015-02-03
#define ERRINFOR_SAVECOUNT   (100)
#define HISTORY_SAVECOUNT   (100)
#define WARING_SAVECOUNT   (100)
#define EVENT_SAVECOUNT   (100)
#define PROCESS_SAVECOUNT   (100)
#define WAITUPDATE_SAVECOUNT   (1000)
#define BACKUPCHARGE_SAVECOUNT   (100)

#define  SYSLOG_MAXLEN 	(8000)
#define  ERRINFOR_MAXLEN 	(80000)
#define  WAITUPDATEHISTORY_MAXLEN 	(80000)
#define  BACKUPCHARGE_MAXLEN 	(100000)
#define  EVENT_MAXLEN 	(100000)
#define  WARING_MAXLEN 	(100000)
#define   PROCESS_MAXLEN 	(100000)
#define  HISTORY_MAXLEN 	(100000)

enum
{
	SYSTEM_ERRSTATE=1,
	CHRSYSTEM_ERRSTATE,
	CHRMODULE_ERRSTATE,
	CEL_ERRSTATE
};
/****************************
	FACTOR DEFINE
****************************/
#define  VOLT_FACTOR  	(10)
#define  CURRENT_FACTOR 	 (10)
#define  SINGLEVOLT_FACTOR 	 (100)
#define  CAPA_FACTOR  	(1)
#define  SOC_FACTOR 	 (1)
#define  TEMP_FACTOR  	(1)
#define  BOXID_FACTOR 	 (1)
#define  BOXPOS_FACTOR 	 (1)
#define  METER_FACTOR  	(100)
#define  POWR_FACTOR  	(10)


//最多模块数量
#define MAXMOULENUMBER (12)
//max charge gun number
#define MAXCHAGEGUNNUMBER (2)


#define  MAXSNDPACKLEN (1024)
#define  RECVMAXPACKLEN (1024)

//use for 0x90
#define  MAXHISTORYRETURNCOUNT  (10)
//use for 0x86
#define  MAXEVENTRETURNCOUNT  (10)
//use for 0x87
#define  MAXWARINGRETURNCOUNT  (10)
#define  MAXPROCESSRETURNCOUNT  (2)

//#define   MAXCHAROFONELINE    (512)
#define   MAXCHAROFONELINE    (1024)

 #define DEFAULT_LOGININTERVAL (30*60) //default 30 min
 //USE FOR 0x49 0x59
#define   HEARTBEATSNDINTERVAL  (3)//SEC
#define   HEARTBEATTIMEOUTCOUNT  (3)//SEC
//USE for 0xE0 0XF0
#define   CHECKNETWORKWORKMODE (1)
#define   AUTONETWORKWORKMODE (2)
#define   SETTIMESNDTIMEINTERVAL (15)


//USE FOR 0x64
#define MAXCHARGERECRDNUMBER  (5)

// 3G
#define DATATRANSFORM_BYTDSCDMA (11)
#define DATATRANSFORM_BYWCDMA (12)
#define DATATRANSFORM_BYCDMA (13)
#define DATATRANSFORM_BYWIFI (10)
#define DATATRANSFORM_BYHYALINE (1)
//socket
#define DATATRANSFORM_BYSOCKET (2)
#define HISTORYSAVE_INTERVAL    (60)
//data struct head define

#define DATAHEAD_FIRSTBYTE 	(0xFA)
#define DATAHEAD_SECONDBYTE 	(0xF5)
#define DATAHEAD_SOFTWAREVERSION 	(0x80)

/***********************
	system papa manager
**************************/
#define	 NET_CMDCODE_0X41   (0x41)
#define  NET_CMDCODE_0X51   (0x51)

#define  NET_CMDCODE_0X42   (0x42)
#define  NET_CMDCODE_0X52   (0x52)

#define  NET_CMDCODE_0X46   (0x46)
#define  NET_CMDCODE_0X56   (0x56)

#define  NET_CMDCODE_0X48   (0x48)
#define  NET_CMDCODE_0X58   (0x58)


#define  NET_CMDCODE_0X49   (0x49)
#define  NET_CMDCODE_0X59   (0x59)

#define  NET_CMDCODE_0X40   (0x40)
#define  NET_CMDCODE_0X50   (0x50)
/***********************
	state manager
	**************************/
#define CODE_LOGIN             (0x01)
#define NET_CMDCODE_0X09        (0x09)
#define CODE_ANSERLOGIN        (0x10)


#define  NET_CMDCODE_0X11      (0x11)

#define  NET_CMDCODE_0X05      (0x05)
#define  NET_CMDCODE_0X15      (0x15)

#define  NET_CMDCODE_0X07      (0x07)
#define  NET_CMDCODE_0X17      (0x17)

#define  NET_CMDCODE_0X08      (0x08)
#define  NET_CMDCODE_0X18      (0x18)

/***********************
	workstate pama get
	************************/
#define  NET_CMDCODE_0XE0  	(0xE0)
#define  NET_CMDCODE_0XF0  	(0xF0)

#define  NET_CMDCODE_0X21   (0x21)
#define  NET_CMDCODE_0X31   (0x31)

#define  NET_CMDCODE_0X22   (0x22)
#define  NET_CMDCODE_0X32   (0x3A) //32��Ϊ3A
#define  NET_CMDCODE_0X3A   (0x3A) //32��Ϊ3A


#define  NET_CMDCODE_0X23   (0x23)
#define  NET_CMDCODE_0X33   (0x33)

#define  NET_CMDCODE_0X24   (0x24)
#define  NET_CMDCODE_0X34   (0x34)

#define  NET_CMDCODE_0X25   (0x25)
#define  NET_CMDCODE_0X35   (0x35)

#define  NET_CMDCODE_0X26 	(0x26)
#define  NET_CMDCODE_0X36   (0x36)
#define  NET_CMDCODE_0X39   (0x39)

  
/***********************
	charge sevice  infor
	**************************/
#define  NET_CMDCODE_0X70     (0x70)
#define  NET_CMDCODE_0X60     (0x60)
#define  NET_CMDCODE_0X69     (0x69)

#define  NET_CMDCODE_0X71     (0x71)
#define  NET_CMDCODE_0X61     (0x61)

#define  NET_CMDCODE_0X72     (0x72)
#define  NET_CMDCODE_0X62     (0x62)

#define  NET_CMDCODE_0X73     (0x73)
#define  NET_CMDCODE_0X63     (0x63)

#define  NET_CMDCODE_0X74     (0x74)
#define  NET_CMDCODE_0X64     (0x64)

#define  NET_CMDCODE_0X75     (0x75)
#define  NET_CMDCODE_0X65     (0x65)

#define  NET_CMDCODE_0X78     (0x78)
#define  NET_CMDCODE_0X68     (0x68)
/***********************
	history data get
	**************************/
#define  NET_CMDCODE_0X80      (0x80)
#define  NET_CMDCODE_0X90      (0x90)
#define  NET_CMDCODE_0X92      (0x92)

#define  NET_CMDCODE_0X86      (0x86)
#define  NET_CMDCODE_0X96      (0x96)

#define  NET_CMDCODE_0X87      (0x87)
#define  NET_CMDCODE_0X97      (0x97)

#define  NET_CMDCODE_0X88      (0x88)
#define  NET_CMDCODE_0X98      (0x98)

#define  NET_CMDCODE_0X43   (0x43)
#define  NET_CMDCODE_0X53   (0x53)

#define  NET_CMDCODE_0XE1   (0xe1)
#define  NET_CMDCODE_0XF1   (0xf1)

#define  NET_CMDCODE_0XE2   (0xe2)
#define  NET_CMDCODE_0XF2   (0xf2)

#define  NET_CMDCODE_0XC1   (0xc1)
#define  NET_CMDCODE_0XD1   (0xd1)

#define  NET_CMDCODE_0XC2   (0xc2)
#define  NET_CMDCODE_0XD2   (0xd2)

#define  NET_CMDCODE_0XC3   (0xc3)
#define  NET_CMDCODE_0XD3   (0xd3)

#define  NET_CMDCODE_0XA0   (0xa0)
#define  NET_CMDCODE_0XB0   (0xb0)

#define  NET_CMDCODE_0XA1   (0xa1)
#define  NET_CMDCODE_0XB1   (0xb1)

#define  NET_CMDCODE_0XA2   (0xa2)
#define  NET_CMDCODE_0XB2   (0xb2)

#define  NET_CMDCODE_0XA3   (0xa3)
#define  NET_CMDCODE_0XB3   (0xb3)

#define  NET_CMDCODE_0X2B   (0x2B)
#define  NET_CMDCODE_0X3B   (0x3B)
//#define  MAXSNDPACKLEN (1024)
#define  RECVMAXPACKLEN (1024)




#pragma pack(push) //
#pragma pack(1)
//USE FOR 0X72
struct _CellInforStruct
{
  unsigned char CellCode[8];

};

/***********************
	system papa manager
**************************/
struct _cmd_code_0x41//锟斤拷锟阶拷锟斤拷锟斤拷斩瞬锟斤拷锟斤拷锟斤拷锟?
{
	//锟矫伙拷ID
	short UerID;
	//指锟斤拷锟斤拷锟斤拷
	short CMD_Serail;
	unsigned	int systotalcapa;
	unsigned	int setareacapa;
	unsigned	int  cellareacapa;
	unsigned	int  dealareacapa;
	//锟斤拷锟阶╋拷锟绞憋拷锟斤拷锟? 默锟斤拷30锟斤拷锟斤拷
	unsigned	int Login_InterTime;

};

struct _cmd_code_0x42//锟斤拷锟阶拷锟斤拷锟斤拷斩瞬锟斤拷锟斤拷锟斤拷锟?
{
	//锟矫伙拷ID
	short UerID;
	//指锟斤拷锟斤拷锟斤拷
	short CMD_Serail;
	SYNCHRO_TIME_S CenterSndCheck;
};

struct _cmd_code_0x46//锟斤拷锟阶拷锟斤拷锟斤拷斩斯锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟?
{
	//锟矫伙拷ID
	short UerID;
	//指锟斤拷锟斤拷锟斤拷
	short CMD_Serail;
	//锟斤拷锟阶拷锟斤拷
	unsigned char Stub_number[STUBNUMBER_LEN];
	unsigned char Stub_Type;//锟斤拷锟阶拷锟斤拷锟?
	unsigned char CanSvrCellType;//锟酵凤拷锟斤拷锟斤拷锟斤拷锟斤拷
	unsigned char Chr_GunNum;//锟斤拷锟角癸拷锟斤拷锟?
	unsigned char ServerIp[4];//锟斤拷锟侥凤拷锟斤拷锟斤拷锟斤拷址
	unsigned char ServerPort[2];//锟斤拷锟侥凤拷锟斤拷锟斤拷锟剿匡拷

};

//鏈嶅姟鍣ㄥ績璺冲寘涓嬪彂
struct _cmd_code_0x48
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	//蹇冭烦搴旂瓟
	short HeartBeatAnser;
};
//鏈嶅姟鍣ㄥ績璺冲寘涓婁紶
struct _cmd_code_0x58
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	//蹇冭烦搴旂瓟
	short HeartBeatAnser;
};
struct _cmd_code_0x49//锟斤拷锟斤拷锟斤拷锟较拷锟斤拷锟斤拷锟斤拷锟?
{
	//锟矫伙拷ID
	short UerID;
	//指锟斤拷锟斤拷锟斤拷
	short CMD_Serail;
	//锟斤拷锟斤拷锟斤拷媳锟斤拷锟斤拷时锟斤拷
	unsigned char HeartBeatSend_interval;
	//锟斤拷锟斤拷锟斤拷写锟斤拷锟?
	unsigned char HeartBeatTimeout_count;

};

struct _cmd_code_0x40
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2

	unsigned char NeedCard_Flag;
	unsigned char NeedPassWd_Flag;
	unsigned char NeedChrgCheck_Flag;
	unsigned char NeedCardPlate_Flag;
	unsigned char NeedChrgunUnlock_Flag;

	unsigned char NeedLinkCheck_Flag;
	unsigned char NeedChrgModeChoise_Flag;
	unsigned char NeedCharge_Flag;
	unsigned char NeedCardStop_Flag;
	unsigned char NeedCutDownLink_Flag;
	
	unsigned char NeedChrgunlock_Flag;
	unsigned char NeedCalate_Flag;
	unsigned char NeedPrinter_Flag;
	unsigned char NeedCheck_Flag;
};

struct _cmd_code_0x50
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	short SetResult;
};

struct _cmd_code_0x43//锟斤拷锟斤拷锟斤拷锟较拷锟斤拷锟斤拷锟斤拷锟?
{
	short UerID;
	short CMD_Serail;
	unsigned char Need_restart;
};

struct _cmd_code_0x53//Only not in charging , take  effect !
{
	short UerID;
	short CMD_Serail;
	unsigned char Need_restart;
};

/***********************
state manager
**************************/
struct _cmd_code_0x01//涓績绯荤粺涓嬭揪绛惧埌鍛戒护
{
	//鐢ㄦ埛ID
	short UerID;
	//鎸囦护搴忓垪
	short CMD_Serail;
} ;

struct _cmd_code_0x10//涓績绯荤粺鏌ヨ绛惧埌搴旂瓟 /
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	//鐢垫睜鍏呭偍涓€浣撴満缂栫爜
	unsigned char Stub_number[STUBNUMBER_LEN];
	//绯荤粺璁惧璧勪骇缂栧彿
	unsigned char FactoryInfor[20];
	//杞欢鐗堟湰
	unsigned char SoftWare_Version[4];
	//鍚姩娆℃暟
	unsigned int Start_Number;
	//鍌ㄥ瓨鎺т欢瀹归噺
	unsigned char  TotalNumberOfFreeBytes[4];
	//涓績绯荤粺杞欢宸茬粡鎸佺画杩愯鏃堕棿
	unsigned int CenterSystem_TotalRunTm;
	//unsigned int LastStartTm;
	//unsigned int LastLoginTm;

};

struct _cmd_code_0x11
{
	unsigned char Stub_number[STUBNUMBER_LEN];
	unsigned char StubWorkState;
	unsigned int SysErrorInfor;
	unsigned char PeripherydeviceState[8];
};

struct  _ControlPama
{
	unsigned char ModuleIndex;
	short SetPamaValue;

};
struct _cmd_code_0x05//涓績绯荤粺鏌ヨ绛惧埌搴旂瓟 /
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char PamaType;
	unsigned char ChargeMOduleNumber;
	//struct  _ControlPama ControlPama[MAXMOULENUMBER];
	struct  _ControlPama ControlPama;
};

struct _cmd_code_0x07
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char CharginggunNum;
	unsigned char ChargingType;
	//unsigned char ModuleNumber;
	//unsigned char ChargeGunIndex;
	//unsigned char ChargeGunIndex[MAXCHAGEGUNNUMBER];
};
/*
struct _cmd_code_0x17
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char ModuleNumber;
	unsigned char ChargeModuleIndex;
	
	short LargestOutVolt;
	short LittestOutVolt;
	short LargestOutCurrent;
	short SingleCellAllowbigestVolt;
	unsigned char CellAllowbigestTemp;
	unsigned char BMS_AllowCharge;
	short BMS_VoltNeed;
	short BMS_CurrentNeed;
	short BMS_AllowSingleLargestVolt;
	short BMS_AllowLargestTemp;
	unsigned char BmsCommunicationVersion[3];
	unsigned char CellBoxNUmber;
	unsigned char CellTotalSerialNUmber;
	unsigned char CellTotalParallelNUmber;
	short CellRatedCapa;
	
};
*/
struct _Crrentchrmoduleinfor
{
	//unsigned char Moduleposcode;
	unsigned char ChargingType;
	short  LargestOutVolt;
	short  LittlestOutVolt;
	short LargestCurrent;
	//short LittlestCurrent;
	short LargestSingleVolt;
	short LargestTemp;
	unsigned char BMS_AllowCharge;
	short BMS_NeedVolt;
	short BMS_Needcurrent;
	short BMS_AllowLargestSingleVolt;
	short BMS_LargestAllowcellTemp;
	unsigned char CommunicationSoftwarVersion[3];
	unsigned char CellBoxNumber;
	unsigned char CellSerialNumber;
	unsigned char CellParallelNumber;
	short CellGroupRatedCapa;
	
};

struct _cmd_code_0x17
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2

	unsigned char ChargingGunNum;
	//unsigned char ModuleNumber;
	//struct _Crrentchrmoduleinfor Crrentchrmoduleinfor[MAXMOULENUMBER];
	struct _Crrentchrmoduleinfor Crrentchrmoduleinfor;
};
struct _cmd_code_0x08
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char ChargingGunNum;
	//unsigned char ChargeGunIndex[MAXCHAGEGUNNUMBER];
	unsigned char ChargingType;
};

/*
struct _CrrentchrCellinfor
{
	unsigned char ChargingType;
	unsigned char Car_VIN[17];//if no,fill it with space
	unsigned char CellBmsCode[8];
	unsigned char CellBoxNumber;
	struct	 _CellInforStruct CellInforStruct[10];
	
	
};
*/
struct _cmd_code_0x18
{
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char ChargingGunNum;
	unsigned char ChargingType;
	unsigned char Car_VIN[17];//if no,fill it with space
	unsigned char CellBmsCode[8];
	unsigned char CellBoxNumber;
	unsigned char bnm[MAXCELLBOXNUMBER][8];
	//struct	 _CrrentchrCellinfor CrrentchrCellinfor[MAXCELLBOXNUMBER][8];
	unsigned char EndIdentify;
};
/***********************
workstate pama get
**************************/

struct _cmd_code_0xE0// 通锟斤拷模式锟斤拷锟斤拷锟斤拷锟斤拷应锟斤拷
{
	//鐢ㄦ埛ID
	short UerID;
	//鎸囦护搴忓垪
	short CMD_Serail;
	//通锟斤拷模式锟斤拷1为应锟斤拷模式锟斤拷2为锟较憋拷模式
	unsigned char NetWorkMode;
	//锟皆讹拷锟较憋拷时锟斤拷锟较憋拷锟斤拷锟斤拷锟侥拷锟轿?5锟斤拷
	unsigned char AnserInterval;

};

struct _cmd_code_0x21
{
	//鐢ㄦ埛ID
	short UerID;
	//鎸囦护搴忓垪
	short CMD_Serail;

};
struct _cmd_code_0x31
{
	//鐢ㄦ埛ID
	short UerID;
	//鎸囦护搴忓垪
	short CMD_Serail;
	unsigned char InptPowerState;
	unsigned char AverageTemp;
	unsigned char OutSideTemp;
	unsigned char WorkState;
	unsigned char CanChrModuleNumber;
	short OutPtActivePower;
	short OutptReactivePower;
	unsigned char ChrSystemTotalState;
	unsigned int ChrSystemErrorState;
	unsigned int AC_DC_ContlModuleErrorState;
	unsigned char FanState;
	unsigned char AirFanState;
	unsigned char HeatState;
	unsigned char FogWaringState;
	unsigned char ShakeSensorState;
	unsigned char ChargingGunNum;
};
struct _cmd_code_0x22
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char ChargingGunNum;
	unsigned char ChargeType[MAXCHAGEGUNNUMBER];
};
struct _cmd_code_0x3A
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char  ChrGunNmber;
	unsigned char  ChargingType;
	unsigned char  ChrGunState;
	unsigned char  CellBmsCode[8];
	short CellTotalVolt;
	short CellTotalCurrent;
	
	short HigestSingleVolt;
	short LittlestSingleVolt;
	unsigned char TempCheckHigestValue;
	unsigned char TempCheckLittlestValue;
	
	short HigestSingleVoltPos;
	short LittlestSingleVoltPos;
	unsigned char TempCheckHigestValue_pos;
	unsigned char TempCheckLittlestValue_pos;
	
	unsigned char Soh_Value;
	unsigned char Soc_Value;
	unsigned char ChrGunWorkState;
	short bmschrlefttm;
	#if 0
	unsigned char  ChargingType2;
	unsigned char  ChrGunState2;
	unsigned char  CellBmsCode2[8];
	short CellTotalVolt2;
	short CellTotalCurrent2;
	
	short HigestSingleVolt2;
	short LittlestSingleVolt2;
	unsigned char TempCheckHigestValue2;
	unsigned char TempCheckLittlestValue2;
	
	short HigestSingleVoltPos2;
	short LittlestSingleVoltPos2;
	unsigned char TempCheckHigestValue_pos2;
	unsigned char TempCheckLittlestValue_pos2;
	
	unsigned char Soh_Value2;
	unsigned char Soc_Value2;
	unsigned char ChrGunWorkState2;
	short bmschrlefttm2;
	#endif
};
struct _cmd_code_0x23
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char ChargingGunNum;
	unsigned char ChargingType[MAXCHAGEGUNNUMBER];
};
struct _cmd_code_0x33
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned int ChargingGunNum;
	unsigned char  ChrGun_Pos;
	short Total_KWH;
	short Total_AH;
	short Total_ChrgeTm;
	unsigned char Start_Soc;
	unsigned char Current_Soc;
	
};
struct _cmd_code_0x34
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char ChargingGunNum;
	unsigned char  ChargingType;
	unsigned char ChrGunEexState;
	unsigned char MoudleId[8];
	unsigned char CellBmsCode[8];

	short  ChrVolt;
	short  ChrCurrent;
	short  OutPutPower;
	short  ChrModuleErrorCode; 
	
	unsigned char  Cu_State;
#if 0
	unsigned char  ChargingType2;
	unsigned char ChrGunEexState2;
	unsigned char MoudleId2[8];
	unsigned char CellBmsCode2[8];

	short  ChrVolt2;
	short  ChrCurrent2;
	short  OutPutPower2;
	short  ChrModuleErrorCode2; 
	
	unsigned char  Cu_State2;

#endif


	
};
struct _cmd_code_0x24
{
	
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char ChargingGunNum;
	unsigned char ChargingType[MAXCHAGEGUNNUMBER];
};
struct _cmd_code_0x25
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char ChargingGunNum;
	unsigned char ChargingType[MAXCHAGEGUNNUMBER];
};
struct _CellSystemErrorInfor
{
	unsigned char CellErrorGroup_ID;
	unsigned char CellErrorgrade;
	short CellErrorCode;
	unsigned char CellErrorPosTotal;
	short CellErrorPos[10];
	unsigned char CellErrorEnd;
	
};

struct _cmd_code_0x35
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char  ChargingGunNum;
	unsigned char  ChargingType;
	
	struct _CellSystemErrorInfor CellErrorInfor;
	struct _CellSystemErrorInfor CellSysTemTotalErrorInfor;
	struct _CellSystemErrorInfor BmsErrorInfor;
	
	//unsigned char ErrorInfor[128];

	
};
struct _SingleCheckPapa
{
	unsigned char ChargeGunIndex;
	unsigned char CellSerailNumber;
};
struct _cmd_code_0x26
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char SingalCheckType;
	unsigned char ChargingGunNum;
	//struct _SingleCheckPapa  SingleCheckPapa[MAXMOULENUMBER];
	struct _SingleCheckPapa  SingleCheckPapa;
};
struct _SingleCellInforCheck
{
	unsigned char  ChargingType;
	unsigned char  CellSerialNnumber;
	unsigned char  CellBoxCode[8];
	unsigned char  SingleCheckPointNUmber;
	short  SinglePama[MAX_SINGLEVOLT_POINT];
};
struct _cmd_code_0x36
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char SingleCheckPamaType;
	unsigned char ChargingGunNum;
	struct _SingleCellInforCheck  SingleCellInforCheck;
	
};
struct _cmd_code_0x39
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char ChargingGunNum;
	unsigned char  ChargingType;
	short Used_KWH;
	short Total_AH;
	short Total_ChrgeTm;
	unsigned char Start_Soc;
	unsigned char Current_Soc;
	int  Current_KWH;
};


/***********************
charge sevice  infor
**************************/
struct _cmd_code_0x70
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char CardNumber[16];
	unsigned char CertificateType;
	unsigned char  CertificateNumber[20];
	short AcceptChanel;
	unsigned char IssuingSerialNUmber[20];
	unsigned char IssuingCode[15];
	unsigned char AcceptOperatorCode[20];
	SYNCHRO_TIME_S DealTime;
	unsigned char PassWrd[16];
	unsigned char ChargeIdentify;
	unsigned char ChargeMoney[12];
	unsigned char PackIndentify[8];
	
};

struct _cmd_code_0x60
{
  //鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char ResponseCode[6];
	unsigned char ResponseCodeDetail[100];
	unsigned char GuestNumber[30];
	unsigned char MainCountLeftMoney[12];
	unsigned char MainCountCanUseLftMoney[12];
	unsigned char ServiceMoney[12];
	unsigned char ServiceCountCanUseLeftMoney[12];
	unsigned char CenterDealSerailNumber[15];
	unsigned char BOSSSerailNumber[20];
	SYNCHRO_TIME_S  DealTime;
	unsigned char PackIndentify[8];
 
};
struct _cmd_code_0x69
{
  //鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char RfidCardNumber[16];
	unsigned char GuestName[20];
	unsigned char ResponseCode[6];
	unsigned char ResponseCodeDetail[64];
	unsigned char GuestNumber[30];
	unsigned char MainCountLeftMoney[12];
	unsigned char MainCountCanUseLftMoney[12];
	unsigned char ServiceMoney[12];
	unsigned char ServiceCountCanUseLeftMoney[12];
	unsigned char CenterDealSerailNumber[15];
	unsigned char BOSSSerailNumber[20];

	int  allow_charge_energy;
	int allow_charge_time;

	SYNCHRO_TIME_S  DealTime;
	unsigned char PackIndentify[8];

};


struct _cmd_code_0x71
{
 
	unsigned char CardNumber[16];
	unsigned char DealType;
	SYNCHRO_TIME_S  DealTime;
	
};

struct _cmd_code_0x61
{
  //鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char CardNumber[16];
	unsigned char DealType;
	SYNCHRO_TIME_S  DealTime;
	unsigned char CenterDealSerailNumber[15];
	unsigned char BOSSSerailNumber[20];
};

//USE FOR 0X62
struct _CellInforStructIdentify
{
  unsigned char CellCode[8];
  unsigned char CellType;
};
struct _cmd_code_0x72
{
	//鐢ㄦ埛ID
	//short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	//short  CMD_Serail;//BYTE=2
	unsigned char  ModuleNumber;
	unsigned char ModuleIndex;
	unsigned char  CellNumber;
	struct _CellInforStruct CellInforStruct[MAXCELLBOXNUMBER];
	SYNCHRO_TIME_S  DealTime;
};
struct _cmd_code_0x62
{
  //鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char  ModuleNumber;
	unsigned char ChargingType;
	unsigned char  CellNumber;
	struct _CellInforStructIdentify CellInforStruct[MAXCELLBOXNUMBER];
	SYNCHRO_TIME_S  DealTime;
	
};
struct _cmd_code_0x73
{
	  //鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char ModuleIndex;
	unsigned char CardNumber[16];
	unsigned char CellBmsCode[8];
	unsigned char Car_VIN[17];//if no,fill it with space
	unsigned char Car_plate[8];
	unsigned char Start_Soc;
	unsigned char Stop_Soc;
	short UseCapa;//an*hour
	short Use_kwh;
	unsigned int chargecontinuetm;//sec
	unsigned char DealType;
	unsigned char DealType_pama;
	unsigned char Stop_Reason;
	SYNCHRO_TIME_S Startcharge_TM;
	SYNCHRO_TIME_S Stopcharge_TM;
	SYNCHRO_TIME_S DealTime;
};
struct _cmd_code_0x63
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char ModuleIndex;
	unsigned char CardNumber[16];
	unsigned char GuestNumber[30];
	unsigned char CanChargeLftTime[12];
	unsigned char MainCountLftMoney[12];
	unsigned char UseMoney[12];
	unsigned char ServiceCountLftMoney[12];
	unsigned char CenterDealSerailNumber[15];
	unsigned char BOSSSerailNumber[20];
	SYNCHRO_TIME_S  DealTime;
};
struct _cmd_code_0x68
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char ModuleIndex;
	unsigned char CardNumber[16];
	unsigned char GuestNumber[30];
	unsigned char UsetimeAndCapa[12];
	unsigned char UseElectirctMoney[12];
	//unsigned char UseMoney[12];
	unsigned char UseServiceMoney[12];
	unsigned char UseTotalMoney[12];
	unsigned char CenterDealSerailNumber[15];
	unsigned char BOSSSerailNumber[20];
	SYNCHRO_TIME_S  DealTime;
};

struct _cmd_code_0x74
{
	unsigned char ModuleIndex;
	unsigned char CardNumber[16];
	unsigned char HistoryCheckCount;
	
};

struct _cmd_code_0x75
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char ChargeGunIndex;
	unsigned char Car_Plate[8];
	SYNCHRO_TIME_S DealTime;
};
struct _RecrdStruct
{
  unsigned char BMS_Code[8];
  unsigned char Start_Soc;
  unsigned char Stop_Soc;
  short  TotalCapa;
  short  TotalKWH;
  int ChargeContinueTime;
  unsigned char ChargeType;
  short ChargeType_Pama;
  unsigned char StopChargeReason;
  SYNCHRO_TIME_S Startcharge_TM;
  SYNCHRO_TIME_S Stopcharge_TM;
  SYNCHRO_TIME_S DealStartTime;
  
};
struct _cmd_code_0x64
{
  //鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char ModuleIndex;
	unsigned char CardNumber[16];
	unsigned char RecrdCount;
	struct _RecrdStruct RecrdStruct[MAXCHARGERECRDNUMBER];
	
};

struct _cmd_code_0x65
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char ChargeGunCode;
	unsigned char CarPalleteCode[8];
	unsigned char Car_VIN[17];
	SYNCHRO_TIME_S DealStartTime;
};

struct _cmd_code_0x78
{
	  //鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	unsigned char ChargeType;
	unsigned char CardNumber[16];
	unsigned char Stub_number[STUBNUMBER_LEN];
	unsigned char Car_VIN[17];//if no,fill it with space
	unsigned char Car_plate[8];
	unsigned char Start_Soc;
	unsigned char Stop_Soc;
	short UseCapa;//an*hour
	short Use_kwh;
	unsigned int chargecontinuetm;//sec
	unsigned char DealType;
	short DealType_pama;
	unsigned char Stop_Reason;
	SYNCHRO_TIME_S Startcharge_TM;
	SYNCHRO_TIME_S Stopcharge_TM;
	SYNCHRO_TIME_S DealTime;
	unsigned  int   Start_KWH;
	unsigned  int   Stop_KWH;
};


/*************************
history record get
**************************/
struct _cmd_code_0x80
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	short  HistoryStartPosIndex;
	unsigned char  CheckCount;
	
};

struct _cmd_code_0x92
{
	//鐢ㄦ埛ID
	//short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	//short  CMD_Serail;//BYTE=2
	//unsigned char  HistoryCheckCount;
	unsigned int  RecordIndex;
	unsigned char ChargeType;
	unsigned char Stub_number[STUBNUMBER_LEN];
	unsigned char  CardNumber[16];
	unsigned char Car_VIN[17];//if no,fill it with space
	unsigned char Car_plate[8];
	unsigned char Start_Soc;
	unsigned char Stop_Soc;
	short UseCapa;//an*hour
	short Use_kwh;
	unsigned int chargecontinuetm;//sec
	unsigned char DealType;
	unsigned char Stop_Reason;
	SYNCHRO_TIME_S Startcharge_TM;
	SYNCHRO_TIME_S Stopcharge_TM;
	//SYNCHRO_TIME_S DealTime;
	unsigned int   Start_KWH;
	unsigned int   Stop_KWH;
};

struct _cmd_code_0x86
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	SYNCHRO_TIME_S Start_TM;
	SYNCHRO_TIME_S Stop_TM;
	unsigned char type_inquire;
	short CheckCount;		//do not need  in 0x96???
};

struct  _partbuf_0x96
{
	unsigned int  index;
	SYNCHRO_TIME_S OccurTm;
	unsigned char type_inquire;
};

struct _cmd_code_0x96
{
	unsigned char Stub_number[STUBNUMBER_LEN];
	unsigned char type_inquire;
	unsigned char num_upload;
	struct _partbuf_0x96  partbuf_0x96[MAXEVENTRETURNCOUNT];
};

struct _cmd_code_0x87
{
	//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	SYNCHRO_TIME_S Start_TM;
	SYNCHRO_TIME_S Stop_TM;
	unsigned char type_inquire;
	short CheckCount;		//do not need  in 0x96???
};

struct  _partbuf_0x97
{
	unsigned int  index;
	SYNCHRO_TIME_S OccurTm;
	unsigned char modnum;
	//unsigned int type_inquire;
	unsigned int errcode;
};
struct _cmd_code_0x97
{
	unsigned char Stub_number[STUBNUMBER_LEN];
	unsigned char type_inquire;
	unsigned char num_upload;
	struct  _partbuf_0x97  partbuf_0x97[MAXWARINGRETURNCOUNT];
	
};
struct _cmd_code_0x88
{
		//鐢ㄦ埛ID
	short  UerID;//BYTE=2
	//鎸囦护搴忓垪
	short  CMD_Serail;//BYTE=2
	SYNCHRO_TIME_S Start_TM;
	SYNCHRO_TIME_S Stop_TM;
	unsigned char type_inquire; //0x01 !
	short CheckCount;
};
#if 0
struct  _process_0x98
{
	unsigned char headbyte;
	unsigned int  index;
	float ChrVoltMesurValue;
	float ChrCurrentMesurValue;
	float power;
	short Ac_ChrUsedTm;
	float Used_KWH;
	short Total_AH;
	SYNCHRO_TIME_S storagetm;
};
#endif
struct  _process_0x98
{
	unsigned char index;
	//short stubhigesallowtvolt;
	//short stublowestallowvolt;
	//short stubhigestallowcurrent;
	short usedkwh;
	short used_Ah;
	unsigned char  usedtm;//min
	unsigned char  start_soc;
	unsigned char current_soc;
	short outvolt;
	short outcurrent;
	short outpower;
	unsigned char comunicatinver[3];
	unsigned char poteviocomunicatinver[4];
	short perbox_ratedah;
	short perbox_ratedvolt;
	unsigned char  percellboxnum;
	unsigned char  percellserialboxnum;
	unsigned char  percellparrellboxnum;
	short tempgetpointnum;
	
	short cellallowhigestvolt;
	short cellallowhigestcurrent;
	short ratedah;
	short cellallowchrvolt;
	short allowtemp;
	unsigned char SOH;
	short cell_hopower_state;
	short  perboxtotalvolt;
	short bmsneedvolt;
	short bmsneedcureent;
	short voltmeasure;
	short currentmeasure;
	unsigned char celllowesttemp;
	unsigned char cellhigesttemp;
	short lesttime;
	//unsigned char lesttime;
	unsigned int bmsstopreason;
	short singlehigestvolt;
	short singlelowestvolt;
	unsigned char  bms_id[8];
	//unsigned int errdata;
	unsigned char Car_VIN[17];
	SYNCHRO_TIME_S storagetm;
};
struct  _partbuf_0x98
{
	unsigned int  index;
	SYNCHRO_TIME_S OccurTm;
	unsigned char Stub_number[STUBNUMBER_LEN];//ID??
	unsigned char ChargingType;
	short stubhigesallowtvolt;
	short stublowestallowvolt;
	short stubhigestallowcurrent;
	short usedkwh;
	short used_Ah;
	unsigned char  usedtm;//min
	unsigned char  start_soc;
	unsigned char current_soc;
	unsigned char  chargegunstate;
	short outvolt;
	short outcurrent;
	short outpower;
	unsigned char comunicatinver[3];
	unsigned char poteviocomunicatinver[4];
	short perbox_ratedah;
	short perbox_ratedvolt;
	
	unsigned char  percellboxnum;
	unsigned char  percellserialboxnum;
	unsigned char  percellparrellboxnum;
	short tempgetpointnum;
	short cellallowhigestvolt;
	short cellallowhigestcurrent;
	short ratedah;
	short cellallowchrvolt;
	short allowtemp;
	unsigned char SOH;
	unsigned char  perboxhopowerstate;
	
	short  perboxtotalvolt;
	short bmsneedvolt;
	short bmsneedcureent;
	short voltmeasure;
	short currentmeasure;
	unsigned char celllowesttemp;
	unsigned char cellhigesttemp;
	short lesttime;
	unsigned int bmsstopreason;
	short singlehigestvolt;
	short singlelowestvolt;
	unsigned char  bms_id[8];
	unsigned int errdata;
	unsigned char Car_VIN[17];
	unsigned char cellboxnum;
	//struct _CellInforStruct CellInforStruct [2];
};
struct _cmd_code_0x98
{
	unsigned char Stub_number[STUBNUMBER_LEN];
	unsigned char type_inquire;//0x12 define in the protocol !
	unsigned char num_upload;
	struct  _partbuf_0x98 partbuf_0x98[MAXPROCESSRETURNCOUNT];
};

struct _cmd_code_0xe1
{
	short  UerID;//BYTE=2
	short  CMD_Serail;//BYTE=2
	unsigned char data_operate_mode;
	unsigned char data_type;
};

struct _cmd_code_0xf1
{
	short  UerID;//BYTE=2
	short  CMD_Serail;//BYTE=2
	unsigned char data_operate_mode;
	unsigned char data_type;
	int total_num;
	int max_num;
};

struct _cmd_code_0xe2
{
	short  UerID;//BYTE=2
	short  CMD_Serail;//BYTE=2
	unsigned char data_operate_mode;
	unsigned char data_type;
	unsigned char data_deal_mode;
};

struct _cmd_code_0xf2
{
	short  UerID;//BYTE=2
	short  CMD_Serail;//BYTE=2
	unsigned char data_operate_mode;
	unsigned char data_deal_mode;
};

struct _cmd_code_0xc1
{
	short  UerID;//BYTE=2
	short  CMD_Serail;//BYTE=2
	unsigned char order_num[20];
	SYNCHRO_TIME_S order_down_time;
	SYNCHRO_TIME_S order_start_time;
	unsigned char order_operate;
	short order_time;
	unsigned char order_carnum[8];
	unsigned char order_cardnum[16];
	unsigned char order_mode;
	unsigned char GuestName[20];
};
struct _cmd_code_0xd1
{
	short  UerID;//BYTE=2
	short  CMD_Serail;//BYTE=2
	unsigned char order_num[20];
	SYNCHRO_TIME_S order_down_time;
	SYNCHRO_TIME_S order_start_time;
	unsigned char order_operate;
	short order_time;
	unsigned char order_carnum[8];
	unsigned char order_cardnum[16];
	unsigned char order_mode;
	unsigned char GuestName[20];
};
struct _cmd_code_0xc2
{
	short  UerID;//BYTE=2
	short  CMD_Serail;//BYTE=2
	
};
struct _cmd_code_0xc3
{
	short  UerID;//BYTE=2
	short  CMD_Serail;//BYTE=2
	
};
#if 0
struct _cmd_code_0xc2
{
	short  UerID;//BYTE=2
	short  CMD_Serail;//BYTE=2
	unsigned char order_num[20];
	SYNCHRO_TIME_S order_down_time;
	SYNCHRO_TIME_S order_start_time;
	unsigned char order_operate;
	short order_time;
	unsigned char order_carnum[8];
	unsigned char order_cardnum[16];
	unsigned char order_mode;
};
#endif
struct _cmd_code_0xd2
{
	short  UerID;//BYTE=2
	short  CMD_Serail;//BYTE=2
	unsigned char order_num[20];
	SYNCHRO_TIME_S order_down_time;
	SYNCHRO_TIME_S order_start_time;
	unsigned char order_operate;
	short order_time;
	unsigned char order_carnum[8];
	unsigned char order_cardnum[16];
	unsigned char order_mode;
	unsigned char GuestName[20];
};
struct _cmd_code_0xd3
{
	short  UerID;//BYTE=2
	short  CMD_Serail;//BYTE=2
	SYNCHRO_TIME_S check_now_time;
	unsigned char check_mode;
	unsigned int  check_time;
	unsigned char check_flag;
	unsigned char check_type;
	unsigned int  check_len;//cm
};
struct _cmd_code_0xa0
{
	short  UerID;//BYTE=2
	short  CMD_Serail;//BYTE=2
	short  version_num;
};
struct _cmd_code_0xb0
{
	short  UerID;//BYTE=2
	short  CMD_Serail;//BYTE=2
	unsigned char Stub_number[STUBNUMBER_LEN];
	short version_num;
	unsigned int system_version;
	SYNCHRO_TIME_S new_start_time;
	SYNCHRO_TIME_S new_sign_time;
};

struct _cmd_code_0xa1
{
	short  UerID;//BYTE=2
	short  CMD_Serail;//BYTE=2
	short  version_num;
	unsigned int down_version_num;
	short total_pack_num;
	short current_pack_num;
	short current_bytes;
	//....
};

struct _cmd_code_0xb1
{
	short  UerID;//BYTE=2
	short  CMD_Serail;//BYTE=2
	short   version_num;
	unsigned int down_version_num;
	short total_pack_num;
	short current_pack_num;
	short current_bytes;
	unsigned char recv_state;
};

struct _cmd_code_0xa2
{
	short  UerID;//BYTE=2
	short  CMD_Serail;//BYTE=2
	short  version_num;
	unsigned int  update_version_num;
	short total_pack_num;
};

struct _cmd_code_0xb2
{
	short  UerID;//BYTE=2
	short  CMD_Serail;//BYTE=2
	short   version_num;
	unsigned int update_version_num;
	short total_pack_num;
	unsigned char update_state;
};

struct _cmd_code_0xa3
{
	short  UerID;//BYTE=2
	short  CMD_Serail;//BYTE=2
	unsigned char update_ser_ip[20];
	unsigned char update_ser_port[5];
	unsigned char log_ser_ip[20];
	unsigned char log_ser_port[5];
	unsigned char update_user_name[20];
	unsigned char update_passwd[20];
	unsigned char device_style[20];
	unsigned char device_version[50];
	unsigned char control;
};

struct _cmd_code_0xb3
{
	short  UerID;//BYTE=2
	short  CMD_Serail;//BYTE=2
	unsigned char update_state;
};
struct _cmd_code_0x2b
{
	//\u9422\u3126\u57dbID
	short  UerID;//BYTE=2
	//\u93b8\u56e6\u62a4\u6434\u5fd3\u57aa
	short  CMD_Serail;//BYTE=2
	unsigned char  moudle_num;
	unsigned char  moudle_index;
};
struct _singlemeterinfor
{
	unsigned char  moudle_index;
	unsigned char  meter_index[50];
	unsigned int  meter_num;
	short input_use_power;
	short input_useless_power;
	short input_power_volt;
	short input_power_current;
	short input_power_factor;
	short input_power_wave;
	unsigned int  input_power_error;
	unsigned int  power_error;
	unsigned char power_switch;
	unsigned char power_insurance;
};
struct _cmd_code_0x3b
{
	//\u9422\u3126\u57dbID
	short  UerID;//BYTE=2
	//\u93b8\u56e6\u62a4\u6434\u5fd3\u57aa
	short  CMD_Serail;//BYTE=2
	unsigned char  moudle_num;
	struct _singlemeterinfor singlemeterinfor[3];
};
typedef struct
{
	/***********************
	system papa manager
	**************************/
	struct _cmd_code_0x41 p_cmd_code_0x41;//���׮�����ն˲�������
	struct _cmd_code_0x42 p_cmd_code_0x42;//���׮�����ն˲�������
	struct _cmd_code_0x46 p_cmd_code_0x46;//���׮�����ն˹�����������
	struct _cmd_code_0x48  p_cmd_code_0x48;
	struct _cmd_code_0x49  p_cmd_code_0x49;

	/***********************
	state manager
	**************************/
	struct _cmd_code_0x01 p_cmd_code_0x01;
	struct _cmd_code_0x11 p_cmd_code_0x11;
	struct _cmd_code_0x05 p_cmd_code_0x05;
	struct _cmd_code_0x07 p_cmd_code_0x07;
	struct _cmd_code_0x17 p_cmd_code_0x17;
	struct _cmd_code_0x08 p_cmd_code_0x08;
	struct _cmd_code_0x18 p_cmd_code_0x18;

	/***********************
	workstate pama get
	**************************/
	struct _cmd_code_0xE0 p_cmd_code_0xE0;
	struct _cmd_code_0x21 p_cmd_code_0x21;
	struct _cmd_code_0x31 p_cmd_code_0x31;
	struct _cmd_code_0x22 p_cmd_code_0x22;
	struct _cmd_code_0x3A p_cmd_code_0x3A;
	struct _cmd_code_0x23 p_cmd_code_0x23;
	struct _cmd_code_0x33 p_cmd_code_0x33;
	struct _cmd_code_0x24 p_cmd_code_0x24;
	struct _cmd_code_0x34 p_cmd_code_0x34;
	struct _cmd_code_0x25 p_cmd_code_0x25;
	struct _cmd_code_0x35 p_cmd_code_0x35;
	struct _cmd_code_0x26 p_cmd_code_0x26;
	struct _cmd_code_0x36 p_cmd_code_0x36;
	struct _cmd_code_0x39 p_cmd_code_0x39;
	struct _cmd_code_0x40 p_cmd_code_0x40;
	struct _cmd_code_0x50  p_cmd_code_0x50;

	/***********************
	charge sevice  infor
	**************************/
	struct _cmd_code_0x70 p_cmd_code_0x70;
	struct _cmd_code_0x60 p_cmd_code_0x60;
	struct _cmd_code_0x69 p_cmd_code_0x69;

	struct _cmd_code_0x71 p_cmd_code_0x71;
	struct _cmd_code_0x61 p_cmd_code_0x61;
	struct _cmd_code_0x72 p_cmd_code_0x72;
	struct _cmd_code_0x62 p_cmd_code_0x62;
	//struct _cmd_code_0x63 p_cmd_code_0x63;
	struct _cmd_code_0x78 p_cmd_code_0x78;
	struct _cmd_code_0x68 p_cmd_code_0x68;
	//struct _cmd_code_0x73 p_cmd_code_0x73;
	struct _cmd_code_0x74 p_cmd_code_0x74;
	struct _cmd_code_0x64 p_cmd_code_0x64;
	struct _cmd_code_0x75 p_cmd_code_0x75;
	struct _cmd_code_0x65 p_cmd_code_0x65;

	#if 0
	struct _cmd_code_0x78 p_cmd_code_0x78;
	#endif
	/***********************
	HISTORY RECORD GET
	**************************/
	struct _cmd_code_0x80 p_cmd_code_0x80;
	struct _cmd_code_0x92 p_cmd_code_0x92[MAXHISTORYRETURNCOUNT];
	struct _cmd_code_0x86 p_cmd_code_0x86;
	struct _cmd_code_0x96 p_cmd_code_0x96;
	struct _cmd_code_0x87 p_cmd_code_0x87;
	struct _cmd_code_0x97 p_cmd_code_0x97;
	struct  _process_0x98 process_0x98[MAXPROCESSRETURNCOUNT];
	struct _cmd_code_0x88 p_cmd_code_0x88;
	struct _cmd_code_0x98 p_cmd_code_0x98;
	/***********************
		v3.0 for BMW
		**************************/
	struct _cmd_code_0x43  p_cmd_code_0x43;
	struct _cmd_code_0x53  p_cmd_code_0x53;

	struct _cmd_code_0xe1 p_cmd_code_0xe1;
	struct _cmd_code_0xf1  p_cmd_code_0xf1;

	struct _cmd_code_0xe2 p_cmd_code_0xe2;
	struct _cmd_code_0xf2  p_cmd_code_0xf2;

	struct _cmd_code_0xc1   p_cmd_code_0xc1;
	struct _cmd_code_0xd1  p_cmd_code_0xd1;

	struct _cmd_code_0xc2  p_cmd_code_0xc2;
	struct _cmd_code_0xd2  p_cmd_code_0xd2;

	struct _cmd_code_0xc3  p_cmd_code_0xc3;
	struct _cmd_code_0xd3  p_cmd_code_0xd3;

	struct _cmd_code_0xa0  p_cmd_code_0xa0;
	struct _cmd_code_0xb0  p_cmd_code_0xb0;

	struct _cmd_code_0xa1  p_cmd_code_0xa1;
	struct _cmd_code_0xb1  p_cmd_code_0xb1;

	struct _cmd_code_0xa2  p_cmd_code_0xa2;
	struct _cmd_code_0xb2  p_cmd_code_0xb2;

	struct _cmd_code_0xa3  p_cmd_code_0xa3;
	struct _cmd_code_0xb3  p_cmd_code_0xb3;

	struct _cmd_code_0x2b cmd_code_0x2b;
	
}NetWorkStrcut_Type,*p_NetWorkStrcut_Type;

struct _updateidle
{
	unsigned char upSendBuf[MAXSNDPACKLEN];
	unsigned int  upSendLen;
};
#if 0
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
	FLOAT32 SysElectricityPrice;
	FLOAT32 SysSeviceMoney;
	FLOAT32  Ac_LimitCurrent;
	char LocalIpAddr[20];
	char LocalMask[20];
	char LocalGetWay[20];
	char LocalMac[20];
	BOOL SocketConnectNeedReboot;
	BOOL GprsConnectNeedReboot;
	char  sysfirst_syntime;
	int historysave_interval;
	int chargebyhand;
	int cardtype;// 1:potevio  ,2:blank card
	
	
};
#endif
#pragma pack(pop)//
void LocalIpaddrSet(void);
 int  FormatStubNumberFrmConfigfile(unsigned char *dest,unsigned char *src);
 int FormatPropertycodeFrmConfigfile(unsigned char *dest,unsigned char *src);
int Inibuf_init(char *storebuf,int storebuf_len,char *setvalue);
BOOL  CheckSysfile_Valid();
int checkfilexsit(const  char *filename);
BOOL  checkerrorinforfilevalid(const char *errorinforpath);
BOOL  syslogfilevalid(const char *syslogpath);
BOOL  waringfilevalid(const char *waringpath);
BOOL  checkeventfilevalid(const char *eventpath);
BOOL  checkhistoryfilevalid(const char *Historyfile_name);
BOOL  checkprocessfilevalid(const char *processfile_name);
BOOL  checkwaitupdatevalid(const char *waitupdate_name);
BOOL  checkbackupvalid(const char *backup_name);
int writefile_with_timeinfor_inend(char *linedata,const char *FilePath);
int writefile_without_timeinfor_inend(unsigned char *linedata,int writelen,const char *FilePath);
int writefile_with_timeinfor_inhead(char *linedata,const char *FilePath);
int writefile_without_timeinfor_inhead(unsigned char *linedata,const char *FilePath);
void ClearFile(const char*filename);
unsigned int NetWorkData_Ananisis(const unsigned char *socket_cu_rev, const unsigned int DataLen,
									const unsigned int Cmd_Code,const unsigned int DataStartPos,
									p_NetWorkStrcut_Type p_NetWorkStrcutOpt);
/***********************
system papa manager
**************************/
int SndPack_0x51(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x41 p_cmd_code_0x41_ipt,const unsigned char SendPack_SerialIpt ,char NetworkCOnnectState);
int SndPack_0x52(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x42 p_cmd_code_0x42_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x53(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x43 p_cmd_code_0x43_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0xF1(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0xf1 p_cmd_code_0xf1_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0xF2(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0xe2 p_cmd_code_0xe2_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x56(const int senddata_ID,const int SndLinkRoad,
					const  struct _cmd_code_0x46 p_cmd_code_0x46_ipt,
					const unsigned char SendPack_SerialIpt,const unsigned int Setrerult,char NetworkCOnnectState);
int SndPack_0x58(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x48 p_cmd_code_0x48_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x59(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x49 p_cmd_code_0x49_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x50(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x50 p_cmd_code_0x50_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
/***********************
state manager
**************************/
int SndPack_0x10(const int senddata_ID,const int SndLinkRoad,
					const struct _sysconfigstruct sysconfigstruct_ipt,const NetWorkStrcut_Type p_NetWorkStrcut_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x11(const int senddata_ID,const int SndLinkRoad,struct _cmd_code_0x11 p_cmd_code_0x11_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x15(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x05 p_cmd_code_0x05_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x17(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x17 p_cmd_code_0x17_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x18(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x18 p_cmd_code_0x18_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);

/***********************
workstate pama get
**************************/
int SndPack_0xF0(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0xE0 p_cmd_code_0xE0_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x31(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x31 p_cmd_code_0x31_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x3A(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x3A p_cmd_code_0x3A_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x33(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x33 p_cmd_code_0x33_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x34(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x34 p_cmd_code_0x34_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x35(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x35 p_cmd_code_0x35_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x36(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x36 p_cmd_code_0x36_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x39(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x39 p_cmd_code_0x39_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
/***********************
charge sevice  infor
**************************/
int SndPack_0x70(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x70 cmd_code_0x70_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x71(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x71 p_cmd_code_0x71_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x72(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x72 p_cmd_code_0x72_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x73(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x63 p_cmd_code_0x63_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x74(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x74 p_cmd_code_0x74_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x75(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x75 p_cmd_code_0x75_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x78(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x78 p_cmd_code_0x78_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
/***********************
HISTORY RECORD GET
**************************/
int SndPack_0x90(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x80 p_cmd_code_0x80_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x92(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x92 *p_cmd_code_0x92_ipt,int GetHistorycnt,
	const  struct _cmd_code_0x80 p_cmd_code_0x80_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);

int SndPack_0x96(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x96 *p_cmd_code_0x96_ipt,int Geteventcnt,
	const  struct _cmd_code_0x86 p_cmd_code_0x86_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x97(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x97 *p_cmd_code_0x97_ipt,int Geteventcnt,
	const  struct _cmd_code_0x87 p_cmd_code_0x87_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);

int SndPack_0x98(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x98 *p_cmd_code_0x98_ipt,int Geteventcnt,
	const  struct _cmd_code_0x88 p_cmd_code_0x88_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);

int SndPack_0xd1(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0xc1 *p_cmd_code_0xc1_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0xd2(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0xc1 *bookinfor,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0xd3(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0xd3 *p_cmd_code_0xd3_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0x3B(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x3b p_cmd_code_0x3b_ipt,
	const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);

int SndPack_0xb0(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0xa0 *p_cmd_code_0xa0_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0xb1(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0xa1 *p_cmd_code_0xa1_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0xb2(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0xa2 *p_cmd_code_0xa2_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
int SndPack_0xb3(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0xa3 *p_cmd_code_0xa3_ipt,const unsigned char SendPack_SerialIpt,char NetworkCOnnectState);
//int SndPack_0x92(const int senddata_ID,const int SndLinkRoad,const  struct _cmd_code_0x80 p_cmd_code_0x80_ipt,const unsigned char SendPack_SerialIpt);
unsigned char Crc_Cal(unsigned char *InBuffer,int len);
void GetsysTime(SYNCHRO_TIME_S *OutStrctTm);
int SendData(const int senddata_ID,const int SndLinkRoad,const unsigned char *sendbuf,const int send_totallen,char NetworkCOnnectState);
int PackDataHead(unsigned char *acSendBuf,unsigned int Buflen,unsigned char headfstbyte,
					unsigned char sndfstbyte,unsigned int serialnumber,unsigned char softversion,unsigned char cmdcode);

//void TimeAnanisis(SYNCHRO_TIME_S *OutTm,const unsigned char *INputBuf);
int HistoryAnanisis(const char *file_name,struct _cmd_code_0x92  *p_cmd_code_0x92OutPt,struct _cmd_code_0x80 cmd_code_0x80_Inpt);
int WaringAnanisis(const char *file_name, struct _partbuf_0x97  *partbuf_0x97_OutPt,struct _cmd_code_0x87 cmd_code_0x87_Inpt);
int EventAnanisis(const char *file_name, struct _partbuf_0x96  *partbuf_0x96_OutPt,struct _cmd_code_0x86 cmd_code_0x86_Inpt);
int mywrite_history_record(struct _cmd_code_0x92 cmd_code_0x92_inpt,const char *HistoryPath);
int insert_onehistory_to_end_of_file(const char *HistoryPath,char *linedata);
int formathistory(struct _cmd_code_0x92 cmd_code_0x92_inpt,char his_record[MAXCHAROFONELINE]);
int checktimeperiod(SYNCHRO_TIME_S checktm,SYNCHRO_TIME_S starttm,SYNCHRO_TIME_S endtm);
int ProcessAnanisis(const char *file_name, struct _process_0x98  *process_0x98_OutPt,struct _cmd_code_0x88 cmd_code_0x88_Inpt);
time_t  SYSTEMTIME_to_time_t( SYNCHRO_TIME_S systime);
void TimeAnanisis(SYNCHRO_TIME_S *OutTm,const unsigned char *INputBuf);
#endif /* NETWORKANANISIS_H_ */
