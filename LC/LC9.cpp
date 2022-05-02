#include<bits/stdc++.h>

using namespace std;

/*
请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。

函数 myAtoi(string s) 的算法如下：

读入字符串并丢弃无用的前导空格
检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
返回整数作为最终结果。
注意：

本题中的空白字符只包括空格字符 ' ' 。
除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。
*/

class Solution {
public:
    int myAtoi(string s) {
        int start = 0;                  // 找到第一个数字
        bool flag = true;
        for(int i = 0;i<s.size();i++){
            if(s[i] == ' '){            // 遇到空格 加一
                start++;
            }else if(s[i] == '-'){      // 遇到-号，为负，弹出
                flag = false;
                start++;
                break;
            }else if(s[i] == '+'){      //遇到+号，为正，弹出  这样就可以解决 +-42 这样的用例
                start++;
                break;
            }else{
                break;
            }
        }

        long long ans = 0;
        for(int i = start;i<s.size();i++){
            if(isdigit(s[i])){  
                ans = ans * 10 + (s[i] - '0');
                if(flag == false){              // 开始判断
                    ans = -ans;
                }

                if(ans > INT_MAX ){         // 大于最大值
                    ans = INT_MAX;
                    return ans;
                }

                if(ans < INT_MIN ){         // 小于最小值
                    ans = INT_MIN;
                    return ans;
                }

                ans = abs(ans);

            }else{
                break;
            }
        }
        if(flag == false){
            ans = -ans;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    string s = "  -42";
    Solution sol;
    cout<<sol.myAtoi(s)<<endl;
    system("pause");
    return 0;
}
