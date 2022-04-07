#include<iostream>
#include<string>

using namespace std;


/*
给定两个字符串, s 和 goal。如果在若干次旋转操作之后，s 能变成 goal ，那么返回 true 。

s 的 旋转操作 就是将 s 最左边的字符移动到最右边。 

例如, 若 s = 'abcde'，在旋转一次之后结果就是'bcdea' 。

输入: s = "abcde", goal = "cdeab"
输出: true
*/

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        char a = s[0];
        string s_new(s.begin()+1,s.end());
        s_new += a;
        while(s_new!=s){
            char a = s_new[0];
            string ss_new(s_new.begin()+1,s_new.end());
            ss_new += a;
            s_new = ss_new;
            if(s_new == goal)
                return  true;
        }
        return false;
    }

/*
首先，如果 s 和 goal 的长度不一样，那么无论怎么旋转，ss 都不能得到 goal，
返回false。字符串 s + s 包含了所有 s可以通过旋转操作得到的字符串，
只需要检查 goal 是否为 s + ss+s 的子字符串即可。
具体可以参考「28. 实现 strStr() 的官方题解」的实现代码，本题解中采用直接调用库函数的方法。
*/

    bool rotateString2(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        s = s + s;
        if(s.find(goal) != string::npos){
            return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    string s = "abcde";
    string goal = "abced";
    Solution sol;
    cout<<sol.rotateString2(s,goal)<<endl;
    system("pause");
    return 0;
}
