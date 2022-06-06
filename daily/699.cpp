#include<bits/stdc++.h>

using namespace std;

/*
在二维平面上的 x 轴上，放置着一些方块。

给你一个二维整数数组 positions ，其中 positions[i] = [lefti, sideLengthi] 表示：
第 i 个方块边长为 sideLengthi ，其左侧边与 x 轴上坐标点 lefti 对齐。

每个方块都从一个比目前所有的落地方块更高的高度掉落而下。
方块沿 y 轴负方向下落，直到着陆到 另一个正方形的顶边 或者是 x 轴上 。
一个方块仅仅是擦过另一个方块的左侧边或右侧边不算着陆。一旦着陆，它就会固定在原地，无法移动。

在每个方块掉落后，你必须记录目前所有已经落稳的 方块堆叠的最高高度 。

返回一个整数数组 ans ，其中 ans[i] 表示在第 i 块方块掉落后堆叠的最高高度。
*/

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) { // 暴力枚举
        int n = positions.size();
        vector<int> height(n);
        for(int i = 0;i<n;i++){
            int left1 = positions[i][0],right1 = positions[i][0] + positions[i][1]-1;
            height[i] = positions[i][1];
            for(int j = 0;j<i;j++){
                int left2 = positions[j][0],right2 = positions[j][0] + positions[j][1]-1;
                if(right1 >= left2 && right2 >= left1){
                    height[i] = max(height[i] , height[j] + positions[i][1]);
                }
            }
        }
        for(int i = 1;i<n;i++){
            height[i] = max(height[i],height[i-1]);
        }
        return height;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> positions = {{1,2},{2,3},{6,1}};
    Solution sol;
    vector<int> ans = sol.fallingSquares(positions);
    system("pause");
    return 0;
}
