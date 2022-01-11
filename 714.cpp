#include<iostream>
#include<vector>

using namespace std;
/*
给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int result = 0;
        int minPrice = prices[0];
        for(int i = 0;i<prices.size();i++){
            if(prices[i] < minPrice){   // 遍历到最小值 比当前的最小值 小 
                minPrice = prices[i];
            }
            if(prices[i] >= minPrice && prices[i] <=minPrice+fee) continue;
            if(prices[i] > minPrice+fee){
                result += prices[i] - minPrice - fee;
                minPrice = prices[i] - fee; // 情况一，这一步很关键
            }
        }
        return result;
    }
};

class Solution2 {           // 动态规划 dp
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        if(len == 0) return 0;

        vector<vector<int>> dp(len,vector<int> (2,0));
        dp[0][0] = -prices[0];
        dp[0][1] = 1;

        for(int i = 1;i<len;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]-prices[i]);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]+prices[i]-fee);    // 卖出的时候 减去手续费就可
        }
        
        return dp[len-1][1];

    }
};

int main(int argc, char const *argv[])
{
    vector<int> price{1,3,2,8,10,4,9};
    int fee = 2;
    Solution2 sol;
    cout<<sol.maxProfit(price,fee)<<endl;
    system("pause");
    return 0;
}
