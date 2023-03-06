#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int climbStairs(int n){
    //如果傳入funtion的值< 1就直接回傳1
    if(n <= 1){
        return 1;
    }else{
        //如果傳入funtion的值>= 1就直接呼叫函式計算值
        return climbStairs(n - 1) + climbStairs(n - 2);
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
