#include<iostream>
#include<vector>

using namespace std;

/*
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

回文串 是正着读和反着读都一样的字符串。
*/

class Solution {
private:
    vector<vector<string>> res;
    vector<string> path;            // 加 const 常量 不能修改

    bool isPalindrome(const string & s,int start,int end){
        for(int i =start,j=end;i<j;i++,j--){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }

    void backtracking(const string &s,int startindex){  
        if(startindex >= s.size()){
            res.push_back(path);
            return;
        }
        for(int i = startindex;i<s.size();i++){
            if(isPalindrome(s,startindex,i)){
                string str = s.substr(startindex,i-startindex+1);
                path.push_back(str);
            }else{
                continue;
            }
            backtracking(s,i+1);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        if(s.size() == 0) return res;
        backtracking(s,0);
        return res;
    }
};

int main(int argc, const char** argv) {
    string s = "aab";
    Solution sol;
    vector<vector<string>> final = sol.partition(s);
    for(auto& s:final){
        for(auto& y:s){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}