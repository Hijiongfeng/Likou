#include<bits/stdc++.h>

using namespace std;

/*
Alice 管理着一家公司，并租用大楼的部分楼层作为办公空间。
Alice 决定将一些楼层作为 特殊楼层 ，仅用于放松。

给你两个整数 bottom 和 top ，表示 Alice 租用了从 bottom 到 
top（含 bottom 和 top 在内）的所有楼层。另给你一个整数数组 special ，
其中 special[i] 表示  Alice 指定用于放松的特殊楼层。

返回不含特殊楼层的 最大 连续楼层数。

示例 1：

输入：bottom = 2, top = 9, special = [4,6]
输出：3
解释：下面列出的是不含特殊楼层的连续楼层范围：
- (2, 3) ，楼层数为 2 。
- (5, 5) ，楼层数为 1 。
- (7, 9) ，楼层数为 3 。
因此，返回最大连续楼层数 3 。
*/

/*
先排序，再遍历
*/

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int n = special.size();
        int ans = INT_MIN;;
        if(bottom < special[0]){
            int temp = special[0] - bottom;
            ans = max(ans,temp);
        }
        if(top > special[n-1]){
            int temp = top - special[n-1];
            ans = max(ans,temp);
        }
        for(int i = 1;i<n;i++){
            if(special[i] - special[i-1] > 1){
                int temp = special[i] - special[i-1]-1;
                ans = max(ans,temp);
            }
        }
        return ans;

    }
};

int main(int argc, char const *argv[])
{
    int a1 = 10;
    int a2 = 30;
    vector<int>special = {19,10,15};
    Solution sol;
    cout<<sol.maxConsecutive(a1,a2,special)<<endl;
    system("pause");
    return 0;
}
