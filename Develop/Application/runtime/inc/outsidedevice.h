/*
 * outsidedevice.h
 *
 *  Created on: 2013-9-3
 *      Author: lijb
 */

#ifndef OUTSIDEDEVICE_H_
#define OUTSIDEDEVICE_H_


typedef struct{
	unsigned char info1;
	unsigned char info2;
	unsigned char info3;
	unsigned char info4;
	int		scale;
}MeterData;

/*
typedef struct{
	float Totalkwh;
	float Avolt;
	float Bvolt;
	float Cvolt;
	float Acurr;
	float Bcurr;
	float Ccurr;
	unsigned char addr_meter[6] ;
	float input_use_power_tota1;
	float  input_use_power_A;
	float  input_use_power_B;
	float  input_use_power_C;
	
	float input_useless_power_total;
	float  input_useless_power_A;
	float  input_useless_power_B;
	float  input_useless_power_C;
	
	float  input_power_volt;
	float  input_power_current;
	
	float  input_power_factor;
	float  input_power_factor_A;
	float  input_power_factor_B;
	float  input_power_factor_C;

	float  input_volt_wave_A;
	float  input_volt_wave_B;
	float  input_volt_wave_C;
	
	unsigned int  input_power_wave;
	unsigned int  input_power_error;
	unsigned int  power_error;
	unsigned char power_switch;
	unsigned char power_insurance;
}MeterInfo;
*/
struct _singlemeterdetail
{
	float input_use_power_tota1;
	float  input_use_power_single;
	
	float input_useless_power_total;
	float  input_useless_power_single;
	
	float  input_power_volt_single;
	float  input_power_current_single;
	
	float  input_power_factor_total;
	float  input_power_factor_single;
	
	float  input_volt_wave_single;
	//unsigned int  input_power_wave;
	unsigned int  input_power_error;
	unsigned int  power_error;
	unsigned char power_switch;
	unsigned char power_insurance;
};
typedef struct{
	float Totalkwh;
	float Avolt;
	float Bvolt;
	float Cvolt;
	float Acurr;
	float Bcurr;
	float Ccurr;
	unsigned char addr_meter[6] ;
	struct _singlemeterdetail singlemeterdetail[3];
}MeterInfo;
/***************************

start  use for rfid main card
* *************************/
//#define DEF_DEBUG_MASTER_CARD

#define DEF_MT_CARD_STX 0X02
#define DEF_MT_CARD_ETX 0X03
#define DEF_MT_CARD_CMD 0X34
#define DEF_MT_CARD_ACTIVE 0X40
#define DEF_MT_CARD_APP 0X41


//以下定义详见<非接触式CPU卡COS手册   建设部版>
#define DEF_CARD_CLA 0X0
#define DEF_CARD_INS 0xA4
#define DEF_CARD_P1  0X0
#define DEF_CARD_P2 0X0
#define DEF_CARD_MF_LIST  0x3F00
#define DEF_CARD_DF_LIST  0xDF01
#define DEF_CLEAR_FILE_CLA 0X0
#define DEF_CLEAR_FILE_INS 0XB0
#define DEF_CLEAR_FILE_P1  0X95  //P1第8位1表示取值范围（0x05~0x1e）即0x95&0x1F=0x15;
#define DEF_CLEAR_FILE_P2  0X0
#define DEF_CLEAR_FILE_DATELEN 0X2a  //预读出数据长度为0x14

#define DEF_DEALY_WAIT_DATE   1
int get_mt_card_num( unsigned char *card_sn,int comport );
/***************************
end  use for rfid main card
* *************************/

/***************************
start  use for meter
* *************************/
unsigned int BCDToBHexDeal(unsigned char *val,unsigned char realDatalen);
void wakeup_meter(int comport);
int getmeteraddres( int comport,MeterInfo *p_MeterInfoOut);
int getdataneed(int comport,MeterInfo *p_MeterInfoOut);
int Get_meter_info(int comport,MeterInfo *p_MeterInfoOut);
int getusefulpower(int comport,MeterInfo *p_MeterInfoOut);
int getuselesspower(int comport,MeterInfo *p_MeterInfoOut);
int getvaluepower(int comport,MeterInfo *p_MeterInfoOut);
int getvoltwavenum(int comport,MeterInfo *p_MeterInfoOut);
/***************************
end   use for meter
* *************************/
#endif /* OUTSIDEDEVICE_H_ */
