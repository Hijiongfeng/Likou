#include<iostream>
#include<vector>

using namespace std;

/*
给你二叉树的根节点 root 和一个整数目标和 targetSum ，
找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。

*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
  
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(TreeNode *cur,int target,int sum){
        if(cur->left == nullptr && cur->right == nullptr && sum == target){
            ans.push_back(path);
            return;
        }

        if(cur->left == nullptr && cur->right == nullptr){
            return;
        }

        if(cur->left){
            path.push_back(cur->left->val);
            sum += cur->left->val;
            backtracking(cur->left,target,sum);
            sum -= cur->left->val;
            path.pop_back();
        }

        if(cur->right){
            path.push_back(cur->right->val);
            sum += cur->right->val;
            backtracking(cur->right,target,sum);
            sum -= cur->right->val;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(root == nullptr) return {};
        path.push_back(root->val);
        backtracking(root,target,root->val);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
