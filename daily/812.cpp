#include<bits/stdc++.h>

using namespace std;

/*
给定包含多个点的集合，从其中取三个点组成三角形，
返回能组成的最大三角形的面积。

示例:
输入: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
输出: 2
解释: 
这五个点如下图所示。组成的橙色三角形是最大的，面积为2。

已知三角形三点的坐标，求面积
行列式方法
*/

class Solution {
    double triangleArea(int x1,int y1,int x2,int y2,int x3,int y3){
        return 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maxArea = 0;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                for(int k = j+1;k<n;k++){
                    maxArea = max(maxArea,triangleArea(points[i][0],points[i][1],points[j][0],points[j][1],points[k][0],points[k][1]));
                }
            }
        }
        return maxArea;
    }
};


/*
给定由一些正数（代表长度）组成的数组 nums ，返回 由其中三个长度组成的、
面积不为零的三角形的最大周长 。如果不能形成任何面积不为零的三角形，返回 0。
示例 1：

输入：nums = [2,1,2]
输出：5
示例 2：

输入：nums = [1,2,1]
输出：0
*/

class Solution2 {
public:
    int largestPerimeter(vector<int>& nums) { // 暴力枚举
        int n = nums.size();
        int maxLength = 0;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                for(int k = j+1;k<n;k++){
                    if(nums[i] + nums[j] > nums[k] && nums[i] + nums[k] > nums[j] &&nums[j] + nums[k] > nums[i]){
                        maxLength = max(maxLength,nums[i]+nums[j]+nums[k]);
                    }
                }
            }
        }
        return maxLength;
    }

    int largestPerimeter(vector<int>& nums) { //  排序+贪心
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = n-1;i>=2;i--){
            if(nums[i-2] + nums[i-1] > nums[i]){
                return nums[i] + nums[i-1] + nums[i-2];
            }
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    // vector<vector<int>> points = {{0,0},{0,2},{0,2}};
    // Solution sol;
    // cout<<sol.largestTriangleArea(points)<<endl;
    vector<int> nums = {2,1,2};
    Solution2 sol;
    cout<<sol.largestPerimeter(nums)<<endl;
    system("pause");
    return 0;
}
