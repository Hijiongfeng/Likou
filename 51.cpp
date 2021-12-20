#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
*/

class Solution {
private:
    vector<vector<string>> res;
    bool isValid(int row,int col,vector<string>& chessboard,int n){
        int count = 0;
            // 检测列 当前位置的 同一列 是否有皇后
        for(int i = 0;i < row;i++){
            if(chessboard[i][col] == 'Q'){
                return false;
            }
        }
            // 检查 45 度是否有；；当前位置的 45 °
        for(int i = row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(chessboard[i][j] == 'Q'){
                return false;
            }
        }
            // 检查 135度角是否有皇后
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void backtracking(int n,int row,vector<string>& chessboard){  // n 为棋盘的大小，row 代表遍历到多少行。
        if(row == n){
            res.push_back(chessboard);
            return;
        }
        for(int col = 0;col<n;col++){
            if(isValid(row,col,chessboard,n)){
                chessboard[row][col] = 'Q';
                backtracking(n,row+1,chessboard);
                chessboard[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n,string(n,'.'));
        backtracking(n,0,chessboard);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<string>> final = sol.solveNQueens(4);
    for(auto& x:final){
        for(auto& y:x){
            cout<<y<<endl;
        }
        cout<<endl;
    }

    system("pause");
    return 0;
}
