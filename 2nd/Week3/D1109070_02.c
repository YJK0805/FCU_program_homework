/*
#include <stdio.h>
#include <stdbool.h>

int total = 0,bad = 0;
//variable name in judge WILL NOT as same as this.

bool isBadVersion(int);



//*/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    long long l = 1,r = n,mid;
    mid = (l + r) / 2;
    while(l < r){
        mid = (l + r) / 2;
        if(isBadVersion(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    return l;
}

/*
bool isBadVersion(int version)
{
    return version >= bad;
}

int main(void)
{
    while(scanf("%d %d",&total,&bad) != EOF)
    {
        int res = firstBadVersion(total);
        printf("%d\n",res);
    }
    return 0;
}

//*/