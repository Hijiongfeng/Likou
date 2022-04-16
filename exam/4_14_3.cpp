#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<limits.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int n0 = count(s.begin(), s.end(), '0');
        int n1 = count(s.begin(), s.end(), '1');
        int res = INT_MAX;
        // "1010..."
        if (n1 == (n + 1) / 2 && n0 == n / 2){   // 不同字符个数相等
            int diff1 = 0;
            for (int i = 0; i < n; ++i){
                if (s[i] - '0' == i % 2){   // 对应位数不同
                    ++diff1;
                }
            }
            res = min(res, diff1 / 2);
        }
        // "0101..."
        if (n0 == (n + 1) / 2 && n1 == n / 2){   // 不同字符个数相等
            int diff2 = 0;
            for (int i = 0; i < n; ++i){
                if (s[i] - '0' != i % 2){   // 对应位数不同
                    ++diff2;
                }
            }
            res = min(res, diff2 / 2);
        }
        if (res == INT_MAX){
            return -1;   // 不存在
        }
        else {
            return res;
        }
    }
};

int main(int argc, char const *argv[])
{
    string str;
    cin>>str;
    Solution sol;
    cout<<sol.minSwaps(str)<<endl;
    system("pause");
    return 0;
}
