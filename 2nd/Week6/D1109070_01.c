#include<stdio.h>
long long min(int a,int b){
    return a > b ? b : a;
}
int main(){
    long long n;
    scanf("%lld",&n);
    long long cost[n + 10];
    for(int i = 0;i < n;i++){
        scanf("%lld",&cost[i]);
    }
    for(int i = 2;i < n;i++){
        cost[i] += min(cost[i - 1],cost[i - 2]);
    }
    printf("%lld\n",min(cost[n - 1],cost[n - 2]));
    return 0;
}