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
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。

高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。
*/

class Solution {
private:
    TreeNode* traversal(vector<int>& nums){
        if(nums.size() == 0) return nullptr;
        int mid = nums.size()/2;
        TreeNode *root = new TreeNode(nums[mid]);

        vector<int> leftNums(nums.begin(),nums.begin()+mid);    //每次创建 一个新的 数组
        vector<int> rightNums(nums.begin()+mid+1,nums.end());

        root->left = traversal(leftNums);
        root->right = traversal(rightNums);
        return root;
    }

public:
    // 迭代算法比较麻烦 暂不考虑

    TreeNode* sortedArrayToBST(vector<int>& nums) {    // 迭代 算法，仿照 中序后序 确定二叉树写的
        if(nums.size() == 0) return nullptr;
        if(nums.size() == 1) return new TreeNode(nums[0]);
        TreeNode *root = traversal(nums);
        return root;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num = {-10,-3,0,5,9};
    Solution sol;
    TreeNode *root = sol.sortedArrayToBST(num);
    system("pause");
    return 0;
}
