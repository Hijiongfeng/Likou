#include<bits/stdc++.h>

using namespace std;

/*
给定一个段落 (paragraph) 和一个禁用单词列表 (banned)。
返回出现次数最多，同时不在禁用列表中的单词。

题目保证至少有一个词不在禁用列表中，而且答案唯一。

禁用列表中的单词用小写字母表示，不含标点符号。
段落中的单词不区分大小写。答案都是小写字母。
transform(str.begin(),str.end(),str.begin(),::tolower);  // 把字符串 全部变成小写
::toupper 全部变成小写
*/

class Solution {
public:

    string mostCommonWord2(string paragraph, vector<string>& banned) {
        map<string,int> mp;
        unordered_set<string> str_set;
        for(auto & str : banned){
            str_set.insert(str);
        }
        int left = 0,right = 0;
        while(right <= paragraph.size()){
            if(isalpha(paragraph[right])){
                right++;
            }else if(left < right && !isalpha(paragraph[right])){
                string s = paragraph.substr(left,right-left);
                transform(s.begin(),s.end(),s.begin(),::tolower);
                if(str_set.find(s) == str_set.end()){
                    mp[s]++;
                }
                right++;
                left = right;
            }else{
                right++;
                left = right;
            }
        }
        string ans;
        int num = 0;
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->second > num){
                num = it->second;
                ans = it->first;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    //string str = "Bob hit a ball, the hit BALL flew far after it was hit.";
    string str = "a.";
    vector<string> banned = {""};
    Solution sol;
    cout<<sol.mostCommonWord2(str,banned)<<endl;
    system("pause");
    return 0;
}
