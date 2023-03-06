/*
#include <stdio.h>
#include <stdbool.h>

//*/

bool isPerfectSquare(int num) {
    int l = 0,r = num;
    while(l <= r){
        long long square,mid = (l + r) / 2;
        square = mid * mid;
        if(square == num){
            return true;
        }else if(square > num){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return false;//true or false
}
/*

int main(void)
{
    int num;
    while(scanf("%d",&num) != EOF)
    {
        bool res = isPerfectSquare(num);
        if(res)
            printf("true\n");
        else
            printf("false\n");
    }
    return 0;
}

//*/
