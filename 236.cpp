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
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

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

// 根据num的值，在 树中 找到对应的节点
// 如果直接生成 节点，对应的 地址 不一样，这样不对
// 先根据值，找到对应的节点，可以
TreeNode* findNode(TreeNode* root,int num){
    if(root == nullptr) return nullptr;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        int size = que.size();
        for(int i= 0;i<size;i++){
            TreeNode *node = que.front();
            que.pop();
            if(node->val == num) return node;
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
    }
    return nullptr;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == q || root == p || root == NULL) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL) return root;

        if (left == NULL && right != NULL) return right;
        else if (left != NULL && right == NULL) return left;
        else  { //  (left == NULL && right == NULL)
            return NULL;
        }
    }
};


int main(int argc, const char** argv) {
    vector<int> num = {8,10,4,1,7,15,20,-1,-1,6,5,-1,-1,-1,-1};
    TreeNode *root = construct_binary_tree(num);
    TreeNode *node1 = findNode(root,6);
    TreeNode *node2 = findNode(root,5);
    Solution sol;
    TreeNode *fin = sol.lowestCommonAncestor(root,node1,node2);
    system("pause");
    return 0;
}