/*
在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：

值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。

返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。

输入：grid = [[2,1,1],[1,1,0],[0,1,1]]
输出：4
示例 2：

输入：grid = [[2,1,1],[0,1,1],[1,0,1]]
输出：-1
解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个方向上。
示例 3：

输入：grid = [[0,2]]
输出：0
解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 


思路：  广度优先搜索 队列
二叉树层序遍历
多少层 就有多少时间

遍历 有1的 就直接返回-1， 否则就返回上面的
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
    
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            
            int m = grid.size();
            int n = grid[0].size();
            int bad = 0;
            int fresh = 0;
            int f[4][2] = {{0,1},{1,0},{0,-1}, {-1,0}};

            queue<pair<int,int>> qu;                        // bfs 使用 队列
            for(int i = 0;i< m;i++){
                for(int j = 0;j < n ;j++){
                    if(grid[i][j] == 2){                    // 坏橘子 类似于 二叉树根节点
                        qu.push({i, j});
                        bad++;
                    }else if (grid[i][j] == 1)
                    {
                        fresh++;
                    }
                }
            }

            int res = -1;
            while (!qu.empty())
            {
                int size = qu.size();                   // 类似于二叉树的节点个数
                res++;
                for (size_t i = 0; i < size; i++)
                {
                    auto node = qu.front();
                    int x = node.first;
                    int y = node.second;
                    qu.pop();
                    for (size_t k = 0; k < 4; k++)
                    {
                        int nx = x+f[k][0];
                        int ny = y+f[k][1];
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1){
                            grid[nx][ny] = 2;
                            qu.push({nx, ny});
                            fresh--;
                        }
                    }
                }
            }

            if(bad == 0 && fresh == 0) return 0;
            if(fresh) return -1;
            return res;
            
        }
    };

int main(){

    // vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    vector<vector<int>> grid = {{1,2}};

    Solution sol;
    std::cout << sol.orangesRotting(grid) << endl;                            

    return 0;
}
