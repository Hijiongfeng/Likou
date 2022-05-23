#include<bits/stdc++.h>

using namespace std;

/*
给你一个二维整数数组 stockPrices ，其中 stockPrices[i] = [dayi, pricei] 
表示股票在 dayi 的价格为 pricei 。折线图 是一个二维平面上的若干个点组成的图，
横坐标表示日期，纵坐标表示价格，折线图由相邻的点连接而成。比方说下图是一个例子：

请你返回要表示一个折线图所需要的 最少线段数 。
*/
class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        sort(stockPrices.begin(),stockPrices.end());
        int ans = 0;
        // int diffPreY = INT_MAX;
        // int diffPreX = INT_MAX;
        long double preK = -1111111.0;
        for(int i = 1;i<stockPrices.size();i++){
            long double diffCurY = (double)stockPrices[i][1] - (double)stockPrices[i-1][1];
            long double diffCurX = (double)stockPrices[i][0] - (double)stockPrices[i-1][0];
            long double curK = diffCurY / diffCurX;
            if(curK != preK){
                ++ans;
            }
            // diffPreY = diffCurY;
            // diffPreX = diffCurX;
            preK = curK;
        }
        return ans;
    }
    int minimumLines2(vector<vector<int>>& stockPrices) {
        sort(stockPrices.begin(),stockPrices.end());            //排序
        int ans = 0;
        if(stockPrices.size() == 1){
            return 0;
        }
        long long diffPreY = stockPrices[1][1] - stockPrices[0][1];
        long long diffPreX = stockPrices[1][0] - stockPrices[0][0];

        if(stockPrices.size() == 2){
            return 1;
        }

        for(int i = 2;i<stockPrices.size();i++){                    // 斜率比较 
            int diffCurY = stockPrices[i][1] - stockPrices[i-1][1];
            int diffCurX = stockPrices[i][0] - stockPrices[i-1][0];
            if(i == 2){
                if(diffCurX * diffPreY == diffCurY * diffPreX){
                    ans++;
                }else{
                    ans += 2;
                }
            }else{
                if(diffCurX * diffPreY != diffCurY * diffPreX)
                    ans++;
            }

            diffPreY = diffCurY;
            diffPreX = diffCurX;

        }
        return ans;
    }

};

int main(int argc, char const *argv[])
{
    // vector<vector<int>> stockPrices = {{83,35},{79,51},{61,48},{54,87},{44,93},{22,5},{87,28},{64,8},
    //                                    {89,78},{62,83},{58,72},{48,7},{97,16},{27,100},{65,48},{11,31},
    //                                    {29,76},{93,29},{72,59},{73,74},{9,90},{66,81},{12,8},{86,80},{84,43},
    //                                    {36,63},{80,45},{81,88},{95,5},{40,59}};
    vector<vector<int>> stockPrices = {{1,1},{500000000,499999999},{1000000000,999999998}};
    Solution sol;
    cout<<sol.minimumLines(stockPrices)<<endl;
    system("pause");
    return 0;
}
