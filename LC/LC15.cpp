#include<bits/stdc++.h>

using namespace std;

/*
给定一个 n × n 的二维矩阵 matrix 表示一个图像。
请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。
请不要 使用另一个矩阵来旋转图像。
*/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size()-1;
        int col = matrix[0].size()-1;
        for(int i = 0;i<=row/2;i++){                // 先上下交换
            for(int j = 0;j<=col;j++){
                swap(matrix[i][j],matrix[row-i][j]);
            }
        }

        for(int i = 0;i<=row;i++){                  // 再对角线交换
            for(int j = i;j<=col;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    
    vector<vector<int>> matrix =  {{1,2,3},{4,5,6},{7,8,9}};
    Solution sol;
    sol.rotate(matrix);
    system("pause");
    return 0;
}
