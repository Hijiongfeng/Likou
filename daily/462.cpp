#include<bits/stdc++.h>

using namespace std;

/*
给你一个长度为 n 的整数数组 nums ，返回使所有数组元素相等需要的最少移动数。

在一步操作中，你可以使数组中的一个元素加 1 或者减 1 。

示例 1：

输入：nums = [1,2,3]
输出：2
解释：
只需要两步操作（每步操作指南使一个元素加 1 或减 1）：
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]

*/
//看到题目第一反应是找出中位数/平均数/出现最多的数这三种结果之一
class Solution {
public:
    int minMoves2(vector<int>& nums) {      // 中位数
        int n = nums.size();
        int avg = nums[n/2];
        int ans = 0;
        for(int a : nums){
            ans += abs(a-avg);
        }
        return ans;
    }
};

/*
给你一个长度为 n 的整数数组，每次操作将会使 n - 1 个元素增加 1 。
返回让数组所有元素相等的最小操作次数。

示例 1：

输入：nums = [1,2,3]
输出：3
解释：
只需要3次操作（注意每次操作会增加两个元素的值）：
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/
// n-1元素+1，等价于1个元素 -1 ，减到最小值就是操作的次数
class Solution2 {
public:
    int minMoves(vector<int>& nums) {
        int minNum = *min_element(nums.begin(),nums.end());
        int ans = 0;
        for(int a : nums){
            ans += abs(a - minNum);
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3};
    Solution sol;
    cout<<sol.minMoves2(nums)<<endl;
    system("pause");
    return 0;
}
