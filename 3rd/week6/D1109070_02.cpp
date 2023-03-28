#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while(t--){
    	long long n;
    	cin >> n;
    	vector<long long> f(n + 1,0);
    	long long high = 0,low = 0;
    	for(int i = 1;i <= n;i++){
    		cin >> f[i];
    		if(f[i] < f[i - 1]){
    			low = high + 1;
    		}else if(f[i] > f[i - 1]){
    			high = low + 1;
    		}
    	}
    	cout << max(high,low) << "\n";
    }
    return 0;
}
