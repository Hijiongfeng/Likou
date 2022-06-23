#include<bits/stdc++.h>

using namespace std;

/*
给你一个 下标从 0 开始 的正整数数组 w ，其中 w[i] 代表第 i 个下标的权重。

请你实现一个函数 pickIndex ，它可以 随机地 从范围 [0, w.length - 1] 内（含 0 和 w.length - 1）
选出并返回一个下标。选取下标 i 的 概率 为 w[i] / sum(w) 。

例如，对于 w = [1, 3]，挑选下标 0 的概率为 1 / (1 + 3) = 0.25 （即，25%），
而选取下标 1 的概率为 3 / (1 + 3) = 0.75（即，75%）。
*/

class Solution {
public:
    Solution(vector<int>& w) {
        //partial_sum(w.begin(), w.end(), back_inserter(arr));
        arr.emplace_back(w[0]);
        for(int i = 1;i<w.size();i++){
            arr.emplace_back(arr.back() + w[i]);
        }
    }
    
    int pickIndex() {
        uniform_int_distribution<> dis(0,arr.back()-1);
        double k = dis(gen);
        int i = upper_bound(arr.begin(),arr.end(),k) - arr.begin();         // 找到第一个大于
        return i;
    }
private:
    vector<int> arr;
    mt19937 gen{random_device{}()};
};

int main(int argc, char const *argv[])
{
    vector<int> w = {1,3,4};
    Solution sol(w);
    cout<<sol.pickIndex()<<endl;
    cout<<sol.pickIndex()<<endl;
    system("pause");
    return 0;
}
