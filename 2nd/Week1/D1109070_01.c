#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long stair[500100],red[500100],blue[500100];
int cmp(const void* a,const void* b){
	int va = *(int *)a;
	int vb = *(int *)b;
	return va - vb;
}
int main(){
	long long t,n,i,j,k;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		if(n == 0){
			printf("0\n");
			continue;
		}
		for(i = 0,j = -1,k = -1;i < n;i++){
			scanf("%lld",&stair[i]);
			if(stair[i] > 0){
				j++;
				blue[j] = stair[i];
			}else{
				k++;
				red[k] = abs(stair[i]);
			}
		}
		qsort(blue,j + 1,sizeof(long long),cmp);
		qsort(red,k + 1,sizeof(long long),cmp);
		long long count = 1,now,r = 0,b = 0;
		if(!(j == -1 || k == -1)){
			if(red[0] > blue[0]){
				now = 1;
			}else{
				now = 0;
			}
			while(1){
				if(now){
					while(r <= k && red[r] < blue[b]){
						r++;
					}
					now = 0;
					if(red[r] > blue[b]){
						count++;
						b++;
					}else if(r > k){
						break;
					}
				}else{
					while(b <= j && red[r] > blue[b]){
						b++;
					}
					now = 1;
					if(red[r] < blue[b]){
						count++;
						r++;
					}else if(b > j){
						break;
					}
				}
			}
		}
		printf("%lld\n",count);
	}
    return 0;
}