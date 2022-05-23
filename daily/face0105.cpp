#include<bits/stdc++.h>

using namespace std;

/*
字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 
给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。
示例 1:

输入: 
first = "pale"
second = "ple"
输出: True
 

示例 2:

输入: 
first = "pales"
second = "pal"
输出: False
*/

class Solution {
public:
    bool oneEditAway(string first, string second) {
        if(first == second){        // 如果直接相等，直接返回 true；
            return true;
        }
        int m = first.size(),n = second.size();
        if(abs(m-n) >= 2) return false;         // 如果长度相差不小2，则无法通过一次编辑得到，返回 false；
        int FlAG = 1;               // 定义一个FLAG，表示只能操作一次
        int l = 0,r = 0;            // 两个指针 遍历
        if(m == n){                 // 如果两个字符串相等，则只能进行替换操作
            while(l < m && r < n){
                if(first[l] != second[r] && FlAG == 1){         // 遇到不等的字符，替换
                    first[l] = second[r];
                    FlAG--;
                }
                if(first[l] != second[r] && FlAG == 0){         // 如果下一个还是不相等的，直接返回false，
                    return false;
                }
                l++;
                r++;
            }
        }

        if(m < n){                  // 交换，保持第一个第一个字符长度长
            swap(first,second);
        }
        while(r < n){               // 如果长度不相等，只能进行删除或插入操作，这两种操作是等价的
            if(first[l] != second[r] && FlAG == 1){         // 不相等 删除
                first.erase(first.begin() + l);
                FlAG--;
            }
            if(first[l] != second[r] && FlAG == 0){         // 如果还有不相同，直接返回false；
                return false;
            }
            l++;
            r++;
        }
        if(FlAG == 1){              // pale和pal 这种情况，这个时候FALG还是等于1，这删除最后一个字符
            first.pop_back();
        }

        if(first != second){        // 判断是否相等，否则返回false
            return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    string first = "pale",second = "pal";
    Solution sol;
    cout<<sol.oneEditAway(first,second)<<endl;
    system("pause");
    return 0;
}
