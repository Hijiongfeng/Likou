#include<bits/stdc++.h>

using namespace std;
/*
使用栈，遇见‘（’，就添加0
*/
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for (auto c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int v = st.top();
                st.pop();
                st.top() += max(2 * v, 1);
            }
        }
        return st.top();
    }
};

int main(int argc, char const *argv[])
{
    
    system("pause");
    return 0;
}
