#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//儲存計算結果的陣列
int memorize[50] = {0};
int climbStairs(int n){
    //如果未計算過就開始計算值並儲存入陣列，如果< 1就直接回傳1，反之呼叫函式計算值
    if(!memorize[n]){
        memorize[n] = n <= 1 ? 1 : climbStairs(n - 1) + climbStairs(n - 2);
    }
    return memorize[n];
}
int main(){
    //產生詢問的亂數，範圍為1~45
    srand(time(NULL));
    int n = rand() % 45 + 1;
    //輸出n值與答案
    printf("n = %d climbStairs(n) = %d\n",n,climbStairs(n));
    return 0;
}
