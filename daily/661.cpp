#include<iostream>
#include<vector>

using namespace std;

/*
图像平滑器 是大小为 3 x 3 的过滤器，用于对图像的每个单元格平滑处理，
平滑处理后单元格的值为该单元格的平均灰度。

每个单元格的  平均灰度 定义为：该单元格自身及其周围的 8 个单元格的平均值，
结果需向下取整。（即，需要计算蓝色平滑器中 9 个单元格的平均值）。

如果一个单元格周围存在单元格缺失的情况，则计算平均灰度时不考虑缺失的单元格
（即，需要计算红色平滑器中 4 个单元格的平均值）。
*/

/*
思路和算法

按照题目的要求，我们直接依次计算每一个位置平滑处理后的结果即可。

具体地，对于位置 (i,j)(i,j)，我们枚举其周围的九个单元是否存在，
对于存在的单元格，我们统计其数量 \textit{num}num 与总和 \textit{sum}sum，
那么该位置平滑处理后的结果即为 \Big\lfloor\dfrac{\textit{sum}}{\textit{num}}\Big\rfloor⌊ 
num
sum
​
 ⌋。
*/

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(m,vector<int> (n,0));

        if(m >= 3 && n >= 3){
            for(int i = 1;i<m-1;i++){
                for(int j = 1;j<n-1;j++){
                    int sum = img[i-1][j-1] + img[i-1][j] + img[i-1][j+1]
                            + img[i][j-1] + img[i][j] + img[i][j+1]
                            + img[i+1][j-1] + img[i+1][j] + img[i+1][j+1];
                    ans[i][j] = sum / 9;
                }
            }
        }

        if(m >=2 && n >= 3){
            for(int j = 1;j<n-1;j++){
                int sum = img[0][j-1] + img[0][j] + img[0][j+1]
                        + img[1][j-1] + img[1][j] + img[1][j+1];
                ans[0][j] = sum / 6;
            }
        }

        if(m >=2 && n >= 3){
            for(int j = 1;j<n-1;j++){
                int sum = img[m-1][j-1] + img[m-1][j] + img[m-1][j+1]
                        + img[m-2][j-1] + img[m-2][j] + img[m-2][j+1];
                ans[m-1][j] = sum / 6;
            }
        }

        if(m >=3 && n >= 2){
            for(int i = 1;i<m-1;i++){
                int sum = img[i-1][0] + img[i][0] + img[i+1][0]
                        + img[i-1][1] + img[i][1] + img[i+1][1];
                ans[i][0] = sum / 6;
            }
        }

        if(m >=3 && n >= 2){
            for(int i = 1;i<m-1;i++){
                int sum = img[i-1][n-1] + img[i][n-1] + img[i+1][n-1]
                        + img[i-1][n-2] + img[i][n-2] + img[i+1][n-2];
                ans[i][n-1] = sum / 6;
            }
        }

        if(m >= 2 && n >= 2){
            int sum1 = img[0][0] +  img[0][1] + img[1][0] + img[1][1];
            int sum2 = img[0][n-1] +  img[0][n-2] + img[1][n-1] + img[1][n-2];
            int sum3 = img[m-2][0] +  img[m-2][1] + img[m-1][0] + img[m-1][1];
            int sum4 = img[m-2][n-2] +  img[m-2][n-1] + img[m-1][n-2] + img[m-1][n-1];

            ans[0][0] = sum1 / 4;
            ans[0][n-1] = sum2 / 4;
            ans[m-1][0] = sum3 / 4;
            ans[m-1][n-1] = sum4 / 4;
        }

        if(m == 1 && n >=2){
            ans[0][0] = (img[0][0] + img[0][1]) / 2;
            ans[0][n-1] = (img[0][n-1] + img[0][n-2]) / 2;
            if(n >= 3){
                for(int j = 1;j<n-1;j++){
                    int sum = img[0][j-1] + img[0][j] + img[0][j+1];
                    ans[0][j] = sum / 3;
                }
            }
        }

        if(n == 1 && m >= 2){
            ans[0][0] = (img[0][0] + img[1][0]) / 2;
            ans[m-1][0] = (img[m-1][0] + img[m-2][0]) / 2;
            if(m >= 3){
                for(int i = 1;i<m-1;i++){
                    int sum = img[i-1][0] + img[i][0] + img[i+1][0];
                    ans[i][0] = sum / 3;
                }
            }
        }

        if(m == 1 && n == 1) return img;

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    //vector<vector<int>> img = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> img = {{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16}};
    Solution sol;
    vector<vector<int>> ans = sol.imageSmoother(img);
    for(auto & a:ans){
        for(auto & b:a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}
