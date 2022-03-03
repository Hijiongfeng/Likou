#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

/*
给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，
满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。

 

示例 1：

输入：nums = [1,2,3,1], k = 3
输出：true

*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {        // 暴力
        int diff;
        for(int i = 0;i<nums.size()-1;i++){
            for(int j = i + 1;j<nums.size();j++){
                if(nums[i] == nums[j]){
                    diff = abs(i-j);
                    if(diff <= k)
                        return true;
                }
            }
        }
        return false;
    }
};

class Solution2 {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {            // 滑动窗口
        unordered_set<int> s;
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            if (i > k) {
                s.erase(nums[i - k - 1]);
            }
            if (s.count(nums[i])) {
                return true;
            }
            s.emplace(nums[i]);
        }
        return false;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,1};
    int k = 3;
    Solution2 sol;
    cout<<sol.containsNearbyDuplicate(nums,k)<<endl;
    system("pause");
    return 0;
}
