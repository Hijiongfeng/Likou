#include<iostream>
#include<vector>

using namespace std;

/*
给你一个整数数组 nums 。nums 中，子数组的 范围 是子数组中最大元素和最小元素的差值。

返回 nums 中 所有 子数组范围的 和 。

子数组是数组中一个连续 非空 的元素序列。

输入：nums = [1,2,3]
输出：4
解释：nums 的 6 个子数组如下所示：
[1]，范围 = 最大 - 最小 = 1 - 1 = 0 
[2]，范围 = 2 - 2 = 0
[3]，范围 = 3 - 3 = 0
[1,2]，范围 = 2 - 1 = 1
[2,3]，范围 = 3 - 2 = 1
[1,2,3]，范围 = 3 - 1 = 2
所有范围的和是 0 + 0 + 0 + 1 + 1 + 2 = 4

*/

class Solution {
private:

    int range(vector<int> & nums,int left,int right){
        if(nums.empty()) return 0;
        if(left == right) return 0;
        int max = nums[left],min = nums[right];
        for(int i = left;i<=right;i++){
            if(nums[i] > max)
                max = nums[i];
            if(nums[i] < min)
                min = nums[i];
        }
        return max - min;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        for(int i = 0;i<nums.size();i++){
            for(int j = i+1;j<nums.size();j++){
                sum += range(nums,i,j);
            }
        }
        return sum;
    }
};

class Solution2 {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        for(int i = 0;i<nums.size();i++){
            int minN = nums[i];
            int maxN = nums[i];
            for(int j = i+1;j<nums.size();j++){
                maxN = max(maxN, nums[j]);              // 只需要比较 当前的最大值 和 下一个数 即可
                minN = min(minN, nums[j]);
                sum += (maxN - minN);
            }
        }
        return sum;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {4,-2,-3,4,1};
    Solution2 sol;
    cout<<sol.subArrayRanges(nums)<<endl;
    system("pause");
    return 0;
}
