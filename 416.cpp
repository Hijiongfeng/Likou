#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

/*
给你一个 只包含正整数 的 非空 数组 nums 。
请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
示例 1：

输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        sum = accumulate(nums.begin(),nums.end(),0);

        if(sum % 2 == 1) return false;
        int target = sum / 2;
        vector<vector<int>> dp(nums.size(),vector<int> (target+1,0));

        for(int j = nums[0];j<=target;j++){         // 初始化数组
            dp[0][j] = nums[0];
        }

        for(int i = 1;i<nums.size();i++){       //  遍历物品
            for(int j = 0;j<=target;j++){       //  遍历背包
                if(j < nums[i]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j],dp[i-1][j-nums[i]]+nums[i]);
                if(dp[i][j] == target) return true;
            }
        }
        return false;
    }

    bool canPartition2(vector<int>& nums) {         // 一维数组
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 == 1) return false;
        int target = sum / 2;

        vector<int> dp(target+1,0);

        for(int i = 0;i<nums.size();i++){
            for(int j = target;j>=nums[i];j--){
                dp[j] = max(dp[j],dp[j-nums[i]]+nums[i]);
            }
        }

        if(dp[target] == target) return true;
        else return false;
    }
};

int main(int argc, char const *argv[])
{   // 1,2,3,5
    vector<int> nums{1,5,11,5};
    Solution sol;
    cout<<sol.canPartition2(nums)<<endl;
    system("pause");
    return 0;
}
