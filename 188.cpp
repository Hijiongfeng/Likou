#include<iostream>
#include<vector>

using namespace std;

/*
给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

// 一天有 2k+1个 状态  奇数是买 偶数是卖
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if(len == 0) return 0;
        vector<vector<int>> dp(len,vector<int> (2*k+1,0));

        for(int j = 0;j<2*k+1;j++){         // 初始化
            if(j % 2 == 1) dp[0][j] = -prices[0];
        }

        for(int i = 1;i<len;i++){       // 奇数 是买入 ，，偶数是卖出
            for(int j = 0;j<2*k+1;j++){
                if(j == 0) dp[i][j] = dp[i-1][j];
                else if(j % 2 == 1) dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]-prices[i]);
                else dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]+prices[i]);
            }
        }
        return dp[len-1][2*k];
    }
};


int main(int argc, const char** argv) {
    vector<int> price{3,2,6,5,0,3};
    int k = 2;
    Solution sol;
    cout<<sol.maxProfit(k,price)<<endl;
    system("pause");
    return 0;
}