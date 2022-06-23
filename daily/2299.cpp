#include<bits/stdc++.h>

using namespace std;
/*
如果一个密码满足以下所有条件，我们称它是一个 强 密码：

它有至少 8 个字符。
至少包含 一个小写英文 字母。
至少包含 一个大写英文 字母。
至少包含 一个数字 。
至少包含 一个特殊字符 。特殊字符为："!@#$%^&*()-+" 中的一个。
它 不 包含 2 个连续相同的字符（比方说 "aab" 不符合该条件，但是 "aba" 符合该条件）。
给你一个字符串 password ，如果它是一个 强 密码，返回 true，否则返回 false 。

 

示例 1：

输入：password = "IloveLe3tcode!"
输出：true
解释：密码满足所有的要求，所以我们返回 true 。
*/


class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n = password.size();
        if(n < 8){
            return false;
        }
        int lower = 0,upper = 0,digit = 0,spechar = 0;
        for(int i = 0;i<n;i++){
            if(i > 0 && password[i] == password[i-1]){
                return false;
            }
            if(password[i] >= 'a' && password[i] <= 'z'){
                ++lower;
            }else if(password[i] >= 'A' && password[i] <= 'Z'){
                ++upper;
            }else if(password[i] >= '0' && password[i] <= '9'){
                ++digit;
            }else{
                ++spechar;
            }
        }
        if(lower && upper && digit && spechar){
            return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    string password = "IloveLe3tcode!";
    Solution sol;
    cout<<sol.strongPasswordCheckerII(password)<<endl;
    system("pause");
    return 0;
}
