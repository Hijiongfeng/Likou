#include <bits/stdc++.h>

using namespace std;

/*
给你一个区间数组 intervals ，其中 intervals[i] = [starti, endi] ，且每个 starti 都 不同 。

区间 i 的 右侧区间 可以记作区间 j ，并满足 startj >= endi ，且 startj 最小化 。

返回一个由每个区间 i 的 右侧区间 的最小起始位置组成的数组。
如果某个区间 i 不存在对应的 右侧区间 ，则下标 i 处的值设为 -1 。

 
示例 1：

输入：intervals = [[1,2]]
输出：[-1]
解释：集合中只有一个区间，所以输出-1。
*/

class Solution
{

public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        map<int,int> num_mp;
        vector<int> beg(n);
        for(int i = 0;i<intervals.size();i++){
            num_mp[intervals[i][0]] = i;
            beg[i] = intervals[i][0];
        }
        sort(beg.begin(),beg.end());
        vector<int> ans;
        for(auto vec : intervals){
            int a = vec[1];
            vector<int>::iterator it = lower_bound(beg.begin(),beg.end(),a);    // 二分查找
            if(it == beg.end()){
                ans.push_back(-1);
            }else{
                ans.push_back(num_mp[*it]);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> inter = {{1, 4}, {2, 3}, {3, 4}};
    Solution sol;
    vector<int> vec = sol.findRightInterval(inter);
    system("pause");
    return 0;
}
