#include<iostream>
#include<vector>

using namespace std;

/*
给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans 作为答案。

示例 1：

输入：n = 2
输出：[0,1,1]
解释：
0 --> 0
1 --> 1
2 --> 10
*/

class Solution {
    int count(int& num){
        int ans = 0;
        for(int i = 31;i>=0;i--){
            if((num >> i) & 1)
                ans++;
        }
        return ans;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0;i<=n;i++){
            if(i == 0)
                ans.push_back(0);
            else
                ans.push_back(count(i));
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n = 5;
    Solution sol;
    vector<int> vec = sol.countBits(n);
    system("pause");
    return 0;
}
