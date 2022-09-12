#define _XOPEN_SOURCE       /* See feature_test_macros(7) */
#include <unistd.h>
#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <crypt.h>
#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <time.h>

int main(int argc,char *argv[])
{
	char *res=(char*)malloc(sizeof(char)*1024);
	char *salt=(char*)malloc(sizeof(char)*1024);

	srand((unsigned int) time(NULL));
	
	sprintf(salt,"$6$%d",rand()%100000);
	res=crypt(argv[1], salt);

	printf("%s\n",res);
    	return 0;
}
