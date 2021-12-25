#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。

示例：
输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8] 解释： 划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[27]={0};
        for(int i = 0;i<s.size();i++){      // 统计各个位置出现的 最大位置
            hash[s[i]-'a'] = i;
        }
        vector<int> result;
        int left = 0;
        int right = 0;
        for(int i = 0;i<s.size();i++){
            right = max(right,hash[s[i] - 'a']);
            if(i == right){         //  如果 i 达到了最大的 位置 证明 出现了一个区间 ，
                result.push_back(right-left+1);
                left = i+1;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    string str = "ababcbacadefegdehijhklij";
    Solution sol;
    vector<int> final = sol.partitionLabels(str);
    for(auto x:final){
        cout<<x<<endl;
    }
    system("pause");
    return 0;
}
