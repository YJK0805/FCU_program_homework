#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    char m[128];
    m['('] = ')',m['{'] = '}',m['['] = ']',m['<'] = '>';
    while(getline(cin,s)){
        stack<char> st;
        for(int i = 0;i < s.size();i++){
            if(!st.empty()){
                if(m[st.top()] == s[i]){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }else{
                st.push(s[i]);
            }
        }
        if(st.empty()){
        	cout << "True\n";
        }else{
        	cout << "False\n";
        }
    }
    return 0;
}