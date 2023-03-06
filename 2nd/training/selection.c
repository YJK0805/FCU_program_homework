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
        int index = 0;
        for(int j = 0;j < 10 - i;j++){
            if(a[index] < a[j]){
                index = j;
            }
        }
        int t = a[index];
        a[index] = a[10 - i - 1];
        a[10 - i - 1] = t;
    }
    for(int i = 0;i < 10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}