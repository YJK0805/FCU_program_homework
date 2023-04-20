#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    char m[128];
    m['('] = ')',m['{'] = '}',m['['] = ']';
    while(cin >> s){
        stack<char> st;
        for(auto &i : s){
        	!st.empty() ? (m[st.top()] == i ? st.pop() : st.push(i)) : st.push(i);
        }
        cout << (st.empty() ? "True\n" : "False\n");
    }
    return 0;
}