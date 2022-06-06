#include<bits/stdc++.h>

using namespace std;

/*
把字符串 s 看作是 “abcdefghijklmnopqrstuvwxyz” 的无限环绕字符串，所以 s 看起来是这样的：

"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd...." . 
现在给定另一个字符串 p 。返回 s 中 唯一 的 p 的 非空子串 的数量 。 

示例 1:

输入: p = "a"
输出: 1
解释: 字符串 s 中只有一个"a"子字符。
*/

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26,0);
        int count = 0;
        cout<<p[0]<<endl;
        cout<<(p[0]+1)%26<<" "<<p[1]%26<<endl;
        cout<<p[2] - p[1]<<endl;
        for(int i = 0;i<p.size();i++){
            if(i > 0 && (p[i-1]+1) % 26 == p[i] % 26){      //相差 1 或者 -25
                count++;
            }else{
                count = 1;
            }
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'],count);
        }
        return accumulate(dp.begin(),dp.end(),0);
    }
};


int main(int argc, char const *argv[])
{
    string p = "zab";
    Solution sol;
    cout<<sol.findSubstringInWraproundString(p)<<endl;
    system("pause");
    return 0;
}
