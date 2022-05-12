#include<bits/stdc++.h>

using namespace std;

/*
由范围 [0,n] 内所有整数组成的 n + 1 个整数的排列序列可以表示为长度为 n 的字符串 s ，其中:

如果 perm[i] < perm[i + 1] ，那么 s[i] == 'I' 
如果 perm[i] > perm[i + 1] ，那么 s[i] == 'D' 
给定一个字符串 s ，重构排列 perm 并返回它。如果有多个有效排列perm，则返回其中 任何一个 。

示例 1：

输入：s = "IDID"
输出：[0,4,1,3,2]
*/

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int lo = 0,hi = n;
        vector<int> perm(n+1);
        for(int i = 0;i<n;i++){
            if(s[i] == 'I'){
                perm[i] = lo;
                lo++;
            }else{
                perm[i] = hi;
                hi--;
            }
        }
        perm[n] = lo;
        return perm;
    }
};

int main(int argc, char const *argv[])
{
    string s = "IDID";
    Solution sol;
    vector<int> vec = sol.diStringMatch(s);
    system("pause");
    return 0;
}
