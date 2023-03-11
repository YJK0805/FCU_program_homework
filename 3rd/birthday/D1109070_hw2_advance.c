#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//用enum定義與宣告月份
typedef enum{
    JAN = 1,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC
}Month;
//定義日期結構，包含月份、日
typedef struct{
    Month month;
    int day;
}Date;
//生成隨機生日函式，並依不同月份生成不同天數
Date generate(){
    Date b;
    b.month = rand() % 12 + 1;
    switch(b.month){
        case FEB:
            b.day = rand() % 29 + 1;
            break;
        case APR: case JUN: case SEP: case NOV:
            b.day = rand() % 30 + 1;
            break;
        default:
            b.day = rand() % 31 + 1;
            break;
    }
    return b;
}
//排序日期的比較函數，排序規則為將月份由小到大再將日由小到大
int compare(const void *a,const void *b){
    const Date *s1 = (const Date *)a;
    const Date *s2 = (const Date *)b;
    if(s1->month != s2->month) {
        return s1->month - s2->month;
    }else{
        return s1->day - s2->day;
    }
}
//計算是否有重複生日，有則回傳1，沒有回傳0
int count(Date birth[],int num){
    if(num == 1){
        return 0;
    }
    for(int i = 1;i < num;i++){
        if(birth[i].month == birth[i - 1].month && birth[i].day == birth[i - 1].day){
            return 1;
        }
    }
    return 0;
}
//輸出模擬結果
void print(int same){
    printf("在100000次模擬中出現%d次生日重複，重複機率為%.5lf。\n",same,same * 1.0 / 100000.0);
}

int main(){
    long long num;
    //輸入班級人數
    printf("請輸入班級人數：");
    scanf("%lld",&num);
    //宣告自訂結構陣列，並將大小設定為班級人數+1，避免overflow
    Date student[num + 1];
    //設定亂數種子
    srand(time(NULL));
    //計算重複次數的變數
    int same = 0;
    //用迴圈模擬100000結果
    for(int i = 0;i < 100000;i++){
        //用迴圈呼叫function生成班級各個人的生日
        for(int j = 0;j < num;j++){
            student[j] = generate();
        }
        //排序生日
        qsort(student,num,sizeof(student[0]),compare);
        //呼叫function，如果有重複生日則+1
        same += count(student,num);
    }
    //呼叫function輸出結果
    print(same);
    return 0;
}
