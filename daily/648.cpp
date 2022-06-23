#include<bits/stdc++.h>

using namespace std;

/*
在英语中，有一个叫做 词根(root) 的概念，
它可以跟着其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。
例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。

现在，给定一个由许多词根组成的词典和一个句子，
需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，
则用最短的词根替换它。

需要输出替换之后的句子。
输入：dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
输出："the cat was rat by the bat"
*/

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        sort(dictionary.begin(),dictionary.end());
        stringstream ss(sentence);
        string temp;
        string res = "";
        while(ss >> temp){
            bool FIND = false;
            for(string & root : dictionary){
                int index = temp.find(root);
                if(index!=string::npos && index == 0){ 
                    res += root;
                    res += " ";
                    FIND = true;
                    break;
                }
            }
            if(!FIND){
                res += temp;
                res += " ";
            }

        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> dictionary = {"catt","cat","bat","rat"};
    string sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";
    Solution sol;
    cout<<sol.replaceWords(dictionary,sentence)<<endl;
    system("pause");
    return 0;
}
