#include <stdio.h>

int main(){
    int height,weight,gender,age;
    //��J�����B�魫�B�ʧO�B�~��
    printf("�п�J����(cm)�G");
    scanf("%d", &height);
    printf("�п�J�魫(kg)�G");
    scanf("%d", &weight);
    printf("�п�J�ʧO(�k1 �k0)�G");
    scanf("%d", &gender);
    printf("�п�J�~�֡G");
    scanf("%d", &age);
    //�p��BMI�BBMR�A�æL�X
    double BMI = weight * 1.0 / (height * 0.01 * height * 0.01), BMR = weight * 9.99 + 6.25 * height - 4.92 * age + (166 * gender - 161);
    printf("�z��BMI�G%.1f\n�z��BMR�G%.1f\n", BMI, BMR);
    //�P�w���зǡA�õ�����ĳ
    printf("���d���зǡG");
    if(BMI < 18.5){
        printf("�魫�L��\n����ĳ�G�ݦh�B�ʡA���Ŷ����A�W�j���A�������d�I\n");
    }else if(BMI >= 18.5 && BMI < 24){
        printf("���d�魫\n����ĳ�G���ߡI�n�~��O��\n");
    }else if(BMI >= 24 && BMI < 27){
        printf("�魫�L��\n����ĳ�G�n�ɧ֤O��u���d�魫�޲z�v�I\n");
    }else if(BMI >= 27){
        printf("�έD\n����ĳ�G�ݭn�ߨ�O��u���d�魫�޲z�v\n");
    }
    //�P�w�L�к���
    printf("�A�L�����G");
    if(BMI > 31.5 || BMI < 16.5){
        printf("�K��\n");
    }else if((BMI > 31 && BMI <= 31.5) || (BMI >= 16.5 && BMI < 17)){
        printf("���N��\n");
    }else if(BMI >= 17 && BMI <= 31){
        printf("�`�Ƨ�\n");
    }
    //�P�wĵ�M��즳�L�X��
    printf("ĵ�M�зǡG");
    if(gender == 1){
        if(BMI >= 18 && BMI <= 28){
            printf("�X��\n");
        }else{
            printf("���X��\n");
        }
    }else{
        if(BMI >= 17 && BMI <= 26){
            printf("�X��\n");
        }else{
            printf("���X��\n");
        }
    }
    return 0;
}