#include<iostream>
#include<vector>
#include<string>

using namespace std;
/*
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int> (word2.size()+1,0));
        // dp[i][j] 表示以下标i-1为结尾的字符串word1，和以下标j-1为结尾的字符串word2，最近编辑距离为dp[i][j]。

        for(int j = 0;j<=word2.size();j++) dp[0][j] = j;         // 删除元素变为 空 字符串
        for(int i = 0;i<=word1.size();i++) dp[i][0] = i;

        for(int i = 1;i<=word1.size();i++){
            for(int j = 1;j<=word2.size();j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
        return dp[word1.size()][word2.size()];
    }

    int minDistance2(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main(int argc, char const *argv[])
{
    string str1 = "horse";
    string str2 = "ros";
    Solution sol;
    cout<<sol.minDistance(str1,str2)<<endl;
    system("pause");
    return 0;
}
