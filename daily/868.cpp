#include<bits/stdc++.h>

using namespace  std;

/*
给定一个正整数 n，找到并返回 n 的二进制表示中两个 相邻 1 之间的 最长距离 。
如果不存在两个相邻的 1，返回 0 。

如果只有 0 将两个 1 分隔开（可能不存在 0 ），
则认为这两个 1 彼此 相邻 。两个 1 之间的距离是它们的二进制表示中位置的绝对差。
例如，"1001" 中的两个 1 的距离为 3 。
示例 1：

输入：n = 22
输出：2
解释：22 的二进制是 "10110" 。
在 22 的二进制表示中，有三个 1，组成两对相邻的 1 。
第一对相邻的 1 中，两个 1 之间的距离为 2 。
第二对相邻的 1 中，两个 1 之间的距离为 1 。
答案取两个距离之中最大的，也就是 2 。
*/

class Solution {
public:
    int binaryGap(int n) {
        int pre = 0;
        int cur = 0;
        int gap = 0;
        for(int i = 31;i>=0;i--){
            if((n >> i) & 1 && pre == 0){
                pre = i;
            }
            if((n >> i) & 1 && pre != 0){
                cur = i;
                gap = pre - cur > gap ? pre - cur : gap;
                pre = cur;
            }
        }
        return gap;
    }
};

int main(int argc, char const *argv[])
{
    int n = 1;
    Solution sol;
    cout<<sol.binaryGap(n)<<endl;
    system("pause");
    return 0;
}
