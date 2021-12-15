#include<iostream>
#include<vector>

using namespace std;

/*给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。

示例 1：

输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
private:
    vector<vector<int>> res;   // 全局变量 ，减少回溯的参数   
    vector<int> path;
    void backtracking(int n,int k,int startindex){
        if(path.size() == k){
            res.push_back(path);
        }
        for(int i = startindex;i<=n;i++){
            path.push_back(i);  //处理节点
            backtracking(n,k,i+1);  // 递归
            path.pop_back();    // 回溯，
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {    // n 为树的宽度，k 为树的深度
        if(k == 0) return res;
        backtracking(n,k,1);
        return res;
    }
};

int main(int argc, const char** argv) {
    Solution sol;
    vector<vector<int>> final = sol.combine(20,5);
    for(auto& x:final){
        for(auto& y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

    system("pause");
    return 0;
}