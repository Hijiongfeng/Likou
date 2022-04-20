#include<bits/stdc++.h>

using namespace std;

/*
给你一个整数 n ，按字典序返回范围 [1, n] 内所有整数。

你必须设计一个时间复杂度为 O(n) 且使用 O(1) 额外空间的算法。

示例 1：

输入：n = 13
输出：[1,10,11,12,13,2,3,4,5,6,7,8,9]
*/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int number = 1;
        for(int i = 0;i <n;i++){
            ans.push_back(number);
            if(number * 10 <= n){
                number *= 10;
            }else{
                while(number % 10 == 9 || number + 1 > n){      // 如果到达9，或者加一 大于n，则回到上一个 起点
                    number /= 10;
                }
                number += 1;
            }
        }
        return ans;
    }

    vector<int> lexicalOrder2(int n) {
        vector<int> ans;
        set<string> str_set;                // set 对string 排序，就是字典树
        for(int i = 1;i<=n;i++){
            str_set.insert(to_string(i));
        }
        for(auto &p :str_set){
            ans.emplace_back(stoi(p));
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n = 13;
    Solution sol;
    vector<int> ans = sol.lexicalOrder2(n);
    system("pause");
    return 0;
}
