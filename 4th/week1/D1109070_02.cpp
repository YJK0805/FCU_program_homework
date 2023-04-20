#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
	getline(cin,s);
	stack<long long> num;
	string cnt = "";
	for(int i = 0;i < s.size();i++){
		if(s[i] != ' ' && i != s.size() - 1){
			cnt += s[i];
		}else{
			if(i == s.size() - 1){
				cnt += s[i];
			}
			if(isdigit(cnt[cnt.size() - 1])){
				num.emplace(stoi(cnt));
			}else{
				long long a = num.top(),b;
				num.pop();
				b = num.top();
				num.pop();
				if(cnt == "+"){
					num.emplace(b + a);
				}else if(cnt == "-"){
					num.emplace(b - a);
				}else if(cnt == "*"){
					num.emplace(b * a);
				}else if(cnt == "/"){
					num.emplace(b / a);
				}
			}
			cnt = "";
		}
	}
	cout << num.top() << "\n";
    return 0;
}
