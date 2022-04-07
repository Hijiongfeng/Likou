#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

/*
树是一个无向图，其中任何两个顶点只通过一条路径连接。
 换句话说，一个任何没有简单环路的连通图都是一棵树。

给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。
给定数字 n 和一个有 n - 1 条无向边的 edges 列表（每一个边都是一对标签），
其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条无向边。

可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，
设结果树的高度为 h 。在所有可能的树中，具有最小高度的树（即，min(h)）被称为 最小高度树 。

请你找到所有的 最小高度树 并按 任意顺序 返回它们的根节点标签列表。

树的 高度 是指根节点和叶子节点之间最长向下路径上边的数量。

输入：n = 4, edges = [[1,0],[1,2],[1,3]]
输出：[1]
解释：如图所示，当根是标签为 1 的节点时，树的高度是 1 ，这是唯一的最小高度树。
*/

/*
        for(auto & [a,b] : degree){         // 结构化绑定
            if(b == N-1)
                return a;
        }
*/

/*

首先，我们看了样例，发现这个树并不是二叉树，是多叉树。
然后，我们可能想到的解法是：根据题目的意思，
就挨个节点遍历bfs，统计下每个节点的高度，然后用map存储起来，后面查询这个高度的集合里最小的就可以了。
但是这样会超时的。

所以从叶子节点出发到根才能得到最短高度。
基于BFS，每次都把当前的叶子节点遍历并剪枝，得到新的叶子节点放入队列中，
直到无法剪枝，这时候队列中的节点即为最小高度树的根节点，
*/


class Solution {
private:
    vector<vector<int>> grid;
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        grid.resize(n);
        vector<int> ans;
        for(int i = 0;i<edges.size();i++){              // 生成邻接表
            grid[edges[i][0]].push_back(edges[i][1]);
            grid[edges[i][1]].push_back(edges[i][0]);
        }

        multimap<int,int> mp;
        for(int i = 0;i<n;i++){
            int h = 0;
            vector<int> visited(n); // 判断是否遍历过
            queue<int> que;
            que.push(i);        // 根节点入队
            while(!que.empty()){
                int size = que.size();
                h++;
                for(int j = 0;j<size;j++){
                    int node = que.front();que.pop();
                    visited[node] = 1;
                    for(int v : grid[node]){
                        if(visited[v] == 1)
                            continue;
                        else if(visited[v] == 0)        // 每一层入队
                            que.push(v);
                    }
                } 
            }
            mp.insert({h-1,i}); 
        }
        int min = INT_MAX;
        for(auto & [a,b] : mp){
            
            if(a > min)
                break;
            min = a;
            ans.push_back(b);
            
        }
        return ans;
    }
};



class Solution2 {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        vector<int> degree(n);   //每个节点对应的度数
        map<int,vector<int>> m;  //邻接表       也可以用一个二维数组 当做邻接表
        vector<int> res; //结果
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            degree[u]++;
            degree[v]++;
            m[u].push_back(v);
            m[v].push_back(u);
        }
        queue<int> q;
        //把叶子节点入栈
        for(int i=0;i<n;i++)
            if(degree[i]==1)
                q.push(i);
        //从外向内一层一层剥，每次加入的都是一层的
        while(!q.empty()){
            res.clear();
            int sz=q.size();
            //一层全部加入结果并且清出去
            for(int i=0;i<sz;i++){
                int t=q.front();
                q.pop();
                res.push_back(t);
                //加入t的邻接叶子节点
                degree[t]--;
                for(auto j:m[t]){
                    degree[j]--;
                    if(degree[j]==1)
                        q.push(j);
                }    
            }
        }
        return res; 
    }
};

int main(int argc, char const *argv[])
{
    int n = 6;
    vector<vector<int>> edges = {{3,0},{3,1},{3,2},{3,4},{5,4}};
    Solution2 sol;
    vector<int> ans = sol.findMinHeightTrees(n,edges);
    system("pause");
    return 0;
}
