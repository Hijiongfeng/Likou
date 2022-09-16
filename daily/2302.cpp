#include<bits/stdc++.h>

using namespace std;

/*
一个数字的 分数 定义为数组之和 乘以 数组的长度。

比方说，[1, 2, 3, 4, 5] 的分数为 (1 + 2 + 3 + 4 + 5) * 5 = 75 。
给你一个正整数数组 nums 和一个整数 k ，请你返回 nums 中分数 严格小于 k 的 非空整数子数组数目。

子数组 是数组中的一个连续元素序列。
*/
/*
只要找到满足条件的左右索引，那么他内部的所有子数组都满足条件
right - left + 1; 就等于区间长度
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        long long sum = 0;
        for(int left = 0,right = 0;right < nums.size();++right){
            sum += nums[right];
            while(sum * (right - left + 1) >= k){
                sum -= nums[left];
                left++;
            }
            ans += (right - left + 1);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {2,1,4,3,5};
    long long k = 10;
    Solution sol;
    cout<<sol.countSubarrays(nums,k)<<endl;
    system("pause");
    return 0;
}
