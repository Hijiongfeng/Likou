#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>

using namespace std;

/*
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

示例 1:

输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {      // 这种小暴力的解法 还是超时
        if(s.size() < p.size()) return {};
        unordered_set<char> ch_set;
        for(char & ch : p){
            ch_set.emplace(ch);
        }
        sort(p.begin(),p.end());
        int N = p.size();
        vector<int> ans;
        for(int i = 0;i<s.size()-N+1;i++){
            if(ch_set.count(s[i])){
              string ss = s.substr(i,N);
              sort(ss.begin(),ss.end());
              if(ss == p){
                ans.push_back(i);
              }
            }
        }
        return ans;
    }
};
/*

由于子串是连续的，且异位词不会改变字符串中每个字符的个数，
所以只有当两个字符串每个字符的个数均相等时，一个字符串才是另一个字符串的异位词。

使用两个数组 cnt_s 和 cnt_p 分别统计 s 和 p 中字母的个数。

由于需要遍历的子串 p 长度均为 m ，
我们可以使用一个固定长度为 m 的滑动窗口来维护 cnt_s​ ：
滑动窗口每向右滑动一次，就多统计一次进入窗口的字符，
少统计一次离开窗口的字符。然后，判断 cnt_s 是否与 cnt_p 相等，
若相等则意味着 p 的异位词之一是 s 的子串。

*/
class Solution2 {
public:
    vector<int> findAnagrams(string s, string p) {      // 滑动窗口
        if(s.size() < p.size()) return {};
        vector<int> ans,cnt_s(26),cnt_p(26);
        int N = p.size();
        int i;
        for(i = 0;i<N;i++){
            cnt_p[p[i] - 'a']++;
            cnt_s[s[i] - 'a']++;
        }
        if(cnt_s == cnt_p) ans.push_back(0);
        for(;i<s.size();i++){
            cnt_s[s[i]-'a']++;
            cnt_s[s[i-N] - 'a']--;
            if(cnt_s == cnt_p) ans.push_back(i-N+1);
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    string s = "cbaebabacd",p = "abc";
    Solution2 sol;
    vector<int> vec = sol.findAnagrams(s,p);
    system("pause");
    return 0;
}
