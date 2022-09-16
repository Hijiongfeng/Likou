#include<bits/stdc++.h>

using namespace std;

/*
假如有一排房子，共 n 个，每个房子可以被粉刷成红色、蓝色或者绿色这三种颜色中的一种，
你需要粉刷所有的房子并且使其相邻的两个房子颜色不能相同。

当然，因为市场上不同颜色油漆的价格不同，所以房子粉刷成不同颜色的花费成本也是不同的。
每个房子粉刷成不同颜色的花费是以一个 n x 3 的正整数矩阵 costs 来表示的。

例如，costs[0][0] 表示第 0 号房子粉刷成红色的成本花费；
costs[1][2] 表示第 1 号房子粉刷成绿色的花费，以此类推。

请计算出粉刷完所有房子最少的花费成本。
*/
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n,vector<int>(3,0));
        for(int j = 0;j<costs[0].size();j++){
            dp[0][j] = costs[0][j];
        }

        for(int i = 1;i<n;i++){
            dp[i][0] = min(dp[i-1][1] ,dp[i-1][2]) + costs[i][0];
            dp[i][1] = min(dp[i-1][0] ,dp[i-1][2]) + costs[i][1];
            dp[i][2] = min(dp[i-1][0] ,dp[i-1][1]) + costs[i][2];
        }

        return min({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> cost =  {{17,2,17},{16,16,5},{14,3,19}};
    Solution sol;
    cout<<sol.minCost(cost)<<endl;
    system("pause");
    return 0;
}
