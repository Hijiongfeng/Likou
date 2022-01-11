#include<iostream>
#include<vector>

using namespace std;
/*
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {        // 贪心算法，找到左最小值，右最大值
        int low = INT_MAX;
        int result = 0;
        for(int i = 0;i<prices.size();i++){
            low = min(low,prices[i]);
            result = max(result,prices[i]-low);
        }
        return result;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {        // 动态规划 dp

        int len = prices.size();
        vector<vector<int>> dp(len,vector<int> (2,0));

        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for(int i = 1;i<len;i++){
            dp[i][0] = max(dp[i-1][0],-prices[i]);          //  持有股票
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]+prices[i]);    //  不持有股票
            cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
        }

        return dp[len-1][1];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> prices{7,1,5,3,6,4};
    Solution2 sol;
    cout<<sol.maxProfit(prices)<<endl;
    system("pause");
    return 0;
}
