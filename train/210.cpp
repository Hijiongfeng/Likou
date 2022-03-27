#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

/*
现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。
给你一个数组 prerequisites ，其中 prerequisites[i] = [ai, bi] ，
表示在选修课程 ai 前 必须 先选修 bi 。

例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。
返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，
你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组 。

示例 1：

输入：numCourses = 2, prerequisites = [[1,0]]
输出：[0,1]
解释：总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。
*/

class Solution {        // 深度优先搜索
private:
    // 存储有向图
    vector<vector<int>> edges;
    // 标记每个节点的状态 0 = 未搜索 ；1 = 搜索中 ； 2 = 已完成
    vector<int> visited;
    // 数组来模拟栈，下标 0 为栈底，n-1 为栈顶
    vector<int> result;
    // 判断是否有环
    bool valid = true;
public:
    void dfs(int u){
        visited[u] = 1;         // 将节点标记为 搜索中

        for(int v:edges[u]){
            if(visited[v] == 0){
                dfs(v);
                if(!valid){
                    return;
                }
            }else if(visited[v] == 1){
                valid = false;
                return;
            }
        }

        visited[u] = 2;
        result.push_back(u);

    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for(const auto & info : prerequisites){
            edges[info[1]].push_back(info[0]);
        }
        // 挑选一个 未搜索 的点，开始进行深度优先搜索
        for(int i = 0;i<numCourses && valid;++i){
            if(!visited[i]){
                dfs(i);
            }
        }
        if(!valid){
            return {};
        }

        reverse(result.begin(),result.end());
        return result;
    }
};


class Solution2 {        // 广度优先搜索
private:
    // 存储有向图
    vector<vector<int>> edges;
    // 存储每个节点的 入度
    vector<int> indeg;
    // 存储答案
    vector<int> result;

public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for(const auto& info : prerequisites){
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }
        
        queue<int> que;
        for(int i = 0;i<numCourses;i++){
            if(indeg[i] == 0){
                que.push(i);
            }
        }

        while(!que.empty()){
            int u = que.front();
            que.pop();
            result.push_back(u);
            for(int v:edges[u]){
                --indeg[v];
                if(indeg[v] == 0){
                    que.push(v);
                }
            }
        }

        if(result.size() != numCourses){
            return {};
        }

        return result;

    }
};




int main(int argc, char const *argv[])
{
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};
    Solution sol;
    vector<int> ans = sol.findOrder(numCourses,prerequisites);

    system("pause");
    return 0;
}
