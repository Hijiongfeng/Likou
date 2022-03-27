#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1

*/

class Solution {        // 使用快排，复杂度 O(nlogn)
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1)  return nums[0];
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i+=2){
            if(nums[i] != nums[i+1])
                return nums[i];
        }
        return nums[nums.size()-1];
    }

    int singleNumber2(vector<int>& nums) {     // 使用 哈希表 ，查找
        unordered_map<int,int> mp;
        for(int a : nums){
            mp[a]++;
        }
        for(int a : nums){
            if(mp[a] == 1)
                return a;
        }
        return 0;
    }

/*

异或运算有以下三个性质。
任何数和 0 做异或运算，结果仍然是原来的数。
任何数和其自身做异或运算，结果是 0。
异或运算满足交换律和结合律。

*/
    int singleNumber3(vector<int>& nums) {     // 异或 运算
        int single = 0;
        for(int num : nums){
            single ^= num;
        }
        return single;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums ={1};
    Solution sol;
    cout<<sol.singleNumber(nums)<<endl;
    system("pause");
    return 0;
}
