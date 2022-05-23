#include<bits/stdc++.h>

using namespace std;

/*
给你一个下标从 0 开始的二进制字符串 s 和两个整数 minJump 和 maxJump 。
一开始，你在下标 0 处，且该位置的值一定为 '0' 。当同时满足如下条件时，
你可以从下标 i 移动到下标 j 处：

i + minJump <= j <= min(i + maxJump, s.length - 1) 且
s[j] == '0'.
如果你可以到达 s 的下标 s.length - 1 处，请你返回 true ，否则返回 false 。

示例 1：

输入：s = "011010", minJump = 2, maxJump = 3
输出：true
解释：
第一步，从下标 0 移动到下标 3 。
第二步，从下标 3 移动到下标 5
*/


class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {     // 把能跳到的地方赋值为2
        int start = 0;
        int n = s.size(),vis = 0;
        if(s[n-1] != '0') return false;
        s[0] = '2';
        for(int i = 0;i<n;i++){
            if(s[i] == '2'){
                for(int j = max(vis-i,minJump);j<=maxJump;j++){     // 更新能到达的区域
                    int p = i+j;
                    if(p >= n) break;
                    if(s[p] == '0') s[p] = '2';
                }
                vis = i+maxJump;
                if(s[n-1] == '2') return true;
            }
        }
        return s[n-1] == '2';
    }
};

int main(int argc, char const *argv[])
{
    string s = "0000000000";
    int minJump = 2,maxJump = 5;
    Solution sol;
    cout<<sol.canReach(s,minJump,maxJump)<<endl;
    system("pause");
    return 0;
}
