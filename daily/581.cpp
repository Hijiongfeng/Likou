#include<bits/stdc++.h>

using namespace std;

/*
给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

请你找出符合题意的 最短 子数组，并输出它的长度。

示例 1：

输入：nums = [2,6,4,8,10,9,15]
输出：5
解释：你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。

把一个数组分成三部分，“左 中 右”；对一个拷贝数组进行排序
对比原来的数组 和排序后的数组 进行比较；找出左右两个边界，最终求出最后的答案；
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(is_sorted(nums.begin(),nums.end())){
            return 0;
        }
        vector<int> nums_copy = nums;
        sort(nums_copy.begin(),nums_copy.end());    //  跟排序后的 进行比较
        int left = 0,right = nums.size() -1;
        for(int i = 0;i<nums.size();i++){           //  找出左右两个边界
            if(nums[i] != nums_copy[i]){
                left = i;
                break;
            }
        }

        for(int j = nums.size() -1;j>=0;j--){
            if(nums[j] != nums_copy[j]){
                right = j;
                break;
            }
        }

        return right - left + 1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {2};
    Solution sol;
    cout<<sol.findUnsortedSubarray(nums)<<endl;
    system("pause");
    return 0;
}
