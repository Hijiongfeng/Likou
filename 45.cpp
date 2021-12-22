#include<iostream>
#include<vector>

using namespace std;

/*
给你一个非负整数数组 nums ，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

假设你总是可以到达数组的最后一个位置。
示例 1:

输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
*/

class Solution {
public:
    int jump(vector<int>& nums) {    // 当前位置 达到了 最大的范围 还没到终点，就 +1 ；
        int curDistance = 0;
        int ans = 0;
        int nextDistance = 0;
        for(int i = 0;i<nums.size()-1;i++){   // 范围变为终点前一位；；最后一个一定能跳过去；；
            nextDistance = max(i+nums[i],nextDistance);
            if(i == curDistance){
                curDistance = nextDistance;
                ans++;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{2,3,0,1,4,5};
    Solution sol;
    cout<<sol.jump(nums)<<endl;
    system("pause");
    return 0;
}
