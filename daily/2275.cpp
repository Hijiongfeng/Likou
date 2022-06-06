#include<bits/stdc++.h>

using namespace std;

/*
对数组 nums 执行 按位与 相当于对数组 nums 中的所有整数执行 按位与 。

例如，对 nums = [1, 5, 3] 来说，按位与等于 1 & 5 & 3 = 1 。
同样，对 nums = [7] 而言，按位与等于 7 。
给你一个正整数数组 candidates 。计算 candidates 中的数字每种组合下 按位与 的结果。
 candidates 中的每个数字在每种组合中只能使用 一次 。

返回按位与结果大于 0 的 最长 组合的长度。

 

示例 1：

输入：candidates = [16,17,71,62,12,24,14]
输出：4
解释：组合 [16,17,62,24] 的按位与结果是 16 & 17 & 62 & 24 = 16 > 0 。
组合长度是 4 。
可以证明不存在按位与结果大于 0 且长度大于 4 的组合。
注意，符合长度最大的组合可能不止一种。
例如，组合 [62,12,24,14] 的按位与结果是 62 & 12 & 24 & 14 = 8 > 0 。

二进制位 某一位 1 的数目最多
*/

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> dit(32,0);
        for(int cand : candidates){
            for(int i = 31;i>=0;i--){
                if(cand >> i & 1 > 0){
                    dit[i]++;
                }
            }
        }
        int maxNum = INT_MIN;
        for(int i = 0;i<32;i++){
            maxNum = max(maxNum,dit[i]);
        }
        return maxNum;
    }


    int largestCombination(vector<int>& candidates) {       // c++ bitset
        vector<int> dict(32,0);
        int i;
        for (int val: candidates) {
            bitset<32> bset(val);
            for (i = 0; i < 32; ++i) {      //  看32位哪一位为 1 
                if (bset[i]) {
                    ++dict[i];
                }
            }
        }
        return *max_element(dict.begin(), dict.end());
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
