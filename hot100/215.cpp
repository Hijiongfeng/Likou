#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

 

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5

*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int max = nums[nums.size()-1];
        for(int i = nums.size()-1;i>=0;i--){
            if(nums[i] <= max){
                max = nums[i];
                k--;
            }
            if(k == 0)
                return max;
                
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    Solution sol;
    cout<<sol.findKthLargest(nums,k)<<endl;
    return 0;
}
