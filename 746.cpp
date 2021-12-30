#include<iostream>
#include<vector>

using namespace std;

/*
给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。

你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。

请你计算并返回达到楼梯顶部的最低花费。
输入：cost = [10,15,20]
输出：15
解释：你将从下标为 1 的台阶开始。
- 支付 15 ，向上爬两个台阶，到达楼梯顶部。
总花费为 15 。
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1);      // 这种解法，第一步不用花费 ，直接站上去。符合逻辑
        dp[0] = 0;                          // 向上跳 要花费该层的 cost ，
        dp[1] = 0;
        for(int i = 2;i<=cost.size();i++){
            int cost1 = dp[i-1]+cost[i-1];
            int cost2 = dp[i-2]+cost[i-2];
            dp[i] = min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[cost.size()];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> cost{10,15,20};
    Solution sol;
    cout<<sol.minCostClimbingStairs(cost)<<endl;
    system("pause");
    return 0;
}
