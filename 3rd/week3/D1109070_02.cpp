#include <bits/stdc++.h>
using namespace std;
vector<int> dsu(10010);
int find(int x){
	if(dsu[x] == x){
		return x;
	}
	dsu[x] = find(dsu[x]);
	return dsu[x];
}
void Union(int a,int b){
	dsu[find(a)] = find(b);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while(t--){
    	long long n;
    	cin >> n;
    	for(int i = 0;i <= n;i++){
			dsu[i] = i;
		}
    	int x;
    	for(int i = 1;i <= n;i++){
    		cin >> x;
    		Union(i,x);
    	}
    	int mp[n + 10] = {0},ans = 0;
    	for(int i = 1;i <= n;i++){
    		int f = find(dsu[i]);
    		mp[f]++;
    		ans = max(ans,mp[f]);
    	}
    	cout << ans << "\n";
    }
    return 0;
}
