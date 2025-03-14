/*

189. 轮转数组

给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。


示例 1:

输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释: 
向右轮转 1 步: [99,-1,-100,3]
向右轮转 2 步: [3,99,-1,-100]
*/

#include<bits/stdc++.h>

using namespace std;
class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int size = nums.size();
            for(int i = 0;i < size;i++){
                nums.push_back(nums[i]);
            }
            
            int n = k % size;
            int gap = size- n;

            nums = vector<int>(nums.begin()+gap,nums.begin()+gap+size);
            int a = 0;
        }
    };

int main(){

    vector<int> nums = {-1,-100,3,99};
    int k = 2;
    Solution sol;
    sol.rotate(nums, k);
    return 0;
}