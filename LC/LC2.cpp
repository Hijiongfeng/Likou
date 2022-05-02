#include<bits/stdc++.h>

using namespace std;

/*
给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；
如果数组中每个元素互不相同，返回 false 。

示例 1：

输入：nums = [1,2,3,1]
输出：true
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> num_set;
        for(int a : nums){
            if(num_set.count(a)){
                return true;
            }else{
                num_set.insert(a);
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
