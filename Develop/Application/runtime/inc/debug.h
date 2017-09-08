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
#ifndef _DEBUG_H_
#define _DEBUG_H_


#define DebugMsg _DEBUG_MSG
#define ErrMsg _ERROR_MSG
#define InfoMsg _INFO_MSG


#define _DEBUG_MSG(lev1,lev2,arg...)   \
            do {                 \
                if (lev1 > lev2) {printf("Dbg:<%d>:%s %d:	",lev2,__FILE__,__LINE__);   \
                printf(arg);  }   \
            } while(0)
 
#define _ERROR_MSG(arg...)   \
            do {                 \
                printf("Err:%s %d:	",__FILE__,__LINE__);  \
                printf(arg);     \
            } while(0)
#define _INFO_MSG(arg...)   \
            do {                 \
                printf("Info:%s %d:	",__FILE__,__LINE__);  \
                printf(arg);     \
            } while(0)      

inline void DebugBuf(char lev1,char lev2,char *buf,int len,char *desc)
{
	int i = 0;
	if (lev1 > lev2)
	{
		printf("DebugBuf:%s %d %s:",__FILE__,__LINE__,desc);
		for(i=0;i<len;i++)
		{
			printf("%02x ",buf[i]);
		}
		printf("\n");
	}
}

#endif  

