#include<iostream>
#include<vector>

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
给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。

注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 任意有效的结果 。
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

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {  // 迭代算法
        if(root == nullptr) return new TreeNode(val);
        TreeNode *cur = root;
        TreeNode *parent = root;
        while(cur != nullptr){
            parent = cur;
            if(cur->val > val) cur = cur->left;
            else cur = cur->right;
        }
        TreeNode *node = new TreeNode(val);
        if(val < parent->val) parent->left = node;
        else parent->right = node;

        return root;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {  // 递归版本 算法
        
    }
};


int main(int argc, char const *argv[])
{
    vector<int> num = {4,2,7,1,3,-1,-1};
    TreeNode *root = construct_binary_tree(num);
    Solution  sol;
    TreeNode *newroot = sol.insertIntoBST(root,5);

    system("pause");
    return 0;
}

