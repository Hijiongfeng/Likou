#include<bits/stdc++.h>

using namespace std;

/*
给你一个字符串 s 和一个字符 c ，且 c 是 s 中出现过的字符。

返回一个整数数组 answer ，其中 answer.length == s.length 且 answer[i] 是 s 中从下标 i 到离它 最近 的字符 c 的 距离 。

两个下标 i 和 j 之间的 距离 为 abs(i - j) ，其中 abs 是绝对值函数。

示例 1：

输入：s = "loveleetcode", c = "e"
输出：[3,2,1,0,1,0,0,1,2,2,1,0]
解释：字符 'e' 出现在下标 3、5、6 和 11 处（下标从 0 开始计数）。
距下标 0 最近的 'e' 出现在下标 3 ，所以距离为 abs(0 - 3) = 3 。
距下标 1 最近的 'e' 出现在下标 3 ，所以距离为 abs(1 - 3) = 2 。
对于下标 4 ，出现在下标 3 和下标 5 处的 'e' 都离它最近，但距离是一样的 abs(4 - 3) == abs(4 - 5) = 1 。
距下标 8 最近的 'e' 出现在下标 6 ，所以距离为 abs(8 - 6) = 2 。
*/

class Solution {
public:
/*
暴力遍历，先把 c的位置找到，再遍历整个数组，进行逐个判断最小
*/
    vector<int> shortestToChar(string s, char c) {
        vector<int> cnt;
        for(int i = 0;i<s.size();i++){
            if(s[i] == c){
                cnt.push_back(i);
            }
        }
        vector<int> ans;
        for(int i = 0;i<s.size();i++){
            int min = INT_MAX;
            for(int j = 0;j<cnt.size();j++){
                min = (abs(i - cnt[j]) <= min) ? abs(i - cnt[j]) : min;
            }
            ans.push_back(min);
        }
        return ans;
    }
/*
左右两次遍历
第一次正向遍历，记录当前点离左侧目标字符的最近距离。

第二次逆向遍历，记录当前点离右侧目标字符的最近距离，同时取两次遍历的最小值。
*/

    vector<int> shortestToChar2(string s, char c) {
        int len = s.size();
        vector<int> res(len);

        for(int i = 0,idx = -len;i<len;i++){        // 初始的时候假设 -len的位置有字母c
            if(s[i] == c){
                idx = i;
            }
            res[i] = i - idx;
        }

        for(int i = len-1,idx = 2*len;i>=0;i--){    // 初始的时候假设 2*n的位置有字母c
            if(s[i] == c){
                idx = i;
            }
            res[i] = min(res[i],abs(i - idx));      // 两次遍历取最小的
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    string str = "loveleetcode";
    char c = 'e';
    Solution sol;
    vector<int> ans = sol.shortestToChar2(str,c);
    system("pause");
    return 0;
}
