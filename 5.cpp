#include<iostream>
#include<vector>
#include<string>

using namespace std;

// 给你一个字符串 s，找到 s 中最长的回文子串。

class Solution {
public:
    string longestPalindrome(string s) {
        // dp[i][j] 表示 i j下标的回文 子串 长度，（分清子串和子序列）
        vector<vector<bool>> dp(s.size(),vector<bool> (s.size(),false));

        int len = 1;
        //string str = to_string(s[0]);
        int left;
        int right;
        //for(int i = 0;i<s.size();i++) dp[i][i] = 1;
        for(int i = s.size()-1;i>=0;i--){
            for(int j = i;j<s.size();j++){
                if(s[i] == s[j]){
                    if(j - i <=1) dp[i][j] = true;
                    else if(dp[i+1][j-1]){
                        dp[i][j] = true;
                    }
                }
                if(dp[i][j] == true && j - i +1 >=len){     // 确定左右区间
                    len = j-i+1;
                    left = i;
                    right = j;
                }
            }
        }
        return s.substr(left,right-left+1);
    }
};

int main(int argc, char const *argv[])
{
    string str = "cbbd";
    Solution sol;
    string s = sol.longestPalindrome(str);
    cout<<s<<endl;

    system("pause");
    return 0;
}
