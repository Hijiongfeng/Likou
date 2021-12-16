#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

/*
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，
找出 candidates 中可以使数字和为目标数 target 的 所有不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

对于给定的输入，保证和为 target 的不同组合数少于 150 个。

*/

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& vec,int target,int sum,int startindex){
        if(sum > target){
            return;
        }
        if(sum == target){
            res.push_back(path);
            return;
        }                                         // 用 startindex 是在 同一个 数组上进行操作；
        for(int i=startindex;i<vec.size() && sum+vec[i] <= target;i++){   // 用 startindex 确保不会去到当前值前面的数值  不加 1 ，可以去本身，加一 不取本身。
            sum += vec[i];
            path.push_back(vec[i]);
            backtracking(vec,target,sum,i);
            sum -= vec[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size() == 0) return res;
        backtracking(candidates,target,0,0);
        return res;
    }
};

// 版本一
class Solution2 {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i); // 不用i+1了，表示可以重复读取当前的数
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

int main(int argc, const char** argv) {
    vector<int> num = {2,3,6,7};
    Solution sol;
    vector<vector<int>> final = sol.combinationSum(num,7);
    for(auto& x:final){
        for(auto& y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}