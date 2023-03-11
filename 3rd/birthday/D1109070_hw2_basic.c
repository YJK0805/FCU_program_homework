#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定義以student為名的結構體，內有name：姓名、month,day：生日日期，並將其typedef為student
typedef struct student{
    char name[20];
    int month,day;
}student;
//讀取檔案的函式，此函式用以將檔案內的資料存入宣告的students的陣列中
void read(FILE *f,student *students,int *count){
    char cnt[100];
    while(fgets(cnt,100,f)){
        sscanf(cnt,"%[^,],%d/%d",students[*count].name,&students[*count].month,&students[*count].day);
        (*count)++;
    }
}
//排序已讀入的資料時，需要使用的比較函式，排序規則為將月份由小到大再將日由小到大
int compare(const void *a,const void *b){
    const student *s1 = (const student *)a;
    const student *s2 = (const student *)b;
    if(s1->month != s2->month){
        return s1->month - s2->month;
    }else{
        return s1->day - s2->day;
    }
}
//此函式輸出有相同生日的人數、日期及個別姓名
void print(student *students,int start,int end){
    printf("There are %d people who also have a birthday on %d/%d, and they are the following students：\n",end - start + 1,students[start].month,students[start].day);
    for(int j = start;j <= end;j++){
        printf("%s\n", students[j].name);
    }
}
//此函式確認讀入的資料中是否有相同生日的同學
void check(student *students, int count){
    int start = -1,end = -1,check = 0;
    for(int i = 1;i < count;i++){
        if(check == 1){
            if(students[i].month == students[i - 1].month && students[i].day == students[i - 1].day){
                end++;
            }else{
                print(students,start,end);
                check = 0;
            }
        }else{
            if(students[i].month == students[i - 1].month && students[i].day == students[i - 1].day){
                check = 1;
                start = i - 1;
                end = i;
            }
        }
    }
}

int main(){
    FILE *f;
    //宣告student型態的陣列students
    student students[100];
    //計算班級人數的變數
    int count = 0;
    //如果檔案無法被開啟就輸出並結束程式
    if((f = fopen("birthday.txt", "r")) == NULL){
        printf("File could not be opened.");
        return 0;
    }
    //宣告函式讀入資料
    read(f,students,&count);
    //排序已讀入的資料
    qsort(students,count,sizeof(student),compare);
    //確認是否有同學有相同生日
    check(students,count);
    //關閉檔案
    fclose(f);
    return 0;
}