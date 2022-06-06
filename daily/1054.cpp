#include<bits/stdc++.h>

using namespace std;

/*
在一个仓库里，有一排条形码，其中第 i 个条形码为 barcodes[i]。

请你重新排列这些条形码，使其中任意两个相邻的条形码不能相等。 
你可以返回任何满足该要求的答案，此题保证存在答案。

示例 1：

输入：barcodes = [1,1,1,2,2,2]
输出：[2,1,2,1,2,1]

根据频次排序，构造出新数组
优先处理频次高的，间隔插入，先处理一半，在处理另一半
根据频率排序，使用map和multimap进行实现。
*/

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {

        map<int,int> num_mp;
        for(int a : barcodes){
            num_mp[a]++;
        }

        multimap<int,int,greater<int>> mu_mp;

        for(auto it = num_mp.begin();it != num_mp.end();it++){
            mu_mp.insert({it->second,it->first});
        }

        int size = barcodes.size();
        vector<int> newbarcodes;

        for(auto it = mu_mp.begin();it!= mu_mp.end();it++){
            int fre = it->first;
            int num = it->second;
            while(fre--){
                newbarcodes.push_back(num);
            }
        }

        vector<int> ans(size,0);

        int len1 = size % 2 == 0 ? size / 2 : size / 2 + 1;

        for(int i = 0,j = 0;i<len1;i++,j+=2){
            ans[j] = newbarcodes[i];
        }
        for(int i = len1,j = 1;i<size;i++,j+=2){
            ans[j] = newbarcodes[i];
        }

        return ans;

    }
};

int main(int argc, char const *argv[])
{
    vector<int> bar = {1,1,1,2,2,2,3,3};
    Solution sol;
    vector<int> ans = sol.rearrangeBarcodes(bar);
    system("pause");
    return 0;
}
