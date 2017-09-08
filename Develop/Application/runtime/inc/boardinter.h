
#ifndef	_BOARDINTER_H
#define _BOARDINTER_H
#include <pthread.h>
#include<time.h>  
#include<sys/time.h>
#define  COMRECVMAXPACKLEN (1024)

#define BOARDCMDCODE_0X01   (0x01)
#define BOARDCMDCODE_0X81   (0x81)

#define BOARDCMDCODE_0X02   (0x02)
#define BOARDCMDCODE_0X82   (0x82)

#define BOARDCMDCODE_0X03   (0x03)
#define BOARDCMDCODE_0X83   (0x83)

#define BOARDCMDCODE_0X04   (0x04)
#define BOARDCMDCODE_0X84  (0x84)

#define BOARDCMDCODE_0X06   (0x06)
#define BOARDCMDCODE_0X86  (0x86)

#define BOARDCMDCODE_0X89  (0x89)

#define BOARDMAINBOARD_ADDR  (0xFE)
#define BOARDBRODCAST_ADDR  (0xFF)

#define NOCHARGE_CMD       (0x00)
#define STARTCHARGE_CMD     (0x01)
#define STOPCHARGE_CMD     (0x02)

#define SINGLEBOARD_GUN_NUM   (0x02)

#ifdef _MAINNOARD_GUN_FOUR
#define TOTALBOARD_GUN_NUM   (0x04)
#else
#define TOTALBOARD_GUN_NUM   (0x02)
#endif
#pragma pack(push) //
#pragma pack(1)

struct _board_code_0x01
{
	unsigned char  modwork_state;
	short opt_current;
	short opt_volt;
	unsigned char  manboard_contactor_state;
};

struct _board_code_0x81
{
	//unsigned char subboardwork_state;
	unsigned char chargegun_linkstate :1;
	unsigned char bms_allowcharge :1;
	unsigned char assistenpower_state :1;
	unsigned char directcontactor_state :1;
	unsigned char bms_stopcharge :1;
	unsigned char reserve :3;
	short bms_need_volt;
	short bms_need_current;
	unsigned char total_soc;
	unsigned char chrge_left_time;

};

struct _board_code_0x02
{
//	unsigned char  cmd_id;
	unsigned char chargetype;
	short  largestopt_volt;
	short largestopt_current;
	short lowestopt_volt;
	unsigned char  charge_linkway;
};

struct _board_code_0x82
{
	//unsigned char  cmd_id;
	unsigned char execute_result;
};

struct _board_code_0x03
{
	

};

struct _board_code_0x83
{
	//unsigned char  cmd_id;
	//unsigned int stopreason;
	unsigned char execute_result;
};

struct _board_code_0x04
{
	unsigned char  reserve[8];
	
};
struct _board_code_0x84
{
	short largest_allow_volt;
	short largest_allow_current;

};
struct _board_code_0x06
{
	
	unsigned char charge_linkway;
};
struct _board_code_0x86
{
	
	unsigned char execute_result;
};

struct _board_code_0x89
{
	
	unsigned int  current_kwh;
};


typedef  struct 
{
	struct _board_code_0x01 board_code_0x01;
	struct _board_code_0x02 board_code_0x02;
	struct _board_code_0x03 board_code_0x03;
	struct _board_code_0x04 board_code_0x04;
	struct _board_code_0x06 board_code_0x06;
	
		
}type_subboardcanrecv;

typedef  struct 
{
	//unsigned char cmd_code_0x81_write;
	struct _board_code_0x81 board_code_0x81;
	unsigned char getcmdflag_0x82;
	struct _board_code_0x82 board_code_0x82;
	unsigned char getcmdflag_0x83;
	struct _board_code_0x83 board_code_0x83;
	struct _board_code_0x84 board_code_0x84;
	unsigned char getcmdflag_0x84;
	
	struct _board_code_0x86 board_code_0x86;
	unsigned char getcmdflag_0x86;

	struct _board_code_0x89  board_code_0x89;
	unsigned char getcmdflag_0x89;
		
}type_mainboardcanrecv;
extern type_mainboardcanrecv  mainboardcanrecv_struct[TOTALBOARD_GUN_NUM];

typedef  struct 
{
	unsigned char assistenpower_port;
	unsigned char directcontactor_port;
	unsigned char contactor_active_reback;
	unsigned char contactor_nagetive_reback;
}_type_outsidedevice;
struct _subboardpacktosnd
{
 	unsigned char needsndpack_0x81;
	unsigned char needsndpack_0x82;
	unsigned char execute_result_0x82;
	
	unsigned char needsndpack_0x83;
	unsigned char execute_result_0x83;
	
	unsigned char needsndpack_0x84;
	unsigned char needsndpack_0x86;

	unsigned char needsndpack_0x89;
};
struct _mainboardpacktosnd
{
 	unsigned char needsndpack_0x01;
	unsigned char needsndpack_0x02;
	//unsigned char cmdid_0x02;
	//unsigned int stopreason;
	
	unsigned char needsndpack_0x03;
	//unsigned char cmdid_0x03;
	//unsigned char execute_result_0x03;
		
	unsigned char needsndpack_0x04;
	unsigned char needsndpack_0x06;
	
};
struct _subboardsysconfigstruct
{
	unsigned char stub_bms_Version[3];
};

struct _boardmutex_lock_struct 
{
	
	pthread_mutex_t mutex_0x81;
	pthread_mutex_t mutex_0x82;
	pthread_mutex_t mutex_0x83;
	pthread_mutex_t mutex_0x84;
	
};
extern struct _boardmutex_lock_struct  boardmutex_lock_struct[TOTALBOARD_GUN_NUM];
#if 0
struct _chargegun_manager
{
	unsigned char gun_needcharge;
	unsigned char Chargeing_flag;
	
};
extern struct _chargegun_manager chargegun_manager[TOTALBOARD_GUN_NUM];
#endif
#pragma pack(pop)//
#endif
