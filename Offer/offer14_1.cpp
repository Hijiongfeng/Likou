#include<iostream>
#include<vector>

using namespace std;

/*
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为 k[0],k[1]...k[m-1] 。
请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

发现规律
找出最优解的规律
当n等于1，2，3的时候，结果是固定的
当n大于3的时候，可以看以下数据
n=4, 最优解：2 2
n=5, 最优解：3 2
n=6, 最优解：3 3
n=7, 最优解：3 2 2
n=8, 最优解：3 3 2
n=9, 最优解：3 3 3
n=10,最优解：3 3 2 2
n=11,最优解：3 3 3 2
n=12,最优解：3 3 3 3
n=13,最优解：3 3 3 2 2
n=14,最优解：3 3 3 3 2
n=15,最优解：3 3 3 3 3

当n % 3 == 0 时，有n / 3个数字，没有2 ；
当n % 3 == 1 时，有n / 3 + 1个数字，其中有2个2；
当n % 3 == 2 时，有n / 3 + 1个数字，其中有1个2；

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



public:
    int cutRope(int n) {
       	if(n <= 1){
            return 0;
        }
        if(n == 2){
            return 1;
        }
        if(n == 3){
            return 2;
        }
        //计算有多少个数字
        int length = n % 3 == 0 ? n / 3 : n / 3 + 1;
        //计算其中有多少个2
        int length1 = n % 3 == 0 ? 0 : 3 - n % 3;
        //结果
        int result = 1;
        for(int i = 0; i < length1; i++){
            result = result * 2;
        }
        for(int i = 0; i < length - length1; i++){
        	result = result * 3;
        }
        return result;
    }
};
};

int main(int argc, char const *argv[])
{
    int n = 10;
    Solution sol;
    cout<<sol.cuttingRope(n)<<endl;
    system("pause");
    return 0;
}
