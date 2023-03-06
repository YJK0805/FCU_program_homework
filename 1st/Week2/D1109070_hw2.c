#include <stdio.h>

int main(){
    int height,weight,gender,age;
    //輸入身高、體重、性別、年齡
    printf("請輸入身高(cm)：");
    scanf("%d", &height);
    printf("請輸入體重(kg)：");
    scanf("%d", &weight);
    printf("請輸入性別(男1 女0)：");
    scanf("%d", &gender);
    printf("請輸入年齡：");
    scanf("%d", &age);
    //計算BMI、BMR，並印出
    double BMI = weight * 1.0 / (height * 0.01 * height * 0.01), BMR = weight * 9.99 + 6.25 * height - 4.92 * age + (166 * gender - 161);
    printf("您的BMI：%.1f\n您的BMR：%.1f\n", BMI, BMR);
    //判定體位標準，並給予建議
    printf("健康體位標準：");
    if(BMI < 18.5){
        printf("體重過輕\n體位建議：需多運動，均衡飲食，增強體能，維持健康！\n");
    }else if(BMI >= 18.5 && BMI < 24){
        printf("健康體重\n體位建議：恭喜！要繼續保持\n");
    }else if(BMI >= 24 && BMI < 27){
        printf("體重過重\n體位建議：要盡快力行「健康體重管理」！\n");
    }else if(BMI >= 27){
        printf("肥胖\n體位建議：需要立刻力行「健康體重管理」\n");
    }
    //判定兵役種類
    printf("服兵役體位：");
    if(BMI > 31.5 || BMI < 16.5){
        printf("免疫\n");
    }else if((BMI > 31 && BMI <= 31.5) || (BMI >= 16.5 && BMI < 17)){
        printf("替代役\n");
    }else if(BMI >= 17 && BMI <= 31){
        printf("常備役\n");
    }
    //判定警專體位有無合格
    printf("警專標準：");
    if(gender == 1){
        if(BMI >= 18 && BMI <= 28){
            printf("合格\n");
        }else{
            printf("不合格\n");
        }
    }else{
        if(BMI >= 17 && BMI <= 26){
            printf("合格\n");
        }else{
            printf("不合格\n");
        }
    }
    return 0;
}