#include<bits/stdc++.h>

using namespace std;

/*
给你一个下标从 0 开始长度为 n 的字符串 num ，它只包含数字。

如果对于 每个 0 <= i < n 的下标 i ，都满足数位 i 在 num 中出现了 num[i]次，
那么请你返回 true ，否则返回 false 。

示例 1：

输入：num = "1210"
输出：true
解释：
num[0] = '1' 。数字 0 在 num 中出现了一次。
num[1] = '2' 。数字 1 在 num 中出现了两次。
num[2] = '1' 。数字 2 在 num 中出现了一次。
num[3] = '0' 。数字 3 在 num 中出现了零次。
"1210" 满足题目要求条件，所以返回 true 。
*/

class Solution {
public:
    bool digitCount(string num) {
        unordered_map<char,int> num_mp;
        for(char c : num){
            num_mp[c]++;
        }
        for(int i = 0;i<num.size();i++){
            if((num[i]-'0') != num_mp[i + '0'])
                return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
