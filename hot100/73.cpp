#include<bits/stdc++.h>

using namespace std;

/*
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        multimap<int,int> idx_mp; 
        int m = matrix.size(),n = matrix[0].size();
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    idx_mp.insert({i,j});
                }
            }
        }

        for(auto &[a,b] : idx_mp){
            for(int j = 0;j<n;j++){
                if(matrix[a][j] != 0){
                    matrix[a][j] = 0;
                }
            }
            for(int i = 0;i<m;i++){
                if(matrix[i][b] != 0){
                    matrix[i][b] = 0;
                }
            }
        }
    }

/*
我们可以用矩阵的第一行和第一列代替方法一中的两个标记数组，
以达到 O(1) 的额外空间。但这样会导致原数组的第一行和第一列被修改，
无法记录它们是否原本包含 0。因此我们需要额外使用两个标记变量分别记录第一行和第一列是否原本包含 0。

在实际代码中，我们首先预处理出两个标记变量，
接着使用其他行与列去处理第一行与第一列，然后反过来使用第一行与第一列去更新其他行与列，
最后使用两个标记变量更新第一行与第一列即可。
*/
    void setZeroes2(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int flag_col0 = false, flag_row0 = false;
        for (int i = 0; i < m; i++) {
            if (!matrix[i][0]) {
                flag_col0 = true;
            }
        }
        for (int j = 0; j < n; j++) {
            if (!matrix[0][j]) {
                flag_row0 = true;
            }
        }
        for (int i = 1; i < m; i++) {           // 更新第一行 第一列
            for (int j = 1; j < n; j++) {
                if (!matrix[i][j]) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (flag_col0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (flag_row0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution sol;
    sol.setZeroes(matrix);
    system("pause");
    return 0;
}
