#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lzw.h"
#include "dict.h"


int main(int argc, char const *argv[])
{
	//put data in file
	FILE *fp=fopen("file.txt","w");
	if (fp==NULL)
		printf("could not open\n");

	char* str="si ton ton mon tond";
	fputs(str , fp);
	fclose(fp);
	//create initial dictionary
	fp=fopen("file.txt","r");
	Dict *dict=LZ_initEncDic(fp);
	fclose(fp);

	D_print(dict);

	fp=fopen("file.txt","r");
	Dict *dict1 = LZ_encode(dict,fp);

	D_print(dict1);

	return 0;
}