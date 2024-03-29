#include<iostream>
#include<vector>

using namespace std;

/*给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
*/
/*快慢双指针  一般判断不等于*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for(int fast = 0;fast<nums.size();fast++){
            if(nums[fast]!=val){
                nums[slow]=nums[fast];
                slow++;
            }
        }
        return slow;
    }
};

int main(int argc, const char** argv) {
    vector<int> nums = {3,2,2,3};
    int target = 3;
    Solution sol;
    cout<<sol.removeElement(nums,target)<<endl;
    for(auto x:nums){
        cout<<x<<endl;
    }
    system("pause");
    return 0;
}