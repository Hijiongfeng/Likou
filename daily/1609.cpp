#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
如果一棵二叉树满足下述几个条件，则可以称为 奇偶树 ：

二叉树根节点所在层下标为 0 ，根的子节点所在层下标为 1 ，根的孙节点所在层下标为 2 ，依此类推。
偶数下标 层上的所有节点的值都是 奇 整数，从左到右按顺序 严格递增
奇数下标 层上的所有节点的值都是 偶 整数，从左到右按顺序 严格递减
给你二叉树的根节点，如果二叉树为 奇偶树 ，则返回 true ，否则返回 false 。
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
    vector<TreeNode*> vecTree; // 构造二叉树节点数组
    TreeNode *root = nullptr;
    for(int i = 0;i<vec.size();i++){
        TreeNode *node = nullptr;
        if(vec[i] != -1){
            node = new TreeNode(vec[i]);
        }
        vecTree.push_back(node);
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
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root == nullptr) return false;
        queue<TreeNode*> que;
        que.push(root);
        int level = 0;
        while(!que.empty()){
            int size = que.size();
            int pre = level % 2 == 0 ? -1 : INT_MAX;  // 根据层数 确定 前一个节点的初始值，保证每层第一个节点是符合题意的，再看后面的节点
            for(int j = 0;j<size;j++){
                TreeNode *node = que.front();que.pop();
                if(level % 2 == 0){                 // 偶数层
                    if(node->val % 2 == 0 || node->val - pre <= 0)  // 如果出现 偶数，或者出现递减，则返回false
                        return false;
                    pre = node->val;
                }else{                              // 奇数层
                    if(node->val % 2 == 1 || node->val - pre >= 0)
                        return false;
                    pre = node->val;
                }

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            level++;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {5,4,2,3,3,7};
    TreeNode *root = construct_binary_tree(nums);
    Solution sol;
    cout<<sol.isEvenOddTree(root)<<endl;
    system("pause");
    return 0;
}
