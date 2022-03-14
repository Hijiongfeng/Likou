#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。
如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，
其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。
*/

class Solution {
private:
    int row, col;
    int fx[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
    bool dfs(vector<vector<char>> & board,string word,int i,int j,int k){
        if(i < 0 || i >= row || j < 0 || j >= col || board[i][j] != word[k]){
            return false;
        }
        if(k == word.size() -1) return true;
        board[i][j] = '\0';
        
        bool res = dfs(board,word,i+fx[0][0],j+fx[0][1],k+1) || dfs(board,word,i+fx[1][0],j+fx[1][1],k+1) ||
                    dfs(board,word,i+fx[2][0],j+fx[2][1],k+1) || dfs(board,word,i+fx[3][0],j+fx[3][1],k+1);

        board[i][j] = word[k];
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(dfs(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    Solution sol;
    cout<<sol.exist(board,word)<<endl;
    system("pause");
    return 0;
}
