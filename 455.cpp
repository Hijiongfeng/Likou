#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。

对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；
并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，
我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。

示例 1:

输入: g = [1,2,3], s = [1,1]
输出: 1
解释: 
你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1,2,3。
虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。
所以你应该输出1。
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {   // 贪心策略 1 小饼干先喂饱小孩子
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int child = 0,cook = 0;
        while(child<g.size() && cook<s.size()){
            if(g[child]<=s[cook]){
                child++;
            }
            cook++;
        }
        return child;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> child{1,2};
    vector<int> cook{1,2,3};
    Solution sol;
    int res = sol.findContentChildren(child,cook);
    cout<<"can fill: "<<res<<endl;
    system("pause");
    return 0;
}
