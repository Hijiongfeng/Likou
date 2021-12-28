#include<iostream>
#include<vector>

using namespace std;

/*
给定一个二叉树，我们在树的节点上安装摄像头。

节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。

计算监控树的所有节点所需的最小摄像头数量。
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* construct_binary_tree(const vector<int>& vec){
    if(vec.size() == 0) return nullptr;
    vector<TreeNode*> vecNode(vec.size(),nullptr);
    TreeNode *root = nullptr;
    for(int i = 0;i<vec.size();i++){
        TreeNode *node = nullptr;
        if(vec[i] != -1){
            node = new TreeNode(vec[i]);
        }
        vecNode[i] = node;   // 用索引查找
        if(i == 0) root = node;
    }
    for(int i = 0;2*i+2<vec.size();i++){
        if(vecNode[i]!=nullptr){
            vecNode[i]->left = vecNode[2*i+1];
            vecNode[i]->right = vecNode[2*i+2];
        }  
    }
}

class Solution {
public:
    int minCameraCover(TreeNode* root) {

    }
};

int main(int argc, char const *argv[])
{
    vector<int> vec{0,0,-1,0,0};
    TreeNode *root = construct_binary_tree(vec);
    int a= 0;
    system("pause");
    return 0;
}
