#include<bits/stdc++.h>

using namespace std;

/*
给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，
用一个数组返回这个矩阵中的所有元素。
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.size() == 1)
            return mat[0];
        vector<int> res;
        int m = mat.size(),n = mat[0].size();
        int row = m-1,col = n-1;
        int N = 2 * min(m,n) - 1;
        for(int i = 0;i<=N;i++){
            if(i == 0){
                res.push_back(mat[0][0]);
                continue;
            }
            if(i % 2 != 0 && i <= col){
                int curRow = 0,curCol = i;
                while(curRow <= min(row,col)){
                    res.push_back(mat[curRow][curCol]);
                    curRow++;
                    curCol--;
                }
            }else if(i % 2 != 0 && i > col){
                int curRow = i - col,curCol = col;
                while(curRow <= min(row,col)){
                    res.push_back(mat[curRow][curCol]);
                    curRow++;
                    curCol--;
                }
            }else if(i % 2 == 0 && i <= row){
                int curRow = i,curCol = 0;
                while(curCol <= min(row,col)){
                    res.push_back(mat[curRow][curCol]);
                    curRow--;
                    curCol++;
                }
            }else if(i % 2 == 0 && i > row){
                int curRow = row,curCol = i - row;
                while(curCol <= min(row,col)){
                    res.push_back(mat[curRow][curCol]);
                    curRow--;
                    curCol++;
                }
            }
        
        }
    return res;
}
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> mat = {{1,2},{3,4},{5,6}};
    Solution sol;
    vector<int> vec = sol.findDiagonalOrder(mat);
    int a = 0;
    system("pause");
    return 0;
}
