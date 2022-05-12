#include<bits/stdc++.h>

using namespace std;

/*

给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true ；否则，返回 false 。

整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3x

 

示例 1：

输入：n = 27
输出：true


方法二：判断是否为最大 33 的幂的约数
思路与算法

我们还可以使用一种较为取巧的做法。

在题目给定的 3232 位有符号整数的范围内，最大的 33 的幂为 3^{19} = 11622614673 
我们只需要判断 nn是否是 3^{19}的约数即可。

与方法一不同的是，这里需要特殊判断 n是负数或 0 的情况。
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0)
            return false;
        while(n){
            
            int temp = n % 3;
            if(n == 1){
                return true;
            }
            if(temp != 0){
                return false;
            }
            n = n / 3;
        }
        return 1;
    }

    bool isPowerOfThree2(int n) {           // 3的19次方为临界值
        return n > 0 && 1162261467 % n == 0;
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
