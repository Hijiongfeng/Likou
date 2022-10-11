#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

/*
给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，
其总和都相等。

示例 1：

输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
输出： True
说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
示例 2:

输入: nums = [1,2,3,4], k = 3
输出: false
。
*/
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k > nums.size()) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) return false;

        // 从大到小放数字
        sort(nums.rbegin(), nums.rend());

        // 记录每个子集中数字之和
        bucket.resize(k); 
        // 每个桶中的数字之和应该为target
        int target = sum/k;
        // index = 0, 表示从0号元素开始遍历
        return backtrack(nums, 0, target);
    }

private:
    // 记录每个子集中数字之和
    vector<int> bucket;

    bool backtrack(vector<int> &nums, int index, int target){
        // 如果所有数字遍历完了
        if(index == nums.size()){
            // 既然所有数字都放进集合中了，那么所有bucket中的元素和一定为target。所以下面这个循环是没有必要的：
            // 检查所有子集中的数字之和是否都是target
            // for(int i = 0; i < bucket.size(); i++){
            //     if(bucket[i] != target){
            //         return false;
            //     }
            // }
            return true;
        }

        // 注意：i 表示第i个子集，index 表示第index个数字
        for(int i = 0; i < bucket.size(); i++){
            // 如果这个数字放入子集i中使子集i中元素和超出target了
            if(bucket[i] + nums[index] > target){
                continue;
            }
            // 如果 当前子集的元素和 与 前一个子集的元素和 是一样的，那就跳过
            if(i > 0 && bucket[i] == bucket[i-1]){
                continue;
            }

            // 将数字放入子集i中
            bucket[i] += nums[index];
            // 递归穷举下一个数字的情况
            if(backtrack(nums, index + 1, target)){
                return true;
            }
            // 撤销选择
            bucket[i] -= nums[index]; 
        }
        // 如果 nums[index] 放入哪个子集都不行
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    Solution sol;
    cout<<sol.canPartitionKSubsets(nums,k)<<endl;
    system("pause");
    return 0;
}
