#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
/*
给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：

选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
重复这个过程恰好 k 次。可以多次选择同一个下标 i 。

以这种方式修改数组后，返回数组 可能的最大和 。
示例 1：

输入：nums = [4,2,3], k = 1
输出：5
解释：选择下标 1 ，nums 变为 [4,-2,3] 。
*/

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {   //  贪心算法
        sort(nums.begin(),nums.end());              // 排序  把最小的 且为负数的进行翻转
        for(int i = 0;i<nums.size();i++){           // 如果 k 依旧大于0，，则翻转最小的；；；
            if(nums[i]<=0 && k>0){
                nums[i] = -nums[i];
                k--;
            }
        }
        sort(nums.begin(),nums.end());
        while(k!=0){
            nums[0] = -nums[0];
            k--;
        }
        //return accumulate(nums.begin(),nums.end(),0);
        int result = 0;
        for(auto& x:nums) result+=x;
        return result;
    }
};

int main(int argc, char const *argv[])
{   
    vector<int> nums{2,-3,-1,5,-4};
    Solution sol;
    cout<<sol.largestSumAfterKNegations(nums,2)<<endl;
    system("pause");
    return 0;
}
