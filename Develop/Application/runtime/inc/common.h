/* filename.c(.cpp)/.h(.hpp)
** 文件功能简述
**
** 错误反馈：andy2003du1984@163.com
**
** 作者：
**	杜鹏(Andrew)	14/06/2013
**	商业软件，保留一切权利
** 修改：
**
** 中国合浦新能源有限公司(potevio)
** http://www.potevio-sh.com
*/
#ifndef	_UART_COMMON_H
#define _UART_COMMON_H

#define LOCAL_READBUFFER_SIZE		200
//���ڽṹ
typedef struct{
	char	prompt;		//prompt after reciving data
	int 	baudrate;		//baudrate
	char	databit;		//data bits, 5, 6, 7, 8
	char 	debug;		//debug mode, 0: none, 1: debug
	char 	echo;			//echo mode, 0: none, 1: echo
	char	fctl;			//flow control, 0: none, 1: hardware, 2: software
	char 	tty;			//tty: 0, 1, 2, 3, 4, 5, 6, 7
	char	parity;		//parity 0: none, 1: odd, 2: even
	char	stopbit;		//stop bits, 1, 2
	const int reserved;	//reserved, must be zero
}portinfo_t;
typedef portinfo_t *pportinfo_t;

#ifndef	NULL
	#define NULL (void*)0
#endif

#define DRV_DBGASSERT(condition)  \
    if(!(condition)) \
    {\
          printf("\n\r ASSERT: File[%s],Line[%d],Func[%s].\n\r", \
                        __FILE__,__LINE__,__FUNCTION__);\
    }



/*****************************************************************************
*			Macro
******************************************************************************/
#define SYS_NO_ERROR                      0
#define SYS_ERROR_INVALID_PARAMETER       1
#define SYS_ERROR_INVALID_ID              2
#define SYS_ERROR_STATE                   3
#define SYS_ERROR_BAD_DATA                4
#define SYS_ERROR_HW_FAULT                5
#define SYS_ERROR_INIT_FAILURE            6
#define SYS_ERROR_TIMEOUT                 7




/*
 *	�򿪴��ڣ������ļ�������
 *	pportinfo: �����õĴ�����Ϣ
*/
extern	int PortOpen(pportinfo_t pportinfo);
/*
 *	���ô���
 *	fdcom: �����ļ������� pportinfo�� �����õĴ�����Ϣ
*/
extern	int PortSet(int fdcom, const pportinfo_t pportinfo);
/*
 *	�رմ���
 *	fdcom�������ļ�������
*/
extern	void PortClose(int fdcom);
/*
 *	�������
 *	fdcom������������ data��������ݣ� datalen����ݳ���
 *	����ʵ�ʷ��ͳ���
*/
//extern	int PortSend(int fdcom, char *data, int datalen);
/*
 *	�������
 *	fdcom������������ data�����ջ�����, datalen.�����ճ��ȣ� baudrate��������
 *	����ʵ�ʶ���ĳ���
*/
extern	int PortRecv(int fdcom, char *data, int datalen, int TimeMs);

extern	void UART_ClearReadBuffer(int fdcom);

extern	void UART_ClearWriteBuffer(int fdcom);

#define 	UART_RECEIVE_PEND	0xFFFF
#define 	UART_RECEIVE_MAX	0
int UARTCOM_Open(int comport,int baudrate, char databits,char parity,char stopbit,char fctl);
int UARTCOM_Close(int comport);
int UARTCOM_WriteBuffer(int comport,unsigned char *wBuffer,int wLen);
int UARTCOM_ReadBuffer(int comport,unsigned char *rBuffer,int rLenExpect,int TimeExpect);
int UARTCOM_ClearReadBuffer(int comport);
int UARTCOM_ClearWriteBuffer(int comport);

#endif
