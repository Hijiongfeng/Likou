#include<bits/stdc++.h>

using namespace std;

/*

给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> num_mp;
        if(nums1.size()>=nums2.size()){
            swap(nums1,nums2);
        }
        for(int a : nums1){
            num_mp[a]++;
        }
        vector<int> ans;
        for(int a : nums2){
            if(num_mp[a] >= 1){
                ans.push_back(a);
                num_mp[a]--;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
