#include<bits/stdc++.h>

using namespace std;

/*
给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
 

示例 1：

输入：nums = [10,5,2,6], k = 100
输出：8
解释：8 个乘积小于 100 的子数组分别为：[10]、[5]、[2],、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。
需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组。
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0){
            return 0;
        }
        int n = nums.size();
        int left = 0;
        int tem = 1;
        int ans = 0;
        for(int right = 0;right<n;right++){
            tem *= nums[right];
            while(left <= right && tem >= k){
                tem /= nums[left];
                left++;
            }
            ans += (right - left + 1);
        }
        return ans;
    }


    int numSubarrayProductLessThanK2(vector<int>& nums, int k) {        // 暴力超时
        if(k == 0){
            return 0;
        }
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            int temp = 1;
            for(int j = i;j<n;j++){
                temp *= nums[j];
                if(temp<k){
                    ans++;
                }else{
                    break;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,1,1};
    int k = 1;
    Solution sol;
    cout<<sol.numSubarrayProductLessThanK(nums,k)<<endl;
    system("pause");
    return 0;
}
