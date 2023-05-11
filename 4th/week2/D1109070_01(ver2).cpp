#include <bits/stdc++.h>
using namespace std;
set<vector<vector<int>>> st;
vector<vector<int>> m(3,vector<int>(3));
vector<vector<int>> ed = {{1,2,3},{4,5,6},{7,8,0}};
typedef struct node{
	vector<vector<int>> mp;
	int x,y,dis;
}Node;
queue<Node> q;
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    Node newn;
    for(int i = 0;i < 3;i++){
    	for(int j = 0;j < 3;j++){
    		cin >> m[i][j];
    		if(m[i][j] == 0){
    			newn.x = i,newn.y = j;
    		}
    	}
    }
    newn.dis = 0,newn.mp = m;
    q.emplace(newn);
    st.insert(m);
    bool ans = false;
    while(!q.empty()){
    	Node newn = q.front();
    	for(int i = 0;i < 4;i++){
    		Node n = newn;
    		n.x += d[i][0],n.y += d[i][1],n.dis++;
    		if(n.x >= 0 && n.x < 3 && n.y >= 0 && n.y < 3){
    			swap(n.mp[newn.x][newn.y],n.mp[n.x][n.y]);
    			if(n.mp == ed){
    				cout << n.dis << "\n";
    				ans = true;
    				break;
    			}else if(!st.count(n.mp)){
    				q.emplace(n);
    				st.insert(n.mp);
    			}
    		}
    	}
    	if(ans){
    		break;
    	}
    	q.pop();
    }
    if(!ans){
    	cout << "impossible\n";
    }
    return 0;
}