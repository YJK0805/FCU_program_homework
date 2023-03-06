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
    for(int i = 1;i < 10;i++){
        int value = a[i],j = i - 1;
        while(j >= 0 && a[j] > value){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = value;
    }
    for(int i = 0;i < 10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}