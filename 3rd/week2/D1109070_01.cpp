#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    while(n--){
    	cin >> s;
    	int ans = s.size();
    	for(int i = 1;i <= s.size();i++){
    		if(!(s.size() % i)){
	    		string check = s.substr(0,i);
	    		int f = 1;
	    		for(int j = i;j < s.size();j += i){
	    			if(check != s.substr(j,i)){
	    				f = 0;
	    				break;
	    			}
	    		}
	    		if(f){
	    			ans = i;
	    			break;
	    		}
	    	}
    	}
    	cout << ans << "\n";
    }
    return 0;
}
