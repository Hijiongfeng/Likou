#include<iostream>
#include<vector>

using namespace std;

/*
给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
示例：

输入：
A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出：3
解释：
长度最长的公共子数组是 [3, 2, 1] 。
*/
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1,vector<int> (nums2.size()+1,0));
        int result = 0;
        for(int i = 1;i<=nums1.size();i++){
            for(int j = 1;j<=nums2.size();j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }

                if(dp[i][j] > result) result = dp[i][j];
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1{1,2,3,2,1};
    vector<int> nums2{3,2,1,4,7};
    Solution sol;
    cout<<sol.findLength(nums1,nums2)<<endl;
    system ("pause");
    return 0;
}
