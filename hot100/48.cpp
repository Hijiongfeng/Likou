/*
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[7,4,1],[8,5,2],[9,6,3]]
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int len = 0;
            if(n % 2 == 0){
                len = n/2;
            }else{
                len = (n+1)/2;
            }

            int row = 0;
            while (row < len)           // 上下翻转
            {
                int tar = n - row - 1;
                swap(matrix[row], matrix[tar]);
                row++;
            }

            for(int i = 0;i < n;i++){               // 对称翻转
                for(int j = i; j< n; j++){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
    };


int main(){

    // vector<vector<int>> matrix{{1,2,3}, {4,5,6}, {7,8,9}};
    vector<vector<int>> matrix{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    Solution sol;
    sol.rotate(matrix);
    return 0;
}
