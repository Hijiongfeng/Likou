#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*
给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
回文字符串 是正着读和倒过来读一样的字符串。
子字符串 是字符串中的由连续字符组成的一个序列。
具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
*/

class Solution {
public:
    int countSubstrings(string s) {
        // 布尔类型的dp[i][j]：表示区间范围[i,j] （注意是左闭右闭）的子串是否是回文子串，
        // 如果是dp[i][j]为true，否则为false。

        vector<vector<bool>> dp(s.size(),vector<bool> (s.size(),false));

        int result = 0;
        for(int i = s.size()-1;i>=0;i--){
            for(int j = i;j<s.size();j++){
                if(s[i] == s[j]){
                    if(j - i <=1){
                        result++;
                        dp[i][j] = true;
                    }else if(dp[i+1][j-1]){
                        result++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    string str = "aaa";
    Solution sol;
    cout<<sol.countSubstrings(str)<<endl;
    system("pause");
    return 0;
}
