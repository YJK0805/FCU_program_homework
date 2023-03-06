#include<stdio.h>
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
    char *part[128];
    //建儲存部別的陣列
    part['D'] = "大學",part['E'] = "進修",part['M'] = "碩士",part['P'] = "博士";
    //計算當前民國年分
    long long year = 1970 + (time(NULL) / 31536000) - 1911;
    //輸入學號並提醒使用者格式
    while(printf("請輸入學號(格式：英文字母+7位數字)：") && scanf("%s",student_id) != EOF){
        //呼叫函式判斷學號是否為真
        if(check(student_id)){
            printf("此為真實學號\n");
            //判斷是新生、延畢生或是其他年級學生
            if(((student_id[1] - '0') * 10 + student_id[2] - '0') == year % 100){
                printf("經由系統判斷您為逢甲大學%s部大一新鮮人，為恭喜您進入逢甲大學，因此獲得一張折價券\n",part[student_id[0]]);
            }else if(((year % 100) - ((student_id[1] - '0') * 10 + student_id[2] - '0')) > 4){
                printf("經由系統判斷您為逢甲大學%s部延畢生，為鼓勵您在課業上繼續努力，因此獲得一張折價券\n",part[student_id[0]]);
            }else{
                printf("經由系統判斷您為逢甲大學%s部學生，不過我們目前的折價活動僅限新生及延畢生，敬請見諒\n",part[student_id[0]]);
            }
        }else{
            //輸出學號不存在
            printf("此學號不存在，請重新輸入\n");
        }
    }
    return 0;
}