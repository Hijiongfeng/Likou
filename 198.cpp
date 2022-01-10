#include<iostream>
#include<vector>

using namespace std;

/*
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

*/

class Solution {
public:
    int rob(vector<int>& nums) {
        //dp[i]：考虑下标i（包括i）以内的房屋，最多可以偷窃的金额为dp[i]。
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        for(int i = 2;i<nums.size();i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);   // 要从 i-2和i-1 考虑
        }

        return dp[nums.size()-1];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{2,7,9,3,1};
    Solution sol;
    cout<<sol.rob(nums)<<endl;
    system("pause");
    return 0;
}
