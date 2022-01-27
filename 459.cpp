#include<iostream>
#include<string>
#include<vector>

using namespace std;
/*
给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

输入: s = "abab"
输出: true
解释: 可由子串 "ab" 重复两次构成。wwwwwwwwwwwwww
*/

class Solution {
private:
    void getNext(int *next,const string &s){
        int j = 0;      // 1.前缀 末尾 2. i 之前的最长相等前后缀
        next[0] = 0;    // 
        for(int i = 1;i<s.size();i++){
            while(j > 0 && s[i] != s[j]){
                j = next[j-1];              // 不相等
            }
            if(s[i] == s[j]){
                j++;                        // 相等
            }
            next[i] = j;
        }
    }

public:
    bool repeatedSubstringPattern(string s) {
        int *next = new int[s.size()];
        getNext(next,s);
        for(int i = 0;i<s.size();i++){
            cout<<next[i]<<endl;
        }
        int len = s.size();
        int nums = len-next[len-1];
        if(next[len-1] != 0 && len % nums == 0){
            delete[] next;
            return true;
        }
        delete[] next;
        return false;
    }
};

int main(int argc, char const *argv[])
{
    string s = "abab";
    Solution sol;
    cout<<sol.repeatedSubstringPattern(s)<<endl;

    system("pause");
    return 0;
}
