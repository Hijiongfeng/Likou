#include<bits/stdc++.h>

using namespace std;

/*
给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。

示例 1：

输入: s = "leetcode"
输出: 0
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> s_mp;
        for(char ch : s){
            s_mp[ch]++;
        }
        for(int i = 0;i<s.size();i++){
            if(s_mp[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    string s = "leetcode";
    Solution sol;
    cout<<sol.firstUniqChar(s)<<endl;
    system("pause");
    return 0;
}
