#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> m(3,vector<int>(3)),ed = {{1,2,3},{4,5,6},{7,8,9}},d = {{-1,0},{1,0},{0,-1},{0, 1}};
unordered_set<long long> st;
typedef struct node{
	vector<vector<int>> mp;
	int g,h,x,y,f;
	bool operator < (const node &n) const{
		return f > n.f || (f == n.f && g > n.g) || (f == n.f && g == n.g && h > n.h);
	}
}Node;
int H(vector<vector<int>> &arr){
	int sum = 0;
	for(int i = 0;i < 3;i++){
    	for(int j = 0;j < 3;j++){
    		if(arr[i][j] == 9){
    			continue;
    		}
    		sum += (arr[i][j] != ed[i][j]);
    	}
    }
    return sum;
}
long long count(vector<vector<int>> &arr){
	long long ans = 0;
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			ans = 10 * ans + arr[i][j];
		}
	}
	return ans;
}
bool check(vector<vector<int>> &arr){
	vector<int> check;
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			check.emplace_back(arr[i][j]);
		}
	}
	int f = 0;
	for(int i = 0;i < 8;i++){
		if(check[i] == 9){
			continue;
		}
		for(int j = i + 1;j < 9;j++){
			f += (check[i] > check[j]);
		}
	}
	return (f & 1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<Node> q;
    Node newn;
    for(int i = 0;i < 3;i++){
    	for(int j = 0;j < 3;j++){
    		cin >> m[i][j];
    		if(m[i][j] == 0){
    			m[i][j] = 9,newn.x = i,newn.y = j;
    		}
    	}
    }
    if(check(m)){
    	cout << "impossible\n";
    }else{
	    newn.g = 0,newn.h = H(m),newn.mp = m,newn.f = newn.g + newn.h;
	    q.emplace(newn);
	    st.insert(count(m));
	    bool ans = false;
	    while(!q.empty()){
	    	Node n = q.top();
	    	for(int i = 0;i < 4;i++){
	    		Node newn = n;
	    		newn.x += d[i][0],newn.y += d[i][1],newn.g++;
	    		if(newn.x >= 0 && newn.x < 3 && newn.y >= 0 && newn.y < 3){
	    			swap(newn.mp[newn.x][newn.y],newn.mp[n.x][n.y]);
	    			if(newn.mp == ed){
	    				cout << newn.g << "\n";
	    				ans = true;
	    				break;
	    			}else if(!st.count(count(newn.mp))){
	    				newn.h = H(newn.mp),newn.f = newn.g + newn.h;
	    				q.emplace(newn);
	    				st.insert(count(newn.mp));
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
	}
    return 0;
}
