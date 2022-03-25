#include<iostream>

using namespace std;

/**
 给定一个整数 n ，返回 n! 结果中尾随零的数量。

提示 n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1

示例 1

输入：n = 3
输出：0
解释：3! = 6 ，不含尾随 0
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        for (int i = 5; i <= n; i += 5) {
            for (int x = i; x % 5 == 0; x /= 5) {
                ++ans;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{


    system("pause");
    return 0;
}
