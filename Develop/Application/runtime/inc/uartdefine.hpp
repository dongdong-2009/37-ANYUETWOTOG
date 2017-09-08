/* filename.c(.cpp)/.h(.hpp)
** 文件功能简述
**
** 错误反馈：andy2003du1984@163.com
**
** 作者：
**	杜鹏(Andrew)	07/06/2013
**	商业软件，保留一切权利
** 修改：
**
** 中国合浦新能源有限公司(potevio) 07/06/2013
** http://www.potevio-sh.com
*/
#ifndef UARTDEFINE_H_
#define UARTDEFINE_H_

typedef struct{
	char	prompt;				//prompt after reciving data
	int 	baudrate;			//baudrate
	char	databit;			//data bits, 5, 6, 7, 8
	char 	debug;				//debug mode, 0: none, 1: debug
	char 	echo;				//echo mode, 0: none, 1: echo
	char	fctl;				//flow control, 0: none, 1: hardware, 2: software
	char 	tty;				//tty: 0, 1, 2, 3, 4, 5, 6, 7
	char	parity;				//parity 0: none, 1: odd, 2: even
	char	stopbit;			//stop bits, 1, 2
	const int reserved;			//reserved, must be zero
}portinfo_t;



#define TIMEOUT_SEC(buflen,baud) 		(buflen*20/baud+2)
#define TIMEOUT_USEC 0
#define MAX_SIZE_READ_BUFFER 			2048 
#define MAX_SYS_UART_NUM 			6
                                	
#define UART_STAT_OPEN	 			1      	
#define	UART_STAT_CLOSE	 			0		
                                	
#define MAX_UART_BUFFER_LEN			128 
#define FIX_UART_BUFFER_LEN			4 
#define M_FRAME_COMMAND_FIRST   		2
#define M_FRAME_COMMAND_END   			3
#define M_FRAME_COMMAND_ACK   			0x50
#define M_FRAME_COMMAND_ERR   			0x45
                                	
#define UART_READ_LEN				128
#define UART_READ_TIMEOUT			1000			//1000 

#define UART_CHECK_NONE				0                                                                                         
#define UART_CHECK_ODD				1                                         
#define UART_CHECK_EVEN				2

#define HMILIB_UART_TTY				3	
//#define	TTY_DEV					"/dev/ttyUSB"
#define	TTY_DEV						"/dev/ttyS"

#define HMILIB_UART_DEFAULT_BAUDRATE		38400 

//UART CONNECTION
#define SPORT_UNUSE				-1
#define HMILIB_ERRINFO_UART_PORTNOTEXIST	1

//UNPACK FRAME
#define RET_UNPACKFRAME_RECVCMDACK		1	//收到执行正确命令字
#define RET_UNPACKFRAME_RECVCMDERR		2	//收到执行错误命令字
#define RET_UNPACKFRAME_RECVCMDDATA		3	//收到执行数据包
#define RET_UNPACKFRAME_RECVTIMEOUT		4	//接收串口数据超时

//COMMAND EXECUSE SUCCESS
#define RET_CMDEXEC_SUCCESS			0	//命令执行成功
#define RET_CMDEXEC_FAILURE			1	//命令执行失败

#define DEF_PRINTDEBUGINFO_MSG	

//xmodem section start
#define SOH  					0x01
#define STX  					0x02
#define EOT  					0x04
#define ACK  					0x06
#define NAK  					0x15
#define CAN  					0x18
#define CTRLZ 					0x1A

#define DLY_1S 					1000 	
#define MAXRETRANS 				25
#define XMODEM_PAGE_LEN 			128
//xmodem section end

#define FILENAME_MAXLEN				1024

#define HMILIBFILEDIR				"/mnt/hgfs/Work/HMILib/eclipseworkspace"

//bin2hex/hex2bin section start
#define OP_OK	0
#define OP_FAIL 1
 
#define BCC		0x00
#define CRC		0x01
 
typedef struct {
	unsigned char l4:4;		 
	unsigned char h4:4;		 	
}BITF;

 
typedef union {
	unsigned int word;	 
	struct
	{
		unsigned char lb;	 
		unsigned char hb;	 
	}byte;
}UNWORD;
 
typedef union {
	BITF  bf;
	unsigned char byte;
}BYTEUNION;

 
typedef struct {
	char  start;	 
	unsigned char  length;		
	unsigned int address;		
	unsigned char  type;		
	unsigned char  data[40];	
	unsigned char  check;		
	unsigned int offset;	
	unsigned char  format;		
}FILE_STRUCT;
//bin2hex/hex2bin section end

#endif /* UARTDEFINE_H_ */
