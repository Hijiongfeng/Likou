#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
示例 1

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
*/
class Solution {
private:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> vec;
        if(intervals.size() == 0) return vec;
        sort(intervals.begin(),intervals.end(),cmp);
        bool flag = false;      // 判断最后一个区间有没有被合并
        for(int i = 1;i<intervals.size();i++){
            int start = intervals[i-1][0];      //  初始的 start 和 end
            int end = intervals[i-1][1];
            while(i<intervals.size() && intervals[i][0] <= end){
                end = max(end,intervals[i][1]);         //  修改有边界的 值
                if(i == intervals.size()-1) flag = true;
                i++;
            }
            vec.push_back({start,end});
        }
        if(flag == false){
            vec.push_back(intervals.back());
        }
        return vec;
    }

    vector<vector<int>> merge2(vector<vector<int>>& intervals){
        sort(intervals.begin(), intervals.end(),cmp);           // 自定义排序
        if(intervals.size() == 1)
            return intervals;
        int lsat_flag = false;
        vector<vector<int>> res;
        for(int i = 1; i < intervals.size();i++){
            vector<int> temp_res = intervals[i-1];
            while (i<intervals.size() && intervals[i][0]>=temp_res[0] && intervals[i][0]<=temp_res[1])
            {
                temp_res[0] = temp_res[0];
                temp_res[1] = max(intervals[i][1], temp_res[1]) ;
                if(i == intervals.size()-1) lsat_flag = true;           // 判断最后一个有没有
                i++;
            }

            res.push_back(temp_res);
        }

        if(lsat_flag == false){
            res.push_back(intervals.back());
        }
        return res;

    }
};

int main(int argc, char const *argv[])
{//{1,3},{2,6},{8,10},{15,18}
    vector<vector<int>> intervals{{1,4},{2,3}};
    Solution sol;
    vector<vector<int>> final = sol.merge2(intervals);
    for(auto x:final){
        for(auto y:x){
        cout<<y<<" ";}
        cout<<endl;
    }
    system("pause");
    return 0;
}
