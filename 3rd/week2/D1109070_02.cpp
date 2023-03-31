#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while(cin >> s){
    	list<char> ans;
    	auto in = ans.begin();
    	for(auto &i : s){
    		if(i == '['){
    			in = ans.begin();
    		}else if(i == ']'){
    			in = ans.end();
    		}else{
    			ans.insert(in,i);
    		}
    	}
    	for(auto &i : ans){
    		cout << i;
    	}
    	cout << "\n";
    }
    return 0;
}
