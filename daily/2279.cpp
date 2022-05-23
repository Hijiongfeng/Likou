#include<bits/stdc++.h>

using namespace std;

/*
现有编号从 0 到 n - 1 的 n 个背包。给你两个下标从 0 开始的整数数组 capacity 和 rocks 。第 i 个背包最大可以装 capacity[i] 块石头，当前已经装了 rocks[i] 块石头。另给你一个整数 additionalRocks ，表示你可以放置的额外石头数量，石头可以往 任意 背包中放置。

请你将额外的石头放入一些背包中，并返回放置后装满石头的背包的 最大 数量。

示例 1：

输入：capacity = [2,3,4,5], rocks = [1,2,4,4], additionalRocks = 2
输出：3
解释：
1 块石头放入背包 0 ，1 块石头放入背包 1 。
每个背包中的石头总数是 [2,3,4,4] 。
背包 0 、背包 1 和 背包 2 都装满石头。
总计 3 个背包装满石头，所以返回 3 。
可以证明不存在超过 3 个背包装满石头的情况。
注意，可能存在其他放置石头的方案同样能够得到 3 这个结果。
*/

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> diffNum(n);
        for(int i = 0;i<n;i++){
            diffNum[i] = capacity[i] - rocks[i];    // 求差值
        }
        sort(diffNum.begin(),diffNum.end());        // 排序
        int i = 0;
        int ans = 0;
        while(i < n && additionalRocks > 0){
            if(diffNum[i] == 0){
                ++ans;

            }else if(additionalRocks >= diffNum[i]){
                additionalRocks -= diffNum[i];
                diffNum[i] = 0;
                
                ++ans;
            }else if(additionalRocks < diffNum[i]){
                break;
            }
            i++;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> capacity = {2,3,4,5};
    vector<int> rocks = {1,2,4,4};
    int additionalRocks = 2;
    Solution sol;
    cout<<sol.maximumBags(capacity,rocks,additionalRocks)<<endl;
    system("pause");
    return 0;
}
