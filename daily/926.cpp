#include<bits/stdc++.h>

using namespace std;

/*
如果一个二进制字符串，是以一些 0（可能没有 0）后面跟着一些 1（也可能没有 1）的形式组成的，
那么该字符串是 单调递增 的。

给你一个二进制字符串 s，你可以将任何 0 翻转为 1 或者将 1 翻转为 0 。

返回使 s 单调递增的最小翻转次数。

示例 1：

输入：s = "00110"
输出：1
解释：翻转最后一位得到 00111.
*/
/*
假设字符串 s 的长度是 n，对于 0≤i<n，用 dp[i][0] 和dp[i][1] 分别表示下标 i 处的字符为 0 
和 1 的情况下使得 s[0..i] 单调递增的最小翻转次数。

当 i = 0i=0 时，对应长度为 11 的前缀，一定满足单调递增，因此 \textit{dp}[0][0]dp[0][0] 和 \textit{dp}[0][1]dp[0][1] 的值取决于字符 s[i]s[i]。具体而言，\textit{dp}[0][0] = \mathbb{I}(s[0] = \text{`1'})dp[0][0]=I(s[0]=‘1’)，\textit{dp}[0][1] = \mathbb{I}(s[0] = \text{`0'})dp[0][1]=I(s[0]=‘0’)，其中 \mathbb{I}I 为示性函数，当事件成立时示性函数值为 11，当事件不成立时示性函数值为 00。

当 1 \le i < n1≤i<n 时，考虑下标 ii 处的字符。如果下标 ii 处的字符是 00，则只有当下标 i - 1i−1 处的字符是 00 时才符合单调递增；如果下标 ii 处的字符是 11，则下标 i - 1i−1 处的字符是 00 或 11 都符合单调递增，此时为了将翻转次数最小化，应分别考虑下标 i - 1i−1 处的字符是 00 和 11 的情况下需要的翻转次数，取两者的最小值。

在计算 \textit{dp}[i][0]dp[i][0] 和 \textit{dp}[i][1]dp[i][1] 时，还需要根据 s[i]s[i] 的值决定下标 ii 处的字符是否需要翻转，因此可以得到如下状态转移方程，其中 \mathbb{I}I 为示性函数：

\begin{aligned} \textit{dp}[i][0] &= \textit{dp}[i - 1][0] + \mathbb{I}(s[i] = \text{`1'}) \\ \textit{dp}[i][1] &= \min(\textit{dp}[i - 1][0], \textit{dp}[i - 1][1]) + \mathbb{I}(s[i] = \text{`0'}) \end{aligned}
dp[i][0]=dp[i−1][0]+I(s[i]=‘1’)
dp[i][1]=min(dp[i−1][0],dp[i−1][1])+I(s[i]=‘0’)
*/
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(2));
        dp[0][0] = s[0] == '1' ? 1 : 0;
        dp[0][1] = s[0] == '0' ? 1 : 0;
        if(n == 1){
            return min(dp[0][0],dp[0][1]);
        }
        for(int i = 1;i < n;i++){
            if(s[i] == '1'){
                dp[i][0] = dp[i-1][0] + 1;
                dp[i][1] = min(dp[i-1][0],dp[i-1][1]);
            }else if(s[i] == '0'){
                dp[i][0] = dp[i-1][0];
                dp[i][1] = min(dp[i-1][0],dp[i-1][1]) + 1;
            }
        }
        return min(dp[n-1][0],dp[n-1][1]);
    }
};

int main(int argc, char const *argv[])
{
    string s = "010110";
    Solution sol;
    cout<<sol.minFlipsMonoIncr(s)<<endl;
    system("pause");
    return 0;
}
