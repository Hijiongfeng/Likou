#include<iostream>
#include<vector>

using namespace std;

/*
在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数。

现在，可以绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足满足：

 nums1[i] == nums2[j]
且绘制的直线不与任何其他连线（非水平线）相交。
请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。
以这种方法绘制线条，并返回可以绘制的最大连线数。   最长公共子序列
*/

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1,vector<int> (nums2.size()+1,0));
        int result = 0;
        for(int i = 1;i<=nums1.size();i++){
            for(int j = 1;j<=nums2.size();j++){
                if(nums1[i-1]==nums2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if(dp[i][j] > result) result = dp[i][j];
            }
        }
        return result;
        // return dp[nums1.size()][nums2.size()];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1{1,4,2};
    vector<int> nums2{1,2,4};
    Solution sol;
    cout<<sol.maxUncrossedLines(nums1,nums2)<<endl;
    system("pause");
    return 0;
}
