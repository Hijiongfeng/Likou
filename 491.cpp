#include<iostream>
#include<vector>
#include<unordered_set>

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
            if(i > 0 && nums[i] < nums[i-1]) continue;    // 这种去重方法 不行呀
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

// 上面写的 去重逻辑 主要针对排序后的数组，i和i-1的比较；
// 然而不排序 之后 好像就行不同了；

class Solution2 {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums,int startIndex){
        if(path.size() > 1){
            res.push_back(path);
        }
        unordered_set<int> uset;
        for(int i=startIndex;i<nums.size();i++){
            if ((!path.empty() && nums[i] < path.back())
            || uset.find(nums[i]) != uset.end()) {
            continue;
            }
            uset.insert(nums[i]); // 记录这个元素在本层用过了，本层后面不能再用了
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if(nums.size() == 0) return res;
        backtracking(nums,0);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num{1,2,3,4,5,6,7,8,9,10,1,1,1,1,1};
    Solution2 sol;
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
