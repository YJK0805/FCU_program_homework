#include <stdio.h>
int main(){
    long long n,r,arr[10010] = {0},num;
    while(scanf("%lld %lld",&n,&r) != EOF){
        for(int i = 0;i < r;i++){
            scanf("%lld",&num);
            arr[num] = 1;
        }
        if(n == r){
            printf("*\n");
        }else{
            for(int i = 1;i <= n;i++){
                if(!arr[i]){
                    printf("%d ",i);
                }
            }
            printf("\n");
        }
        for(int i = 0;i <= n;i++){
            arr[i] = 0;
        }
    }
    return 0;
}