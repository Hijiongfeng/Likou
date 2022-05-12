#include<bits/stdc++.h>

using namespace std;

/*
颠倒给定的 32 位无符号整数的二进制位。

提示：

请注意，在某些语言（如 Java）中，没有无符号整数类型。
在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的还是无符号的，其内部的二进制表示形式都是相同的。
在 Java 中，编译器使用二进制补码记法来表示有符号整数。
因此，在 示例 2 中，输入表示有符号整数 -3，输出表示有符号整数 -1073741825。

示例 1：

输入：n = 00000010100101000001111010011100
输出：964176192 (00111001011110000010100101000000)
解释：输入的二进制串 00000010100101000001111010011100 表示无符号整数 43261596，
     因此返回 964176192，其二进制表示形式为 00111001011110000010100101000000。

*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 31;i>=0;i--){
            if((n >> i) & 1){
                ans += pow(2,31-i);
            }
        }
        return ans;
    }

    uint32_t reverseBits2(uint32_t n) {
        uint32_t rev = 0;
        for (int i = 0; i < 32 && n > 0; ++i) {     // 从低位到高位
            rev |= (n & 1) << (31 - i);
            n >>= 1;
        }
        return rev;
    }
};

int main(int argc, char const *argv[])
{
    uint32_t n = 1;
    Solution sol;
    cout<<sol.reverseBits2(n)<<endl;
    system("pause");
    return 0;
}
