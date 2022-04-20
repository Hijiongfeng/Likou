#include<bits/stdc++.h>

using namespace std;

/*
给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。
示例 1:
输入: a = "11", b = "1"
输出: "100"
示例 2:
输入: a = "1010", b = "1011"
输出: "10101"
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int flag = 0;
        int len1 = a.size(),len2 = b.size();
        if(len1 > len2){                    // a的长度大于b的长度
            reverse(a.begin(),a.end());
            reverse(b.begin(),b.end());     // 翻转
            int N = len1 - len2;
            while(N--){                     // 后面 补 0  
                b.push_back('0');           // 也可以前面补0；  a = '0' + a;(这个是前面补0，省了一个翻转的操作)
            }
        }
        if(len1 <= len2){   
            reverse(a.begin(),a.end());     // 翻转
            reverse(b.begin(),b.end());
            int N = len2 - len1;            // b 的长度大于 a
            while(N--){                     // 后面 补 0
                a.push_back('0');
            }
        }

        for(int i = 0;i<a.size() && i<b.size();i++){
            int temp = (a[i] - '0') + (b[i] - '0') + flag;
            if(temp == 2){ 
                ans.push_back(0 + '0');     // 如果是2，这一位结果是 0， 出现进位；
                flag = 1;
            }else if(temp == 3){            // 如果是3，这一位结果是 1， 出现进位；
                ans.push_back(1 +'0');
                flag = 1;
            }else{                          // 如果是其他的，就当前结果，不出现进位
                ans.push_back(temp +'0');
                flag = 0;
            }
        }
        if(flag == 1){
            ans.push_back('1');
            flag = 0;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string a = "11",b = "11";
    Solution sol;
    cout<<sol.addBinary(a,b)<<endl;
    system("pause");
    return 0;
}