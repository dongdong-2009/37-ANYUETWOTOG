/*
 * led-iic.h
 *
 *  Created on: Nov 18, 2013
 *      Author: root
 */

#ifndef LED_IIC_H_
#define LED_IIC_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>

#define   I2C_BUFSIZE  16
int  mcp4725Init();
int mcp4725write( int fd,unsigned output, unsigned int writeEEPROM );
unsigned int getshowvalue(unsigned int inptvalue);
unsigned int adc_ch_read(int fd,unsigned char ch);
#endif /* LED_IIC_H_ */
