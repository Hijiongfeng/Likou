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

int main(int argc, char const *argv[])
{   vector<int> nums{7,1,5,3,6,4};
    Solution sol;
    cout<<sol.maxProfit(nums)<<endl;
    system("pause");
    return 0;
}
