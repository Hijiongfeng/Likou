#include<iostream>
#include<vector>

using namespace std;

/*
给定一个二进制数组 nums 和一个整数 k，
如果可以翻转最多 k 个 0 ，则返回 数组中连续 1 的最大个数 。

示例 1：

输入：nums = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释：[1,1,1,0,0,1,1,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。
*/
/*
代码思路：

使用 left 和 right 两个指针，分别指向滑动窗口的左右边界。
right 主动右移：right 指针每次移动一步。当 A[right] 为 0，说明滑动窗口内增加了一个 0；
leftleft 被动右移：判断此时窗口内 00 的个数，
如果超过了 KK，则 leftleft 指针被迫右移，直至窗口内的 00 的个数小于等于 KK 为止。
滑动窗口长度的最大值就是所求。

*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int cnt = 0;        // 统计0的个数 区间内小于 k 个，都可以翻转
        for(int left = 0,right = 0;right<n;right++){
            if(nums[right] == 0) cnt++;
            while(cnt > k){
                if(nums[left] == 0)
                    cnt--;
                left++;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    Solution sol;
    cout<<sol.longestOnes(nums,k)<<endl;
    system("pause");
    return 0;
}
