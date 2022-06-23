#include<bits/stdc++.h>

using namespace std;

/*
第一行输出查找到x的兄弟单词的个数m 第二行输出查找到的按照字典顺序排序后
的第k个兄弟单词，没有符合第k个的话则不用输出。
示例1
输入：
3 abc bca cab abc 1

输出：
2
bca
*/

bool isSame(vector<int>& dict,vector<int>& new_dict){
    for(int i = 0;i<26;i++){
        if(dict[i] != new_dict[i]){
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    string s = "6 cab ad abcd cba abc bca abc 1";
    stringstream ss(s);
    int N = 0;
    string temp;
    vector<string> vec;
    while(ss >> temp){
        vec.emplace_back(temp);
    }
    N = stoi(vec[0]);
    vector<string> word;
    for(int i = 0;i<N;i++){
        word.emplace_back(vec[i+1]);
    }
    vector<int> dict(26,0);
    int M = vec.size();
    string X = vec[M-2];
    for(int i = 0;i<X.size();i++){
        dict[X[i] - 'a']++;
    }
    vector<string> brother_words;
    for(int i = 0;i<word.size();i++){
        vector<int> new_dict(26,0);
        for(int j = 0;j<word[i].size();j++){
            new_dict[word[i][j] - 'a']++;
        }
        if(isSame(dict,new_dict) && word[i] != X){
            brother_words.emplace_back(word[i]);
        }
    }
    sort(brother_words.begin(),brother_words.end());
    cout<<brother_words.size()<<endl;
    if(brother_words.size() >= stoi(vec[vec.size()-1])){
        cout<<brother_words[stoi(vec[vec.size()-1])-1];
    }
    system("pause");
    return 0;
}
