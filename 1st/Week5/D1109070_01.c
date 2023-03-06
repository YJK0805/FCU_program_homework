#include <stdio.h>
long long gcd(long long x,long long y){
	if(x % y == 0){
		return y;
	}else{
		return gcd(y, x%y);
	}
}
long long lcm(long long x,long long y){
	return (x * y) / gcd(x, y);
}
int main(){
    long long a,b;
    char c;
    while(scanf("%lld %lld %c",&a,&b,&c) != EOF){
        if(c == 'G'){
            printf("%lld\n",gcd(a,b));
        }else{
            printf("%lld\n",lcm(a,b));
        }
    }
    return 0;
}
