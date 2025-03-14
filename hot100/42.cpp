/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，
在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 

*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        // 暴力方法 往左往右寻找
        int trap(vector<int>& height) {
            int sum = 0;
            for(int i = 0;i < height.size();i++)
            {
                if(i == 0 || i == height.size() -1 )
                {
                    continue;
                }

                int rHeight = height[i];
                int lHeight = height[i];
                for(int r = i+1;r<height.size();r++){
                    if(height[r]>rHeight) rHeight = height[r];
                }

                for(int l = i-1; l>=0;l--){
                    if(height[l]>lHeight) lHeight = height[l];
                }

                int wa = min(lHeight, rHeight) - height[i];

                if(wa>=0)
                    sum+=wa;
            }

            return sum;
        }

        // 动态规划 记录每根柱子左右两侧的最低
        //  从左往右遍历，记录左侧
        // 从右往左遍历，记录右侧
        int trap2(vector<int>& height) {
            if(height.size() <=2) return 0;

            vector<int> lHeight(height.size(), 0);
            vector<int> rHeight(height.size(), 0);
            
            for(int i = 0;i<height.size();i++){
                if(i==0){
                    lHeight[i] = height[i];
                    continue;
                }else{
                    lHeight[i] = max(height[i], lHeight[i-1]);
                } 
            }

            for(int i = height.size()-1;i>=0;i--){
                if(i==height.size()-1){
                    rHeight[i] = height[i];
                    continue;
                }else{
                    rHeight[i] = max(height[i], rHeight[i+1]);
                } 
            }

            int sum = 0;
            for(int i = 0;i < height.size();i++)
            {
                if(i == 0 || i == height.size() -1 )
                {
                    continue;
                }

                int wa = min(lHeight[i], rHeight[i]) - height[i];

                if(wa>=0)
                    sum+=wa;
            }

            return sum;
        }
    };


int main(){

    Solution sol;
    // vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height = {4,2,0,3,2,5};

    cout << sol.trap2(height) << endl;

}






