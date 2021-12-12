#include<iostream>
#include<vector>
#include<queue>
#include<stack>

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
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
*/

TreeNode* construct_binary_tree(const vector<int> & vec){
    vector<TreeNode*> vecTree;
    TreeNode *root = nullptr;
    for(int i = 0;i<vec.size();i++){
        TreeNode *node = nullptr;
        if(vec[i] != -1){
            node = new TreeNode(vec[i]);
        }
        vecTree.push_back(node);       
        if(i == 0) root = node;
    }

    for(int i=0;2*i+2<vec.size();i++){
        if(vecTree[i] != nullptr){
            vecTree[i]->left = vecTree[2*i+1];
            vecTree[i]->right = vecTree[2*i+2];
        }
    }
    return root;
}
class Solution {
public:

    int getHeight(TreeNode *root){
        if(root == nullptr) return 0;
        int leftHeight = getHeight(root->left);
        if(leftHeight == -1) return -1;
        int rightHeight = getHeight(root->right);
        if(rightHeight == -1) return -1;
        if(abs(leftHeight - rightHeight)>1){
            return -1;
        }else{
            return 1+max(leftHeight,rightHeight);
        }
    }

    bool isBalanced(TreeNode* root) {   // 递归算法  求出左右 子树的高度 ，判断是否是平衡二叉树
        return getHeight(root) == -1? false: true; 
    }

    // 迭代算法  要定义一个函数用来求 二叉树的高度  层序遍历 可以  真正求二叉树的高度 应该用后序遍历
    int getHeight2(TreeNode *root){
        if(root == nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int res = 0;
        while(!que.empty()){
            int size = que.size();
            res++;
            for(int i = 0;i<size;i++){
                TreeNode *node = que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return res;
    }

    bool isBalanced2(TreeNode* root) {   // 
        if(root == nullptr) return true;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode *node = st.top();
            st.pop();
            if(abs(getHeight2(node->left) - getHeight2(node->right)) > 1){
                return false;
            }
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        return true;
    }

};
int main(int argc, const char** argv) {
    vector<int> num = {3,9,20,-1,-1,15,7};
    TreeNode *root = construct_binary_tree(num);
    Solution sol;
    cout<<sol.isBalanced2(root)<<endl;
    
    system("pause");
    return 0;
}