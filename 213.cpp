#include<iostream>
#include<vector>

using namespace std;
/*
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。
同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。

*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        int result1 = robRange(nums,0,nums.size()-2);   // 两种情况， 取最大
        int result2 = robRange(nums,1,nums.size()-1);

        return max(result1,result2);

    }

    int robRange(vector<int>& nums,int start,int end){
        if(start == end) return nums[start];
        vector<int> dp(nums.size(),0);
        dp[start] = nums[start];
        dp[start+1] = max(nums[start],nums[start+1]);

        for(int i = start+2;i<=end;i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[end];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{1,2,3,4,5};
    Solution sol;
    cout<<sol.rob(nums)<<endl;
    system("pause");
    return 0;
}
