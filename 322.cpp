#include<iostream>
#include<vector>

using namespace std;

/*
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。

*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        // 完全背包问题，不限制银币的数量
        // dp[i] 表示的是 最少的硬币数量 dp[i-coins[j]] 推出
        // 不用求排列 或者组合 遍历顺序 无所谓

        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;

        // 先遍历 物品 在遍历 背包

        for(int i = 0;i<coins.size();i++){
            for(int j = coins[i];j<=amount;j++){
                if(dp[j-coins[i]] != INT_MAX)
                    dp[j] = min(dp[j-coins[i]]+1,dp[j]);
            }
        }

        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
        
    }
};


int main(int argc, char const *argv[])
{
    vector<int> coins{2};
    int amount = 3;
    Solution sol;
    cout<<sol.coinChange(coins,amount)<<endl;
    system("pause");
    return 0;
}
