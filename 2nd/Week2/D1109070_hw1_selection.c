#include<stdio.h>
void selection_sort(int *arr,int start,int end){
    //index：已排序的索引數量、find_max：找極值(最大值)的迴圈使用的變數、max_num_index：最大值的index、max_num：最大值
    int index,find_max,max_num_index,max_num;
    for(index = start;index <= end;index++){
        max_num_index = 0,max_num = arr[0];
        for(find_max = start;find_max <= end - index;find_max++){
            //當下值大於目前的最大值時將最大值換成此值、最大值的index也同時更新
            if(arr[find_max] > max_num){
                max_num = arr[find_max];
                max_num_index = find_max;
            }
        }
        //將當下排序的陣列值與找到的極值交換
        int temp = arr[end - index];
        arr[end - index] = arr[max_num_index];
        arr[max_num_index] = temp;
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
    //選擇排序函式，需傳送的有要排序的陣列、要排序的頭尾值(index)
    selection_sort(nums,0,9);
    //輸出已排序陣列
    printf("sorting array:");
    for(int index = 0;index < 10;index++){
        printf("%d ",nums[index]);
    }
    printf("\n");
    return 0;
}
