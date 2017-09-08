/*
 * IODrv.h
 *
 *  Created on: 2010-10-21
 *      Author: root
 */

#ifndef IODRV_H_
#define IODRV_H_

#define GET_GPIO	0x301
#define SET_GPIO	0x302	
#define AD_CONVST	0x303
#define WD_FEED		0x304
#define IO_TEST		0x305
#define TRIGGER_OUT	0x306
#define GPIOCON_PWR	0x307
#define LCDEN_OPER	0x308
#define POWER_CTL	0x309
#define RTS485_J07_CTL	0x310
#define RTS485_J10_CTL	0x311

#define DI0	    0
#define DI1	    1
#define DI2	    2
#define DI3	    3
#define DI4	    4
#define DI5	    5
#define DI6	    6
#define DI7	    7

#define DI8		8
#define DI9		9
#define DI10    10
#define DI11    11
#define DI12    12
#define DI13    13
#define DI14    14
#define DI15    15

#define DO0	    100
#define DO1	    101
#define DO2	    102
#define DO3	    103
#define DO4	    104
#define DO5	    105
#define DO6	    106
#define DO7	    107
#define DO8	    108
#define DO9	    109
#define DO10	110
#define DO11	111
#define DO12	112
#define DO13	113
#define DO14	114
#define DO15	115

typedef struct{
	int io_node;
	int io_data;
}io_value;

#endif /* IODRV_H_ */
