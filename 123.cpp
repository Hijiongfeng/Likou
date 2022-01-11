#include<iostream>
#include<vector>

using namespace std;

/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {    // 每一天都有五种 状态 0,1,2,3,4；
        int len = prices.size();

        vector<vector<int>> dp(len,vector<int> (5,0));

        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];

        for(int i = 1;i<len;i++){
            dp[i][0] = dp[i-1][0];                                 // 没有操作
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i]);       // 第一次买入
            dp[i][2] = max(dp[i-1][2],dp[i-1][1]+prices[i]);        // 卖出
            dp[i][3] = max(dp[i-1][3],dp[i-1][2]-prices[i]);        // 买入
            dp[i][4] = max(dp[i-1][4],dp[i-1][3]+prices[i]);        // 卖出
        }
        return dp[len-1][4];

    }
};

int main(int argc, const char** argv) {
    vector<int> price{1,2,3,4,5};
    Solution sol;
    cout<<sol.maxProfit(price)<<endl;
    system("pause");
    return 0;
}