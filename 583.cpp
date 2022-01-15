#include<iostream>
#include<vector>

using namespace std;

/*
给定两个单词 word1 和 word2，找到使得 word1 和 word2 
相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。

两个字符串都可以删除        删除多少 
多了一条路？
*/

class Solution {
public:
    int minDistance(string word1, string word2) {       // 动态规划 dp  
        vector<vector<int>> dp(word1.size()+1,vector<int> (word2.size()+1,0));
        for(int i = 0;i<=word1.size();i++) dp[i][0] = i;
        for(int j = 1;j<=word2.size();j++) dp[0][j] = j;        // 初始化 dp 数组  删除的个数可以达到相等

        for(int i = 1;i<=word1.size();i++){
            for(int j = 1;j<=word2.size();j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];       // 不需要删除 与上一次相同
                else dp[i][j] = min(dp[i-1][j-1]+2,min(dp[i-1][j]+1,dp[i][j-1]+1));     // 删一个 删两个 的情况
            }
        }

        return dp[word1.size()][word2.size()];
    }
};

int main(int argc, const char** argv) {
    string str1 = "sea";
    string str2 = "eat";
    Solution sol;
    cout<<sol.minDistance(str1,str2)<<endl;
    system("pause");
    return 0;
}