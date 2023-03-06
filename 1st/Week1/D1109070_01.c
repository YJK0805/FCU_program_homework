#include <stdio.h>
int main(){
    long long i,j,k;
    for(i=3,j=1;i>=0;i--,j+=2){
        for(k=0;k<i;k++){
            printf(" ");
        }
        for(k=0;k<j;k++){
            printf("*");
        }
        printf("\n");
    }
    for(i=1,j=5;i<=3;i++,j-=2){
        for(k=0;k<i;k++){
            printf(" ");
        }
        for(k=0;k<j;k++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
