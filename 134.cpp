#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

/*
在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。

如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。

说明: 

如果题目有解，该答案即为唯一答案。
输入数组均为非空数组，且长度相同。
输入数组中的元素均为非负数。
示例 1:

输入: 
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

输出: 3

解释:
从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
因此，3 可为起始索引。
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {   // 如果 加油站的油小 则直接返回
        if(accumulate(gas.begin(),gas.end(),0)-accumulate(cost.begin(),cost.end(),0) < 0) return -1;
        vector<int> curDiff(gas.size(),0);
        for(int i = 0;i<gas.size();i++){
            curDiff[i] = gas[i] - cost[i];   // 算差值
        }
        int start = 0;
        int curSum = 0;
        for(int i=0;i<gas.size();i++){      
            curSum += curDiff[i];
            if(curSum<0){               // 差值和 为 负数  从下一个 开始。和变为 0 ；
                start = i+1;
                curSum = 0;
            }
        }
        return start;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> cost{3,4,5,1,2};
    vector<int> gas{1,2,3,4,5};
    Solution sol;
    cout<<sol.canCompleteCircuit(gas,cost)<<endl;
    system("pause");
    return 0;
}
