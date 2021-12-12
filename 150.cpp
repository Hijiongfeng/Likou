#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;
/*根据 逆波兰表示法，求表达式的值。
有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
说明：
*/

// 计算机方便识别后缀表达式  后缀表达式 使用 栈 去做

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if(tokens[i] == "+") st.push(num2 + num1);
                if(tokens[i] == "-") st.push(num2 - num1);
                if(tokens[i] == "*") st.push(num2 * num1);
                if(tokens[i] == "/") st.push(num2 / num1);
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};

int main(int argc, const char** argv) {
    //"4","13","5","/","+"
    vector<string> tok = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution sol;
    cout<<sol.evalRPN(tok)<<endl;;
    system("pause");
    return 0;
}