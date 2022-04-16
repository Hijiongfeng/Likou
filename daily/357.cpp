#include<iostream>
#include<vector>

using namespace std;

/*
给你一个整数 n ，统计并返回各位数字都不同的数字 x 的个数，
其中 0 <= x < 10n 。
示例 1：

输入：n = 2
输出：91
解释：答案应为除去 11、22、33、44、55、66、77、88、99 外，在 0 ≤ x < 100 范围内的所有数字。 

排列组合
找规律，除了n==0的情况，其他位数的数字数就是9*A(9)(n-1)：
*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return 10;
        int ans = 10,cur = 9;
        for(int i = 0;i<n-1;i++){
            cur *= 9-i;
            ans += cur; 
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n = 3;
    Solution sol;
    cout<<sol.countNumbersWithUniqueDigits(n)<<endl;
    system("pause");
    return 0;
}
