#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*
给你一个长桌子，桌子上盘子和蜡烛排成一列。给你一个下标从 0 开始的字符串 s ，
它只包含字符 '*' 和 '|' ，其中 '*' 表示一个 盘子 ，'|' 表示一支 蜡烛 。

同时给你一个下标从 0 开始的二维整数数组 queries ，
其中 queries[i] = [lefti, righti] 表示 子字符串 s[lefti...righti] 
（包含左右端点的字符）。对于每个查询，你需要找到 子字符串中 在 两支蜡烛之间 的盘子的 数目 。
如果一个盘子在 子字符串中 左边和右边 都 至少有一支蜡烛，那么这个盘子满足在 两支蜡烛之间 。

比方说，s = "||**||**|*" ，查询 [3, 8] ，表示的是子字符串 "*||**|" 。
子字符串中在两支蜡烛之间的盘子数目为 2 ，子字符串中右边两个盘子在它们左边和右边 都 至少有一支蜡烛。
请你返回一个整数数组 answer ，其中 answer[i] 是第 i 个查询的答案。

*/

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> prex(s.size(),0);
        vector<int> res;
        int count = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '*'){
                count++;
            }
            if(s[i] == '|'){
                prex[i] = count;
            }
        }

        for(int i = 0;i<queries.size();i++){
            int left = queries[i][0];
            int right = queries[i][1];
            while(s[left] != '|' || s[right] != '|'){
                if(s[left] != '|'){
                    left++;
                }
                if(s[right] != '|'){
                    right--;
                }
                if(left > right){
                    break;
                }
            }
            // while(s[right] != '|'){
            //     right--;
            // }
            if(left > right){
                res.push_back(0);
            }else{
                res.push_back(prex[right] - prex[left]);
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> preSum(n);                      // preSum 保存盘子的数目  
        for (int i = 0, sum = 0; i < n; i++) {
            if (s[i] == '*') {
                sum++;
            }
            preSum[i] = sum;
        }
        vector<int> left(n);                        // 左数组 保存 左边 蜡烛的位置
        for (int i = 0, l = -1; i < n; i++) {
            if (s[i] == '|') {
                l = i;
            }
            left[i] = l;
        }
        vector<int> right(n);                       // 右数组 保存 右边 蜡烛的位置
        for (int i = n - 1, r = -1; i >= 0; i--) {
            if (s[i] == '|') {
                r = i;
            }
            right[i] = r;
        }
        vector<int> ans;
        for (auto& query : queries) {
            int x = right[query[0]], y = left[query[1]];
            ans.push_back(x == -1 || y == -1 || x >= y ? 0 : preSum[y] - preSum[x]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    // string s = "**|**|***|";
    // vector<vector<int>> queries = {{2,5},{5,9}};
    string s = "***|**|*****|**||**|*";
    vector<vector<int>> queries = {{1,17},{4,5},{14,17},{5,11},{15,16}};
    Solution2 sol;
    vector<int> res = sol.platesBetweenCandles(s,queries);
    for(auto & a : res)
    {
        cout<<a<<endl;
    }
    system("pause");
    return 0;
}
