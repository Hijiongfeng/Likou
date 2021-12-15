#include<iostream>
#include<vector>

using namespace std;

/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/

const string letterMap[10] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

class Solution {
private:
    vector<string> res;
    string s;
    void backtracking(const string& digits,int index){   // 递归函数  取哪个按键
        if(index == digits.size()){
            res.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for(int i = 0;i<letters.size();i++){         // 每个 按键 的字母 个数
            s.push_back(letters[i]);
            backtracking(digits,index+1);
            s.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return res;
        backtracking(digits,0);
        return res;
    }
};

int main(int argc, const char** argv) {
    Solution sol;
    vector<string> ves = sol.letterCombinations("23");
    for(auto& s:ves){
        cout<<s<<endl;
    } 
    system("pause");
    return 0;
}