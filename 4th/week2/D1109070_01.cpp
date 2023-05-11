#include <bits/stdc++.h>
using namespace std;
set<vector<vector<int>>> st;
vector<vector<int>> m(3,vector<int>(3));
typedef struct node{
	vector<vector<int>> mp;
	int x,y,dis;
}Node;
queue<Node> q;
int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
bool check(vector<vector<int>> &v){
	for(int i = 0,k = 1;i < 3;i++){
		for(int j = 0;j < 3;j++,k++){
			if(k == 9){
				break;
			}else if(v[i][j] != k){
				return false;
			}
		}
	}
	return true;
}
bool over(int &x,int &y){
	return x >= 0 && x < 3 && y >= 0 && y < 3;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0;i < 3;i++){
    	for(int j = 0;j < 3;j++){
    		cin >> m[i][j];
    	}
    }
    st.insert(m);
    for(int i = 0;i < 3;i++){
    	for(int j = 0;j < 3;j++){
    		if(m[i][j] == 0){
    			Node newn;
    			newn.x = i,newn.y = j,newn.dis = 0,newn.mp = m;
    			q.emplace(newn);
    			break;
    		}
    	}
    }
    bool ans = false;
    while(!q.empty()){
    	Node newn = q.front();
    	for(int i = 0;i < 4;i++){
    		Node n = newn;
    		n.x += d[i][0],n.y += d[i][1],n.dis++;
    		if(over(n.x,n.y)){
    			swap(n.mp[newn.x][newn.y],n.mp[n.x][n.y]);
    			if(check(n.mp)){
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
