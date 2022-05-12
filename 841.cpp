#include<bits/stdc++.h>

using namespace std;

/*
有 n 个房间，房间按从 0 到 n - 1 编号。最初，除 0 号房间外的其余所有房间都被锁住。你的目标是进入所有的房间。然而，你不能在没有获得钥匙的时候进入锁住的房间。

当你进入一个房间，你可能会在里面找到一套不同的钥匙，每把钥匙上都有对应的房间号，即表示钥匙可以打开的房间。你可以拿上所有钥匙去解锁其他房间。

给你一个数组 rooms 其中 rooms[i] 是你进入 i 号房间可以获得的钥匙集合。如果能进入 所有 房间返回 true，否则返回 false。

示例 1：

输入：rooms = [[1],[2],[3],[]]
输出：true
解释：
我们从 0 号房间开始，拿到钥匙 1。
之后我们去 1 号房间，拿到钥匙 2。
然后我们去 2 号房间，拿到钥匙 3。
最后我们去了 3 号房间。
由于我们能够进入每个房间，我们返回 true。

构建一个无向图，
dfs或bfs遍历所有节点，
看是否经过所有节点
*/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {     // 广度优先搜索
        if(rooms[0].size() == 0)
            return false;
        int n = rooms.size();
        queue<vector<int>> que;
        vector<bool> visited(n,false);
        que.emplace(rooms[0]);
        visited[0] = true;
        while(!que.empty()){
            vector<int> temp_vec = que.front();
            que.pop();
            int size = temp_vec.size();
            for(int i = 0;i<size;i++){
                if(visited[temp_vec[i]] == false){
                    que.push(rooms[temp_vec[i]]);
                    visited[temp_vec[i]] = true;
                }
            }
        }
        for(bool f : visited){
            if(f == false){
                return false;
            }
        }
        return true;
    }


    bool canVisitAllRooms2(vector<vector<int>>& rooms) {     // 深度优先搜索
        if(rooms[0].size() == 0)
            return false;
        int n = rooms.size();
        vector<bool> visited(n,false);
        dfs(rooms,visited,0);
        for(bool f : visited){
            if(f == false){
                return false;
            }
        }
        return true;
    }

    void dfs(vector<vector<int>>& room,vector<bool>& visited,int x){    // 递归每一个节点
        visited[x] = true;
        for(auto& temp : room[x]){
            if(visited[temp] == false)
                dfs(room,visited,temp);
        }
    }
};

int main(int argc, char const *argv[])
{
    //vector<vector<int>> rooms = {{1,3},{3,0,1},{2},{0}};
    vector<vector<int>> rooms = {{1},{2},{3},{}};
    Solution sol;
    cout<<sol.canVisitAllRooms2(rooms)<<endl;
    system("pause");
    return 0;
}
