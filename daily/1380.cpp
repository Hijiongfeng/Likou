#include<iostream>
#include<vector>

using namespace std;
/*
给你一个 m * n 的矩阵，矩阵中的数字 各不相同 。请你按 任意 顺序返回矩阵中的所有幸运数。

幸运数是指矩阵中满足同时下列两个条件的元素：

在同一行的所有元素中最小
在同一列的所有元素中最大

思路：遍历整个数组，模拟一下, 判断一个数字 是否为 此行的最小值，此列的最大值
*/

class Solution {
private:
    bool isLucky(int row,int col,vector<vector<int>>& matrix){
        int target = matrix[row][col];
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0;i<n;i++){         // 这一行
            if(matrix[row][i] < target) return false;
        }

        for(int i = 0;i<m;i++){
            if(matrix[i][col] > target) return false;
        }
        return true;
    }
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> vec;
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(isLucky(i,j,matrix)){
                    vec.push_back(matrix[i][j]);
                }
            }
        }
        return vec;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix{{3,7,8},{9,11,13},{15,16,17}};
    Solution sol;
    vector<int> vec = sol.luckyNumbers(matrix);
    system("pause");
    return 0;
}
