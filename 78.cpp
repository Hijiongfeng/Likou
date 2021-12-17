#include<iostream>
#include<vector>

using namespace std;

/*
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums,int startindex){
        if(path.size() <= nums.size()){
            res.push_back(path);   
        }else{
            return;
        }
        for(int i=startindex;i<nums.size();i++){
            path.push_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0) return res;
        //res.push_back(path);
        backtracking(nums,0);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{1,2,3};
    Solution sol;
    vector<vector<int>> final = sol.subsets(nums);
    for(auto& x:final){
        for(auto& y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    } 
    system("pause");
    return 0;
}
