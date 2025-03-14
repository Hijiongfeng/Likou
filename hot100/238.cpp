#include<bits/stdc++.h>

using namespace std;

/*
给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。

题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

请不要使用除法，且在 O(n) 时间复杂度内完成此题。

示例 1:

输入: nums = [1,2,3,4]
输出: [24,12,8,6]

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1,suffix = 1;
        vector<int> pre(nums.size());   // 前后乘积列表
        vector<int> suf(nums.size());
        for(int i = 0;i<nums.size();i++){
            prefix *= nums[i];
            pre[i] = prefix;
        }
        for(int i = nums.size() -1;i>=0;i--){
            suffix *= nums[i];
            suf[i] = suffix;
        }
        vector<int> ans(nums.size());
        for(int i = 0;i<nums.size();i++){       // 每个索引处的答案等于 这个数的左右乘积
            if(i == 0){
                ans[i] = suf[i+1];
            }else if(i == nums.size() -1){
                ans[i] = pre[i-1];
            }else{
                ans[i] = pre[i-1] * suf[i+1];
            }
        }
        return ans;
    }

    vector<int> productExceptSelf2(vector<int>& nums){
        int prefix = 1,suffix = 1;
        vector<int> pre(nums.size());
        vector<int> suf(nums.size());
        for(int i = 0;i<nums.size();i++){
            prefix *= nums[i];
            pre[i] = prefix;
        }
        for(int i = nums.size() -1;i>=0;i--){
            suffix *= nums[i];
            suf[i] = suffix;
        }
        vector<int> ans(nums.size());
        for(int i = 0;i<nums.size();i++){
            if(i == 0){
                ans[i] = suf[i+1];
            }else if(i == nums.size() -1){
                ans[i] = pre[i-1];
            }else{
                ans[i] = pre[i-1] * suf[i+1];
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {-1,1,0,-3,3};
    Solution sol;
    vector<int> vec = sol.productExceptSelf2(nums);
    for(int a : vec){
        cout<<a<<endl;
    }
    system("pause");
    return 0;
}
