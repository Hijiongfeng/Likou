#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

/*
给你一个大小为 n x n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。

返回执行此操作后，grid 中最大的岛屿面积是多少？

岛屿 由一组上、下、左、右四个方向相连的 1 形成。
*/

class Solution {
private:
    int fx[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int dfs(int x,int y,vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        if(x < 0 || x >= m || y < 0 || y >= n){
            return 0;
        }
        if(grid[x][y] != 1) return 0;
        
        grid[x][y] = count;                     // 把地块变成 不同的编号
        int ans = 1;
        for(int i = 0;i<4;i++){
            ans += dfs(x+fx[i][0],y+fx[i][1],grid);
        }
        return ans;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int,int> mp;
        int maxarea = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    int area = dfs(i,j,grid);
                    mp[count] = area;               // 通过编号 访问面积
                    maxarea = max(maxarea,area);
                    count++;
                }
            }
        }

        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 0){
                    unordered_set<int> m_set;           // 用set去重，，防止加载到同一块陆地，不同陆地编号是不同的
                    for(auto &item : fx){
                        int xx = i+item[0];
                        int yy = j + item[1];
                        if(xx>=0 && xx<grid.size() && yy>=0 && yy<grid[0].size())
                        {
                            if(grid[xx][yy] != 0)
                            {
                                m_set.insert(grid[xx][yy]);     // 水 相邻有几个编号
                            }
                        }
                    }
                    int temparea = 1;
                    for(auto item : m_set){
                        temparea += mp[item];
                    }

                    maxarea = max(maxarea,temparea);
                }
            }
        }

        return maxarea;

    }
private:
    int count = 2;
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {{1, 0}, {0, 1}};
    Solution sol;
    cout<<sol.largestIsland(grid)<<endl;
    system("pause");
    return 0;
}
