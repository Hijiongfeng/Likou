#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }
        //将正在处理请求的服务器的处理结束时间和编号都放入一个优先队列 busy 中
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
        vector<int> requests(k);
        for (int i = 0; i < arrival.size(); i++) {
            // 如果队列头的第一个元素（时间）小于 当前请求到达的时间，就把这个服务器重新加入到可用，并且删除掉
            while (!busy.empty() && busy.top().first <= arrival[i]) {   
                available.insert(busy.top().second);
                busy.pop();
            }
            // 如果为空，就跳过
            if (available.empty()) {
                continue;
            }
            auto p = available.lower_bound(i % k);      // 找到服务器的编号
            if (p == available.end()) {                 // 服务器是一个环，最后一个 是第一个
                p = available.begin();
            }
            requests[*p]++;
            busy.emplace(arrival[i] + load[i], *p);     // 入队
            available.erase(p);                         // 服务器使用了之后，就从可用的删除掉
        }
        int maxRequest = *max_element(requests.begin(), requests.end());
        vector<int> ret;
        for (int i = 0; i < k; i++) {
            if (requests[i] == maxRequest) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    int k = 3;
    vector<int> arrival = {1,2,3,4,5};
    vector<int> load = {5,2,3,3,3}; 
    Solution sol;
    vector<int> ans = sol.busiestServers(k,arrival,load);
    system("pause");
    return 0;
}
