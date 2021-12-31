#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

/*
有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。

每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。

*/// 分成两堆 就可以了，两堆 越接近；剩下的越小

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(),stones.end(),0);
        int target = sum / 2;

        vector<vector<int>> dp(stones.size(),vector<int> (target+1,0));

        for(int j = stones[0];j<=target;j++){
            dp[0][j] = stones[0];
        }

        for(int i = 1;i<stones.size();i++){
            for(int j = 0;j<=target;j++){
                if(j < stones[i]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j],dp[i-1][j-stones[i]]+stones[i]);
            }
        }

        return sum - dp[stones.size()-1][target] - dp[stones.size()-1][target];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> stones{31,26,33,21,40};
    Solution sol;
    cout<<sol.lastStoneWeightII(stones)<<endl;
    system("pause");
    return 0;
}
