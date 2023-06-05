#include <bits/stdc++.h>
using namespace std;
ifstream in;
ofstream out;
struct TreeNode {
    int value,l,r;
};
void traversal(int now){
    in.seekg(now);
    TreeNode node;
    in.read(reinterpret_cast<char*>(&node),sizeof(TreeNode));
    out << node.value << " ";
    if(node.l != -1){
        traversal(node.l);
    }
    if(node.r != -1){
        traversal(node.r);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    in.open("input.obj",ios::binary);
    out.open("output.txt");
    traversal(0);
    in.close();
    out.close();
    return 0;
}