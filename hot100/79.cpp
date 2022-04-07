#include<iostream>
#include<vector>

using namespace std;

/*
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。
如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，
其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
*/
/*
回溯法
*/
class Solution {
private:
    int fx[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    bool check(vector<vector<char>>& board,vector<vector<bool>>& visited,int i,int j,string & s,int k){
        if(board[i][j] != s[k]){
            return false;
        }else if(k == s.size() -1){
            return true;
        }

        visited[i][j] = true;
        bool result = false;
        for(int kk = 0;kk<4;kk++){
            int newi = i+fx[kk][0];
            int newj = j+fx[kk][1];
            if(newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()){
                if(visited[newi][newj] == false){
                    bool flag = check(board,visited,newi,newj,s,k+1);
                    if(flag){
                        result = true;
                        break;
                    }  
                }
            }
        }
        visited[i][j] = false;
        return result;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<bool>> visited(h, vector<bool>(w));
        for(int i = 0;i<h;i++){
            for(int j = 0;j<w;j++){
                bool flag = check(board,visited,i,j,word,0);
                if(flag)
                    return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {{'A','B','C','E'},
                                  {'S','F','C','S'},
                                  {'A','D','E','E'}};
    string word = "SEE";
    Solution sol;
    cout<<sol.exist(board,word)<<endl;
    system("pause");
    return 0;
}
