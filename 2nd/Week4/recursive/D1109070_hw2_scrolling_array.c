#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int climbStairs(int n){
    //宣告最原始的陣列值
    int arr[3] = {1,1,2};
    //如果詢問值< 2就直接回傳值
    if(n <= 2){
        return n;
    }else{
        //從第3項開始滾動數值，直到詢問值為止
        for(int i = 3;i <= n;i++){
            arr[0] = arr[1];
            arr[1] = arr[2];
            arr[2] = arr[0] + arr[1];
        }
        return arr[2];
    }
}
int main(){
    //產生詢問的亂數，範圍為1~45
    srand(time(NULL));
    int n = rand() % 45 + 1;
    //輸出n值與答案
    printf("n = %d climbStairs(n) = %d\n",n,climbStairs(n));
    return 0;
}
