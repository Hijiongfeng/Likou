#include<bits/stdc++.h>

using namespace std;

/*
给你由 n 个小写字母字符串组成的数组 strs，其中每个字符串长度相等。

这些字符串可以每个一行，排成一个网格。例如，strs = ["abc", "bce", "cae"] 可以排列为：

abc
bce
cae
你需要找出并删除 不是按字典序升序排列的 列。
在上面的例子（下标从 0 开始）中，列 0（'a', 'b', 'c'）和列 2（'c', 'e', 'e'）都是按升序排列的，
而列 1（'b', 'c', 'a'）不是，所以要删除列 1 。

返回你需要删除的列数。

*/


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        int ans = 0;
        for(int j = 0;j<n;j++){
            string temp = "";
            for(int i = 0;i<m;i++){
                temp += strs[i][j];
            }
            if(!is_sorted(temp.begin(),temp.end())){
                ++ans;
            }
        }
        return ans;
    }
};


/*
给你一个整型数组 nums ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。

示例 1：

输入：nums = [1,2,3]
输出：6

输入：nums = [1,2,3,4]
输出：24

*/


class Solution2 {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size() == 3)
            return nums[0]*nums[1]*nums[2];
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int maxNum = nums[n-1];
        return max(nums[0]*nums[1]*maxNum,nums[n-3]*nums[n-2]*maxNum);

    }
};

int main(int argc, char const *argv[])
{
    vector<string> strs = {"cba","daf","ghi"};
    Solution sol;
    cout<<sol.minDeletionSize(strs)<<endl;
    system("pause");
    return 0;
}
