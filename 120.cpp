#include<bits/stdc++.h>

using namespace std;

/*
给定一个三角形 triangle ，找出自顶向下的最小路径和。

每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 
下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。

示例 1：

输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
输出：11
解释：如下面简图所示：
   2
  3 4
 6 5 7
4 1 8 3
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {           // 动态规划
        if(triangle.size() == 1){
            return triangle[0][0];
        }
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n));   // 采用了一个n*n 大小的矩阵；还可以对空间进行优化
        dp[0][0] = triangle[0][0];
        for(int i = 1;i<triangle.size();i++){
            dp[i][0] = dp[i-1][0] + triangle[i][0];             // 最左边
            for(int j = 1;j<i;j++){
                dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]) + triangle[i][j];   // 中间
            }
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];           // 最右边
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }


    int minimumTotal2(vector<vector<int>>& triangle) {           // 动态规划
        if(triangle.size() == 1){
            return triangle[0][0];
        }
        int n = triangle.size();
        vector<vector<int>> dp(2,vector<int>(n));   // 采用了一个2*n 大小的矩阵；根据奇数偶数进行转移
        dp[0][0] = triangle[0][0];
        for(int i = 1;i<n;i++){
            int cur = i % 2;
            int pre = 1 - cur;
            dp[cur][0] = dp[pre][0] + triangle[i][0];
            for(int j = 1;j<i;j++){
                dp[cur][j] = min(dp[pre][j-1],dp[pre][j]) + triangle[i][j];
            }
            dp[cur][i] = dp[pre][i-1] + triangle[i][i];
        }
        return *min_element(dp[(n-1) % 2].begin(),dp[(n-1) % 2].end());
    }


};

int main(int argc, char const *argv[])
{
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    Solution sol;
    cout<<sol.minimumTotal2(triangle)<<endl;
    system("pause");
    return 0;
}
