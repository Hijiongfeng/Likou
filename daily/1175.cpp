#include<bits/stdc++.h>
using namespace std;

/*
请你帮忙给从 1 到 n 的数设计排列方案，使得所有的「质数」
都应该被放在「质数索引」（索引从 1 开始）上；你需要返回可能的方案总数。

让我们一起来回顾一下「质数」：质数一定是大于 1 的，并且不能用两个小于它的正整数的乘积来表示。

由于答案可能会很大，所以请你返回答案 模 mod 10^9 + 7 之后的结果即可。
s
示例 1：

输入：n = 5
输出：12
解释：举个例子，[1,2,5,4,3] 是一个有效的排列，
但 [5,2,3,4,1] 不是，因为在第二种情况里质数 5 被错误地放在索引为 1 的位置上。

*/

class Solution {
    vector<int> prime = {2,3,5,7,11,13,17,19,23,29,
                        31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int mod = 1e9 + 7;
    long long rank(int num){
        long long ans = 1;
        while(num){
            ans *= num;
            ans %= mod;
            num--;
        }
        return ans;
    }
public:
    int numPrimeArrangements(int n) {
        int index = upper_bound(prime.begin(),prime.end(),n) - prime.begin();
        long long a = rank(index);
        long long b = rank(n - index);
        return a * b % mod;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout<<sol.numPrimeArrangements(100)<<endl;
    system("pause");
    return 0;
}
