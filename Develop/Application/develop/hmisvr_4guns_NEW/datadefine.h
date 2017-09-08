/*============================================================================*
 *         Copyright(c) 2010, Siemens Limited China
 *                          ALL RIGHTS RESERVED
 *
 *  PRODUCT : AcPost HMI
 *
 *  FILENAME:
 *  PURPOSE : Date Define
 *
 *  HISTORY :
 *  DATE          VERSION        AUTHOR               NOTE
 *  2010-08-10	   V1.0		LiXinnan	     Created
 *---------------------------------------------------------------------------*/

#ifndef DATADEFINE_H
#define DATADEFINE_H
#include "DB_Unity.h"
#include <QtGui>
#include "rundialog.h"
#include "define.h"
#include "maindialog.h"
//#include "datainputdialog.h"

s_HMI_RFID g_sHMIRFID;
s_HMI_CHRG g_sHMICHRG;
s_HMI_METER g_sHMIMETER;
s_IDLE_TIME g_sDLGIDLETIME;
UINT8 g_uchmi_state;        //HIM系统工作状态

QTranslator *tor;           //翻译文件

mainDialog *maindlg;
//datainputDialog *datainputdlg;
INT16 (*API_Read_DB)(UINT32 label,void* Data,UINT8* DataType);
INT16 (*API_Write_DB)(UINT32 label,void* Data,UINT8* DataType);
void (*API_DB_Initial)(void);

QProcess *mplayerProcess;

s_MPLAY_CTRL g_mplay_ctrl;
s_TIME g_settingtime;
s_TIME g_bookchargetime;
BOOL bContChrgFlag; //充电结束后继续充电标志
char g_loglev = 0;
s_CHECK_TIME g_sCHECKTIME;

#endif // DATADEFINE_H
