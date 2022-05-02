#include<bits/stdc++.h>

using namespace std;

/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。

示例 1:

输入: nums = [1,3,5,6], target = 5
输出: 2

满足时间复杂度就使用二分查找
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {   // 标准二分查找
        int left = 0,right = nums.size();
        while(left < right){
            int middle = left + (right - left) / 2;
            if(nums[middle] == target){
                return middle;
            }else if(nums[middle] > target){
                right = middle;
            }else{
                left = middle+1;
            }
        }
        return left;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {1,3,5,6};
    int target = 5;
    Solution sol;
    cout<<sol.searchInsert(nums,target)<<endl;
    system("pause");
    return 0;
}
