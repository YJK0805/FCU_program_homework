#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while(cin >> s){
    	string ans = "",home = "";
    	int f = 1;
    	for(int i = 0;i < s.size();i++){
    		if(s[i] == '['){
    			f = 0;
    			ans = home + ans;
    			home = "";
    		}else if(s[i] == ']'){
    			f = 1;
    			ans = home + ans;
    			home = "";
    		}else if(f){
    			ans += s[i];
    		}else{
    			home += s[i];
    		}
    	}
    	ans = home + ans;
    	cout << ans << "\n";
    }
    return 0;
}
