#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
字符串的一个子序列是原始字符串删除一些（也可以不删除）
字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
**/

class Solution {
public:
    bool isSubsequence(string s, string t) {            // 动态规划 dp
        // 我感觉可以利用 子序的 解法 解决。s 是 t的子序，最后找到的子序
        // 长度等于 s.size() 则返回true 否则返回false
        vector<vector<int>> dp(s.size()+1,vector<int> (t.size()+1,0));
        int nums = 0;
        for(int i = 1;i<=s.size();i++){
            for(int j = 1;j<=t.size();j++){
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if(dp[i][j] > nums) nums = dp[i][j];
            }
        }
        if(nums == s.size()) return true;
        return false;
    }
};


class Solution2 {
public:
    bool isSubsequence(string s, string t) {            // 动态规划  第二种 解法  注意这里表示的为 长度，
        //dp[i][j] 表示以下标i-1为结尾的字符串s，和以下标j-1为结尾的字符串t，相同子序列的长度为dp[i][j]。
        // 初始化为 i-1和j-1 是为了 方便递推公式；
        vector<vector<int>> dp(s.size()+1,vector<int> (t.size()+1,0));

        for(int i = 1;i<=s.size();i++){
            for(int j = 1;j<=t.size();j++){
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = dp[i][j-1];
            }
        }

        if(dp[s.size()][t.size()] == s.size()) return true;
        return false;
    }
};


int main(int argc, char const *argv[])
{
    string str1 = "ace";
    string str2 = "abcde";
    Solution2 sol;
    cout<<sol.isSubsequence(str1,str2)<<endl;
    system("pause");
    return 0;
}
