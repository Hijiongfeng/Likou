#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

/*
给你一个大小为 m x n 的二进制矩阵 grid 。

岛屿 是由一些相邻的 1 (代表土地) 构成的组合，
这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。
你可以假设 grid 的四个边缘都被 0（代表水）包围着。

岛屿的面积是岛上值为 1 的单元格的数目。

计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0
*/
class Solution {
private:
    int fx[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

    int dfs(int x,int y,vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        if(x < 0||x >= m || y < 0 || y >= n) return 0;      // 递归 结束 的标志
        if(grid[x][y] != 1) return 0;

        grid[x][y] = 2;                 // 遍历后的陆地 ； 这个用 不同与 陆地和水 的标志 表示更好
        
        double ans = 1;                 // 初始陆地面积 为 1       这一块就 相当于 这一路的
        for(int i = 0;i<4;i++){
            ans += dfs(x+fx[i][0],y+fx[i][1],grid);
        }
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1){                // 这一块 是陆地 就进入 dfs
                    int a = dfs(i,j,grid);
                    maxArea = max(maxArea,a);
                }
            }
        }
        return maxArea;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    Solution sol;
    cout<<sol.maxAreaOfIsland(grid)<<endl;
    system("pause");
    return 0;
}
