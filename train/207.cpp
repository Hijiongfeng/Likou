#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，
其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

示例 1：

输入：numCourses = 2, prerequisites = [[1,0]]
输出：true
解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
*/

class Solution {    // 深度优先搜索
private:
    vector<vector<int>> edges;
    vector<int> visited;        // 三种状态
    bool vaild;
public:
    void dfs(int u){
        visited[u] = 1;             // 搜索中

        for(int v : edges[u]){
            if(visited[v] == 0){    // 0 是未搜索
                dfs(v);
                if(!vaild){
                    return;
                }
            }else if(visited[v] == 1){
                vaild = false;
                return;
            }
        }
        visited[u] = 2;             // 搜索结束
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for(const auto& info : prerequisites){
            edges[info[1]].push_back(info[0]);
        }
        for(int i = 0;i<numCourses && vaild;i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        return vaild;
    }
};

class Solution2 {       // 拓扑排序  广度优先搜索
private:
    vector<vector<int>> edges;      // 有向图 的邻接表
    vector<int> indge;    // 节点的入度
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {        //  这是一个有向图
        edges.resize(numCourses);
        indge.resize(numCourses);
        for(const auto& info : prerequisites){
            edges[info[1]].push_back(info[0]);
            ++indge[info[0]];
        }
        
        queue<int> que;
        for(int i = 0;i<numCourses;i++){
            if(indge[i] == 0)           // 将所有入度 为 0 的节点，放入队列中
                que.push(i);
        }

        int visited = 0;
        while(!que.empty()){
            int u = que.front();
            ++visited;
            que.pop();
            for(int v : edges[u]){
                --indge[v];             // 将其 相连节点 的 入度 减1；
                if(indge[v] == 0){      // 入度 为 0，放入队列中
                    que.push(v);
                }
            }
        }

        return visited == numCourses;

    }
};


int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
