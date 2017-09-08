/**
 * @file
 * @brief initialization file read and write API
 *	-size of the ini file must less than 16K
 *	-after '=' in key value pair, can not support empty char. this would not like WIN32 API
 *	-support comment using ';' prefix
 *	-can not support multi line
 * @author Deng Yangjun
 * @date 2007-1-9
 * @version 0.2
 */
 
#ifndef INI_FILE_H_
#define INI_FILE_H_
#include "pubheader.h"
#ifdef __cplusplus
extern "C"
{

#endif

#define   MAXCHAROFPERONELINE    (512)

int read_profile_string( const char *section, const char *key, char *value, int size,const  char *default_value, const char *file);
int read_profile_int( const char *section, const char *key,int default_value, const char *file);
float read_profile_float( const char *section, const char *key,float default_value, const char *file);
int write_profile_string( const char *section, const char *key,const  char *value, const char *file);
int write_profile_int( const char *section, const char *key,const int value, const char *file);
int write_profile_float( const char *section, const char *key,const float value, const char *file);
void TimeAnanisis(SYNCHRO_TIME_S *OutTm,const unsigned char *INputBuf);
#ifdef __cplusplus
}; //end of extern "C" {
#endif

#endif //end of INI_FILE_H_

