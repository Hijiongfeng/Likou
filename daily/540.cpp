#include<iostream>
#include<vector>

using namespace std;

/*
给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。

请你找出并返回只出现一次的那个数。

你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        for(int i = 0;i<nums.size()-1;i+=2){
            if(nums[i] != nums[i+1]) return nums[i];    // 返回中间元素
        }
        return nums[nums.size()-1];     // 返回最后一个元素
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {3,3,7,7,10,11,11};
    Solution sol;
    cout<<sol.singleNonDuplicate(nums)<<endl;
    system("pause");
    return 0;
}
