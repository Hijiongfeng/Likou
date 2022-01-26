#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/*
四数相加 二
给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
*/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> umap;
        for(int a:nums1){
            for(int b:nums2){
                umap[a+b]++;
            }
        }
        int count = 0;
        for(int c:nums3){
            for(int d:nums4){
                if(umap.find(0-(c+d))!=umap.end()){
                    count += umap[0-(c+d)];         // 就相当于一个 组合数
                    //count++;
                }
            }
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {-2,-1};
    vector<int> nums3 = {-1,2};
    vector<int> nums4 = {0,2};
    Solution sol;
    cout<<sol.fourSumCount(nums1,nums2,nums3,nums4)<<endl;
    system("pause");
    return 0;
}
