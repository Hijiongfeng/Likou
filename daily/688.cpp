#include<iostream>
#include<vector>

using namespace std;

/*
骑士在棋盘上的概率  动态规划
定义：dp[i][j][k] 表示走 k 步到坐标 [i, j] 位置的概率。
*/

class Solution {    // 动态规划
private:
    vector<vector<int>> dirs = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k+1,vector<vector<double>> (n,vector<double> (n)));
        for(int step = 0;step<=k;step++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    if(step == 0){
                        dp[step][i][j] = 1;
                    }else{
                        for(auto & dir: dirs){
                            int ni = i + dir[0];
                            int nj = j + dir[1];
                            if(ni >= 0 && ni <n && nj >= 0 && nj < n){
                                dp[step][i][j] += dp[step-1][ni][nj] / 8;
                            }
                        }
                    }
                }
            }
        }

        return dp[k][row][column];
    }
};


class Solution2 {    // 暴力解法  找到每条路径，一条路径上概率相乘，不同路径上概率相加  dfs
private:
    vector<vector<int>> dirs = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
    double dfs(int n,int k,int i,int j){
        if(i < 0 || i>=n || j< 0 || j>=n){
            return 0;
        }
        if(k == 0){
            return 1;
        }
        double ans = 0;
        for(auto & dir : dirs){
            ans += dfs(n,k-1,i+dir[0],j+dir[1]) / 8;
        }
        return ans;
    }
public:
    double knightProbability(int n, int k, int row, int column) {

        return dfs(n,k,row,column);
    }
};

int main(int argc, char const *argv[])
{
    int n = 3;
    int k = 2;
    int row = 0;
    int col = 0;
    Solution2 sol;
    cout<<sol.knightProbability(n,k,row,col)<<endl;
    system("pause");
    return 0;
}
