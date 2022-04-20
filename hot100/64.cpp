#include<bits/stdc++.h>

using namespace std;

/*
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例 1：

输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
输出：7
解释：因为路径 1→3→1→1→1 的总和最小。

动态规划
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n));
        int sum = 0;
        for(int j = 0;j<n;j++){             // 初始化 dp
            sum += grid[0][j];
            dp[0][j] = sum;
        }
        sum = 0;
        for(int i = 0;i<m;i++){
            sum += grid[i][0];
            dp[i][0] = sum;
        }

        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){         // 取最小的
                dp[i][j] = min(dp[i][j-1] + grid[i][j] ,dp[i-1][j] + grid[i][j]);
            }
        }
        return dp[m-1][n-1];
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> grids = {{1,3,1},{1,5,1},{4,2,1}};
    Solution sol;
    cout<<sol.minPathSum(grids)<<endl;
    system("pause");
    return 0;
}
