#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

/**
给你一个整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 */

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {      // 二维好理解一点
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(target > sum) return 0;
        if((sum+target)%2 == 1) return 0;
        int left = (sum+target)/2;
        if(left < 0) left = -left;          // 负数情况
        vector<vector<int>> dp(nums.size(),vector<int> (left+1,0));     // 填满j 有多少种方法

        dp[0][0] = 1;       // 填满 容量为0 的，有一种方法，那就是不填
        for(int j = 0;j<=left;j++){
            if(nums[0] == j) dp[0][j] += 1;         //  只有相等的时候，才有一种方法 能够填满
        }

       
        for(int i = 1;i<nums.size();i++){
            for(int j = 0;j<=left;j++){
                if(j < nums[i]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]];
            }
        }
        
        return dp[nums.size()-1][left];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num{100};
    int target =-200;
    Solution sol;
    cout<<sol.findTargetSumWays(num,target)<<endl;
    system("pause");
    return 0;
}
