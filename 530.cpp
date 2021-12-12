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
给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。

差值是一个正数，其数值等于两值之差的绝对值。
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
private:
    vector<int> vec;
    void traversal(TreeNode *root){
        if(root == nullptr) return;
        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        if(root == nullptr) return 0;
        traversal(root);
        int min = INT_MAX;
        for(int i = 0;i<vec.size();i++){
            for(int j = 0;j<vec.size();j++){
                if(vec[i] != vec[j]){
                    min = min < (abs(vec[j]-vec[i])) ? min : abs(vec[j]-vec[i]);
                }
            }
        }
        return min;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num = {4,2,6,1,3,-1,-1};
    TreeNode *root = construct_binary_tree(num);
    Solution sol;
    cout<<sol.getMinimumDifference(root)<<endl;
    system("pause");
    return 0;
}
