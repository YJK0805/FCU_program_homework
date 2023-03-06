#include<stdio.h>
void insertion_sort(int *arr,int arrsize){
    //index：已排序的索引數量
    for(int index = 1;index < arrsize;index++){
        //insertion_value：此輪排序的陣列值、insertion_index：此輪排序的索引值
        int insertion_value = arr[index],insertion_index = index - 1;
        //當此輪排序的值較小時就不斷將比較值往後推直到排序值較大為止
        while(insertion_index >= 0 && arr[insertion_index] > insertion_value){
            arr[insertion_index + 1] = arr[insertion_index];
            insertion_index--;
        }
        //將此輪排序的值插入陣列中的位置
        arr[insertion_index + 1] = insertion_value;
    }
}
int main(){
    //宣告陣列並賦予未排序的值
    int nums[10] = {20,60,30,20,10,2,5,89,100,50};
    //先輸出原陣列值
    printf("original array:");
    for(int index = 0;index < 10;index++){
        printf("%d ",nums[index]);
    }
    printf("\n");
    //插入排序函式，需傳送的有要排序的陣列、陣列大小
    insertion_sort(nums,10);
    //輸出已排序陣列
    printf("sorting array:");
    for(int index = 0;index < 10;index++){
        printf("%d ",nums[index]);
    }
    printf("\n");
    return 0;
}
