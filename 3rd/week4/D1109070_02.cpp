#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	string s,t = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	while(getline(cin,s)){
		string t2[128];
		for(int i = 1;i < t.size();i++){
			t2[t[i]] = t[i - 1];
		}
		for(int i = 0;i < s.size();i++){
			if(s[i] != ' '){
				cout << t2[s[i]];
			}else{
				cout << ' ';
			}
		}
		cout << "\n";
	}
	return 0;
}
