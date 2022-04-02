#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

/*
给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。
请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。

示例 1：

输入：nums = [4,3,2,7,8,2,3,1]
输出：[5,6]
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_set<int> st;
        for(int& a : nums){
            st.insert(a);
        }
        for(int i = 1;i<=n;i++){
            if(st.find(i)!=st.end())
                continue;
            else
                ans.push_back(i);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
