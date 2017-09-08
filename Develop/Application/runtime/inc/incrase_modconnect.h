/*
 * commoduleinter.h
 *
 *  Created on: Oct 16, 2014
 *      Author: root
 */

#ifndef MODCONNECT_H_
#define MODCONNECT_H_
#include "pubheader.h"
 #include <string.h>
 #include<sys/socket.h>
#include<linux/if.h>
#include<linux/socket.h>
#include<linux/sockios.h>
 #include"can.h"

 #define COMM_MODULE_FRAME_START	(0x68)
#define COMM_MODULE_FRAME_END	(0x16)
#define COMM_SLAVE_MODULE_ADDR                    (0x80)
#define COMM_HOST_MACHINE_ADDR                   (0x00)

#define MODULECTL_TXMAXLEN	(512)
#define MODULECTL_RXMAXLEN	(1024)
#define MODWORKSTATE_OPEN (0x00)
#define MODWORKSTATE_CLOSE (0x01)
#define MODWORKSTATE_UNKOWN  (0xFF)
#define MODCTL_OPEN (0x55)
#define MODCTL_CLOSE (0xAA)

//#define MODULE_SINGLE_GROUP  (1)
#define MAXMOD_NUM  (10)
#ifdef MODULE_SINGLE_GROUP
#define SINGLEGROUP_MAXMODNUM  (MAXMOD_NUM)
#else
#define SINGLEGROUP_MAXMODNUM   (MAXMOD_NUM/2)
#endif
#define HEXBUF_LEN	  (1024)

#define MOD_LIMITSTATE_YES (0x00)
#define MOD_LIMITSTATE_NO (0x01)
#define DEVICE_YES (0x00)
#define DEVICE_NO (0x01)
#define CONNECT_FAIL (0xE2)

#define COMMON_CMDID (0x1307c080|CAN_EFF_FLAG)
#define REPLYCOMMON_CMDID (0x1207c080)

#define GETVOLTSET_CMDID    (0x13010080|CAN_EFF_FLAG)
#define REPLYVOLTSET_CMDID    (0x12010080)

#define GETCURRENTSET_CMDID    (0x13010880|CAN_EFF_FLAG)
#define REPLYCURRENTSET_CMDID    (0x12010880)

#define CMD_CTL_OUTPUT    (0x00)
#define CMD_REPLYCTL_OUTPUT    (0x00)

#define CMD_GETSTATE    (0x01)
#define CMD_REPLY_GETSTATE    (0x01)

#define CMD_CTL_SWITCH    (0x02)
#define CMD_REPLYCTL_SWITCH    (0x02)

#define  RESERVE_VALUE (0x00)
#define CMD_FAIL   (0x00)
#define CMD_SUCCESS   (0xFF)

#pragma pack(push) //
#pragma pack(1)
typedef	union 
{
	float fdata ;
	unsigned  char charbuf[4];   
}_ubitfloat ;

typedef	union 
{
      unsigned  short  idata ;
	unsigned  char charbuf[2];   
}_ubitshort ;
struct _clt_output_struct
{
	unsigned  char cmd_id;
	unsigned  char reserve_1;
	short setcurrent;
	unsigned int  setvolt;
};
struct _replyclt_output_struct
{
	unsigned  char cmd_id;
	unsigned  char set_result;
	
};

struct _getstate_struct
{
	unsigned  char cmd_id;
	unsigned  char databuf[8];
	
};
struct _replygetstate_struct
{
	unsigned  char cmd_id;
	unsigned  char reserve_1;
	short opt_current;
	short opt_volt;
	unsigned  char state_1;
	unsigned  char state_0;
};

struct _cltmodswitch_struct
{
	unsigned  char cmd_id;
	unsigned  char databuf[8];
};
struct _replycltmodswitch_struct
{
	unsigned  char cmd_id;
	unsigned  char set_result;
};
/*
struct _getvoltset_struct
{
	unsigned  char buf[8];
};
*/
struct _replygetvoltset_struct
{
	short  reserve_0;
	short  reserve_1;
	short  reserve_2;
	short  set_volt;
};
struct _replygetcurentset_struct
{
	short  set_current;
	short  reserve_1;
	short  reserve_2;
	short  reserve_3;
	
};

typedef  struct   
{
	 struct can_frame  getstate_struct[SINGLEGROUP_MAXMODNUM];
	// struct can_frame  cltmodswitch_struct[SINGLEGROUP_MAXMODNUM];
	 struct can_frame  getvoltset_struct[SINGLEGROUP_MAXMODNUM];
	 struct can_frame  getcurrentset_struct[SINGLEGROUP_MAXMODNUM];
}_commonmod_ctl_struct;
// extern _commonmod_ctl_struct commonmod_ctl_struct;
typedef  struct   
{
	 struct _replyclt_output_struct  replyclt_output_struct;
	 struct _replygetstate_struct  replygetstate_struct[SINGLEGROUP_MAXMODNUM];
	  struct _replycltmodswitch_struct  replycltmodswitch_struct[SINGLEGROUP_MAXMODNUM];
	 struct _replygetvoltset_struct replygetvoltset_struct[SINGLEGROUP_MAXMODNUM];
	 struct _replygetcurentset_struct replygetcurentset_struct[SINGLEGROUP_MAXMODNUM];
}MODULECTLDATASTRUCT;
//extern MODULECTLDATASTRUCT ModuleCtlDataInfor;
#pragma pack(pop)

short quickcal(short *a,int i,int j);
//unsigned int getmodresponse(const int comport,unsigned char *rBuffer,int rLenExpect);
 float  incrasegetrealoutcurrent(float  inptcurrent);
 float  incrasegetrealoutvolt(float  inptvolt);
float incrasegetoutvolt(const float  needvolt,const float  largestopt_volt,const float  bms_largestvolt);
 float  incrasegetoutcurrent(const float  needcurrent,const float largestopt_current,const float  bms_largestcurrnt);
//int packcltcmd_datalen_8(const int fd_modulectl,struct can_frame iptcanframe);
//int packcltcmd_datalen_0(const int fd_modulectl,struct can_frame iptcanframe);
#endif /* MODCONNECT_H_ */
