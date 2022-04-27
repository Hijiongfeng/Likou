#include<bits/stdc++.h>

using namespace std;

/*
有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 
“太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。

这个岛被分割成一个由若干方形单元格组成的网格。
给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c) 上单元格 高于海平面的高度 。

岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，
雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。

返回 网格坐标 result 的 2D列表 ，其中 result[i] = [ri, ci] 表示雨水可以从单元格 (ri, ci) 流向 太平洋和大西洋 。
*/

static const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

/*
雨水的流动方向是从高到低，每个单元格上的雨水只能流到高度小于等于当前单元格的相邻单元格。
从一个单元格开始，通过搜索的方法模拟雨水的流动，则可以判断雨水是否可以从该单元格流向海洋。

如果直接以每个单元格作为起点模拟雨水的流动，则会重复遍历每个单元格，导致时间复杂度过高。
为了降低时间复杂度，可以从矩阵的边界开始反向搜索寻找雨水流向边界的单元格，反向搜索时，
每次只能移动到高度相同或更大的单元格。

由于矩阵的左边界和上边界是太平洋，矩阵的右边界和下边界是大西洋，
因此从矩阵的左边界和上边界开始反向搜索即可找到雨水流向太平洋的单元格，
从矩阵的右边界和下边界开始反向搜索即可找到雨水流向大西洋的单元格。

可以使用深度优先搜索实现反向搜索，搜索过程中需要记录每个单元格是否可以
从太平洋反向到达以及是否可以从大西洋反向到达。反向搜索结束之后，遍历每个网格，
如果一个网格既可以从太平洋反向到达也可以从大西洋反向到达，
则该网格满足太平洋和大西洋都可以到达，将该网格添加到答案中。

*/

class Solution {
public:
    vector<vector<int>> heights;

    void dfs(int row, int col, vector<vector<bool>> & ocean) {
        int m = ocean.size();
        int n = ocean[0].size();
        if (ocean[row][col]) {
            return;
        }
        ocean[row][col] = true;
        for (int i = 0; i < 4; i++) {
            int newRow = row + dirs[i][0], newCol = col + dirs[i][1];
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && heights[newRow][newCol] >= heights[row][col]) {
                dfs(newRow, newCol, ocean);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // 从两边进行搜索，都为true，则可以流向两边

        for (int i = 0; i < m; i++) {       
            dfs(i, 0, pacific); 
        }
        for (int j = 1; j < n; j++) {
            dfs(0, j, pacific);
        }
        for (int i = 0; i < m; i++) {
            dfs(i, n - 1, atlantic);
        }
        for (int j = 0; j < n - 1; j++) {
            dfs(m - 1, j, atlantic);
        }
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    vector<int> cell;
                    cell.emplace_back(i);
                    cell.emplace_back(j);
                    result.emplace_back(cell);
                }
            }
        }
        return result;
    }
};

/*
方法二：广度优先搜索
反向搜索也可以使用广度优先搜索实现。
搜索过程中同样需要记录每个单元格是否可以从太平洋反向到达以及是否可以从大西洋反向到达。
反向搜索结束之后，遍历每个网格，如果一个网格既可以从太平洋反向到达也可以从大西洋反向到达，
则该网格满足太平洋和大西洋都可以到达，将该网格添加到答案中。
*/

class Solution2 {
public:
    vector<vector<int>> heights;

    void bfs(int row, int col, vector<vector<bool>> & ocean) {
        if (ocean[row][col]) {
            return;
        }
        int m = heights.size();
        int n = heights[0].size();
        ocean[row][col] = true;
        queue<pair<int, int>> qu;
        qu.emplace(row, col);
        while (!qu.empty()) {
            auto [row, col] = qu.front();
            qu.pop();
            for (int i = 0; i < 4; i++) {
                int newRow = row + dirs[i][0], newCol = col + dirs[i][1];
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && heights[newRow][newCol] >= heights[row][col] && !ocean[newRow][newCol]) {
                    ocean[newRow][newCol] = true;
                    qu.emplace(newRow, newCol);
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            bfs(i, 0, pacific);
        }
        for (int j = 1; j < n; j++) {
            bfs(0, j, pacific);
        }
        for (int i = 0; i < m; i++) {
            bfs(i, n - 1, atlantic);
        }
        for (int j = 0; j < n - 1; j++) {
            bfs(m - 1, j, atlantic);
        }
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    vector<int> cell;
                    cell.emplace_back(i);
                    cell.emplace_back(j);
                    result.emplace_back(cell);
                }
            }
        }
        return result;
    }
};


int main(int argc, char const *argv[])
{
    vector<vector<int>> heights = {{1,2,2,3,5},
                                   {3,2,3,4,4},
                                   {2,4,5,3,1},
                                   {6,7,1,4,5},
                                   {5,1,1,2,4}};
    Solution sol;
    vector<vector<int>> ans = sol.pacificAtlantic(heights);
    system("pause");
    return 0;
}
