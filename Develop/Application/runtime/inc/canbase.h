/*
 * caninterface.h
 *
 *  Created on: Mar 18, 2014
 *      Author: root
 */

#ifndef CANBASE_H_
#define CANBASE_H_

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
//#include "businter.h"
//#include "NetWorkDel.h"
#include "pubheader.h"

#define  ONEMSC   (1000)
#if 1
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

#endif
#define PRIORITY_01			(1)
#define PRIORITY_02			(2)
#define PRIORITY_03			(3)
#define PRIORITY_04			(4)
#define PRIORITY_05			(5)
#define PRIORITY_06			(6)
#define PRIORITY_07			(7)
canid_t   format_canid(__u8 p,__u8 r,__u8 dp,__u8 pf,__u8 ps,__u8 sa);
__u8 get_sa(canid_t);//èŽ·å–æºåœ°å€id
__u8 get_da(canid_t);//èŽ·å–ç›®çš„åœ°å€id
__u8 get_pf(canid_t);//èŽ·å–å‘½ä»¤ä»£ç 
int Can_SendData(const int senddata_ID,struct can_frame  sndcan_frame);
int  recvcandata(int cansock_id,struct can_frame  *canrev_return);
long timeval_tolong(struct timeval ipttimeval);
#endif /* CANINTERFACE_H_ */
