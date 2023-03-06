#include <stdio.h>

int main(){
    int w , h;
    while(scanf("%d %d",&w,&h) != EOF){
        float BMI = w * 1.0 / (h * 0.01 * h * 0.01);
        if(BMI>=100){
            printf("%.3f\n", BMI);
        }else if(BMI>=10){
            printf("0%.3f\n", BMI);
        }else{
            printf("00%.3f\n", BMI);
        }
    }
    return 0;
}