#include<bits/stdc++.h>

using namespace std;

/*
索引从0开始长度为N的数组A，包含0到N - 1的所有整数。
找到最大的集合S并返回其大小，其中 S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }且遵守以下的规则。

假设选择索引为i的元素A[i]为S的第一个元素，
S的下一个元素应该是A[A[i]]，之后是A[A[A[i]]]... 以此类推，不断添加直到S出现重复的元素。

示例 1:

输入: A = [5,4,0,3,1,6,2]
输出: 4
解释: 
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

其中一种最长的 S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
*/

class Solution {
public:

    void dfs(vector<int>& nums,int i,unordered_set<int>& st){
        if(st.count(nums[i])){
            return;
        }
        st.insert(nums[i]);
        dfs(nums,nums[i],st);
    }

    int arrayNesting(vector<int>& nums) {
        unordered_set<int> st;
        int max = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            st.clear();
            dfs(nums,i,st);
            int temp = st.size();
            if(temp > max){
                max = st.size();
            }
        }
        return max;
    }
};


class Solution2 {
public:
    int arrayNesting(vector<int> &nums) {
        int ans = 0, n = nums.size();
        vector<int> vis(n);                 // 标记数组
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            while (!vis[i]) {
                vis[i] = true;
                i = nums[i];
                ++cnt;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {5,4,0,3,1,6,2};
    cout<<nums.max_size()<<endl;
    nums.push_back(88);
    cout<<nums.capacity()<<endl;
    cout<<nums.size()<<endl;
    Solution2 sol;
    cout<<sol.arrayNesting(nums)<<endl;
    system("pause");
    return 0;
}
