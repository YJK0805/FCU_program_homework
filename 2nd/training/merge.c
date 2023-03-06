#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int temp[20];
void merge(int *arr,int l,int r){
    int mid = (l + r) / 2;
    for(int i = l,j = mid + 1,k = l;k <= r;k++){
        if(i > mid){
            temp[k] = arr[j];
            j++;
        }else if(j > r){
            temp[k] = arr[i];
            i++;
        }else if(arr[i] > arr[j]){
            temp[k] = arr[j];
            j++;
        }else{
            temp[k] = arr[i];
            i++;
        }
    }
    for(int i = l;i <= r;i++){
        arr[i] = temp[i];
    }
}
void msort(int *arr,int l,int r){
    if(l == r){
        return;
    }
    int mid = (l + r) / 2;
    msort(arr,l,mid);
    msort(arr,mid + 1,r);
    merge(arr,l,r);
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
    msort(a,0,9);
    for(int i = 0;i < 10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}