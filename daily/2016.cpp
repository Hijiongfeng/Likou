#include<iostream>
#include<vector>

using namespace std;

/*
给你一个下标从 0 开始的整数数组 nums ，该数组的大小为 n ，
请你计算 nums[j] - nums[i] 能求得的 最大差值 ，其中 0 <= i < j < n 且 nums[i] < nums[j] 。

返回 最大差值 。如果不存在满足要求的 i 和 j ，返回 -1 。
*/

class Solution {            // 暴力
public:
    int maximumDifference(vector<int>& nums) {
        int val = 0;
        for(int i = 0;i<nums.size()-1;i++){
            
            for(int j = i+1;j<nums.size();j++){
                val = nums[j] - nums[i] > val ? nums[j] - nums[i] : val;
            }
        }
        return val == 0 ? -1 : val;
    }
};


class Solution2 {            // 贪心  只需要遍历 一次数组
public:
    int maximumDifference(vector<int>& nums) {
        int val = -1;
        int min = nums[0];
        for(int i = 0;i<nums.size();i++){
            if(nums[i] > min){
                val = max(val,nums[i] - min);
            }else{
                min = nums[i];
            }
        }
        return val;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {1,5,2,10};
    Solution sol;
    cout<<sol.maximumDifference(nums)<<endl;
    system("pause");
    return 0;
}
