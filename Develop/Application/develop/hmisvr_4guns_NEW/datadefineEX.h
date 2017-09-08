/*============================================================================*
 *         Copyright(c) 2010, Siemens Limited China
 *                          ALL RIGHTS RESERVED
 *
 *  PRODUCT : AcPost HMI
 *
 *  FILENAME:
 *  PURPOSE : Date Define Extern
 *
 *  HISTORY :
 *  DATE          VERSION        AUTHOR               NOTE
 *
 *---------------------------------------------------------------------------*/


#ifndef DATADEFINEEX_H
#define DATADEFINEEX_H

#include "IO_Thread.h"

#ifndef TRUE
#define TRUE          0
#endif

#ifndef FALSE
#define FALSE         1
#endif

#ifndef ALARM
#define ALARM         1
#endif

#ifndef NORMAL
#define NORMAL        0
#endif

#ifndef ENABLE
#define ENABLE         1
#endif

#ifndef DISABLE
#define DISABLE        0
#endif

#ifndef IOTRUE
#define IOTRUE         0
#endif

#ifndef IOFALSE
#define IOFALSE        1
#endif

//add by andy0708
#define HMI_CHG_DOOR_OPEN	TRUE
#define HMI_CHG_DOOR_CLOSE	FALSE
#define HMI_CHG_PLUG_IN		TRUE
#define HMI_CHG_PLUG_OUT	FALSE 

                                       
                                       
//----------------

#include <QtGui>
#include "DB_Unity.h"
#include "rundialog.h"
#include "define.h"
#include "maindialog.h"
//#include "datainputdialog.h"
#include "libsound.h"
extern s_HMI_RFID g_sHMIRFID;
extern s_HMI_CHRG g_sHMICHRG;
extern s_HMI_METER g_sHMIMETER;
extern s_IDLE_TIME g_sDLGIDLETIME;
extern UINT8 g_uchmi_state;        //本地HIM系统工作状态

extern mainDialog *maindlg;
//extern datainputDialog *datainputdlg;
extern QProcess *mplayerProcess;
extern s_MPLAY_CTRL g_mplay_ctrl;
extern QTranslator *tor;

extern INT16 (*API_Read_DB)(UINT32 label,void* Data,UINT8* DataType);
extern INT16 (*API_Write_DB)(UINT32 label,void* Data,UINT8* DataType);
extern void (*API_DB_Initial)(void);

extern s_TIME g_settingtime;
extern s_TIME g_bookchargetime;
extern BOOL bContChrgFlag; //充电结束后继续充电标志
extern char g_loglev ;
extern s_CHECK_TIME g_sCHECKTIME;

#endif // DATADEFINEEX_H
