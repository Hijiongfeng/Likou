#include<bits/stdc++.h>

using namespace std;

/*
给定两个大小相等的数组 nums1 和 nums2，nums1 
相对于 nums 的优势可以用满足 nums1[i] > nums2[i] 的索引 i 的数目来描述。

返回 nums1 的任意排列，使其相对于 nums2 的优势最大化。

示例 1：

输入：nums1 = [2,7,11,15], nums2 = [1,10,4,11]
输出：[2,11,7,15]
*/

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {    // n*n 超时
        sort(nums1.begin(),nums1.end());
        vector<int> ans;
        vector<bool> used(nums1.size(),false);
        for(int i = 0;i<nums2.size();i++){
            int flag = 0;
            for(int j = 0;j<nums1.size();j++){
                if(nums1[j] > nums2[i]){
                    ans.push_back(nums1[j]);
                    nums1.erase(nums1.begin()+j);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                ans.push_back(nums1[0]);
                nums1.erase(nums1.begin());
            }
        }
        return ans;
    }
// 田忌赛马 用最差的抵最好的
/*
如果 num1 最大的 大于 num2 最大的，这直接抵掉
如果不大于，则用 num1 最小的去抵。
*/
    vector<int> advantageCount2(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        vector<pair<int,int>> vt;
        for(int i = 0;i<nums2.size();i++){
            vt.push_back(make_pair(nums2[i],i));
        }
        sort(vt.begin(),vt.end());
        vector<int> ans(nums2.size());
        int l1 = 0,r1 = nums1.size()-1,l2 = 0,r2 = nums2.size()-1;
        while(r2 >= 0){
            if(nums1[r1] > vt[r2].first){
                ans[vt[r2].second] = nums1[r1];
                r2--;
                r1--;
            }else{
                ans[vt[r2].second] = nums1[l1];
                r2--;
                l1++;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {12,24,8,32}, nums2 = {13,25,32,11};
    Solution sol;
    vector<int> res = sol.advantageCount2(nums1,nums2);
    int a = 0;
    system("pause");
    return 0;
}
