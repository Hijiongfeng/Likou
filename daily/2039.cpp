#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
给你一个有 n 个服务器的计算机网络，服务器编号为 0 到 n - 1 。
同时给你一个二维整数数组 edges ，其中 edges[i] = [ui, vi] 

表示服务器 ui 和 vi 之间有一条信息线路，在 一秒 内它们之间可以传输 任意 数目的信息。
再给你一个长度为 n 且下标从 0 开始的整数数组 patience 。

题目保证所有服务器都是 相通 的，也就是说一个信息从任意服务器出发，
都可以通过这些信息线路直接或间接地到达任何其他服务器。

编号为 0 的服务器是 主 服务器，其他服务器为 数据 服务器。
每个数据服务器都要向主服务器发送信息，并等待回复。信息在服务器之间按 最优 线路传输，
也就是说每个信息都会以 最少时间 到达主服务器。主服务器会处理 所有 新到达的信息并 立即 
按照每条信息来时的路线 反方向 发送回复信息。

在 0 秒的开始，所有数据服务器都会发送各自需要处理的信息。从第 1 秒开始，
每 一秒最 开始 时，每个数据服务器都会检查它是否收到了主服务器的回复信息（包括新发出信息的回复信息）：

如果还没收到任何回复信息，那么该服务器会周期性 重发 信息。
数据服务器 i 每 patience[i] 秒都会重发一条信息，也就是说，
数据服务器 i 在上一次发送信息给主服务器后的 patience[i] 秒 后 会重发一条信息给主服务器。
否则，该数据服务器 不会重发 信息。
当没有任何信息在线路上传输或者到达某服务器时，该计算机网络变为 空闲 状态。

请返回计算机网络变为 空闲 状态的 最早秒数 。
*/

/*
无向图 求最短距离 广度优先搜索
根据图中的边对应的关系 edges 即可求出图中任意节点之间的最短距离。
利用广度优先搜索求出节点 0 到其他节点的最短距
*/

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();       
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);  
        for (auto & v : edges) {
            adj[v[0]].emplace_back(v[1]);
            adj[v[1]].emplace_back(v[0]);
        }

        queue<int> qu;
        qu.emplace(0);
        visit[0] = true;
        int dist = 1;
        int ans = 0;
        while (!qu.empty()) {
            int sz = qu.size();
            for (int i = 0; i < sz; ++i) {
                int curr = qu.front();
                qu.pop();
                for (auto & v : adj[curr]) {
                    if (visit[v]) {
                        continue;
                    }
                    qu.emplace(v);
                    int time = patience[v] * ((2 * dist - 1) / patience[v]) + 2 * dist + 1;
                    ans = max(ans, time);
                    visit[v] = true;
                }
            }
            dist++;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> edge = {{0,1},{1,2}};
    vector<int> patience = {0,2,1};
    Solution sol;
    cout<<sol.networkBecomesIdle(edge,patience)<<endl;
    system("pause");
    return 0;
}
