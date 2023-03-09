#include<stdio.h>
long long inverse(long long e,long long r){
    if(r == 1){
        return 0;
    }
    long long x0 = 0,x1 = 1,r0 = r,q,t;
    while(e > 1){
        q = e / r;
        t = r;
        r = e % r;
        e = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if(x1 < 0){
        x1 += r0;
    }
    return x1;
}
long long fpow(long long a,long long b,long long n){
    if(b == 0){
        return 1;
    }else if(b % 2){
        return (a % n) * (fpow(a,b - 1,n) % n) % n;
    }else{
        long long cur = fpow(a,b / 2,n);
        return cur % n * cur % n % n;
    }
}
int main(){
    long long p,q,e;
    scanf("%lld %lld %lld",&p,&q,&e);
    long long r = (p - 1) * (q - 1),d = inverse(e,r),N = p * q,c;
    while(scanf("%lld",&c) != EOF){
        long long n = fpow(c,d,N);
        printf("%lld\n",n);
    }
}