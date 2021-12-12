#include<iostream>
#include<vector>

using namespace std;
/*给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。。*/
//滑动窗口 揭发  记住 while 循环内的方法，
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int i = 0;
        int sum = 0;
        for(int j = 0;j<nums.size();j++){
            sum += nums[j];
            while(sum>=target){
                int subLength = j - i + 1;
                result = result < subLength ? result : subLength;
                sum -= nums[i];
                i++;
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,4,4};
    int target = 4;
    Solution sol;
    cout<<sol.minSubArrayLen(target,nums)<<endl;
    system("pause");  
    return 0;
}
