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
#ifndef UARTBUFFER_H_
#define UARTBUFFER_H_


#include "uartdefine.hpp"


/*
 *
 */
class UartBuffer {
public:
	UartBuffer();
	virtual ~UartBuffer();
	int 		uartOpen(unsigned char tty, int baudrate, char databits,char parity,char stopbit,char fctl);
	int 		uartClose(unsigned char fdcom);
	int 		uartWriteBuffer(unsigned char fdcom,unsigned char  *wBuffer,int wLen);
	int 		uartReadBuffer(unsigned char fdcom,unsigned char *rBuffer,int rLenExpect,int TimeExpect);
	int 		uartClearReadBuffer(unsigned char fdcom);
	int 		uartClearWriteBuffer(unsigned char fdcom);
	char 		xmodemTransmit(unsigned char fdcom,unsigned char *src, int srcsz);
	char 		file_format_covert_hex_to_bin(char *hex_filename,char *bin_filename);
private:
	typedef 	portinfo_t *pportinfo_t;
	portinfo_t 	tty_info;	
	int 		last_error;
	unsigned int 	g_max_addr;		
	unsigned int 	verify_addr;	
	FILE_STRUCT 	g_hex;	
	int 		portOpen(pportinfo_t pportinfo);
	int 		portSet(unsigned char fdcom, const pportinfo_t pportinfo);
	void 		portClose(unsigned char fdcom);
	int 		portSend(unsigned char fdcom,unsigned char *data, int datalen);
	int 		portRecv(unsigned char fdcom, unsigned char *data, int datalen, int TimeMs);
	char 		*get_ptty(pportinfo_t pportinfo);
	int 		convbaud(unsigned long int baudrate);
	//hex2bin convertion
	void 		MemcopyStr(const char *p_source,char *p_dest,unsigned char num);
	char 		hex2bin(const char *p_hex,const char *p_bin,unsigned char fill_length,const unsigned char *p_fill);
	void 		AddVerifyToBin(const char *p_bin,unsigned char verify_type);
	unsigned char 	AsciiToHex(char ascii1,char ascii2,unsigned char *p_data);
	unsigned int 	VerifyData(unsigned int num,unsigned char *p_data,unsigned char type,unsigned int last);
	//xmodem transmition
	void		flushinput(void);
	unsigned char 	port_inbyte(unsigned char fdcom,int time_out);
	void    	port_outbyte(unsigned char fdcom,unsigned char c);
	char 		check(int crc, unsigned char *buf, int sz);
	unsigned int 	crc16_ccitt(unsigned char *buf, int len);
	void 		debugBufferHex(unsigned char *buffer, int buflen );
};

#endif /* UARTBUFFER_H_ */
