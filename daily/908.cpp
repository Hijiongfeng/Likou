#include<bits/stdc++.h>

using namespace std;

/*
给你一个整数数组 nums，和一个整数 k 。

在一个操作中，您可以选择 0 <= i < nums.length 的任何索引 i 。将
 nums[i] 改为 nums[i] + x ，其中 x 是一个范围为 [-k, k] 的整数。对于每个索引 i ，
 最多 只能 应用 一次 此操作。

nums 的 分数 是 nums 中最大和最小元素的差值。 

在对  nums 中的每个索引最多应用一次上述操作后，返回 nums 的最低 分数 。

示例 1：

输入：nums = [1], k = 0
输出：0
解释：分数是 max(nums) - min(nums) = 1 - 1 = 0。
*/

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minNum = *min_element(nums.begin(),nums.end());
        int maxNum = *max_element(nums.begin(),nums.end());
        if(minNum == maxNum){
            return 0;
        }else if(maxNum - minNum >= 2* abs(k)){
            return maxNum - minNum - 2* abs(k);
        }else{
            return 0;
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
