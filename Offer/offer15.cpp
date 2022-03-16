#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*
编写一个函数，输入是一个无符号整数（以二进制串的形式），
返回其二进制表达式中数字位数为 '1' 的个数（也被称为 汉明重量).）。

提示：

请注意，在某些语言（如 Java）中，没有无符号整数类型。在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的还是无符号的，其内部的二进制表示形式都是相同的。
在 Java 中，编译器使用 二进制补码 记法来表示有符号整数。因此，在上面的 示例 3 中，输入表示有符号整数 -3。
*/


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for(int i = 31;i>=0;i--){       // 对 n 右移，与 1 作 & 运算，得出1的个数
            if((n >> i) & 1){
                count++;
            }
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    uint32_t n = 4294967293;
    Solution sol;
    cout<<sol.hammingWeight(n)<<endl;
    system("pause");
    return 0;
}
