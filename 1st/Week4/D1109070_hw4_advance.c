#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
//建立要計算檢查碼用的數字
int num[7] = {0,8,7,6,8,7,6};
//檢查學號與檢查碼是否正確的函式
bool check(char id[]){
    if((int)strlen(id) != 8 || (id[0] != 'D' && id[0] != 'E' && id[0] != 'M' && id[0] != 'P')){
        return false;
    }else{
        int S = 0,cur = 0;
        for(int i = 1;i <= 7;i++){
            cur = (id[i] - '0') * num[i];
            S += (cur / 10 + cur % 10);
        }
        if(((10 - S % 10)%10) == (id[7] - '0')){
            return true;
        }else{
            return false;
        }
    }
}
int main(){
    char student_id[10];
    //計算當前民國年分
    long long year = 1970 + (time(NULL) / 31536000) - 1911;
    //輸入學號並提醒使用者格式
    while(printf("請輸入學號(格式：英文字母+7位數字)：") && scanf("%s",student_id) != EOF){
        //呼叫函式判斷學號是否為真
        if(check(student_id)){
            printf("此為真實學號\n");
            //設定亂數種子
            srand(time(NULL));
            //設定幸運選項
            int lucky = rand() % 4,choose;
            //亂數產生幸運選項，並讓消費者選擇選項，如果選擇與之相同即獲得隨機折數的折價券
            while(printf("請選擇0~3其中一個數字來抽獎：") && scanf("%d",&choose)){
                if(choose >= 0 && choose <= 3){
                    if(choose == lucky){
                        int discount = rand() % 10;
                        if(discount == 0){
                            printf("恭喜中獎，你獲得的獎勵為今日消費0元\n");    
                        }else{
                            printf("恭喜中獎，你獲得1張%d折折價券\n",discount);
                        }
                    }else{
                        printf("很可惜沒有中獎，歡迎再度光臨\n");
                    }
                    break;
                }else{
                    printf("輸入錯誤，請重新輸入\n");
                }
            }
        }else{
            //輸出學號不存在
            printf("此學號不存在，請重新輸入\n");
        }
    }
    return 0;
}