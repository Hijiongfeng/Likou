#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>

using namespace std;
/*
给出一个字符串数组 words 组成的一本英语词典。
返回 words 中最长的一个单词，该单词是由 words 词典中其他单词逐步添加一个字母组成。

若其中有多个可行的答案，则返回答案中字典序最小的单词。若无答案，则返回空字符串。

输入：words = ["w","wo","wor","worl", "world"]
输出："world"
解释： 单词"world"可由"w", "wo", "wor", 和 "worl"逐步添加一个字母组成。


*/

class Solution {
public:
    string longestWord(vector<string>& words) {         // 字典序列
        string ans;
        set<string> myset;
        for(auto& a : words){
            myset.insert(a);
        }
        sort(words.begin(),words.end());        // 对字符串 进行排序

        for(int i = 0;i<words.size();i++){
            if(words[i].size()==1)
                continue;
            else if(myset.count(words[i].substr(0,words[i].size()-1))==0){      // 如果 没有减1的那个字符串，就删除当前字符串
                myset.erase(words[i]);
            }
        }
        for(string s : myset){
            if(s.size() > ans.size())
                ans = s;
        }
        return ans;

    }
};

int main(int argc, char const *argv[])
{
    //vector<string> words = {"w","wo","wor","worl", "world"};
    //vector<string> words ={"b","br","bre","brea","break","breakf","breakfa","breakfas","breakfast","l","lu","lun","lunc","lunch","d","di","din","dinn","dinne","dinner"};
    vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    Solution sol;
    cout<<sol.longestWord(words)<<endl;
    system("pause");
    return 0;
}
