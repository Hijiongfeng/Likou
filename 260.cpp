#include<bits/stdc++.h>

using namespace std;

/*
给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。

进阶：你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？

示例 1：

输入：nums = [1,2,1,3,2,5]
输出：[3,5]
解释：[5, 3] 也是有效的答案。

如果我们把数组分成两个子数组，每个数组都满足「恰好有一个元素只出现一次，
其余所有元素均出现两次」，是不是就可以按照之前的方法直接解决了呢？
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {   // 哈希表的方法
        unordered_map<int,int> nums_mp;
        for(int num : nums){
            nums_mp[num]++;
        }
        vector<int> vec;
        for(auto & [a,b] : nums_mp){
            if(b == 1){
                vec.push_back(a);
            }
        }
        return vec;
    }
    vector<int> singleNumber2(vector<int>& nums) {   // 哈希表的方法
        unsigned int target = 0;
        for(auto n : nums){
            target ^= n;
        }

        int lowbit = target & (-target);

        int a1 = 0;
        int a2 = 0;
        for(auto n :nums){
            if(n & lowbit){
                a1 ^= n;
            }else{
                a2 ^= n;
            }
        }

        vector<int> ans;
        ans.push_back(a1);
        ans.push_back(a2);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,1,3,2,5};
    Solution sol;
    vector<int> ans = sol.singleNumber(nums);
    system("pause");
    return 0;
}
