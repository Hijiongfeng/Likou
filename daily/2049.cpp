#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/*
给你一棵根节点为 0 的 二叉树 ，它总共有 n 个节点，
节点编号为 0 到 n - 1 。同时给你一个下标从 0 开始的整数数组 parents 表示这棵树，
其中 parents[i] 是节点 i 的父节点。由于节点 0 是根，所以 parents[0] == -1 。

一个子树的 大小 为这个子树内节点的数目。每个节点都有一个与之关联的 分数 。
求出某个节点分数的方法是，将这个节点和与它相连的边全部 删除 ，
剩余部分是若干个 非空 子树，这个节点的 分数 为所有这些子树 大小的乘积 。

请你返回有 最高得分 节点的 数目 。
*/

class Solution {
private:
    unordered_map<int,int> leftTree;
    unordered_map<int,int> rightTree;

    int dfs(vector<int> & left,vector<int> & right,int head){
        if(left[head] == -1 && right[head] == -1){
            return 1;                       //如果没有儿子，直接返回1
        }                                   // return 回到上一层
        int m = 0,n = 0;
        if(left[head] != -1){
            m = dfs(left,right,left[head]);
        }
        if(right[head] != -1){
            n = dfs(left,right,right[head]);
        }
        leftTree[head] = m;
        rightTree[head] = n;
        return m+n+1;
    }
public:
    int countHighestScoreNodes(vector<int>& parents) {
        vector<int> left(parents.size(),-1);    //每个节点的左儿子，初始化为-1
        vector<int> right(parents.size(),-1);   //每个节点的右儿子，初始化为-1

        int head = -1;
        for(int i = 0;i<parents.size();i++){
            if(parents[i] == -1){
                head = i;
                continue;
            }
            if(left[parents[i]] == -1){     // 左右 其实没有 区别，不要被 图示的 迷惑
                left[parents[i]] = i;       //i的父亲节点还没有左儿子，先安排i为左儿子。
            }else{
                right[parents[i]] = i;
            }
        }
        dfs(left,right,head);
        long long maxScore = 0;
        int ans = 0;
        long long now = 0;
        vector<long long> cnt;

        for(int i = 0;i<parents.size();i++){
            now = 1;
            int m = leftTree[i];
            int n = rightTree[i];
            int k = parents.size() - m - n -1;
            if(m){
                now *= m;
            }
            if(n)//右子树非空
            {
                now*=n;
            }
            if(k)//父节点非空
            {
                now*=k;
            }

            cnt.push_back(now);
            maxScore = max(maxScore,now);

        }

        for(int i = 0;i<parents.size();i++){
            if(cnt[i] == maxScore){
                ans++;
            }
        }
        return ans;

    }
};



int main(int argc, char const *argv[])
{
    vector<int> parents = {-1,2,0,2,0};
    Solution sol;
    cout<<sol.countHighestScoreNodes(parents)<<endl;
    system("pause");
    return 0;
}
