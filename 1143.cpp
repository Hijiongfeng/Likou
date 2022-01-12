#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
*/
// 子序列 要求不连续也行
// 子数组 要求要连续

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int> (text2.size()+1,0));
        
        int result = 0;
        for(int i = 1;i<=text1.size();i++){
            for(int j = 1;j<=text2.size();j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                if(dp[i][j] > result) result = dp[i][j];
            }
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
    string str1 = "bl";
    string str2 = "yby";
    Solution sol;
    cout<<sol.longestCommonSubsequence(str1,str2)<<endl;
    system("pause");
    return 0;
}
