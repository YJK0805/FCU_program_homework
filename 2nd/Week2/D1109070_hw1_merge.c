#include<stdio.h>
//合併陣列所需的空間
int temp[20];
void merge(int *arr,int left,int right){
    //mid：中間值、first_index：第一段需合併陣列的索引值、second_index：第二段需合併陣列的索引值、new_index：先合併進另一陣列空間的索引值
    int mid = (left + right) / 2,first_index,second_index,new_index;
    for(first_index = left,second_index = mid + 1,new_index = left;new_index <= right;new_index++){
        if(first_index > mid){
            //當第一段陣列合併完後就不斷將第二段陣列合併
			temp[new_index] = arr[second_index];
			second_index++;
		}else if(second_index > right){ 
            //當第二段陣列合併完後就不斷將第一段陣列合併
			temp[new_index] = arr[first_index];
			first_index++;
		}else if(arr[first_index] > arr[second_index]){
            //當第一段陣列目前值>第二段陣列目前值先合併第二段陣列值
			temp[new_index] = arr[second_index];
			second_index++;
		}else{
            //當第二段陣列目前值>第一段陣列目前值先合併第一段陣列值
			temp[new_index] = arr[first_index];
			first_index++;
		}
    }
    int index;
    //將暫存的合併陣列(temp)複製進需合併陣列(arr)
    for(index = left;index <= right;index++){
		arr[index] = temp[index]; 
	}
}
void msort(int *arr,int left,int right){
    //如果左界=右界代表此範圍排序完成
    if(left == right){
        return;
    }
    int mid = (left + right) / 2;
    msort(arr,left,mid);
    msort(arr,mid + 1,right);
    //將此範圍的陣列合併
    merge(arr,left,right);
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
    //合併排序函式，需傳送的有要排序的陣列、要排序的頭尾值(index)
    msort(nums,0,9);
    //輸出已排序陣列
    printf("sorting array:");
    for(int index = 0;index < 10;index++){
        printf("%d ",nums[index]);
    }
    printf("\n");
    return 0;
}
