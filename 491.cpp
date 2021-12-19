#include<iostream>
#include<vector>

using namespace std;

/*
给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。

数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
输入：nums = [4,6,7,7]
输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]

输入：nums = [4,4,3,2,1]   不能进行排序
输出：[[4,4]]
*/

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums,int startIndex,vector<bool> used){
        if(path.size() >= 2 && path.size() <= nums.size()){
            res.push_back(path);
        }
        for(int i=startIndex;i<nums.size();i++){
            if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false){
                continue;
            }
            if(i > 0 && nums[i] < nums[i-1]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums,i+1,used);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if(nums.size() == 0) return res;
        vector<bool> used(nums.size(),false);
        backtracking(nums,0,used);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num{4,4,3,2,1};
    Solution sol;
    vector<vector<int>> final = sol.findSubsequences(num);
    for(auto& x:final){
        for(auto& y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    } 
    system("pause");
    return 0;
}
