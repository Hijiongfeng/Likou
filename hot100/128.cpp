#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

/*
给定一个未排序的整数数组 nums ，
找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
*/

/*
枚举每个数，找 x+1,x+2....；
进行优化，如果已经找了 x+1，那么再从X+2开始就没有意义了
跳过就是 如果一个数有 前驱数 就跳过
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for(const int& num:nums){
            num_set.insert(num);
        }

        int count = 0;

        for(const int & num : num_set){
            if(!num_set.count(num-1)){  // 找不到 num-1 才进入循环
                int curNum = num;
                int curCount = 1;

                while(num_set.count(curNum + 1)){
                    curNum += 1;
                    curCount += 1;
                }
                count = max(curCount,count);
            }
        }
        
        return count;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {9,1,4,7,3,-1,0,5,8,-1,6};
    Solution sol;
    cout<<sol.longestConsecutive(nums)<<endl;
    system("pause");
    return 0;
}
