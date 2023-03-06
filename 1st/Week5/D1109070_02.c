#include <stdio.h>
long long a[1010];
int main(){
    long long n;
    scanf("%lld",&n);
    for(int i = 0;i < n;i++){
        scanf("%lld",&a[i]);
    }
    long long now = 0;
    for(long long i = 0;i < n;i++){
        now += a[i];
        if(!(now % a[i])){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
