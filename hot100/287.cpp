#include<bits/stdc++.h>

using namespace std;

/*
给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内
（包括 1 和 n），可知至少存在一个重复的整数。

假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。

你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {  // 方法一 哈希表
        unordered_set<int> num_set;
        for(int a : nums){
            if(!num_set.count(a)){
                num_set.insert(a);
            }else{
                return a;
            }
        }
        return 0;
    }

    int findDuplicate2(vector<int>& nums) {  // 方法二 快慢双指针 进行映射 找环
        int slow = 0,fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];
        while(slow != fast){        // 判断是否有环 慢的走一步，快的走两步
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int pre1 = 0;               // 找到环入口
        int pre2 = slow;
        while(pre1 != pre2){
            pre1 = nums[pre1];
            pre2 = nums[pre2];
        }
        return pre1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,3,4,2,1};
    Solution sol;
    cout<<sol.findDuplicate2(nums)<<endl;
    system("pause");
    return 0;
}
