#include<stdio.h>
#include<stdlib.h>
#include <string.h>
char tmp1[100],tmp2[100];
int cmp(const void *a,const void *b){
	char *A = (char*) a;
	char *B = (char*) b;
	strcpy(tmp1,A);
	strcpy(tmp1 + strlen(tmp1),B);
	strcpy(tmp2,B);
	strcpy(tmp2 + strlen(tmp2),A);
	return strcmp(tmp2,tmp1);
}
int main(){
	long long n;
	char str[60][50];
	while (scanf("%lld",&n) && n){
		for(int i = 0;i < n;i++){
			scanf("%s",str[i]);
		}
		qsort(str,n,sizeof(str[0]),cmp);
		for(int i = 0;i < n;i++){
			printf("%s",str[i]);
		}
		printf("\n");
	}
    return 0;
}