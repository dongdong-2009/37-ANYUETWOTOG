/*[ Compilation unit ----------------------------------------------------------

   Component       : HMILib

   Name            : HMI.h

   Author          : Changling &Dupeng / Siemens AG IC MOL CTE EVI R&D CN SW

   Last Author     : HMI.h

   Language        : C++

   Creation Date   : 2012-11-15

   Description     : This file provide a uniform interface to access HMI board

               Copyright (C) Siemens AG 2012-2012 All Rights Reserved

-----------------------------------------------------------------------------*/
/*] END */

#ifndef HMI_H_
#define HMI_H_

/**
 @brief bellow define for led matrix,togther with hardware sch will include more infor

 @detailes description
 */

//#define DEF_PRINTDEBUGINFO_MSG
#define DEBUG_MSG _DEBUG_MSG
#define INFO_MSG _INFO_MSG
#define ERR_MSG _ERROR_MSG

#ifdef DEF_PRINTDEBUGINFO_MSG
    #define _DEBUG_MSG(lev,arg...)   \
            do {                 \
                if (lev > 0) {printf("Debug:<%d>:%s %d:	",lev,__FILE__,__LINE__);   \
                printf(arg);  }   \
            } while(0)
#else
    #define _DEBUG_MSG(lev,arg...)
#endif

#define _ERROR_MSG(arg...)   \
            do {                 \
                fprintf(stderr,"Error:%s %d:	",__FILE__,__LINE__);  \
                fprintf(stderr,arg);     \
            } while(0)

#define _INFO_MSG(arg...)   \
            do {                 \
                printf("Info:%s %d:	",__FILE__,__LINE__);  \
                printf(arg);     \
            } while(0)

namespace hmiType
{
    typedef enum
    {
        LED_ALL=(0xffffff),///<ALL LED
        LKP=	(0x000800),    ///<bit18 LED_KEY_PRESET_0 single color
        LKI=	(0x002000),    ///<bit19 LED_KEY_INFO_0
        LKD=	(0x000400),    ///<bit20 LED_KEY_DELAY_0
        LKM=	(0x001000),    ///<bit21 LED_KEY_MAN_0
        LKS=	(0x000200),    ///<bit22 LED_KEY_START_0//sdpmi
        Delay0= (0x000001), ///<led column0 support three color
        Delay1= (0x000002), ///<led column1 support three color
        Delay2= (0x000004),   ///<led column2 support three color
        Delay3= (0x000008),   ///<led column3 support three color
        Delay4= (0x000010),   ///<led column4 support three color
        Delay5= (0x000020),   ///<led column5 support three color
        Delay6= (0x000040),   ///<led column6 support three color
        Delay7= (0x000080),   ///<led column7 support three color
        Ready = (0x000100)    ///<ready led support three color
    }
    LED_NUM_T;

    typedef enum
    {
        UploadFile_Picture	= 0x05,///<upLoad Picture to SPI FLASH
        UploadFile_Character	= 0x06 ///<uploade char lib to SPI FLASH
    }
    UploadFileType_T;///<

    typedef enum
    {
        FILETYPE_HEX            = 0x01,///<file type Hex is fw upgrade file
        FILETYPE_BIN            = 0x02 ///<file type bin is charlib file or picture file
    }
    FileType_T;

    typedef enum
    {
        ttyS0                    = 0,///<ttyS0, choose a com port in your system
        ttyS1                    = 1,///<ttyS1, choose a com port in your system
        ttyS2                    = 2,///<ttyS2, choose a com port in your system
        ttyS3                    = 3,///<ttyS3, choose a com port in your system
        ttyS4                    = 4 ///<ttyS4, choose a com port in your system
    }
    UART_TTYNO_T;

    typedef enum
    {
        fontBasic               = 0x18,///<only when isExtendLib is false
        fontExtend1             = 0x11,///<only when isExtendLib is true
        fontExtend2             = 0x12,///<only when isExtendLib is true
        fontExtend3             = 0x13,///<only when isExtendLib is true
        fontExtend4             = 0x14,///<only when isExtendLib is true
        fontExtend5             = 0x15,///<only when isExtendLib is true
        fontExtend6             = 0x16,///<only when isExtendLib is true
    }
    FONT_NO_T;

    typedef enum
    {
        Backspace     		= 0x08,///<move cursor postion Horizontal left
        HorizontalTab 		= 0x09,///<move cursor postion Horizontal right
        LineFeed      		= 0x0a,///<move cursor postion vertical down
        Home 		  	= 0x0b,///<move cursor postion home (0,0)
        VerticalTab	  	= 0x0c,///<move cursor postion vertical up
        CarriageReturn		= 0x0d,///<move cursor postion (0,0)of line
        ClearBOL		= 0x0e ///<delete a char in current cursor position to begining.
    }
    CursorMoveType_T;///<

    typedef enum
    {
        MacroStart		= 0,///<command of excute Macro
        SetMacro		= 1,///<command of set a Macro
        EraseMacro		= 3 ///<erase Marcro
    }
    MacroFunction_T;

    typedef enum
    {
        Reset                   = 0,///<refer to ResetMode_T find op mcu or lcd
        PowerDownMode           = 1,///<refer to PownDownMode_T mode on or off
        SleepMode               = 2 ///<para after is xxms
    }
    RunMode_T;

    typedef enum
    {
        ResetMCU                = 0x00, ///<MCU reset///<subclass of RunMode_T Reset,distinguish Reset mcu or LCD
        ResetLCD                = 0x01  ///<clear LCD
    }
    ResetMode_T;

    typedef enum
    {
        TurnOffPowerDnMode      = 0x00,///<subclass of RunMode_T PowerDownMode: powerdown mode off
        TurnOnPowerDnMode       = 0x01 ///<subclass of RunMode_T PowerDownMode: powerdown mode on
    }
    PownDownMode_T;

    typedef enum
    {
        LED_Off           	= 0x00,///<for all LED
        LED_Red                 = 0x01,///<for led column and ready
        LED_Green		= 0x02,///<for led column and ready
        LED_Yellow		= 0x03,///<for led column and ready
        LED_Blue		= 0x04 ///<for capkey status led
    }
    LEDColor_T;

    typedef enum
    {
        NoneBlink		= 0x00,///<no blink
        Blink_0P2S		= 0x01,///<blink interval 0.2s
        Blink_0P5S		= 0x02,///<<blink interval 0.5s
        Blink_1S                = 0x03,///<<blink interval 1s
        Blink_2S		= 0x04 ///<<blink interval 2s


    }
    BlinkMode_T;

    typedef enum
    {
        Bright_lev_1		= 0xf8,///<The brightness level of LCD, 1
        Bright_lev_2		= 0xf9,///<The brightness level of LCD, 2
        Bright_lev_3		= 0xfa,///<The brightness level of LCD, 3
        Bright_lev_4		= 0xfb,///<The brightness level of LCD, 4
        Bright_lev_5		= 0xfc,///<The brightness level of LCD, 5
        Bright_lev_6		= 0xfd,///<The brightness level of LCD, 6
        Bright_lev_7		= 0xfe,///<The brightness level of LCD, 7
        Bright_lev_8		= 0xff ///<The brightness level of LCD, 8
    }
    Brightness_T;

    typedef enum
    {
        KeyNameDelay            = 0x01,///<capkey p1
        KeyNameReset            = 0x02,///<capkey p2
        KeyNameMan              = 0x04,///<capkey p3
        KeyNameInfo             = 0x08,///<capkey p4
        KeyNameStart            = 0x10 ///<capkey p5

    }
    KeyName_T;///<capkey NO.

    typedef enum
    {
        LowToHigh               = 0x00,///<what electrical triggle mode will wake up MCU _|-
        HighToLow               = 0x01,///<what electrical triggle mode will wake up MCU -|_
        Pulse                   = 0x02,///<what electrical triggle mode will wake up MCU _|-|_
    }
    WakeUp_T;

    typedef enum
    {
        SetArea                 = 0x11,///<fill area with 1
        ClearArea               = 0x12,///<clear area
        SetOutLine              = 0x14,///<draw a block
        ClearOutLine            = 0x15 ///<clear a block
    }
    AreaOutLineOP_T;

    typedef enum
    {
        SetPixel                = 0x16,///<Operate single pixe illuminate pixe.
        ClearPixel              = 0x17 ///<Operate single pixe go out pixe.
    }
    PixelOP_T;
}//end namespace


/**
 @brief HMI interface function

 @detailes description
 */
class HMI {
public:
	static HMI *hmiInstance()
	{
		if(0 == p_instance_){
			static HMI hmiInstance;
			p_instance_ = &hmiInstance;


		}
		return p_instance_;
	}
    int serialPortConnection(hmiType::UART_TTYNO_T ttyno,int baudrate);
    int serialPortDisconnection(void);
    int authentication(void);
    int handShaking(void);
    int setHMIBaudRate(int baudRate);
    int ledPlay(int ledCode, hmiType::LEDColor_T Color, hmiType::BlinkMode_T blinkMode, unsigned char blinkModeDuration, bool isDimmingModeON, unsigned char dimmingTimes);
    int cursorPosition(int x, int y);
    int cursorMove(hmiType::CursorMoveType_T cursorMoveType);
    int invertArea(void);
    int selectFont(bool isExtendLib,hmiType::FONT_NO_T font);
    int displayCharacterWrite(const char *myString);
    int shiftString(void);
    int textScroll(void);
    int clearBOL(void);
    int pictureDisplay(unsigned char picID);
    int pictureDisplay_ByPosition(unsigned char picID,unsigned char x,unsigned char y,unsigned char xlen,unsigned char ylen );
    int capKeyStroke(int *kValue);
    int setCapKeySensitivity(hmiType::KeyName_T kName, unsigned char sValueDown,unsigned char sValueUp);
    int drawLine(int xEnd, int yEnd);///x,y start is current cursor position.
    int graphicWrite(char *gData);
    int setClearAreaOutline(hmiType::AreaOutLineOP_T areaOutLine, int xLeft, int xRight, int yTop, int yBottom);
    int setClearPixel(hmiType::PixelOP_T setClear, int x, int y);
    int setRunMode(hmiType::RunMode_T runMode,unsigned char data);
    int runWakeUpSetRegisterMask(unsigned char keyNum);
    int wakeUp(hmiType::WakeUp_T type,unsigned char delayMs);
    int macroFunction(hmiType::MacroFunction_T macroType);
    int setCursorStatus(bool cursorScope, bool scopeType);
    int runWakeUpSetRegisterMask(hmiType::KeyName_T keyMask);
    int setBrightness(hmiType::Brightness_T bValue);
    int filesUpLoad(char *filename,hmiType::UploadFileType_T isPictureCharLib,unsigned char filesID);
    int fwUpgrade(char *filename);

    private:
    HMI();// use this was forbidden, this is singleton mode
    virtual ~HMI();
    static HMI *p_instance_;
    int fdcom;
    unsigned char uartstate;
};


#endif /* HMI_H_ */
