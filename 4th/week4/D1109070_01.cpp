#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t,fib[50] = {0,1};
    for(int i = 2;i < 50;i++){
    	fib[i] = fib[i - 1] + fib[i - 2];
    }
    cin >> t;
    while(t--){
    	long long n;
    	cin >> n;
    	string ans = "";
    	bool flag = false;
    	for(int i = 49,cnt = n;i >= 2;i--){
    		if(cnt >= fib[i]){
    			cnt -= fib[i];
    			ans += '1';
    			flag = true;
    		}else if(flag){
    			ans += '0';
    		}
    	}
    	cout << n << " = " << ans << " (fib)\n";
    }
    return 0;
}
