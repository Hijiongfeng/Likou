#include<bits/stdc++.h>

using namespace std;
/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"
示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1){
            return strs[0];
        }
        string s = "";
        for(int i = 0;i<strs[0].size() && i <strs[1].size();i++){
            if(strs[0][i] != strs[1][i]){
                break;
            }else{
                s += strs[0][i];
            }
        }

        for(int i = 2;i<strs.size();i++){
            int N = s.size() -1;
            if(N <= strs[i].size()){
                for(int j = N;j>=0;j--){
                    if(s[j] != strs[i][j]){
                        s.pop_back();
                    }
                }
            }else{
                s.resize(strs[i].size());
                N = s.size() -1;
                for(int j = N;j>=0;j--){
                    if(s[j] != strs[i][j]){
                        s.pop_back();
                    }
                }
            }

        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> strs = {"abab","aba","a"};
    Solution sol;
    cout<<sol.longestCommonPrefix(strs)<<endl;
    return 0;
}
