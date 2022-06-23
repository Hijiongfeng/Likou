#include<bits/stdc++.h>

using namespace std;

/*
给定一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点，
如果这些点构成一个 回旋镖 则返回 true 。

回旋镖 定义为一组三个点，这些点 各不相同 且 不在一条直线上 。

示例 1：

输入：points = [[1,1],[2,3],[3,2]]
输出：true
*/

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        vector<int> cord1 = points[0];
        vector<int> cord2 = points[1];
        vector<int> cord3 = points[2];

        if((cord1[0] == cord2[0] && cord1[1] == cord2[1]) ||
            (cord1[0] == cord3[0] && cord1[1] == cord3[1]) ||
            (cord2[0] == cord3[0] && cord2[1] == cord3[1])){
                return false;
        }

        long diffY1 = cord2[1] - cord1[1];
        long diffX1 = cord2[0] - cord1[0];

        long diffY2 = cord3[1] - cord2[1];
        long diffX2 = cord3[0] - cord2[0];

        if(diffY1 * diffX2 == diffX1 * diffY2){
            return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> points = {{1,1},{2,3},{3,2}};
    Solution sol;
    cout<<sol.isBoomerang(points)<<endl;
    system("pause");
    return 0;
}
