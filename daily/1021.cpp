#include<bits/stdc++.h>

using namespace std;

/*
有效括号字符串为空 ""、"(" + A + ")" 或 A + B ，其中 A 和 B 都是有效的括号字符串，+ 代表字符串的连接。

例如，""，"()"，"(())()" 和 "(()(()))" 都是有效的括号字符串。
如果有效字符串 s 非空，且不存在将其拆分为 s = A + B 的方法，我们称其为原语（primitive），
其中 A 和 B 都是非空有效括号字符串。

给出一个非空有效字符串 s，考虑将其进行原语化分解，
使得：s = P_1 + P_2 + ... + P_k，其中 P_i 是有效括号字符串原语。

对 s 进行原语化分解，删除分解中每个原语字符串的最外层括号，返回 s 。

 

示例 1：

输入：s = "(()())(())"
输出："()()()"
解释：
输入字符串为 "(()())(())"，原语化分解得到 "(()())" + "(())"，
删除每个部分中的最外层括号后得到 "()()" + "()" = "()()()"。
*/

class Solution {
public:
    string removeOuterParentheses(string s) {   // 使用 栈 进行模拟（方法一）
        string ans = "";
        if(s == "") return ans;
        stack<char> st;
        string temp = "";
        for(char ch : s){
            temp += ch;
            if(ch == '('){
                st.push(')');
            }else if(ch == st.top()){
                st.pop();
            }
            if(st.empty()){
                int size = temp.size();
                ans += string(temp.begin()+1,temp.begin()+size-1);
                temp = "";
            }
        }
        return ans;
    }
// 使用计数（方法二）  遇到左括号加一，遇到右括号减一
    string removeOuterParentheses2(string s) {   
        string ans = "";
        int cnt = 0;
        for(char c : s){
            if(c == ')'){
                cnt--;
            }
            if(cnt){
                ans.push_back(c);
            }
            if(c == '('){
                cnt++;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s = "(()())(())";
    Solution sol;
    cout<<sol.removeOuterParentheses2(s)<<endl;
    system("pause");
    return 0;
}
