#ifndef __GPIO_CASE_CODES_H__
#define __GPIO_CASE_CODES_H__
/*
addby lanjun  2013.11.10
*date		version			detail					author
*20131116  	V0		initial version release.    	lanjun
*20140117  	V1		delete  "case INPUT_PB27"   	lanjun  usefulless
*					add  "case OUTPUT_PC31"			lanjun  PC31 use for can reset   2014.3.18
ioctl(fd,CASE_CODES,arg) instruction:
1.CASE_CODES  can be defined as follows.
2.If CASE_CODE is output_class ,you need to give the arg to
tell driver  what you want to output: HIGH or LOW.
3.Corresponding  to each case, there is only one pin . 

*/
//input pins CASE_CODES without pullup inside of CPU
#define	INPUT_PB21	(1) //急停开关，低急停被按下
#define	INPUT_PB22 	(8)
#define	INPUT_PB23	(3)
#define	INPUT_PB24	(4)
#define	INPUT_PB25	(5)
#define	INPUT_PB26	(6) //过流保护，低过流
#define	INPUT_PB27	(7)
//#define	INPUT_PC11	(7)// ac_cc 低电平 S闭合
#define	INPUT_PB20	(10) 
#define	INPUT_PC17	(9)  // lcd check
//output pins CASE_CODES
//#define	OUTPUT_PB20	(10) //RFID card reset
#define	OUTPUT_PB28	(11) //led1
#define	OUTPUT_PB29	(12) //led2
#define	OUTPUT_PB30	(13) //led3
#define	OUTPUT_PB31	(14) //led4

#define	OUTPUT_PC24	(15)  //副电磁锁吸合
#define	OUTPUT_PC22	(16)  //主电磁锁吸合
#define	OUTPUT_PC20	(17)  //主交流接触器吸合
#define	OUTPUT_PC18	(18)  //副交流接触器吸合
#define	OUTPUT_PC16	(19)  //gprs_powet_en

#define	OUTPUT_PC10	(20)  //y5
#define	OUTPUT_PC11	(21)  //y6
#define	OUTPUT_PC13	(27)  //y7
#define	OUTPUT_PC15	(28)  //y8


//MCP2515 reset  added by lan  20140117
// 0:reset activity    
// 1:reset unactivity
#define	OUTPUT_PC31	(24)  // PC31 use for can0 reset
#define	OUTPUT_PC29	(25)  // PC29 use for can1 reset
#define	OUTPUT_PC27	(26)  // PC27 use for can2 reset


#define	OUTPUT_PD25	(22)  //LCD 背光控制，高电平半亮，低电平全亮。
#define	OUTPUT_PE0	(23)  //LCD 背光控制，高电亮，低电平关。



#define	HIGH	1
#define	LOW		0
#endif
