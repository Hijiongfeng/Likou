#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 
返回以该节点为根的子树。 如果节点不存在，则返回 NULL。

例如，

给定二叉搜索树:

        4
       / \
      2   7
     / \
    1   3

和值: 2
你应该返回如下子树:

      2     
     / \   
    1   3

*/

TreeNode* construct_binary_tree(const vector<int>& vec){
    vector<TreeNode*> vecTree;
    TreeNode *root = nullptr;
    for(int i=0;i<vec.size();i++){
        TreeNode *node = nullptr;
        if(vec[i] != -1){
            node = new TreeNode(vec[i]);
        }
        vecTree.push_back(node);
        if(i == 0) root = node;
    }

    for(int i =0;2*i+2<vec.size();i++){
        if(vecTree[i] != nullptr){
            vecTree[i]->left = vecTree[2*i+1];
            vecTree[i]->right = vecTree[2*i+2];
        }
    }
    return root;
}
// 明白   二叉搜索树 的 概念
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {  //迭代算法
        if(root == nullptr) return nullptr;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode *node = que.front();
            que.pop();
            if(node->val == val) return node;
            if(node->val > val && node->left != nullptr) que.push(node->left);
            if(node->val < val && node->right != nullptr) que.push(node->right);
        }
        return nullptr;
    }

    TreeNode* searchBST2(TreeNode* root, int val) {  // 递归算法  递归 太难了
        if(root == nullptr || root->val == val) return root;

        if(root->val > val) return searchBST2(root->left,val);
        if(root->val < val) return searchBST2(root->right,val);
        return nullptr;
    }
};

int main(int argc, const char** argv) {
    vector<int> num = {4,2,7,1,3,-1,-1};
    TreeNode *root = construct_binary_tree(num);
    Solution sol;
    TreeNode *node2 = sol.searchBST2(root,5);
    system("pause");
    return 0;
}