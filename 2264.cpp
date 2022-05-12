#include<bits/stdc++.h>

using namespace std;

/*
给你一个字符串 num ，表示一个大整数。如果一个整数满足下述所有条件，则认为该整数是一个 优质整数 ：

该整数是 num 的一个长度为 3 的 子字符串 。
该整数由唯一一个数字重复 3 次组成。
以字符串形式返回 最大的优质整数 。如果不存在满足要求的整数，则返回一个空字符串 "" 。

注意：

子字符串 是字符串中的一个连续字符序列。
num 或优质整数中可能存在 前导零 。
 

示例 1：

输入：num = "6777133339"
输出："777"
解释：num 中存在两个优质整数："777" 和 "333" 。
"777" 是最大的那个，所以返回 "777" 。
*/

class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string> str_vec = {"000","111","222",
                                "333","444","555",
                                "666","777","888","999"};
        int Index = INT_MAX;
        for(int i = 0;i<str_vec.size();i++){    // 依次找，循环出来就是最大的
            int temp = num.find(str_vec[i]);
            if(temp != string::npos){
                Index = temp;
            } 
        }
        if(Index == INT_MAX){
            return "";
        }
        return num.substr(Index,3);
    }
};

int main(int argc, char const *argv[])
{
    string num = "3200014888";
    Solution sol;
    cout<<sol.largestGoodInteger(num)<<endl;
    system("pause");
    return 0;
}
