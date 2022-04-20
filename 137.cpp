#include<bits/stdc++.h>

using namespace std;

/*
给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。

示例 1：

输入：nums = [2,2,3,2]
输出：3
示例 2：

输入：nums = [0,1,0,1,0,1,99]
输出：99

方法一：哈希表
思路与算法

我们可以使用哈希映射统计数组中每个元素的出现次数。
对于哈希映射中的每个键值对，键表示一个元素，值表示其出现的次数。

在统计完成后，我们遍历哈希映射即可找出只出现一次的元素。

方法二：
如下图所示，考虑数字的二进制形式，对于出现三次的数字，各 二进制位 出现的次数都是 3 的倍数。
因此，统计所有数字的各二进制位中 1 的出现次数，并对 3 求余，结果则为只出现一次的数字。
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {   // 哈希表
        unordered_map<int,int> nums_mp;
        for(auto &a : nums){
            nums_mp[a]++;
        }
        for(auto &[a,b] : nums_mp){         // 结构化绑定 c++17 才出的
            if(b == 1){
                return a;
            }
        }
        return 0;
    }

    int singleNumber2(vector<int>& nums) {   // 位运算
        int cnt[32] = {0};

        for(int x : nums){
            for(int i = 0;i<32;i++){
                if((x >> i) & 1 == 1){
                    cnt[i]++;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<32;i++){
            if((cnt[i] % 3 & 1) == 1){
                ans += (1 << i);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    //cout<<(1 << 2)<<endl;
    vector<int> nums = {2,2,3,2};
    Solution sol;
    cout<<sol.singleNumber2(nums)<<endl;
    system("pause");
    return 0;
}
