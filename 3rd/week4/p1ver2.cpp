#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    set<string> st;
    string s;
    while(getline(cin,s)){
    	for(int i = 0;i < s.size();i++){
    		if(isalpha(s[i])){
    			s[i] = tolower(s[i]);
    		}else{
    			s[i] = ' ';
    		}
    	}
    	stringstream cnt(s);
    	while(cnt >> s){
    		st.insert(s);
    	}
    }
    for(auto &i : st){
    	cout << i << "\n";
    }
    return 0;
}
