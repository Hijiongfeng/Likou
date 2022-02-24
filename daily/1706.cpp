#include<iostream>
#include<vector>

using namespace std;

/*
用一个大小为 m x n 的二维网格 grid 表示一个箱子。你有 n 颗球。箱子的顶部和底部都是开着的。

箱子中的每个单元格都有一个对角线挡板，跨过单元格的两个角，可以将球导向左侧或者右侧。

将球导向右侧的挡板跨过左上角和右下角，在网格中用 1 表示。
将球导向左侧的挡板跨过右上角和左下角，在网格中用 -1 表示。
在箱子每一列的顶端各放一颗球。每颗球都可能卡在箱子里或从底部掉出来。
如果球恰好卡在两块挡板之间的 "V" 形图案，或者被一块挡导向到箱子的任意一侧边上，就会卡住。

返回一个大小为 n 的数组 answer ，其中 answer[i] 是球放在顶部的第 i 列后
从底部掉出来的那一列对应的下标，如果球卡在盒子里，则返回 -1 。

思路：思路

我们依次判断每个球的最终位置。对于每个球，从上至下判断球位置的移动方向。
在对应的位置，如果挡板向右偏，则球会往右移动；如果挡板往左偏，则球会往左移动。
若移动过程中碰到侧边或者 \text{V}V 型，则球会停止移动，卡在箱子里。
如果可以完成本层的移动，则继续判断下一层的移动方向，直到落出箱子或者卡住。
*/

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> res;
        for(int i = 0;i<n;i++){
            int ans = i;
            for(auto & vec : grid){
                if(ans == 0){               // 判断是否 卡左边界
                    if(vec[0] == -1){
                        res.push_back(-1);
                        break;
                    }
                }
                if(ans < n-1 && vec[ans] == 1 && vec[ans+1] == -1){     // 是否形成 V 型
                    res.push_back(-1);
                    break;
                }
                if(ans > 0 && vec[ans] == -1 && vec[ans-1] == 1){       // 是否形成 V 型
                    res.push_back(-1);
                    break;
                }
                if(ans == n-1 && vec[ans] == 1){    // 判断是否卡 右边界
                    res.push_back(-1);
                    break;
                }
                if(vec[ans] == 1){                  // 上面那些都不满足 才能 +1，或者 -1.
                    ans++;
                }
                if(vec[ans] == -1){
                    ans--;
                }
            }
            res.push_back(ans);
            res.resize(i+1);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {{1,1,1,-1,-1},
                                {1,1,1,-1,-1},
                                {-1,-1,-1,1,1},
                                {1,1,1,1,-1},
                                {-1,-1,-1,-1,-1}};
    // vector<vector<int>> grid = {{1,1,1,1,1,1},
    //                             {-1,-1,-1,-1,-1,-1},
    //                             {1,1,1,1,1,1},
    //                             {-1,-1,-1,-1,-1,-1}};
    //vector<vector<int>> grid = {{-1}};
    Solution sol;
    vector<int> vec;
    vec = sol.findBall(grid);
    for(auto & c:vec){
        cout<<c<<endl;
    }
    system("pause");
    return 0;
}
