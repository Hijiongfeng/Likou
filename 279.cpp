#include<iostream>
#include<vector>

using namespace std;

/*
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

给你一个整数 n ，返回和为 n 的完全平方数的 最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;

        for(int j = 0;j<=n;j++){
            for(int i = 1;i * i<=j;i++){
                dp[j] = min(dp[j],dp[j-i*i]+1);
            }
        }
        return dp[n];

    }
};

int main(int argc, char const *argv[])
{
    int n = 12;
    Solution sol;
    cout<<sol.numSquares(n)<<endl;

    system  ("pause");
    return 0;
}
