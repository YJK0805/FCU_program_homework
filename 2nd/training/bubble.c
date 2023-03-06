#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
    for(int i = 0;i < 10;i++){
        for(int j = 1;j < 10 - i;j++){
            if(a[j] < a[j - 1]){
                int t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t;
            }
        }
    }
    for(int i = 0;i < 10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}