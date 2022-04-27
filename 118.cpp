#include<bits/stdc++.h>

using namespace std;

/*
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。
示例 1:

输入: numRows = 5
输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(1,vector<int>(1,1));
        if(numRows == 1) return ans;
        if(numRows >= 2){
            vector<int> temp(2,1);
            ans.emplace_back(temp);
        }
        for(int i = 3;i<=numRows;i++){
            vector<int> temp_cur(i,1);                      // 当前行
            vector<int> temp_pre = ans[i-2];                // 前一行
            for(int j = 1;j<temp_cur.size() -1;j++){
                temp_cur[j] = temp_pre[j-1] + temp_pre[j];  // 模拟
            }
            ans.emplace_back(temp_cur);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n = 30;
    Solution sol;
    vector<vector<int>> ans = sol.generate(n);
    for(vector<int> a : ans){
        for(int b : a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}
