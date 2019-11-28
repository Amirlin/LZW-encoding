#include "lzw.h"

Dict *LZ_initEncDic(FILE *fp)
{
	char c;
	Dict *dict =D_new(20);
	c=fgetc(fp);
	while(c!=EOF)
	{
		//char s[2];
		char *s = (char *)malloc(2 * sizeof(char));
		s[0]=c;
		s[1]='\0';
		char *buffer = (char *)malloc(12 * sizeof(char));
		sprintf(buffer, "%d",dict->size); 
	 	int a=D_put(dict, s,buffer);// to avoid having double elements in dict
		 if (a==1)
		 	dict->size++;
		printf("%s\n",s );
		c=fgetc(fp);
	}
return dict;
}

Dict *LZ_encode(Dict *initDic, FILE *fp)
{
	char arrDecode[10][10];
	char c=fgetc(fp);
	char *prev = (char *)malloc(10 * sizeof(char));
		prev[0]=c;
		prev[1]='\0';
	while(c!=EOF)
	{
		c=fgetc(fp);
		char *cur = (char *)malloc(2 * sizeof(char));
		cur[0]=c;
		cur[1]='\0';
		char *temp= (char *)malloc((6) * sizeof(char));
		strcat(temp,prev);
		strcat(temp,cur);
		if (D_search(initDic, temp)==0)
			strcpy(prev,temp);
		else
		{
			char *buffer = (char *)malloc(6 * sizeof(char));
			sprintf(buffer, "%d",initDic->size); //integer to string
		printf("%s\n",temp);
			D_put(initDic,temp,buffer);
			initDic->size++;
		strcpy(prev,cur);
		if (strcmp(cur,"d")==0)
			break;
		}
	}
	return initDic;
}