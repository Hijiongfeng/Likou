#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
给你个整数数组 arr，其中每个元素都 不相同。

请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。
示例 1：

输入：arr = [4,2,1,3]
输出：[[1,2],[2,3],[3,4]]

*/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int min = INT_MAX;
        for(int i = 1;i<arr.size();i++){
            if(arr[i] - arr[i-1] == min){
                //vector<int> {arr[i] , arr[i-1]}
                ans.emplace_back(vector<int> {arr[i-1] , arr[i]});
            }
            if(arr[i] - arr[i-1] < min){
                min = arr[i] - arr[i-1];
                ans.clear();
                ans.emplace_back(vector<int> {arr[i-1] , arr[i]});
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> arr = {4,2,1,3};
    Solution sol;
    vector<vector<int>> ans = sol.minimumAbsDifference(arr);
    system("pause");
    return 0;
}
