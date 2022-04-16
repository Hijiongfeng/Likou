#include<bits/stdc++.h>

using namespace std;

/*
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。

示例 1：

输入：nums = [1,1,1], k = 2
输出：2

子数组是连续的，子序列可以不是连续的
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {   // 前缀和
        unordered_map<int,int> mp;
        int ans = 0;
        int pre = 0;
        mp[0] = 1;
        for(int i = 0;i<nums.size();i++){
            pre += nums[i];
            if(mp.find(pre-k) != mp.end()){
                ans += mp[pre-k];
            }
            mp[pre]++;
        }
        return ans;
    }

    int subarraySum2(vector<int>& nums, int k) {   // 暴力 枚举
        int count = 0;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            int sum = 0;
            for(int j = i;j<nums.size();j++){
                sum += nums[j];
                if(sum == k){
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,1,1,};
    int k = 2;
    Solution sol;
    cout<<sol.subarraySum2(nums,k)<<endl;
    system("pause");
    return 0;
}
