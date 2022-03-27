#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

/*
现有一份 n + m 次投掷单个 六面 骰子的观测数据，
骰子的每个面从 1 到 6 编号。观测数据中缺失了 n 份，你手上只拿到剩余 m 次投掷的数据。幸好你有之前计算过的这 n + m 次投掷数据的 平均值 。

给你一个长度为 m 的整数数组 rolls ，其中 rolls[i] 
是第 i 次观测的值。同时给你两个整数 mean 和 n 。

返回一个长度为 n 的数组，包含所有缺失的观测数据，
且满足这 n + m 次投掷的 平均值 是 mean 。
如果存在多组符合要求的答案，只需要返回其中任意一组即可。如果不存在答案，返回一个空数组。

k 个数字的 平均值 为这些数字求和后再除以 k 。

注意 mean 是一个整数，所以 n + m 次投掷的总和需要被 n + m 整除。

示例 1：

输入：rolls = [3,2,4,3], mean = 4, n = 2
输出：[6,6]
解释：所有 n + m 次投掷的平均值是 (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4 。
*/

class Solution {        //  这个方法会超时
    vector<int> path;
    vector<vector<int>>  result;
    void backtracking(vector<int> & candidates,int sum,int n,int startIndex){
        if(path.size() > n || accumulate(path.begin(),path.end(),0) > sum){
            
            return;
        }
        
        if(path.size() == n && accumulate(path.begin(),path.end(),0) == sum){
            result.push_back(path);
            return;
        }

        for(int i = startIndex;i<candidates.size();i++){
            path.push_back(candidates[i]);
            backtracking(candidates,sum,n,i);
            path.pop_back();
        }
    }
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int nSum = mean * (rolls.size() + n) - accumulate(rolls.begin(),rolls.end(),0);
        vector<int> ans;
        vector<int> candidates;
        for(int i = 1;i<=6;i++){
            candidates.push_back(i);
        }
        if(nSum / n > 6 || (nSum / n == 6 && nSum % n != 0) || nSum <= 0 || nSum < n){
            return {};
        }else{
            backtracking(candidates,nSum,n,0);
        }
        return result[0];
    }
};

class Solution2  {      // 模拟构造的方法
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int nSum = mean * (rolls.size() + n) - accumulate(rolls.begin(),rolls.end(),0);
        
        if(nSum / n > 6 || (nSum / n == 6 && nSum % n != 0) || nSum <= 0 || nSum < n){
            return {};
        }

        vector<int> ans(n,nSum / n);        // 平均分配
        int rem = nSum % n;
        for(int i = 0;i<rem;i++){   // 余数分配
            ans[i]++;
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    //vector<int> rolls = {4,1,4,3,3,5,3,5,4,2,3,1,2,6,2,4,2,5,5,5,2,2,4,6,6,5,3,1,5,1,1,1,3,1,2,1,3,2,2,5,2,1,6,5,2,2,5,2,5,3,1,2,6,3,6,1,1,6,1,3,5,5,3,5,5,3,1,6,5,1,6,4,1,3,3,6,3,3,3,6,1,3,2,4,4,5,6,6,3,4,3,2,5,6,2,6,5,1,4,4,5,2,2,6,4,2,3,5,3,3,4,6,3,6,2,3,1,2,2,5,2,3,5,5,3,4,1,4,4,3,4,5,4,3,4,1,3,2,5,1,5,4,3,6,5,2,1,1,2,2,6,5,6,4,1,6,5,5,6,3,5,3,2,6,2,3,5,6,6,3,4,5,6,6,3,1,5,4,6,6,3,3,2,5,6,3,2,1,3,1,6,6,5,4,2,5,5,1,4,5,3,5,1,3,4,3,5,3,5,3,6,3,6,4,2,3,2,4,1,1,1,6,1,3,5,3,4,4,3,6,1,6,2,1,4,1,2,6,4,3,4,2,5,2,6,1,4,1,1,5,5,4,2,3,4,5,1,5,1,4,6,6,3,6,6,1,6,2,5,3,6,2,5,3,3,3,6,4,5,3,3,3,6,3,2,6,3,2,3,3,5,5,5,3,6,5,1,6,4,5,1,4,1,5,1,3,3,1,5,5,6,4,6,2,5,2,1,3,5,6,5,4,5,2,1,6,6,6,5,5,5,6,1,4,6,4,4,5,5,3};
    vector<int> rolls = {1,5,6};
    int mean = 3,n = 4;
    Solution2 sol;
    vector<int> ans = sol.missingRolls(rolls,mean,n);
    
    system("pause");
    return 0;
}
