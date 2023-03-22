#include <bits/stdc++.h>
using namespace std;
long long find(long long cnt,long long n,long long a){
	long long i = 1;
	while(cnt * i % n != a){
    	i++;
    }
    return cnt * i;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a[3],n[3];
    for(int i  = 0;i < 3;i++){
    	cin >> n[i] >> a[i];
    }
    long long num1,num2,num3;
    num1 = find(n[1] * n[2],n[0],a[0]);
    num2 = find(n[0] * n[2],n[1],a[1]);
    num3 = find(n[0] * n[1],n[2],a[2]);
    long long ans = num1 + num2 + num3,x = n[0] * n[1] * n[2];
    ans -= ((ans / x) * x);
    cout << ans << "\n";
    return 0;
}
