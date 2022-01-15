#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*
给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。
字符串的一个 子序列 是指，通过删除一些（也可以不删除）
字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）
题目数据保证答案符合 32 位带符号整数范围。

*/

class Solution {
public:
    int numDistinct(string s, string t) {   // 动态规划 dp  s 变成 t  注意这里为个数
        // dp[i][j]：以i-1为结尾的s子序列中出现以j-1为结尾的t的个数为dp[i][j]。
        vector<vector<int>> dp(s.size()+1,vector<int> (t.size()+1,0));
        for(int i = 0;i<=s.size();i++) dp[i][0] = 1;
        for(int j = 1;j<=t.size();j++) dp[0][j] = 0;

        for(int i = 1;i<=s.size();i++){
            for(int j = 1;j<=t.size();j++){
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1]+dp[i-1][j];        // bagg 和 bag 的情况
                else dp[i][j] = dp[i-1][j];
            }
        }

        return dp[s.size()][t.size()];
    }
};

int main(int argc, const char** argv) {
    string s = "rabbbit";
    string t = "rabit";
    Solution sol;
    cout<<sol.numDistinct(s,t)<<endl;
    system("pause");
    return 0;
}