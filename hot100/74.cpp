#include<bits/stdc++.h>

using namespace std;

/*
74. 搜索二维矩阵
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {    // 右上角向下搜索
        int row = 0,col = matrix[0].size() -1;
        while(matrix[row][col] < target){
            row++;
            if(row == matrix.size()){
                return false;
            }
        }

        for(int j = col;j>=0;j--){
            if(matrix[row][j] == target){
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 70;
    Solution sol;
    cout<<sol.searchMatrix(matrix,target)<<endl;
    system("pause");
    return 0;
}
