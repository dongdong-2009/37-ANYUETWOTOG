/*
 * businter.h
 *
 *  Created on: Jul 9, 2014
 *      Author: root
 */

#ifndef BUSINTER_H_
#define BUSINTER_H_
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<linux/if.h>
#include<linux/socket.h>
#include<linux/sockios.h>
#include<string.h>
#include"can.h"
#include<time.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include "pubheader.h"
#ifndef TRUE
#define TRUE   (1)
#endif
#ifndef FALSE
#define FALSE   (0)
#endif

#ifndef NULL
#define NULL   (0)
#endif


#define _NEWBMS_STANDRD
#define BMS_VERSION_V1_0   (0x01)
#define BMS_VERSION_V1_1   (0x02)

#define RTS (16)
#define CTS (17)
#define ABORT (0xFF)
#define EndofMsgAck  (19)

#define ERROR_BMS (1)
#define ERROR_STUB (2)
#define ERROR_LINK (3)
#define ERROR_OTHER (4)
#define ERROR_CURRENT_BIG (5)
#define ERROR_VOLT_BIG (6)
#define ERROR_EMERGENCY (7)


#define PRIORITY_01			(1)
#define PRIORITY_02			(2)
#define PRIORITY_03			(3)
#define PRIORITY_04			(4)
#define PRIORITY_05			(5)
#define PRIORITY_06			(6)
#define PRIORITY_07			(7)

#define DEVICEREADY_YES   (0xAA)
#define DEVICEREADY_NO   (0x00)
#define DEVICEREADY_UNKOWN   (0xFF)

#define STUBDEVICE_ADDR    (0x56)
#define BMS_ADDR   			(0xF4)
#define BMS_BSTADDR   			(0xFF)
#define CHARGEWATCH_ADDR   			(0xF4)
#define  MAX_CANBUF_LEN		(2048)
#define MAX_SINGLEVOLT_POINT   (256)
#define MAX_SINGLETEMP_POINT   (128)
//use for 0x72
#define MAXCELLBOXNUMBER (20)
#pragma pack(push) //
#pragma pack(1)
struct _cmdcode_9728
{
	__u8  stub_communication_version[3];
	
	
};
struct _cmdcode_9984
{
	short largest_allow_volt;
};
struct _cmdcode_256
{
	__u8  bmsidentify;
	__u8  stubnumber;
	__u8  stubereacode[6];
};
struct _cmdcode_512
{
	__u8 bms_inter_version[3];
	__u8 cell_type;
	short rated_capa;
	short rated_volt;
	__u8 cell_produce_factory[4];
	__u32  cell_serailnumber;
	__u8 cell_produce_y;
	__u8 cell_produce_m;
	__u8 cell_produce_d;
	__u8 cell_charge_times[3];
	__u8 cell_property_indentify;
	__u8 reserve;
	__u8 car_vin[17];
	__u8 bnm[8];
	__u8 bms_software_version[8];
};
struct _cmdcode_12288
{
	__u8 putian_inter_version[3];
	__u8 car_vin[17];
	__u8 cell_totalbox;
	__u8 cell_serial_num;
	__u8 cell_parallel_num;
	__u8  cell_tempcollect_num;
	__u8  bms_id[8];
	__u8 BNM [MAXCELLBOXNUMBER][8];
};
struct _cmdcode_1536
{
	short sglcell_largest_allow_volt;
	short largest_allow_current;
	short cell_nominal_totalcapa;
	short largest_allow_volt;
	__u8 largest_allow_temp;
	short cell_hopower_state;
	short cell_total_volt;
	__u8 total_soh;
	
};

struct _cmdcode_1792
{
	__u8 m_sec;
	__u8 m_min;
	__u8 m_hour;
	__u8 m_day;
	__u8 m_month;
	__u8  m_year[2];
	
};
struct _cmdcode_2048
{
	short  largest_opt_volt;
	short  lowest_opt_volt;
	short  largest_opt_current;
	short  lowest_opt_current;
	
};
struct _cmdcode_2304
{
	__u8 bms_isready;
	
};
struct _cmdcode_2560
{
	__u8 stub_isready;
	
};
struct _cmdcode_4096
{
	short bms_need_volt;
	short bms_need_current;
	__u8 bms_need_mode;
	
};
struct _cmdcode_4352
{
	short chrgevolt_mesr_value;
	short chrgecurrent_mesr_value;
	short largest_siglcell_volt_grp;
	__u8 total_soc;
	short chrge_left_time;
};
struct _cmdcode_4608
{
	short volt_opt_value;
	short current_opt_value;
	short total_charge_time;
	__u8 charge_halt;
};
struct _bmssndpack_manager
{
	struct _cmdcode_256 cmdcode_256;
};
struct _cmdcode_4864
{
	__u8 higestsglcell_voltgrpId;
	__u8 higestcell_temp;
	__u8 higest_temp_checkpoint;
	__u8 lowestcell_temp;
	__u8 lowest_temp_checkpoint;
	
	__u8 singlecell_volt_overload  :2;
	__u8 singlecell_soc_overload  :2;
	__u8 singlecell_chrcurr_overload  :2;
	__u8 singlecell_temp_overload  :2;

	__u8 insulation_state :2;
	__u8 cell_connector_state :2;
	__u8 allow_charge_state :2;
	__u8 space_4              :2;
	
};

struct _cmdcode_5376
{
	short sglcell_voltinfor[MAX_SINGLEVOLT_POINT];
};

struct _cmdcode_5632
{
	__u8 sglcell_tempinfor[MAX_SINGLETEMP_POINT];
};
struct _cmdcode_5888
{
	short sglcell_reserve[16];
};
struct _cmdcode_6400
{
	__u8 bmsstop_reason;
	short bmsstop_brkdownreason;
	__u8 bmsstop_errreason;
};
struct _cmdcode_6656
{
	__u8 stubstop_reason;
	short stubstop_brkdownreason;
	__u8 stubstop_errreason;
};
struct _cmdcode_7168
{
	__u8 stop_soc;
	short sgllowest_volt;
	short sglhigestest_volt;
	__u8   lowest_temp;
	__u8   higest_temp;
};
struct _cmdcode_7424
{
	short chrtotaltm;
	short totalkwh;
	 int stubnum;
};
struct _cmdcode_7680
{
	__u8 timeout_indentify_0x00	:2;
	__u8 timeout_indentify_0xAA	:2;
	__u8 space_1 					:4;

	__u8  timeout_timesync		:2;
	__u8 timeout_stubready		:2;
	__u8 space_2 					:4;

	__u8  timeout_stubstate		:2;
	__u8  timeout_stubstop		:2;
	__u8 space_3 					:4;

	__u8  timeout_stubstatic		:2;
	__u8  space_4		:6;
	
	
};
struct _cmdcode_7936
{
	__u8 timeout_512	:2;
	__u8  space_1		:6;

	__u8 timeout_1536	:2;
	__u8 timeout_2304		:2;
	__u8 space_2 					:4;

	__u8 timeout_4352	:2;
	__u8 timeout_4096	:2;
	__u8 timeout_6400	:2;
	__u8 space_3					:2;
	
	__u8  timeout_7168		:2;
	__u8  space_4		:6;
};

struct _ErrorInfor
{
	
	unsigned char Errorgrade;
	unsigned char ErrorCode;
	unsigned char ErrorPosTotal;
	short ErrorPos[10];
	unsigned char ErrorEnd;
};

struct _cmdcode_13056
{
	unsigned char CellErrorgrade;
	
	struct _ErrorInfor  ErrorInfor[10];
	
};
struct _cmdcode_13824
{
	unsigned char CellErrorgrade;
	
	struct _ErrorInfor ErrorInfor[10];
	
};
struct _cmdcode_14080
{
	unsigned char CellErrorgrade;
	
	struct _ErrorInfor ErrorInfor[10];
	
};

struct _cmdcode_13312
{
	unsigned char stubErrorgrade;
	struct _ErrorInfor ErrorInfor[10];
	
};
struct __tpcm_rts
{
	__u8 ctl_byte;
	short  packdatalen;
	__u8 pack_num;
	__u8 reserve;
	__u32 loadpgn :24;
	//__u8   space_1  :8;
	
};

typedef union __byte_three
{
	__u32 int_value :24;
	__u8  buf_value[3];
} _union_byte_three;

typedef union __short
{
	short short_value :16;
	__u8  buf_value[2];
} _union_short;

struct _mutil_datalen_struct
{
	short datalen_0x5376;
	short datalen_0x5632;
	short datalen_0x5888;
}; 
extern struct _mutil_datalen_struct mutil_datalen_struct[SINGLEBOARD_GUN_NUM];
typedef  struct 
{
	struct _cmdcode_9984		cmdcode_9984;
	struct _cmdcode_512		cmdcode_512;
	struct _cmdcode_12288	cmdcode_12288;
	struct _cmdcode_1536		cmdcode_1536;
	//struct _cmdcode_1792		cmdcode_1792;
	//struct _cmdcode_2048		cmdcode_2048;
	struct _cmdcode_2304		cmdcode_2304;
	struct _cmdcode_2560		cmdcode_2560;
	struct _cmdcode_4096		cmdcode_4096;
	struct _cmdcode_4352		cmdcode_4352;
	//struct _cmdcode_4608		cmdcode_4608;
	struct _cmdcode_4864		cmdcode_4864;
	struct _cmdcode_5376		cmdcode_5376;
	struct _cmdcode_5632		cmdcode_5632;
	struct _cmdcode_5888		cmdcode_5888;
	struct _cmdcode_6400		cmdcode_6400;
	//struct _cmdcode_6656		cmdcode_6656;
	struct _cmdcode_7168		cmdcode_7168;
	struct _cmdcode_7680		cmdcode_7680;
	//struct _cmdcode_7936		cmdcode_7936;
	struct _cmdcode_13056	cmdcode_13056;
	struct _cmdcode_13824	cmdcode_13824;
	struct _cmdcode_14080	cmdcode_14080;
	//12544
	//13568
	//struct _cmdcode_13312	cmdcode_13312;
	
}type_canrecvdata;
extern type_canrecvdata  getcanrecvdata_struct[SINGLEBOARD_GUN_NUM];
struct _canpack_get
{
	__u8 flag_get_cmd512;	
	__u8 flag_get_cmd12288;	
	__u8 flag_get_cmd1536;	
	__u8 flag_get_cmd2304;
	__u8 flag_get_cmd4864;
	__u8 flag_get_cmd4352_send;
	__u8 flag_get_cmd4352;	
	__u8 flag_get_cmd4096;	
	__u8 flag_get_cmd6400;	
	__u8 flag_get_cmd7168;	
	__u8 flag_get_cmd9984;	
	__u8 bms_inter_flag;
};
extern struct _canpack_get 	canpack_get[SINGLEBOARD_GUN_NUM] ;
struct _canpack_tosnd
{
	__u8 start_bms;
	__u8 start_bmsinter;
	__u8 stop_volt_error;
	
	__u8 flag_snd_cmd9728;	
	__u8 flag_snd_cmd256_00;	
	__u8 flag_snd_cmd256_AA;
	__u8 flag_snd_cmd1792;
	__u8 flag_snd_cmd2048;
	__u8 flag_snd_cmd2560;
	__u8 flag_snd_cmd4608;
	__u8 flag_snd_cmd6656;
	__u8 flag_snd_cmd7424;
};
extern struct _canpack_tosnd  canpack_tosnd[SINGLEBOARD_GUN_NUM];
#pragma pack(pop)//

//extern type_canrecvdata  getcanrecvdata_struct;
extern struct _canpack_get 	canpack_get[SINGLEBOARD_GUN_NUM];

//extern struct _canpack_get 	canpack_get;

#define  CODE_PGN9728    	(0x2600)
#define  CODE_PGN9984     	(0x2700)

#define  CODE_PGN256     	(0x100)
#define  CODE_PGN512     	(0x200)
#define  CODE_PGN60416  	(0xEC00)
#define  CODE_PGN12288   	(0x3000)

#define  CODE_PGN1536    (0x600)
#define  CODE_PGN1792    (0x700)
#define  CODE_PGN2048    (0x800)
#define  CODE_PGN2304    (0x900)
#define  CODE_PGN2560    (0xA00)

#define  CODE_PGN4096    (0x1000)
#define  CODE_PGN4352    (0x1100)
#define  CODE_PGN4608    (0x1200)
#define  CODE_PGN4864    (0x1300)
#define  CODE_PGN5376    (0x1500)
#define  CODE_PGN5632    (0x1600)
#define  CODE_PGN5888    (0x1700)
#define  CODE_PGN6400    (0x1900)
#define  CODE_PGN6656    (0x1A00)

#define  CODE_PGN7168    (0x1C00)
#define  CODE_PGN7424    (0x1D00)

#define  CODE_PGN7680    (0x1E00)
#define  CODE_PGN7936    (0x1F00)

#define  CODE_PGN13056   (0x3300)
#define  CODE_PGN13312   (0x3400)
#define  CODE_PGN13824   (0x3600)
#define  CODE_PGN14080   (0x3700)

#define  CODE_PGN12544   (0x3100)
#define  CODE_PGN12800   (0x3200)
#define  CODE_PGN13568   (0x3500)

#define  CODE_PF_0x26     	(0x26)
#define  CODE_PF_0x27     	(0x27)
#define  CODE_PF_0x01     	(0x1)
#define  CODE_PF_0x02     	(0x2)
#define  CODE_PF_0xEC  	(0xEC)
#define  CODE_PF_0xEB  	(0xEB)
#define  CODE_PF_0x30   	(0x30)

#define  CODE_PF_0x06    (0x6)
#define  CODE_PF_0x07    (0x7)
#define  CODE_PF_0x08    (0x8)
#define  CODE_PF_0x09    (0x9)
#define  CODE_PF_0x0A    (0xA)

#define  CODE_PF_0x10    (0x10)
#define  CODE_PF_0x11    (0x11)
#define  CODE_PF_0x12    (0x12)
#define  CODE_PF_0x13    (0x13)
#define  CODE_PF_0x15    (0x15)
#define  CODE_PF_0x16    (0x16)
#define  CODE_PF_0x17    (0x17)
#define  CODE_PF_0x19    (0x19)
#define  CODE_PF_0x1A    (0x1A)

#define  CODE_PF_0x1C    (0x1C)
#define  CODE_PF_0x1D    (0x1D)

#define  CODE_PF_0x1E    (0x1E)
#define  CODE_PF_0x1F    (0x1F)

#define  CODE_PF_0x33   (0x33)
#define  CODE_PF_0x34   (0x34)
#define  CODE_PF_0x36   (0x36)
#define  CODE_PF_0x37   (0x37)

#define  CODE_PF_0x31   (0x31)
#define  CODE_PF_0x32   (0x32)
#define  CODE_PF_0x35   (0x35)


#define  PF_0x27_LEN		(2)
#define  PF_0x02_LEN		(41)
#define  PF_0x06_LEN		(13)
#define  PF_0x09_LEN		(1)
#define  PF_0x10_LEN		(5)
#define  PF_0x11_LEN		(9)
#define  PF_0x13_LEN		(7)
#define  PF_0x19_LEN		(4)
#define  PF_0x1c_LEN		(7)
#define  PF_0x1e_LEN		(4)

canid_t   format_canid(__u8 p,__u8 r,__u8 dp,__u8 pf,__u8 ps,__u8 sa);
__u8 get_sa(canid_t);//èŽ·å–æºåœ°å€id
__u8 get_da(canid_t);//èŽ·å–ç›®çš„åœ°å€id
__u8 get_pf(canid_t);//èŽ·å–å‘½ä»¤ä»£ç 
int Can_SendData(const int senddata_ID,struct can_frame  sndcan_frame);

//int candata_resolve(struct can_frame  iptcan_frame);
int candata_resolve(unsigned char gunindex,type_canrecvdata  *canrecvdata_struct,const __u8 *databuf,const __u8 iptpf);
struct can_frame  pack_cts(__u8 packnumtoget,__u8 packstartpos,_union_byte_three  trans_pgn);
struct can_frame  pack_cmd9728(__u8 stub_communication_version[3]);
struct can_frame  pack_cmd256(__u8 identify);
struct can_frame  pack_cmd1792(void);
struct can_frame  pack_cmd2048(unsigned char bms_vesion,float largest_opt_volt,float lowestopt_volt,float largest_opt_current ,float lowest_opt_current);
struct can_frame  pack_cmd2560(__u8 identify);
struct can_frame  pack_cmd4608(unsigned char bms_vesion,float optvolt,float optcurrent,short chargetm,short charge_halt);
struct can_frame  pack_cmd6656(unsigned char stopreason,short brkdownreason,unsigned char  errreason);
struct can_frame  pack_cmd7424(unsigned char bms_vesion,short chrtotaltm,short totalkwh, int stubnum );
struct can_frame  pack_cmd7936(__u8 errcode);
struct can_frame  pack_endofmsgack(__u8 totalpacknum,short  totalbyte,_union_byte_three  trans_pgn);
__u8 workin_idle(unsigned char gunindex);
__u8  workin_get9984(unsigned char gunindex);
__u8 workin_get512(unsigned char gunindex);
__u8 workin_get1536(unsigned char gunindex);
__u8 workin_get2304(unsigned char gunindex);
__u8 workin_get4352(unsigned char gunindex);
__u8 workin_canchargestop(unsigned char gunindex);
__u8 workin_canchargestatics(unsigned char gunindex);

void GetsysTime(SYNCHRO_TIME_S *OutStrctTm);
#endif /* BUSINTER_H_ */
