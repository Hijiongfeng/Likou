#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

/*
给定一个整数 n ，返回 可表示为两个 n 位整数乘积的 最大回文整数 。
因为答案可能非常大，所以返回它对 1337 取余 。
*/
/*
我们可以从大到小枚举回文数，由于确定了回文数的左半部分，其右半部分也就确定了，
因此我们只需要枚举左半部分，同时由于两个 n位整数的乘积至多是个 2n 位数，我们可以从 10^n-1 
开始枚举回文数的左半部分。
*/
class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        }
        int upper = pow(10, n) - 1;
        for (int left = upper;; --left) { // 枚举回文数的左半部分
            long p = left;
            for (int x = left; x > 0; x /= 10) {
                p = p * 10 + x % 10; // 翻转左半部分到其自身末尾，构造回文数 p
            }
            for (long x = upper; x >= sqrt(p); --x) { // 如果平方的结果大于p，这结果肯定不是
                if (p % x == 0) { // x 是 p 的因子
                    return p % 1337;
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    int n = 3;
    Solution sol;
    cout<<sol.largestPalindrome(n)<<endl;
    system("pause");
    return 0;
}
