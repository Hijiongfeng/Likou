#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

示例 1：

输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
*/

class Solution {
private:
    int fx[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(int x,int y,vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        if(x < 0 || x >= m || y < 0 || y >= n) return;
        if(grid[x][y] != '1') return;
        grid[x][y] = '2';
        for(int i = 0;i<4;i++){
            dfs(x+fx[i][0],y+fx[i][1],grid);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    ++ans;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> grid = {  {'1','1','1','1','0'},
                                    {'1','1','0','1','0'},
                                    {'1','1','0','0','0'},
                                    {'0','0','0','0','1'}};
    Solution sol;
    cout<<sol.numIslands(grid)<<endl;

    system("pause");
    return 0;
}
