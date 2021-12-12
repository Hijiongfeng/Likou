#include<iostream>
#include<string>
using namespace std;
/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
*/
class Solution {
public:
    bool isAnagram(string s, string t) {  //哈希表
        int record[26] = {0};
        for(int i=0;i<s.size();i++){
            record[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++){
            record[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(record[i] != 0){
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char** argv) {
    string s1 = "rac";
    string s2 = "car";
    cout<<s2[2]-'a'<<endl;
    Solution sol;
    cout<<sol.isAnagram(s1,s2)<<endl;;
    system("pause");
    return 0;
}