#include<stdio.h>
int main(){
    long long year,month;
    while (scanf("%lld %lld",&year,&month) != EOF){
        if(!(year % 400) || (!(year % 4) && (year % 100))){
            switch(month){
                case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
                    printf("31\n");
                    break;
                case 4: case 6: case 9: case 11:
                    printf("30\n");
                    break;
                case 2:
                    printf("29\n");
                    break;
                default:
                    printf("-1\n");
                    break;                    
            }
        }else{
            switch(month){
                case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
                    printf("31\n");
                    break;
                case 4: case 6: case 9: case 11:
                    printf("30\n");
                    break;
                case 2:
                    printf("28\n");
                    break;
                default:
                    printf("-1\n");
                    break;                    
            }
        }
    }
    return 0;
}