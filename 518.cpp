#include<iostream>
#include<vector>

using namespace std;
/*
给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。

请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。

假设每一种面额的硬币有无限个。 

题目数据保证结果符合 32 位带符号整数。
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {        //  一维数组
        vector<int> dp(amount+1,0);
        dp[0] = 1;
        for(int i = 0;i<coins.size();i++){
            for(int j = coins[i];j<=amount;j++){
                dp[j] += dp[j-coins[i]];
            }
        } 
        return dp[amount];
    }
};

class Solution2 {
public:
    int change(int amount, vector<int>& coins) {        // 二维数组  不好做
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,0));
        dp[0][0] = 1;
        for(int j=0;j<=amount;j++){
            if(j >= coins[0]) dp[0][j] = 1;
        }

        for(int i = 1;i<coins.size();i++){
            for(int j = 0;j<=amount;j++){
                if(j < coins[i]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];     // 还要考虑本层的一个情况
            }
        }
        return dp[coins.size()-1][amount];
    }
};

int main(int argc, char const *argv[])
{
    int amount = 5;
    vector<int> coins{1,2,5};
    Solution sol;
    cout<<sol.change(amount,coins)<<endl;
    system("pause");
    return 0;
}
