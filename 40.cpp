#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;

/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

注意：解集不能包含重复的组合。 
*/

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& vec,int target,int startindex,vector<bool> used){  // 去除相同的元素，用一个used的数组
        if(accumulate(path.begin(),path.end(),0) > target){
            return;
        }
        if(accumulate(path.begin(),path.end(),0) == target){
            res.push_back(path);
            return;
        }
        for(int i = startindex;i<vec.size();i++){
            if(i>0 && vec[i] == vec[i-1] && used[i-1] == false){           // 这个去重的 逻辑 有点像 前面那个  三数之和，四数之和；
                continue;
            }
            path.push_back(vec[i]);
            used[i] = true;
            backtracking(vec,target,i+1,used);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<bool> used(candidates.size(),false);
        backtracking(candidates,target,0,used);
        return res;
    }
};

int main(int argc, const char** argv) {
    vector<int> num = {10,1,2,7,6,1,5};
    Solution sol;
    
    vector<vector<int>> final = sol.combinationSum2(num,8);
    for(auto& x:final){
        for(auto& y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}