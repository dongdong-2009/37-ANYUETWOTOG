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
#ifndef	_UART1_SPECIFIC_H
#define	_UART1_SPECIFIC_H

#define 	UART_RECEIVE_PEND	0xFFFF
#define 	UART_RECEIVE_MAX	0
int UARTCOM_Open(int comport,int baudrate, char databits,char parity,char stopbit,char fctl);
int UARTCOM_Close(int comport);
int UARTCOM_WriteBuffer(int comport,unsigned char *wBuffer,int wLen);
int UARTCOM_ReadBuffer(int comport,unsigned char *rBuffer,int rLenExpect,int TimeExpect);
int UARTCOM_ClearReadBuffer(int comport);
int UARTCOM_ClearWriteBuffer(int comport);


int UART1_Open(int baudrate, char databits,char parity,char stopbit,char fctl);

int UART1_Close(void);

int UART1_WriteBuffer(unsigned char *wBuffer,int wLen);

int UART1_ReadBuffer(unsigned char *rBuffer,int rLenExpect,int TimeExpect);

int UART1_ClearReadBuffer(void);

int UART1_ClearWriteBuffer(void);

int UART4_Open(int baudrate, char databits,char parity,char stopbit,char fctl);
int UART4_Close(void);
int UART4_WriteBuffer(unsigned char *wBuffer,int wLen);
int UART4_ReadBuffer(unsigned char *rBuffer,int rLenExpect,int TimeExpect);
int UART4_ClearReadBuffer(void);
int UART4_ClearWriteBuffer(void);

#endif
