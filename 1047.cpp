#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;
/*给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
*/
// 使用 栈 进行删除  如果栈为空 或者 元素与栈顶的元素不相同 就push  否则就pop
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string res;
        for(int i=0;i<s.size();i++){
            if(st.empty() || st.top() != s[i]){
                st.push(s[i]);
            }else{
                st.pop();
            }
        }
        while(!st.empty()){
            //res.push_back(st.top());
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(int argc, const char** argv) {
    string str = "abbaca";
    Solution sol;
    cout<<sol.removeDuplicates(str)<<endl;
    system("pause");
    return 0;
}