#include<bits/stdc++.h>

using namespace std;

/*
给你一个由若干单词组成的句子 sentence ，单词间由空格分隔。每个单词仅由大写和小写英文字母组成。

请你将句子转换为 “山羊拉丁文（Goat Latin）”（一种类似于 猪拉丁文 - Pig Latin 的虚构语言）。
山羊拉丁文的规则如下：

如果单词以元音开头（'a', 'e', 'i', 'o', 'u'），在单词后添加"ma"。
例如，单词 "apple" 变为 "applema" 。
如果单词以辅音字母开头（即，非元音字母），移除第一个字符并将它放到末尾，之后再添加"ma"。
例如，单词 "goat" 变为 "oatgma" 。
根据单词在句子中的索引，在单词最后添加与索引相同数量的字母'a'，索引从 1 开始。
例如，在第一个单词后添加 "a" ，在第二个单词后添加 "aa" ，以此类推。
返回将 sentence 转换为山羊拉丁文后的句子。
输入：sentence = "I speak Goat Latin"
输出："Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
*/

class Solution {
public:
    bool check(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c== 'u'){
            return true;
        }
        return false;
    }
    string toGoatLatin(string sentence) {
        string ans = "";
        int index = 1;
        for(int i = 0;i<sentence.size();i++){
            int len = i;
            while(sentence[len] != ' ' &&  len < sentence.size()){
                len++;
            }
            string temp = sentence.substr(i,len - i); 
            if(check(tolower(temp[0]))){
                temp += "ma";
                temp += string(index,'a');
                ++index;
                ans += temp;
                ans += " ";
            }else{
                char ch = temp[0];
                temp = string(temp.begin() + 1,temp.end());
                temp.push_back(ch);
                temp += "ma";
                temp += string(index,'a');
                ++index;
                ans += temp;
                ans += " ";
            }
            i = len;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string sentence = "I speak Goat Latin";
    Solution sol;
    cout<<sol.toGoatLatin(sentence)<<endl;
    stringstream ss(sentence);
    string temp;
    while(ss >> temp){
        cout<<temp<<endl;
    }
    
    system("pause");
    return 0;
}
