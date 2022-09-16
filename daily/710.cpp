#include<bits/stdc++.h>

using namespace std;

/*
给定一个整数 n 和一个 无重复 黑名单整数数组 blacklist 。设计一种算法，
从 [0, n - 1] 范围内的任意整数中选取一个 未加入 黑名单 blacklist 的整数。
任何在上述范围内且不在黑名单 blacklist 中的整数都应该有 同等的可能性 被返回。

优化你的算法，使它最小化调用语言 内置 随机函数的次数。

实现 Solution 类:

Solution(int n, int[] blacklist) 初始化整数 n 和被加入黑名单 blacklist 的整数
int pick() 返回一个范围为 [0, n - 1] 且不在黑名单 blacklist 中的随机整数
*/

class Solution {
public:
    Solution(int n, vector<int>& blacklist) :gen{random_device{}()}{
        int m = blacklist.size();
        //ischoise.resize(n-m);
        for(int & a : blacklist){
            num_set.insert(a);
        }
        for(int i = 0;i<n;i++){
            if(num_set.count(i) == 0){
                ischoise.push_back(i);
            }
        }
    }
    
    int pick() {
        int N = ischoise.size();
        uniform_int_distribution<int> dis(0,N-1);
        int k = dis(gen);
        return ischoise[k];
    }
private:

    vector<int> ischoise;
    unordered_set<int> num_set;
    mt19937 gen;
};


int main(int argc, char const *argv[])
{
    int n = 1;
    vector<int> vec;
    Solution sol(n,vec);
    cout<<sol.pick()<<endl;
    cout<<sol.pick()<<endl;
    cout<<sol.pick()<<endl;
    system("pause");
    return 0;
}
