#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

/*
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
说明：
所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:
输入: k = 3, n = 7
输出: [[1,2,4]]
*/

class Solution {     // 把所有包含 k个数 的集合都找出来， 判读是否 等于 目标值；；；
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int k, int n,int numstart){   
        if(path.size() == k){
            if(accumulate(path.begin(),path.end(),0) == n){
                res.push_back(path);
            }
            return;
        }
        for(int i= numstart;i<=9;i++){
            path.push_back(i);
            backtracking(k,n,i+1);
            path.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n == 0) return res;
        res.clear();
        path.clear();
        backtracking(k,n,1);
        return res;
    }
};

int main(int argc, const char** argv) {
    Solution sol;
    vector<vector<int>> final = sol.combinationSum3(3,9);
    for(auto& x:final){
        for(auto& y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}