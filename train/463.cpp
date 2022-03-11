#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*

给定一个 row x col 的二维网格地图 grid ，
其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。

网格中的格子 水平和垂直 方向相连（对角线方向不相连）。
整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。

岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。
格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。

 

示例 1：

输入：grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
输出：16
解释：它的周长是上面图片中的 16 个黄色的边
*/

/*
思路：

可以看到，dfs 函数直接返回有这几种情况：

!inArea(grid, r, c)，即坐标 (r, c) 超出了网格的范围，也就是我所说的「先污染后治理」的情况
grid[r][c] != 1，即当前格子不是岛屿格子，这又分为两种情况：
grid[r][c] == 0，当前格子是海洋格子
grid[r][c] == 2，当前格子是已遍历的陆地格子
那么这些和我们岛屿的周长有什么关系呢？实际上，岛屿的周长是计算岛屿全部的「边缘」，
而这些边缘就是我们在 DFS 遍历中，dfs 函数返回的位置。观察题目示例，
我们可以将岛屿的周长中的边分为两类，如下图所示。黄色的边是与网格边界相邻的周长，而蓝色的边是与海洋格子相邻的周长。

当我们的 dfs 函数因为「坐标 (r, c) 超出网格范围」返回的时候，实际上就经过了一条黄色的边；
而当函数因为「当前格子是海洋格子」返回的时候，实际上就经过了一条蓝色的边。
这样，我们就把岛屿的周长跟 DFS 遍历联系起来了，我们的题解代码也呼之欲出：
*/

class Solution {
private:
    int fx[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int dfs(int x,int y,vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        if(x < 0 || x >= m || y < 0 || y >= n){         // 到边界
            return 1;
        } 
        if(grid[x][y] == 0) return 1;               // 接触水
        if(grid[x][y] != 1) return 0;
        grid[x][y] = 2;
        for(int i = 0;i<4;i++){
            ans +=dfs(x+fx[i][0],y+fx[i][1],grid);
        }
        return ans;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    ans = dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {{0,1,0,0},
                                {1,1,1,0},
                                {0,1,0,0},
                                {1,1,0,0}};
    Solution sol;
    cout<<sol.islandPerimeter(grid)<<endl;
    system("pause");
    return 0;
}
