#include<iostream>
#include<vector>

using namespace std;

/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> path(m,vector<int> (n,0));
        for(int i = 0;i<m;i++) path[i][0] = 1;
        for(int i = 0;i<n;i++) path[0][i] = 1;

        for(int i = 1;i<m;i++){     //  递推公式，从1,1,开始
            for(int j = 1;j<n;j++){
                path[i][j] = path[i-1][j] + path[i][j-1];
            }
        }

        return path[m-1][n-1];
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout<<sol.uniquePaths(3,7)<<endl;
    system("pause");
    return 0;
}
