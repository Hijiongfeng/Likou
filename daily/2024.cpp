#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*
一位老师正在出一场由 n 道判断题构成的考试，
每道题的答案为 true （用 'T' 表示）或者 false （用 'F' 表示）。
老师想增加学生对自己做出答案的不确定性，方法是 最大化 有 连续相同 结果的题数。
（也就是连续出现 true 或者连续出现 false）。

给你一个字符串 answerKey ，其中 answerKey[i] 是第 i 个问题的正确结果。
除此以外，还给你一个整数 k ，表示你能进行以下操作的最多次数：

每次操作中，将问题的正确答案改为 'T' 或者 'F' （也就是将 answerKey[i] 改为 'T' 或者 'F' ）。
请你返回在不超过 k 次操作的情况下，最大 连续 'T' 或者 'F' 的数目。

输入：answerKey = "TTFF", k = 2
输出：4
解释：我们可以将两个 'F' 都变为 'T' ，得到 answerKey = "TTTT" 。
总共有四个连续的 'T' 。

*/

/*

滑动窗口  与 1004 题类似 翻转求最大长度
统计窗口内T的数量 记录下来
T的数量大于k，左指针右移，等于T时 数量--；
ans 记录区间长度

（记录T时，是要把T变成F）
*/

class Solution {
private:
    int maxConsecutiveChar(string & answerkey,int k,char ch){
        int n = answerkey.size();
        int ans = 0;
        for(int left = 0,right = 0,sum = 0;right<n;right++){
            if(answerkey[right] == ch) sum++;
            while(sum > k){
                if(answerkey[left] == ch)
                    sum--;
                left++;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxConsecutiveChar(answerKey,k,'T'),maxConsecutiveChar(answerKey,k,'F'));
    }
};

int main(int argc, char const *argv[])
{
    string s = "TTFT";
    Solution sol;
    cout<<sol.maxConsecutiveAnswers(s,1);
    system("pause");
    return 0;
}
