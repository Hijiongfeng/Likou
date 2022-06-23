#include<bits/stdc++.h>

using namespace std;

/*
给定一个字符串 s 和一些 长度相同 的单词 words 。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。

注意子串要与 words 中的单词完全匹配，中间不能有其他字符 ，但不需要考虑 words 中单词串联的顺序。

示例 1：

输入：s = "barfoothefoobarman", words = ["foo","bar"]
输出：[0,9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {        // 滑动窗口 把单词当做分组的长度
        vector<int> res;
        int m = words.size(), n = words[0].size(), ls = s.size();
        for (int i = 0; i < n && i + m * n <= ls; ++i) {
            unordered_map<string, int> differ;
            for (int j = 0; j < m; ++j) {
                ++differ[s.substr(i + j * n, n)];
            }
            for (string &word: words) {
                if (--differ[word] == 0) {
                    differ.erase(word);
                }
            }
            for (int start = i; start < ls - m * n + 1; start += n) {
                if (start != i) {
                    string word = s.substr(start + (m - 1) * n, n);
                    if (++differ[word] == 0) {
                        differ.erase(word);
                    }
                    word = s.substr(start - n, n);
                    if (--differ[word] == 0) {
                        differ.erase(word);
                    }
                }
                if (differ.empty()) {
                    res.emplace_back(start);
                }
            }
        }
        return res;
    }


    vector<int> findSubstring2(string s, vector<string>& words) {
        vector<int> dict(26,0);
        int length = 0;
        for(string & word : words){
            for(char & ch : word){
                dict[ch - 'a']++;
                length++;
            }
        }
        int N = s.size();
        int left = 0,right = 0;
        vector<int> ans;
        vector<int> newdict(26,0);
        for(int i = 0;i<length;i++){
            newdict[s[i] - 'a']++;
        }
        if(dict == newdict){
            ans.push_back(0);
        }


        for(int i = 1;i < N-length;i++){
            int temp = i + length - 1;
            newdict[s[i - 1] - 'a']--;
            newdict[s[temp] - 'a']++;
            if(dict == newdict){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";

    vector<string> words = {"fooo","barr","wing","ding","wing"};
    Solution sol;
    vector<int> ans = sol.findSubstring(s,words);
     
    int a = 0;
    system("pause");
    return 0;
}
