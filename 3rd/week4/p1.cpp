#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<string,int> mp;
    string s,s1;
    while(getline(cin,s)){
    	s1 = "";
    	for(int i = 0;i < s.size();i++){
    		if(isalpha(s[i])){
    			s1 += tolower(s[i]);
    		}else{
    			if(s1 != ""){
	    			mp[s1] = 1;
	    			s1 = "";
	    		}
    		}
    	}
    	if(s1 != ""){
			mp[s1] = 1;
		}
    }
    for(auto &i : mp){
    	cout << i.first << "\n";
    }
    return 0;
}
