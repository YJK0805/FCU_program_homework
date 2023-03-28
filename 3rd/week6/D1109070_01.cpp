#include <bits/stdc++.h>
using namespace std;
vector<long long> prime;
void find(){
	long long count = 0;
	for(int i = 2,count = 0;count < 100;i++){
		long long f = 1;
		for(int j = 2;j < i - 1;j++){
			if(!(i % j)){
				f = 0;
				break;
			}
		}
		if(f){
			count++;
			prime.emplace_back(i);
		}
	}
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    find();
    long long n;
    while(cin >> n && n){
    	vector<long long> ans(prime.size(),0);
    	long long co = 0;
    	for(int i = 2;i <= n;i++){
    		long long cnt = i,j = -1;
    		while(cnt != 1){
    			j++;
    			co = max(co,j);
	    		while(!(cnt % prime[j])){
	    			ans[j]++;
	    			cnt /= prime[j];
	    		}
	    	}
    	}
    	cout << setw(3) << n << "! =";
    	for(int i = 0;i <= co;i++){
    		if(i == 15){
    			cout << "\n      ";
    		}
    		cout << setw(3) << ans[i];
    	}
    	cout << "\n";
    }
    return 0;
}
