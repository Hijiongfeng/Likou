#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

/*
给定一个大小为 n 的数组，找到其中的多数元素。
多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size()/2;
        unordered_map<int,int> mp;
        for(int a:nums){
            mp[a]++;
        }
        for(int i = 0;i<nums.size();i++){
            if(mp[nums[i]] > n)
                return nums[i];
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}

