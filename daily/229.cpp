#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

/*
给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

示例 1：

输入：nums = [3,2,3]
输出：[3]
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int in = nums.size() / 3;
        int per = nums[0];
        int count = 1;
        vector<int> res;
        unordered_map<int,int> mp;
        for(int & num : nums){
            mp[num]++;
        }
        for(auto && [m,n] : mp){
            if(n > in){
                res.push_back(m);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{

    vector<int> nums = {3,2,3};
    Solution sol;
    vector<int> ans = sol.majorityElement(nums);

    system("pause");
    return 0;
}
