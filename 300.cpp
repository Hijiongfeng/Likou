#include<iostream>
#include<vector>

using namespace std;

/*
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

*/

class Solution {        //  动态规划  dp[i] 代表i之前 包括 i 最长上升子序列的长度
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <=1 ) return nums.size();
        vector<int> dp(nums.size(),1);

        int result = 0;
        for(int i = 1;i<nums.size();i++){
            for(int j = 0;j < i;j++){  //位置i的最长升序子序列等于j从0到i-1各个位置的最长升序子序列 + 1 的最大值。
                if(nums[i] > nums[j]) dp[i] = max(dp[i],dp[j]+1);   //  比较的是 i 和 j 不强调连续
            }
            if(dp[i]>result) result  = dp[i];
        }
        return result;
    }
};

int main(int argc, const char** argv) {
    vector<int> nums{10,9,2,5,3,7,101,18};
    Solution sol;
    cout<<sol.lengthOfLIS(nums)<<endl;
    system("pause");
    return 0;
}