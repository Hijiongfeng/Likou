#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

/*
442. 数组中重复的数据
给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围 [1, n] 内，
且每个整数出现 一次 或 两次 。请你找出所有出现 两次 的整数，并以数组形式返回。

你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间的算法解决此问题。
示例 1：

输入：nums = [4,3,2,7,8,2,3,1]
输出：[2,3]
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> num_mp;
        for(int a : nums){
            num_mp[a]++;
            if(num_mp[a] == 2){
                ans.emplace_back(a);
            }
        }
        return ans;
    }

    vector<int> findDuplicates2(vector<int>& nums) {        // 原地哈希
        vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            while(nums[i] != nums[nums[i] - 1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i = 0;i<nums.size();i++){
            if(i != nums[i]-1){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }

/*
当前数字的下标应该是x-1，判断x-1是否为正，如果为正，就变为负数，表示已经使用过当前数字
如果再次遇见负数，就表示当前数字已经出现两次，
这里我们需要去当前数字的绝对值，去找下标。
*/
    vector<int> findDuplicates3(vector<int>& nums) {        // 使用正负号进行标记
        vector<int> ans;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int x = abs(nums[i]);
            if(nums[x-1] > 0){
                nums[x-1] = -nums[x-1];
            }else{
                ans.push_back(x);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    Solution sol;
    vector<int> vec = sol.findDuplicates3(nums);
    system("pause");
    return 0;
}
