#include<bits/stdc++.h>

using namespace std;

/*
给你一个下标从 0 开始长度为 n 的整数数组 nums 。
如果以下描述为真，那么 nums 在下标 i 处有一个 合法的分割 ：

前 i + 1 个元素的和 大于等于 剩下的 n - i - 1 个元素的和。
下标 i 的右边 至少有一个 元素，也就是说下标 i 满足 0 <= i < n - 1 。
请你返回 nums 中的 合法分割 方案数。

输入：nums = [10,4,-8,7]
输出：2
解释：
总共有 3 种不同的方案可以将 nums 分割成两个非空的部分：
- 在下标 0 处分割 nums 。那么第一部分为 [10] ，和为 10 。第二部分为 [4,-8,7] ，和为 3 。因为 10 >= 3 ，所以 i = 0 是一个合法的分割。
- 在下标 1 处分割 nums 。那么第一部分为 [10,4] ，和为 14 。第二部分为 [-8,7] ，和为 -1 。因为 14 >= -1 ，所以 i = 1 是一个合法的分割。
- 在下标 2 处分割 nums 。那么第一部分为 [10,4,-8] ，和为 6 。第二部分为 [7] ，和为 7 。因为 6 < 7 ，所以 i = 2 不是一个合法的分割。
所以 nums 中总共合法分割方案受为 2 。

*/

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {       // 前缀和
        int n = nums.size();
        vector<long long> preSum(n);
        preSum[0] = nums[0];
        for(int i = 1;i<n;i++){
            preSum[i] = preSum[i-1] + nums[i];
        }
        int ans = 0;
        for(int i = 0;i<n-1;i++){
            if(2 * preSum[i] >= preSum.back())
                ans++;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {0,0};
    Solution sol;
    cout<<sol.waysToSplitArray(nums)<<endl;
    system("puase");
    return 0;
}
