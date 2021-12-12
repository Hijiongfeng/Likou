#include<iostream>
#include<vector>

using namespace std;
/*给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

*///快慢 双指针  一般判断 不等于
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int slow = 0;
        for(int fast = 0;fast < nums.size()-1;fast++){
            if(nums[fast] != nums[fast+1]){
                slow++;
                nums[slow]=nums[fast+1];
            }
        }

        return slow+1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3};
    Solution sol;
    cout<<sol.removeDuplicates(nums)<<endl;
    system("pause");
    return 0;
}
