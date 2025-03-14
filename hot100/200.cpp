/*

https://leetcode.cn/problems/number-of-islands/solutions/211211/dao-yu-lei-wen-ti-de-tong-yong-jie-fa-dfs-bian-li-

给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。


示例 1：

输入：grid = [
  ["1','1','1','1','0"],
  ["1','1','0','1','0"],
  ["1','1','0','0','0"],
  ["0','0','0','0','0"]
]
输出：1
*/

#include<bits/stdc++.h>

using namespace std;
class Solution {

    int f[4][2] = {{0,1},{1,0},{0,-1}, {-1,0}};
    void dfs(int i, int j, vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size(); 

        if(i >=m || i <0 || j >=n || j <0) return;
        if( grid[i][j] != '1') return;
        
        grid[i][j] = '2';                               // 遍历过的格子变成2

        for(int k = 0;k <4;k++){
            dfs(i+f[k][0], j+f[k][1], grid);
        }
    }

    public:
        int numIslands(vector<vector<char>>& grid) {
            
            int m = grid.size();
            int n = grid[0].size();
            int ans = 0;

            for(int i = 0;i < m; i++){
                for(int j = 0;j < n; j++){
                    if(grid[i][j] == '1'){
                        ans++;
                        dfs(i, j, grid);
                    }
                }
            }
            return ans;
        }
    };


int main(){



    vector<vector<char>> grid = {{'1','1','1','1','0'},
                                {'1','1','0','1','0'},
                                {'1','1','0','0','0'},
                                {'0','0','0','0','0'}};
    
    Solution sol;
    cout << sol.numIslands(grid) << endl;                            

    return 0;
}