#include<iostream>
#include<vector>

using namespace std;

/*
给你一个正整数 n ，生成一个包含 1 到 n*n 所有元素，
且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int> (n,0));
        int startx = 0,starty = 0;
        int loop = n / 2;
        int mid = n / 2;
        int count = 1; // 用来给矩阵中每一个空格赋值
        int offset = 1; // 每一圈循环，需要控制每一条边遍历的长度
        int i,j;
        while(loop--){
            i = startx;
            j = starty;
            // 下面开始的四个for就是模拟转了一圈
            // 模拟填充上行从左到右(左闭右开)
            for (j = starty; j < starty + n - offset; j++) {
                matrix[startx][j] = count++;
            }
            // 模拟填充右列从上到下(左闭右开)
            for (i = startx; i < startx + n - offset; i++) {
                matrix[i][j] = count++;
            }
            // 模拟填充下行从右到左(左闭右开)
            for (; j > starty; j--) {
                matrix[i][j] = count++;
            }
            // 模拟填充左列从下到上(左闭右开)
            for (; i > startx; i--) {
                matrix[i][j] = count++;
            }

            // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
            startx++;
            starty++;

            // offset 控制每一圈里每一条边遍历的长度
            offset += 2;
        }

        if (n % 2) {
            matrix[mid][mid] = count;
        }
        return matrix;
    }
};

int main(int argc, char const *argv[])
{
    int n = 3;
    Solution sol;
    vector<vector<int>> res = sol.generateMatrix(n);
    for(auto &x:res){
        for(auto &y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    } 
    system("pause");
    return 0;
}
