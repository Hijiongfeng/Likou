#include<bits/stdc++.h>

using namespace std;

/*
给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans(1,vector<int>(1,1));
        if(rowIndex == 0) return ans[0];
        if(rowIndex >= 1){
            vector<int> temp(2,1);
            ans.emplace_back(temp);
        }
        for(int i = 2;i<=rowIndex;i++){
            vector<int> temp_cur(i+1,1);                      // 当前行
            vector<int> temp_pre = ans[i-1];                // 前一行
            for(int j = 1;j<temp_cur.size() -1;j++){
                temp_cur[j] = temp_pre[j-1] + temp_pre[j];  // 模拟
            }
            ans.emplace_back(temp_cur);
        }
        return ans[rowIndex];
    }
};

int main(int argc, char const *argv[])
{
    int n = 33;
    Solution sol;
    vector<int> ans = sol.getRow(n);
    
    for(int b : ans){
        cout<<b<<endl;
    }

    system("pause");
    return 0;
}
