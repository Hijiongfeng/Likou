#include<bits/stdc++.h>

using namespace std;

/*
给定一个可能含有重复元素的整数数组，要求随机输出给定的数字的索引。 您可以假设给定的数字一定存在于数组中。

注意：
数组大小可能非常大。 使用太多额外空间的解决方案将不会通过测试。

示例:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) 应该返回索引 2,3 或者 4。每个索引的返回概率应该相等。
solution.pick(3);

// pick(1) 应该返回 0。因为只有nums[0]等于1。
solution.pick(1);
*/

class Solution {
    unordered_map<int,vector<int>> num_mp;
public:
    Solution(vector<int>& nums) {
        srand((unsigned)time(NULL));
        for(int i = 0;i<nums.size();i++){
            num_mp[nums[i]].emplace_back(i);
        }
    }
    
    int pick(int target) {
        vector<int> vec = num_mp[target];
        if(vec.size() == 1){
            return vec[0];
        }
        int n = vec.size() - 1;
        int randindex =  rand() % (n+1);   ///要取得[a,b]的随机整数
        return vec[randindex];
    } 
};

class Solution2 {       // 水塘抽样
    vector<int> nums;
public:
    Solution2(vector<int>& nums) :nums(nums){
        srand((unsigned)time(NULL));
    }
    
    int pick(int target) {
        int ans;
        for(int i = 0,cnt = 0;i<nums.size();i++){
            if(nums[i] == target){
                ++cnt;          // 第 cnt 次遇到 target
                if(rand() % cnt == 0){
                    ans = i;
                }
            }
        }
        return ans;
    } 
};



int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,3,3};
    Solution*  sol = new Solution(nums);
    cout<<sol->pick(3)<<endl;
    system("pause");
    return 0;
}
