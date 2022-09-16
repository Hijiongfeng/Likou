#include<bits/stdc++.h>

using namespace std;

/*
给你两个正整数数组 spells 和 potions ，长度分别为 n 和 m ，其中 spells[i] 表示第 i 个咒语的能量强度，potions[j] 表示第 j 瓶药水的能量强度。

同时给你一个整数 success 。一个咒语和药水的能量强度 相乘 如果 大于等于 success ，那么它们视为一对 成功 的组合。

请你返回一个长度为 n 的整数数组 pairs，其中 pairs[i] 是能跟第 i 个咒语成功组合的 药水 数目。
*/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(),potions.end());
        int N = potions.size();
        for(int & spell : spells){
            double temp = success * 1.0 / spell;
            int index = lower_bound(potions.begin(),potions.end(),temp) - potions.begin();
            ans.push_back(N - index);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> spells = {5,1,3};
    vector<int> potions = {1,2,3,4,5}; 
    int success = 7;
    Solution sol;
    vector<int> ans = sol.successfulPairs(spells,potions,success);
    system("pause");
    return 0;
}
