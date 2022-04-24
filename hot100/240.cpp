#include<bits/stdc++.h>

using namespace std;

/**
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。

 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {    // 右上角开始查找
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0,col = n-1;
        while(row < m && col >= 0){
            if(matrix[row][col] == target){
                return true;
            }else if(matrix[row][col] > target){
                col--;
            }else{
                row++;
            }
        }
        return false;
    }

    bool searchMatrix2(vector<vector<int>>& matrix, int target) {    // 二分查找
    //lower_bound() 函数用于在指定区域内查找不小于目标值的第一个元素。 底层的实现是二分查找
        for(const auto& row : matrix){
            auto it  = lower_bound(row.begin(),row.end(),target);
            if(it != row.end() && *it == target){
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{1,4,7,11,15},
                                  {2,5,8,12,19},
                                  {3,6,9,16,22},
                                  {10,13,14,17,24},
                                  {18,21,23,26,30}};
    int target = 33;
    Solution sol;
    cout<<sol.searchMatrix(matrix,target)<<endl;
    system("pause");
    return 0;
}
