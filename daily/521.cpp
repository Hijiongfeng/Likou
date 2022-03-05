#include<iostream>
#include<vector>
#include<string>
#include<set>

using namespace std;

/*
给你两个字符串 a 和 b，请返回 这两个字符串中 最长的特殊序列  。如果不存在，则返回 -1 。

「最长特殊序列」 定义如下：该序列为 某字符串独有的最长子序列（即不能是其他字符串的子序列） 。

字符串 s 的子序列是在从 s 中删除任意数量的字符后可以获得的字符串。

例如，"abc" 是 "aebdc" 的子序列，
因为删除 "aebdc" 中斜体加粗的字符可以得到 "abc" 。
 "aebdc" 的子序列还包括 "aebdc" 、 "aeb" 和 "" (空字符串)。

输入: a = "aba", b = "cdc"
输出: 3
解释: 最长特殊序列可为 "aba" (或 "cdc")，两者均为自身的子序列且不是对方的子序列。
*/
class Solution {
public:
    int findLUSlength(string a, string b) {
        int N1 = a.size();
        int N2 = b.size();
        if(N1 < N2) swap(a,b);
        if(a != b) return a.size();
        multiset<char> st;
        for(auto & s : b){
            st.insert(s);
        }
        int count = 0;
        for(auto & s : a){
            if(st.find(s) == st.end()){
                count++;
            }
        }
        return count == 0 ? -1 : count;
    }
};


int main(int argc, char const *argv[])
{
    string s1 = "d",s2 = "abcdf";
    Solution sol;
    cout<<sol.findLUSlength(s1,s2)<<endl;
    system("pause");
    return 0;
}
