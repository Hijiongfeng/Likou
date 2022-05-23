#include<bits/stdc++.h>

using namespace std;

/*
几张卡牌 排成一行，每张卡牌都有一个对应的点数。点数由整数数组 cardPoints 给出。

每次行动，你可以从行的开头或者末尾拿一张卡牌，最终你必须正好拿 k 张卡牌。

你的点数就是你拿到手中的所有卡牌的点数之和。

给你一个整数数组 cardPoints 和整数 k，请你返回可以获得的最大点数。

示例 1：

输入：cardPoints = [1,2,3,4,5,6,1], k = 3
输出：12
解释：第一次行动，不管拿哪张牌，你的点数总是 1 。但是，先拿最右边的卡牌将会最大化你的可获得点数。
最优策略是拿右边的三张牌，最终点数为 1 + 6 + 5 = 12 。
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {          // 固定大小的窗口
        int n = cardPoints.size();
        int sum = accumulate(cardPoints.begin(),cardPoints.end(),0);
        int windowSize = n-k;
        int windowSum = accumulate(cardPoints.begin(),cardPoints.begin()+windowSize,0);
        int minSum = windowSum;
        for(int i = 0;i<k;i++){
            int newwindowSum = windowSum + cardPoints[i+windowSize] - cardPoints[i];
            minSum = min(minSum,newwindowSum);
            windowSum = newwindowSum;
        }
        return sum - minSum;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> cardPoints = {1,79,80,1,1,1,200,1};
    int k = 3;
    Solution sol;
    cout<<sol.maxScore(cardPoints,k)<<endl;
    system("pause");
    return 0;
}
