#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * @brief 
 * 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。 
输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
 */
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums,int startIndex,vector<bool> used){
        if(path.size() <= nums.size()){
            res.push_back(path);
        }else{
            return;
        }
        for(int i=startIndex;i<nums.size();i++){
            if(i>0 && nums[i] == nums[i-1] && used[i-1] == false) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums,i+1,used);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.size() == 0) return res;
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end());   // 去重需要排序
        backtracking(nums,0,used);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{1,2,2};
    Solution sol;
    vector<vector<int>> final = sol.subsetsWithDup(nums);
    for(auto& x:final){
        for(auto& y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    } 
    system("pause");
    return 0;
}
