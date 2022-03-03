#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*

给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。返回这个结果。

示例 1:

输入: num = 38
输出: 2 
解释: 各位相加的过程为：
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2
由于 2 是一位数，所以返回 2。

*/
class Solution {
public:
    int addDigits(int num) {
        string s = to_string(num);          // 转化为 string
        int n = -1;
        while(n != 1){              // 循环
            int temp = 0;
            for(auto & c : s){              // 依次相加各位的数值
                temp += (c - '0');
            }
            s = to_string(temp);
            n = s.size();
        }
        return s[0] - '0';          // 最后 s 剩下1位的时候，返回即可
    }
};

int main(int argc, char const *argv[])
{
    int num = 38;
    Solution sol;
    cout<<sol.addDigits(num)<<endl;
    system("pause");
    return 0;
}
