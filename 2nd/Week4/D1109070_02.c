#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct locate{
    long long x,y;
};
int main(){
    long long n,a,b,ans = 0;
    struct locate student;
    scanf("%lld %lld %lld",&n,&a,&b);
    for(int i = 0;i < n;i++){
        scanf("%lld %lld",&student.x,&student.y);
        if(abs(student.x) + abs(student.y) >= a && abs(student.x) + abs(student.y) <= b){
            ans++;
        }
    }
    printf("%lld\n",ans);
    return 0;
} 