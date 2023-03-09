#include <stdio.h>
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
        x0 = x1 - x0 * q;
        x1 = t;
    }
    if(x1 < 0){
        x1 += r0;
    }
    return x1;
}
int main(){
    long long p,q,e;
    while(scanf("%lld %lld %lld",&p,&q,&e) != EOF){
        long long r = (p - 1) * (q - 1),d = inverse(e,r);
        printf("%lld %lld\n",r,d);
    }
    return 0;
}
