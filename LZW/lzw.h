#ifndef LZW
#define LZW

#include "dict.h"

Dict *LZ_initEncDic(FILE *fp);
Dict *LZ_encode(Dict *pEncDic,FILE *fp);
char *LZ_decode(Dict *pEncDic, int *encodedText, int len);

#endif