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
#ifndef INI_PUBSVR_H_
#define INI_PUBSVR_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "iodrv.h"
#include "DB_Unity.h"
#include "ioremap.h"

/*
 * io.h
 */
typedef enum _RTS485_RE_TE{
	TE = 1,
	RE = 0
}RTS485_RE_TE;
extern int fd;
int iodrv_init(void);
void set_rts485_j07_ioctl_TE(void);
void set_rts485_j07_ioctl_RE(void);
void set_rts485_j10_ioctl_TE(void);
void set_rts485_j10_ioctl_RE(void);


/*
 * file operation
 */
int update_one_line_from_the_file(char *Filename,char *updatebuf,int inptlineno);
int insert_one_line_to_end_of_file(char *dir,char *filename,char *linedata);
int checkfile_lenth(char *Filename);


#endif //end

