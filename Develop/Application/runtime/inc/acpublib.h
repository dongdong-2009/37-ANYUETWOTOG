/*
 * acpublib.h
 *
 *  Created on: Apr 17, 2014
 *      Author: root
 */

#ifndef ACPUBLIB_H_
#define ACPUBLIB_H_

#include <sys/stat.h>
#include <fcntl.h>              // open
#include <stdlib.h>             // exit
#include<string.h>
#include "pubheader.h"
#include <sys/stat.h>
#include "DB_Unity.h"
#include <stdio.h>              // printf
#include<sys/types.h>
#include<sys/socket.h>
#include<linux/if.h>
#include<linux/socket.h>
#include<linux/sockios.h>
#include "can.h"
#include <unistd.h>
BOOL  CheckSysfile_Valid();
int checkfilexsit(const  char *filename);
BOOL  checkerrorinforfilevalid(const char *errorinforpath);
BOOL  checkhistoryfilevalid(char *Historyfile_name);


canid_t   format_canid(__u8 cmd,__u8 sa,__u8 da);
struct can_frame  CanPackInit_CMD_0XF1(__u8 cmd,__u8 sa,__u8 da);
struct can_frame  CanPackInit_CMD_0XF2(__u8 cmd,__u8 sa,__u8 da,__u8 cmdpama) ;
struct can_frame  CanPackInit_CMD_0XF3(__u8 cmd,__u8 sa,__u8 da,__u8 cmdpama,__u8 actresult) ;
struct can_frame  CanPackInit_CMD_0XF6(__u8 cmd,__u8 sa,__u8 da,struct  _SubStub_LockSate iptlockstate);
//0 æˆåŠŸ  1å¤±è´¥
__u8 get_sa(canid_t);//èŽ·å–æºåœ°å€id
__u8 get_da(canid_t);//èŽ·å–ç›®çš„åœ°å€id
__u8 get_cmd(canid_t);//èŽ·å–å‘½ä»¤ä»£ç 
int CANSendData(const int senddata_ID,struct can_frame  sndcan_frame);
#endif /* ACPUBLIB_H_ */
