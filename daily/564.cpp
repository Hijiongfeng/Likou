#include<iostream>
#include<vector>
#include<string>
#include<math.h>

using namespace std;

/*
给定一个表示整数的字符串 n ，返回与它最近的回文整数（不包括自身）。如果不止一个，返回较小的那个。

“最近的”定义为两个整数差的绝对值最小。

考虑到以上所有的可能，我们可以给出最终的方案：
分别计算出以下每一种可能的方案对应的回文整数，在其中找到与原数最近且不等于原数的数即为答案。

1.用原数的前半部分替换后半部分得到的回文整数。

2.用原数的前半部分加一后的结果替换后半部分得到的回文整数。

3.用原数的前半部分减一后的结果替换后半部分得到的回文整数。

4.为防止位数变化导致构造的回文整数错误，因此直接构造 999\dots 999999…999 和 100\dots 001100…001 作为备选答案。

*/

class Solution {
private:
    vector<long> getCandidates(const string & n){
        int len = n.size();
        vector<long> candidates = {         // 情况4
            (long)pow(10,len)+1,
            (long)pow(10, len - 1) - 1,
        };

        long selfPre = stol(n.substr(0,(len + 1) / 2));

        for(auto i : {selfPre-1, selfPre ,selfPre + 1 }){       // 情况 1,2,3  ；；
            string preFix = to_string(i);
            string candidate = preFix + string(preFix.rbegin()+ (len & 1),preFix.rend());
            candidates.push_back(stol(candidate));
        }

        return candidates;
    }

public:
    string nearestPalindromic(string n) {
        if(stoi(n) <= 10){
            int a = stoi(n);
            return to_string(a-1);
        }
        long selfNumber = stol(n), ans = -1;

        const vector<long>& candidates = getCandidates(n);

        for (auto& candidate : candidates) {
            if (candidate != selfNumber) {
                if (ans == -1 ||
                    abs(candidate - selfNumber) < abs(ans - selfNumber) ||
                    abs(candidate - selfNumber) == abs(ans - selfNumber) && candidate < ans) {
                    ans = candidate;
                }
            }
        }
        return to_string(ans);
    }
};


int main(int argc, char const *argv[])
{
    string s = "1999";
    Solution sol;
    cout<<sol.nearestPalindromic(s)<<endl;
    system("pause");
    return 0;
}
