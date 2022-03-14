#include<iostream>
#include<vector>

using namespace std;

/*
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为 k[0],k[1]...k[m-1] 。
请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
*/

class Solution {
public:
    int cuttingRope(int n) {
        if(n == 1 || n == 2) return 1;
        vector<int> dp(n+1);
        dp[2] = 1;
        for(int i = 3;i<=n;i++){
            for(int j = 1;j<=i-1;j++){
                dp[i] = max(dp[i],max(j*(i-j),j*dp[i-j]));
            }
        }
        return dp[n];
    }
};

int main(int argc, char const *argv[])
{
    int n = 10;
    Solution sol;
    cout<<sol.cuttingRope(n)<<endl;
    system("pause");
    return 0;
}
