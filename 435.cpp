#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。

示例 1:
输入: [ [1,2], [2,3], [3,4], [1,3] ]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。
*/

class Solution {
private:
    static bool cmp(const vector<int>& a,const vector<int>& b){
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(),intervals.end(),cmp);
        int count = 1;          //  求最大的 不重叠的区间   
        int end = intervals[0][1];      //  分割点为 右边的值
        for(int i = 0;i<intervals.size();i++){
            if(end<=intervals[i][0]){   
                count++;
                end = intervals[i][1];
            }
        }
        return intervals.size() - count;       // 减去 不重叠的 就是 需要去掉的重叠的区间；；
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> intervals{{1,2}, {2,3}, {3,4}, {1,3}};
    Solution sol;
    cout<<sol.eraseOverlapIntervals(intervals)<<endl;
    system("pause");
    return 0;
}
