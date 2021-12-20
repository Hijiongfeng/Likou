#include<iostream>
#include<vector>

using namespace std;
/*
编写一个程序，通过填充空格来解决数独问题。

数独的解法需 遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。

*/

class Solution {
private:
    bool isValid(int row,int col,char val,vector<vector<char>>& board){
        /*判断棋盘是否合法有如下三个维度：
            同行是否重复
            同列是否重复
            9宫格里是否重复*/
        for(int i = 0;i<9;i++){
            if(board[row][i] == val){
                return false;
            }
        }
        for(int i = 0;i<9;i++){
            if(board[i][col] == val){
                return false;
            }
        }
        int startRow = (row / 3) * 3;    // 计算每个格子 起始点的行号和列号；
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) { // 判断9方格里是否重复
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == val ) {
                    return false;
                }
            }
        }
        return true;
    }

    bool backtracking(vector<vector<char>>& board){   // 解数组 是一个 二维搜索
        for(int i =0;i<board.size();i++){           // 行
            for(int j =0;j<board[0].size();j++){    // 列
                if(board[i][j] != '.') continue;        // 已经有数字 跳过
                for(char k = '1';k<='9';k++){           //  看一下是否能填入 1-9；
                    if(isValid(i,j,k,board)){
                        board[i][j] = k;
                        if(backtracking(board)) return true;
                        board[i][j] ='.';
                    }
                }
                return false;   // 9 个数都试完了  还没找到结果  返回 false
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> board{{'5','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}};

    vector<vector<int>> num{{2,2},{2,2}}; // 二维数组的 初始化
    Solution sol;
    sol.solveSudoku(board);

    for(auto& x:board){
        for(auto& y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

    system("pause");
    return 0;
}
