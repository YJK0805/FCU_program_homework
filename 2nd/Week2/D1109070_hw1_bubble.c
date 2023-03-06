#include<stdio.h>
void bubble_sort(int *arr,int start,int end){
    //index：已排序的索引數量、swap_index：迴圈第二圈需不斷判斷需不需要交換值的index、temp：在需要兩值需要交換時的暫存值
    int index,swap_index,temp;
    for(index = start;index <= end;index++){
        //每一輪皆須從一開始遍歷到最後索引減去已排序數量
        for(swap_index = start;swap_index < end - index;swap_index++){
            //當下值比下一值大的時候兩數交換
            if(arr[swap_index] > arr[swap_index + 1]){
                temp = arr[swap_index];
                arr[swap_index] = arr[swap_index + 1];
                arr[swap_index + 1] = temp;
            }
        }
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
    //氣泡排序函式，需傳送的有要排序的陣列、要排序的頭尾值(index)
    bubble_sort(nums,0,9);
    //輸出已排序陣列
    printf("sorting array:");
    for(int index = 0;index < 10;index++){
        printf("%d ",nums[index]);
    }
    printf("\n");
    return 0;
}
