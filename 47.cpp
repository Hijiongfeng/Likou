#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
示例 1：

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
*/

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums,vector<bool> used){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }
        for(int i = 0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1] && used[i-1] == false) continue;  // 层间去重   要排序
            if(used[i] == true) continue;      //  不取 取过的，
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums,used);
            used[i] = false;
            path.pop_back();
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() == 0) return res;
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end());
        backtracking(nums,used);
        return res;
    }
};


int main(int argc, const char** argv) {
    vector<int> num{1,1,2};
    Solution sol;
    vector<vector<int>> final = sol.permuteUnique(num);
    for(auto& x:final){
        for(auto& y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}