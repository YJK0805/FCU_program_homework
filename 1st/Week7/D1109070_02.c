#include <stdio.h>
long long C(long long n,long long m){
    long long sum = 1;
    for(int i = 1;i <= m;i++){
        sum = sum * (n - m + i) / i;
    }
    return sum;
}
int main(){
    long long n,m;
    while(scanf("%lld %lld",&n,&m) && (n || m)){
        printf("%lld\n",C(n,m));
    }
    return 0;
}