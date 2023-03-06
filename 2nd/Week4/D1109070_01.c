#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct locate{
    long long x,y;
};
int cmp(const void *a,const void *b){
    struct locate va = *(struct locate*) a,vb = *(struct locate*) b;
    long long a_dis = abs(va.x) + abs(va.y),b_dis = abs(vb.x) + abs(vb.y);
    if(a_dis != b_dis){
        return a_dis - b_dis;
    }else{
        if(abs(va.x) != abs(vb.x)){
            return abs(va.x) - abs(vb.x);
        }else if(abs(va.y) != abs(vb.y)){
            return abs(va.y) - abs(vb.y);
        }else{
            if(va.x > 0 && va.y > 0){
                return -1;
            }else if(vb.x > 0 && vb.y > 0){
                return 1;
            }else if(va.x < 0 && va.y > 0){
                return -1;
            }else if(vb.x < 0 && vb.y > 0){
                return 1;
            }else if(va.x < 0 && va.y < 0){
                return -1;
            }else if(vb.x < 0 && vb.y < 0){
                return 1;
            }else if(va.x > 0 && va.y < 0){
                return -1;
            }else if(vb.x > 0 && vb.y < 0){
                return 1;
            }
        }
    }
}
int main(){
    long long n;
    struct locate student[10010];
    scanf("%lld",&n);
    for(int i = 0;i < n;i++){
        scanf("%lld %lld",&student[i].x,&student[i].y);
    }
    qsort(student,n,sizeof(struct locate),cmp);
    for(int i = 0;i < n;i++){
        printf("%lld %lld\n",student[i].x,student[i].y);
    }
    return 0;
} 