#include<iostream>
#include<vector>

using namespace std;

/*
给定一个数组 prices ，其中 prices[i] 是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {    // 贪心算法，只要上升就买  就能获得最大的利润
        int count = 0;
        for(int i = 0;i<prices.size()-1;i++){
            if(prices[i+1]-prices[i] >=0){
                count+=(prices[i+1]-prices[i]);
            }
        }
        return count;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {    // 动态规划  dp  可以买卖多次
        int len = prices.size();
        if(len == 0)  return 0;
        vector<vector<int>> dp(len,vector<int> (2,0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for(int i = 1;i<len;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]-prices[i]);        // 持有股票 与上一个题的唯一区别是可以买卖多次，没有股票可以从前一个状态推出
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]+prices[i]);        // 不持有股票  不持有股票 与上一题一致
        }

        return dp[len-1][1];

    }
};

int main(int argc, char const *argv[])
{   vector<int> nums{7,1,5,3,6,4};
    Solution2 sol;
    cout<<sol.maxProfit(nums)<<endl;
    system("pause");
    return 0;
}
