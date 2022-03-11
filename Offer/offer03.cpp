#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

/*
找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 

*/

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {       //数组
        sort(nums.begin(),nums.end());
        for(int i = 1;i<nums.size();i++){
            if(nums[i] == nums[i-1])
                return nums[i];
        }
        return -1;
    }
};

class Solution2 {
public:
    int findRepeatNumber(vector<int>& nums) {       // 哈希表
        unordered_set<int> st;
        for(int i = 0;i<nums.size();i++){
            if(st.find(nums[i]) != st.end())
                return nums[i];
            else
                st.insert(nums[i]);
        }
        return -1;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {2,3,1,0,2,5,3};
    Solution2 sol;
    cout<<sol.findRepeatNumber(nums)<<endl;
    system("pause");
    return 0;
}
