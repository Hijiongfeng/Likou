#include<bits/stdc++.h>

using namespace std;

/*
你有一个单词列表 words 和一个模式  pattern，
你想知道 words 中的哪些单词与模式匹配。

如果存在字母的排列 p ，使得将模式中的每个字母 x 替换为 p(x) 之后，
我们就得到了所需的单词，那么单词与模式是匹配的。

（回想一下，字母的排列是从字母到字母的双射：
每个字母映射到另一个字母，没有两个字母映射到同一个字母。）

返回 words 中与给定模式匹配的单词列表。

你可以按任何顺序返回答案。
示例：

输入：words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
输出：["mee","aqq"]
解释：
"mee" 与模式匹配，因为存在排列 {a -> m, b -> e, ...}。
"ccc" 与模式不匹配，因为 {a -> c, b -> c, ...} 不是排列。
因为 a 和 b 映射到同一个字母。
*/
/*也可以按照官方题解，构造两次映射关系，如果在两次映射中都成立的话，就把这个单词保存下来*/
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(string & word : words){
            unordered_map<char,char> mp;
            unordered_set<char> set;                        // 找到的保存下来
            if(word.size() != pattern.size()){
                continue;
            }
            bool flag = true;
            for(int i = 0;i<word.size();i++){                           // 构造pattern到word的映射
                char ch = pattern[i];
                if(mp.count(ch) == 0 && set.count(word[i]) == 0){       // 
                    mp[ch] = word[i];
                    set.insert(word[i]);
                }else if(mp.count(ch) == 0 && set.count(word[i])){
                    flag = false;
                    break;
                }else if(mp.count(ch) && mp[ch] == word[i]){            // 
                    continue;
                }else if(mp.count(ch) && mp[ch] != word[i]){
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                res.push_back(word);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> words = {"ccc"};
    string pattern = "abb";
    Solution sol;
    vector<string> vec = sol.findAndReplacePattern(words,pattern);
    for(string & s : vec){
        cout<<s<<endl;
    }
    system("pause");
    return 0;
}
