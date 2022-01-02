#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*
给你一个二进制字符串数组 strs 和两个整数 m 和 n 。

请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。

如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

示例 1：

输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3 输出：4

解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
 其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。

示例 2： 输入：strs = ["10", "0", "1"], m = 1, n = 1 输出：2 解释：最大的子集是 {"0", "1"} ，所以答案是 2
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {   // 三维，背包二维
        vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>> (m+1,vector<int> (n+1,0)));

        int c0 = 0,c1 = 0;
        for(char c:strs[0]){
            if(c == '0') c0++;
            else c1++;
        }

        for(int i = 0;i<=m;i++){
            for(int j = 0;j<=n;j++){
                if(i >= c0 && j>= c1) dp[0][i][j] = 1;
            }
        }

        for(int k = 1;k<strs.size();k++){        // 背包从 1 开始索引
            int zeroNuns = 0,oneNums = 0;
            for(char &c:strs[k]){
                if(c == '0') zeroNuns++;            // 要先把物品循环玩，统计出0和1的个数
                else oneNums++;
            }
            for(int i = 0;i<=m;i++){        // i 为 0 的数目
                for(int j = 0;j<=n;j++){    // j 为 1 的数目
                    if(i>=zeroNuns && j>= oneNums) dp[k][i][j] = max(dp[k-1][i][j],dp[k-1][i-zeroNuns][j-oneNums] + 1);     // 要么是前一个的，要么是 这个能装下，要腾出空间给他
                    else dp[k][i][j] = dp[k-1][i][j];
                    }
                }
            }
        return dp[strs.size()-1][m][n];
    }
};

int main(int argc, char const *argv[])
{
    vector<string> strs{"10", "0001", "111001", "1", "0"};
    int m = 5,n = 3;
    Solution sol;
    cout<<sol.findMaxForm(strs,m,n)<<endl;
    system("pause");
    return 0;
}
