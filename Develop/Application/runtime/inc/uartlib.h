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
#ifndef UARTLIB_H_
#define UARTLIB_H_

int UART1_Open(int baudrate, char databits,char parity,char stopbit,char fctl);
int UART1_Close(void);
int UART1_WriteBuffer(char *wBuffer,int wLen);
int UART1_ReadBuffer(char *rBuffer,int rLenExpect,int TimeExpect);
int UART1_ClearReadBuffer(void);
int UART1_ClearWriteBuffer(void);

int UART2_Open(int baudrate, char databits,char parity,char stopbit,char fctl);
int UART2_Close(void);
int UART2_WriteBuffer(char *wBuffer,int wLen);
int UART2_ReadBuffer(char *rBuffer,int rLenExpect,int TimeExpect);
int UART2_ClearReadBuffer(void);
int UART2_ClearWriteBuffer(void);

int UART3_Open(int baudrate, char databits,char parity,char stopbit,char fctl);
int UART3_Close(void);
int UART3_WriteBuffer(char *wBuffer,int wLen);
int UART3_ReadBuffer(char *rBuffer,int rLenExpect,int TimeExpect);
int UART3_ClearReadBuffer(void);
int UART3_ClearWriteBuffer(void);

int UART4_Open(int baudrate, char databits,char parity,char stopbit,char fctl);
int UART4_Close(void);
int UART4_WriteBuffer(char *wBuffer,int wLen);
int UART4_ReadBuffer(char *rBuffer,int rLenExpect,int TimeExpect);
int UART4_ClearReadBuffer(void);
int UART4_ClearWriteBuffer(void);

#endif /* UARTLIB_H_ */
