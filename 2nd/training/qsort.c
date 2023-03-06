#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cmp(const void *a,const void *b){
    int va = *(int*) a,vb = *(int*) b;
    return va - vb;
}
int main(){
    srand(time(0));
    int a[20];
    for(int i = 0;i < 10;i++){
        a[i] = rand() % 100;
    }
    for(int i = 0;i < 10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    qsort(a,10,sizeof(int),cmp);
    for(int i = 0;i < 10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}