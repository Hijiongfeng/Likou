#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。
示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {    // 暴力解法
        if(nums.size() == 1) return nums[0];
        int max = INT_MIN;
        int count = 0;
        for(int i = 0;i<nums.size();i++){
            count = 0;
            for(int j = i;j<nums.size();j++){
                count+=nums[j];
                max = count>max ? count:max; 
            }
        }
        return max;
    }
};


class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int max = INT_MIN;
        int count = 0;
        for(int i = 0;i<nums.size();i++){
            count+=nums[i];
            if(count>max){
                max = count;
            }
            if(count < 0) count = 0;    // 变成负数 之后 下一个从0开始累加；；
        }
        return max;
    }
};



int main(int argc, char const *argv[])
{
    vector<int> nums{5,4,-1,7,8};
    Solution2 sol;
    cout<<sol.maxSubArray(nums)<<endl;
    system("pause");
    return 0;
}
