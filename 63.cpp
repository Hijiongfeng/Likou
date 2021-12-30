#include<iostream>
#include<vector>

using namespace std;

/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
*/


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> path(m,vector<int> (n,0));
        for(int i = 0;i<m;i++){
            if(obstacleGrid[i][0] == 1){        //  障碍物前面的 初始化为1，后面的都为 0；
                break;
            }
            path[i][0] = 1;
        }
        for(int i = 0;i<n;i++){
            if(obstacleGrid[0][i] == 1){
                break;
            }
            path[0][i] = 1;
        }
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                if(obstacleGrid[i][j] == 1) continue;       //  遇到障碍物，跳过
                path[i][j] = path[i-1][j] + path[i][j-1];
            }
        }
        return path[m-1][n-1];
    }
};
int main(int argc, char const *argv[])
{
    vector<vector<int>> map{{0,0,0},{0,1,0},{0,0,0}};
    Solution sol;

    cout<<sol.uniquePathsWithObstacles(map)<<endl;
    system("pause");
    return 0;
}
