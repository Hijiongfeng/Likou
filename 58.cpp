#include<bits/stdc++.h>

using namespace std;

/*
给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。
返回字符串中 最后一个 单词的长度。

单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
示例 1：

输入：s = "Hello World"
输出：5
解释：最后一个单词是“World”，长度为5。
示例 2：

输入：s = "   fly me   to   the moon  "
输出：4
解释：最后一个单词是“moon”，长度为4。
*/

class Solution {
public:
    int lengthOfLastWord(string s) {   // 使用stringstream自动分割每个单词
        stringstream ss(s);
        string temp;
        while(ss >> temp){
            
        }
        return temp.size();
    }

    int lengthOfLastWord2(string s) {   // 从最后开始遍历
        int index = s.size() - 1;

        while (s[index] == ' ') {
            index--;
        }
        int wordLength = 0;
        while (index >= 0 && s[index] != ' ') {
            wordLength++;
            index--;
        }

        return wordLength;
    }
};

int main(int argc, char const *argv[])
{
    string s = "a";
    Solution sol;
    cout<<sol.lengthOfLastWord2(s)<<endl;
    system("pause");
    return 0;
}
