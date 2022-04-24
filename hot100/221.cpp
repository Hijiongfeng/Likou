#include<bits/stdc++.h>

using namespace std;

/*
在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
*/
/*

那么如何计算dp 中的每个元素值呢？对于每个位置 (i,j)，检查在矩阵中该位置的值：

如果该位置的值是 0，则 dp(i,j)=0，因为当前位置不可能在由 1组成的正方形中；

如果该位置的值是 1，则 dp(i,j) 的值由其上方、左方和左上方的三个相邻位置的 dp 值决定。
具体而言，当前位置的元素值等于三个相邻位置的元素中的最小值加 11，状态转移方程如下：

dp(i, j)=min(dp(i−1, j), dp(i−1, j−1), dp(i, j−1))+1

*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 && matrix[0].size() == 0){
            return 0;
        }
        int maxSide = 0;
        int m = matrix.size(),n = matrix[0].size();

        vector<vector<int>> dp(m,vector<int> (n));

        for(int j = 0;j<n;j++){
            if(matrix[0][j] == '1'){
                dp[0][j] = 1;
                maxSide = 1;
            }
        }

        for(int i = 0;i<m;i++){
            if(matrix[i][0] == '1'){
                dp[i][0] = 1;
                maxSide = 1;
            }
        }

        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
                }
                maxSide = max(maxSide,dp[i][j]);
            }
        }

        return maxSide * maxSide;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> matrix = {{'1','0','1','0','0'},
                                   {'1','0','1','1','1'},
                                   {'1','1','1','1','1'},
                                   {'1','0','0','1','0'}};
    Solution sol;
    cout<<sol.maximalSquare(matrix)<<endl;

    system("pause");
    return 0;
}
