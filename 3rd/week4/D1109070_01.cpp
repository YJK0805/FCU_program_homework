#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    set<string> st;
    string s;
    while(getline(cin,s)){
    	string s1 = "";
    	for(int i = 0;i < s.size();i++){
    		if(isalpha(s[i])){
    			s1 += tolower(s[i]);
    		}else{
    			if(s1 != ""){
	    			st.insert(s1);
	    			s1 = "";
	    		}
    		}
    	}
    	if(s1 != ""){
			st.insert(s1);
		}
    }
    for(auto &i : st){
    	cout << i << "\n";
    }
    return 0;
}
