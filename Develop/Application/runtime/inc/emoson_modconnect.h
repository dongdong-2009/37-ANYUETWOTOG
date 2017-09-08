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
#define MODULECTL_TXMAXLEN	(512)
#define MODULECTL_RXMAXLEN	(1024)
#define MODWORKSTATE_OPEN (0x00)
#define MODWORKSTATE_CLOSE (0x01)
#define MAXMOD_NUM  (0x02)
#define HEXBUF_LEN	  (1024)

#define MOD_LIMITSTATE_YES (0x00)
#define MOD_LIMITSTATE_NO (0x01)
#define DEVICE_YES (0x00)
#define DEVICE_NO (0x01)
#define CONNECT_FAIL (0xE2)
#define CTL_VOLT    (0xE1)//���ڵ�ѹ
#define CTL_CURRENT    (0xE0)//���ڵ���
#define STRATOFFRAME     (0x7E)
#define ENDOFFRAME     (0x0D)
#define SOFTWAREVERSION     (0x20)
#define CID1_CLTCMD   (0x41)
#define CID2_CLTCMD (0x80)

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
struct _singlemodanalog
{
	float optcurrent;
	unsigned  char selfdefnum;
	float modtemp;
	float limitpoint;
	float optvolt;
	float AB_volt;
	float BC_volt;
	float CA_volt;
	float reserve;	
};


struct _totalmodanalog
{
	float averagevolt;
	unsigned  char modnum;
	struct _singlemodanalog singlemodanalog[MAXMOD_NUM];
};
extern struct _totalmodanalog totalmodanalog;
struct _singlemodstate 
{
	unsigned  char workstate;
	unsigned  char limitstate;
	unsigned  char reserve_3;
	unsigned  char selfdefnum;
	unsigned  char reserve_5;
	unsigned  char reserve_6;
	unsigned  char reserve_7;
	unsigned  char reserve_8;
	unsigned  char reserve_9;
	
};
struct _totalmodstate
{
	unsigned  char modnum;
	struct _singlemodstate singlemodstate[MAXMOD_NUM];
};

extern struct _totalmodstate totalmodstate;
struct _singlemodwaringstate
{
	unsigned  char moderrstate;
	
	unsigned  char selfdefnum;	
	unsigned  char modprotect;
	unsigned  char fan_err;
	unsigned  char temp_overload;
	unsigned  char limitpower;
	unsigned  char reserve_5;
	unsigned  char connect_state;
	unsigned  char reserve_7;
};
struct _totalwaringstate
{
	
	unsigned  char modnum;
	struct _singlemodwaringstate singlemodwaringstate[MAXMOD_NUM];
};
extern struct _totalwaringstate totalwaringstate;
#pragma pack(pop)

unsigned char asc_hex(unsigned char asch, unsigned char	ascl);
unsigned char ascstring_hexstring(unsigned char *Output ,unsigned int Outputlen,unsigned char *Input,unsigned int Inputlen);
unsigned char	HexToAscii(unsigned char Input);
unsigned char	HexStingToAsciiString(unsigned char *Output ,unsigned int Outputlen,unsigned char *Input,unsigned int Inputlen);
short checkcrc(unsigned  char  *checkbuf,unsigned int checklen);
int AnalisisAnalog(unsigned  char *databuf,unsigned int datalen);
int dataconvert(unsigned  char hexdatabuf[1024],unsigned  char *databuf,unsigned int datalen);
int checkdatavalid(unsigned  char *checkbuf,unsigned int checklen);
unsigned short cal_lenchecksum(unsigned short lennum);
void checksumtoacsii(unsigned  char *optbuf,unsigned short checksum);
int packcltcmd(unsigned  char optbuf[HEXBUF_LEN],unsigned  char ctlcmd,float iptvalue);
unsigned int SndAnalogCmd(const int fd_modulectl);
unsigned int SndStateCmd(const int fd_modulectl);
unsigned int SndWaringStateCmd(const int fd_modulectl);
unsigned int SndOpenDCCmd(const int fd_modulectl);
unsigned int SndCloseDCCmd(const int fd_modulectl);
unsigned int SndOpenACCmd(const int fd_modulectl);
unsigned int SndCloseACCmd(const int fd_modulectl);
unsigned int SndCtlVoltCmd(const int fd_modulectl,const short  needvolt,const float  largestopt_volt,const short  bms_largestvolt);
unsigned int SndCtlCurrentCmd(const int fd_modulectl,const short  needcurrent,const float largestopt_current,const short  bms_largestcurrnt);
short quickcal(short *a,int i,int j);
unsigned int getmodresponse(const int comport,unsigned char *rBuffer,int rLenExpect);
unsigned int producecltcmd_pub(void);
float  getrealoutcurrent(short  inptcurrent);
float  getrealoutvolt(short  inptvolt);
#endif /* MODCONNECT_H_ */
