#include<iostream>
#include<vector>

using namespace std;

/*
改为：一步一个台阶，两个台阶，三个台阶，.......，直到 m个台阶。问有多少种不同的方法可以爬到楼顶呢？

1阶，2阶，.... m阶就是物品，楼顶就是背包。

每一阶可以重复使用，例如跳了1阶，还可以继续跳1阶。

问跳到楼顶有几种方法其实就是问装满背包有几种方法。

此时大家应该发现这就是一个完全背包问题了！
**/

class Solution {
public:
    int climbStairs(int m,int n) {
        // m是物品，n是背包
        vector<int> dp(n+1,0);
        dp[0] = 1;

        // 求排列 1,2；2,1不是一种情况
        for(int j = 0;j<=n;j++){
            for(int i = 0;i<=m;i++){
                if(j>=i) dp[j] += dp[j-i];
            }
        }
        return dp[n];
    }
};

int main(int argc, char const *argv[])
{
    int m = 2;
    int n = 2;
    Solution sol;
    cout<<sol.climbStairs(m,n)<<endl;
    system("pause");
    return 0;
}
