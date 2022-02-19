#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/*
有一个无向的 星型 图，由 n 个编号从 1 到 n 的节点组成。星型图有一个 中心 节点，
并且恰有 n - 1 条边将中心节点与其他每个节点连接起来。

给你一个二维整数数组 edges ，其中 edges[i] = [ui, vi] 表示在节点 ui 和 vi 之间存在一条边。
请你找出并返回 edges 所表示星型图的中心节点。

*/

/*
根据图论：「度」是一个顶点连接了几条边。 
中心点的度 为 n-1，n为节点数量
*/

class Solution2 {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> degree;
        for(auto & edge : edges){           // 计算每条边的度，用 unorder_map 存储
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        int N = degree.size();

        for(auto & [a,b] : degree){         // 结构化绑定
            if(b == N-1)
                return a;
        }
        return 0;
    }
};


class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // vector<int> first = edges[0];
        // vector<int> second = edges[1];
        // for(int i = 0;i<first.size();i++){
        //     for(int j = 0;j<second.size();j++){
        //         if(first[i] == second[j]) return first[i];
        //     }
        // }
        // return 0;
        if(edges[0][0] == edges[1][0]) return edges[0][0];
        if(edges[0][0] == edges[1][1]) return edges[0][0];
        if(edges[0][1] == edges[1][0]) return edges[0][1];
        if(edges[0][1] == edges[1][1]) return edges[0][1];
        return 0;
    }
};

int main(int argc, char const *argv[])
{//edges = [[1,2],[5,1],[1,3],[1,4]]
    vector<vector<int>> edges{{1,2},{2,3},{4,2}};
    Solution2 sol;
    cout<<sol.findCenter(edges)<<endl;
    system("pause");
    return 0;
}
