#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    //亂數種子
    srand(time(NULL));
    //宣告儲存答案的陣列
    int dp[50];
    //預先宣告最前面兩項的值
    dp[0] = 1,dp[1] = 1;
    //計算各個答案的值
    for(int i = 2;i <= 45;i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    //重複詢問5次答案
    for(int i = 0;i < 5;i++){
        int n = rand() % 45 + 1;
        printf("n = %d climbStairs(n) = %d\n",n,dp[n]);
    }
    return 0;
}
