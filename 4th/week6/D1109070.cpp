#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int value;
    int leftOffset;
    int rightOffset;
};
ifstream input;
ofstream output;
void preorderTraversal(int now){
    input.seekg(now);
    TreeNode node;
    input.read(reinterpret_cast<char*>(&node),sizeof(TreeNode));
    output << node.value << " ";
    if(node.leftOffset != -1){
        preorderTraversal(node.leftOffset);
    }
    if(node.rightOffset != -1){
        preorderTraversal(node.rightOffset);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input.open("input.obj",ios::binary);
    output.open("output.txt");
    preorderTraversal(0);
    input.close();
    output.close();
    return 0;
}