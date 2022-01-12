#include<iostream>
#include<vector>

using namespace std;

/*
给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，
那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。
示例 1：

输入：nums = [1,3,5,4,7]
输出：3
解释：最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。 
*/

class Solution {            // 动态规划解法
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(),1);  //dp[i]：以下标i为结尾的数组的连续递增的子序列长度为dp[i]。
        int result = 0;
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i+1] > nums[i]){        // 如果下一个大于上一个数字，就在下一个序列上加一
                dp[i+1] = dp[i]+1;
            }
            if(dp[i+1] > result) result = dp[i+1];
        }
        return result;
    }
};

class Solution2 {            // 贪心算法
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int result = 0;
        int count = 1;
        for(int i = 0;i<nums.size()-1;i++){     // 遇到上升的就加一，，并且把最大的保存下来。
            if(nums[i+1]>nums[i]) count++;
            else count = 1;
            if(count > result) result = count;
        }
        return result;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums{1,3,5,4,7};
    Solution2 sol;
    cout<<sol.findLengthOfLCIS(nums)<<endl;
    system("pause");
    return 0;
}
