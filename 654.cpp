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
给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 定义如下：

二叉树的根是数组 nums 中的最大元素。
左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。
右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。
返回有给定数组 nums 构建的 最大二叉树 。

*/
class Solution {
private:
    int findMax(vector<int> nums){
        int max = nums[0];
        for(int x:nums){
            if(max<x){
                max = x;
            }
        }
        return max;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;

        int rootValue = findMax(nums);  // 找到最大值
        TreeNode *root = new TreeNode(rootValue);
        if(nums.size() == 1) return root;

        //找到 最大值的索引  确定分割点 在哪边
        int deminateIndex;
        for(deminateIndex = 0;deminateIndex<nums.size();deminateIndex++){
            if(nums[deminateIndex] == rootValue) break;
        }

        //  分割左右

        vector<int> leftNums(nums.begin(),nums.begin()+deminateIndex);
        vector<int> rightNums(nums.begin()+deminateIndex+1,nums.end());

        root->left = constructMaximumBinaryTree(leftNums);
        root->right = constructMaximumBinaryTree(rightNums);
        return root;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {3,2,1,6,0,5};
    Solution sol;
    TreeNode *root = sol.constructMaximumBinaryTree(nums);
    system("pause");
    return 0;
}
