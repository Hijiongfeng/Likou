#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

/*
给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。

题目数据保证答案符合 32 位整数范围。

排列总和
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,0);
        dp[0] = 1;
                    // 求排列
        for(int i = 0;i<=target;i++){
            for(int j = 0;j<nums.size();j++){
                if(i >= nums[j]){
                    dp[i] += dp[i-nums[j]];
                } 
            }
        }
        return dp[target];
    }
};

class Solution2 {            // 试一试回溯法

private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums,int target,vector<bool>& used){
        if(accumulate(path.begin(),path.end(),0) == target){
            res.push_back(path);
            return;
        }
        if(accumulate(path.begin(),path.end(),0) > target){
            return;
        }

        for(int i = 0;i<nums.size();i++){
            if(i > 0 && nums[i] == nums[-1] ) continue;
            //if(used[i] == true) continue;
            path.push_back(nums[i]);
           // used[i] = true;
            backtracking(nums,target,used);
           // used[i] = false;
            path.pop_back();
        }
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<bool> used(nums.size(),false);   
        sort(nums.begin(),nums.end());          // 要进行排序
        backtracking(nums,target,used);
        return res.size();
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111};
    int target = 999;
    Solution2 sol;
    cout<<sol.combinationSum4(nums,target)<<endl;
    system("pause");
    return 0;
}
