#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    for(int i = 0;i < t;i++){
    	if(i){
    		cout << "\nCase " << i + 1 << ":\n";
    	}else{
    		cout << "Case " << i + 1 << ":\n";
    	}
    	vector<long long> mp(36),ans(40);
    	for(int i = 0;i < 36;i++){
    		cin >> mp[i];
    	}
    	long long n;
    	cin >> n;
    	for(int i = 0;i < n;i++){
    		long long num,cheap = INT_MAX;
    		cin >> num;
    		for(int j = 2;j <= 36;j++){
    			long long cnt = num,count = 0;
    			while(cnt){
    				count += mp[cnt % j];
    				cnt /= j;
    			}
    			ans[j] = count;
    			cheap = min(cheap,count);
    		}
    		cout << "Cheapest base(s) for number " << num << ":";
    		for(int j = 2;j <= 36;j++){
    			if(ans[j] == cheap){
    				cout << " " << j;
    			}
    		}
    		cout << "\n";
    	}
    }
    return 0;
}
