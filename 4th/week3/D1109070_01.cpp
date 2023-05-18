#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x) : val(x),left(NULL),right(NULL){}
};
TreeNode* insert(TreeNode* root,int val){
    if(!root){
        return new TreeNode(val);
    }else if(root->val > val){
        root->left = insert(root->left,val);
    }else{
        root->right = insert(root->right,val);
    }
    return root;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i < n;i++){
    	cin >> v[i];
    }
	TreeNode* root = new TreeNode(v[n - 1]);
    for(int i = n - 2;i >= 0;i--){
    	insert(root,v[i]);
    }
	queue<TreeNode*> q;
    q.emplace(root);
    while(!q.empty()){
    	int len = q.size();
    	for(int i = 0;i < len;i++){
    		TreeNode* now = q.front();
    		q.pop();
    		cout << now->val << " ";
    		if(now->left){
    			q.emplace(now->left);
    		}
    		if(now->right){
    			q.emplace(now->right);
    		}
    	}
    	cout << "\n";
    }
    return 0;
}
