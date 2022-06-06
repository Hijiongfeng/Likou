#include<bits/stdc++.h>

using namespace std;

/*
给定一个正整数 n，返回 连续正整数满足所有数字之和为 n 的组数 。 

 

示例 1:

输入: n = 5
输出: 2
解释: 5 = 2 + 3，共有两组连续整数([5],[2,3])求和后为 5。

*/

class Solution {
public:
    int consecutiveNumbersSum(int n) {      // 暴力？？？
        int num = 1;
        for(int i = 1;2*i<n;i++){
            int j = i,temp = 0;
            while(temp != n && temp <= n){
                temp+=j;
                j++;
            }
            if(temp == n){
                num++;
            }
        }
        return num;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout<<sol.consecutiveNumbersSum(65581200)<<endl;
    system("pause");
    return 0;
}
