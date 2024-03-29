#include<iostream>
#include<vector>

using namespace std;

/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

*/
class Solution {
public:
    int numWays(int n) {
        if(n == 0 ) return 1;
        if(n == 1 || n == 2){
            return n;
        }
        vector<int> dp(2);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 3;i<=n;i++){
            int c = dp[0] + dp[1];
            c %= 1000000007;
            dp[0] = dp[1];
            dp[1] = c;
        }
        return dp[1];

    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    cout<<sol.numWays(7)<<endl;
    system("pause");
    return 0;
}
