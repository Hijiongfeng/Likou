#include<iostream>
#include<vector>

using namespace std;

/*
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
*/
class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1){
            return n;
        }
        vector<int> dp(2);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2;i<=n;i++){
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
    system("pause");
    return 0;
}
