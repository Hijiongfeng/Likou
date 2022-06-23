#include<bits/stdc++.h>

using namespace std;

/*
给你一个整数 n ，表示一个国家里的城市数目。城市编号为 0 到 n - 1 。

给你一个二维整数数组 roads ，其中 roads[i] = [ai, bi] 表示城市 ai 和 bi 之间有一条 双向 道路。

你需要给每个城市安排一个从 1 到 n 之间的整数值，且每个值只能被使用 一次 。
道路的 重要性 定义为这条道路连接的两座城市数值 之和 。

请你返回在最优安排下，所有道路重要性 之和 最大 为多少。

*/
// 贪心算法 根据每个节点的度进行定权重
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int,int> mp;
        for(auto & vec : roads){
            mp[vec[0]]++;
            mp[vec[1]]++;
        }
        multimap<int,int,greater<int>> mult_mp;
        for(auto & [a,b] : mp){
            mult_mp.insert({b,a});
        }
        for(auto & [a,b] : mult_mp){
            mp[b] = n;
            n--;
        }
        long long ans = 0;
        for(auto & vec : roads){
            ans += (mp[vec[0]]+mp[vec[1]]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n = 5;
    vector<vector<int>> roads = {{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};
    Solution sol;
    cout<<sol.maximumImportance(n,roads)<<endl;
    system("pause");
    return 0;
}
