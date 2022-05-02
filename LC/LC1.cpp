#include<bits/stdc++.h>

using namespace std;

/*
给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

示例 1:

输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]

*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0;i<n;i++){
            nums.push_back(nums[i]);
        }
        
        int leftK = k % n;
        int gap = n - leftK;
        while(leftK--){
            nums.pop_back();
        }
        nums = vector<int>(nums.begin()+gap,nums.end());
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    Solution sol;
    sol.rotate(nums,k);
    system("pause");
    return 0;
}
