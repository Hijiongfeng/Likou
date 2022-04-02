#include<iostream>
#include<vector>

using namespace std;

/*
给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。

示例 1：

输入：nums = [1,1,0,1,1,1]
输出：3
解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int tem = 0;
        for(int i = 0;i<nums.size();i++){
            
            if(nums[i] == 1)
                tem++;
            if(nums[i] == 0)
                tem = 0;
            ans = tem >= ans ? tem : ans;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{


    system("pause");
    return 0;
}
