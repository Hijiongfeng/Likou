#include<bits/stdc++.h>

using namespace std;

/*
在 n x n 的网格 grid 中，我们放置了一些与 x，y，z 三轴对齐的 1 x 1 x 1 立方体。

每个值 v = grid[i][j] 表示 v 个正方体叠放在单元格 (i, j) 上。

现在，我们查看这些立方体在 xy 、yz 和 zx 平面上的投影。

投影 就像影子，将 三维 形体映射到一个 二维 平面上。
从顶部、前面和侧面看立方体时，我们会看到“影子”。

返回 所有三个投影的总面积 。
*/

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int up = 0,left = 0,right = 0;
        int m = grid.size(),n = grid[0].size();
        for(vector<int> & a : grid){            // 上视图
            for(int b : a){
                if(b != 0){
                    up++;
                }
            }
        }

        for(int i = 0;i<m;i++){                 // 左视图
            auto vec = grid[i];
            sort(vec.begin(),vec.end());
            left += vec[vec.size()-1];
        }

        for(int j = 0;j<n;j++){                 // 右视图
            int max = grid[0][j];

            for(int i = 0;i<m;i++){
                if(grid[i][j] > max){
                    max = grid[i][j];
                }
            }
            right += max;
        }
        return up + left + right;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {{1,2},{3,4}};
    Solution sol;
    cout<<sol.projectionArea(grid)<<endl;
    system("pause");
    return 0;
}
