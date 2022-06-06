#include<bits/stdc++.h>

using namespace std;

/*
给你一棵二叉搜索树的 root ，请你 按中序遍历 将其重新排列为一棵递增顺序搜索树，
使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* construct_binary_tree(const vector<int>& vec){
    vector<TreeNode*> vecTree(vec.size(),nullptr); // 构造二叉树节点数组
    TreeNode *root = nullptr;
    for(int i = 0;i<vec.size();i++){
        TreeNode *node = nullptr;
        if(vec[i] != -1){
            node = new TreeNode(vec[i]);
        }
        vecTree[i] = node;
        if(i == 0) root = node;
    }
    
    for(int i = 0;2 * i + 2 < vec.size();i++){
        if(vecTree[i] != nullptr){
            vecTree[i]->left = vecTree[2*i+1];  //找左右子树
            vecTree[i]->right = vecTree[2*i+2];
        }
    }
    return root;
}


class Solution {
    void inOrder(TreeNode* root,vector<int>& num){
        if(root == nullptr){
            return;
        }
        inOrder(root->left,num);
        num.push_back(root->val);
        inOrder(root->right,num);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(root ==  nullptr) return nullptr;
        vector<int> num;
        inOrder(root,num);
        TreeNode* newRoot = new TreeNode(num[0]);
        TreeNode* temp = newRoot;
        for(int i = 1;i<num.size();i++){
            temp->right = new TreeNode(num[i]);
            temp = temp->right;
        }
        return newRoot;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vec  = {5,7,1};
    TreeNode* root = construct_binary_tree(vec);
    Solution sol;
    TreeNode* newRoot = sol.increasingBST(root);
    system("pause");
    return 0;
}
