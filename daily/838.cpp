#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*
n 张多米诺骨牌排成一行，将每张多米诺骨牌垂直竖立。在开始时，同时把一些多米诺骨牌向左或向右推。

每过一秒，倒向左边的多米诺骨牌会推动其左侧相邻的多米诺骨牌。同样地，倒向右边的多米诺骨牌也会推动竖立在其右侧的相邻多米诺骨牌。

如果一张垂直竖立的多米诺骨牌的两侧同时有多米诺骨牌倒下时，由于受力平衡， 该骨牌仍然保持不变。

就这个问题而言，我们会认为一张正在倒下的多米诺骨牌不会对其它正在倒下或已经倒下的多米诺骨牌施加额外的力。

给你一个字符串 dominoes 表示这一行多米诺骨牌的初始状态，其中：

dominoes[i] = 'L'，表示第 i 张多米诺骨牌被推向左侧，
dominoes[i] = 'R'，表示第 i 张多米诺骨牌被推向右侧，
dominoes[i] = '.'，表示没有推动第 i 张多米诺骨牌。
返回表示最终状态的字符串。

输入：dominoes = "RR.L"
输出："RR.L"
解释：第一张多米诺骨牌没有给第二张施加额外的力。

输入：dominoes = ".L.R...LR..L.."
输出："LL.RR.LLRRLL.."


如果两边的骨牌同向，那么这段连续的竖立骨牌会倒向同一方向。
如果两边的骨牌相对，那么这段骨牌会向中间倒。
如果两边的骨牌相反，那么这段骨牌会保持竖立。

如果左侧没有被推倒的骨牌，则假设存在一块向左倒的骨牌；如果右侧没有被推倒的骨牌
则假设存在一块向右倒的骨牌。这样的假设不会破坏骨牌的最终状态，并且边界情况也可以落入到上述三种情况中。


*/

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int i = 0;
        char left = 'L';
        while(i < n){
            int j = i;
            while(j < n && dominoes[j] == '.'){
                j++;
            }
            char right = j < n ? dominoes[j] : 'R';
            if(left == right){                          // 左右相同
                while(i < j){
                    dominoes[i++] = right;
                }
            }else if(left == 'R' && right == 'L'){      // 都向内
                int k = j-1;
                while(i < k){
                    dominoes[i++] = left;
                    dominoes[k--] = right;
                }
            }

            left = right;
            i = j + 1;
        }
        return dominoes;
    }
};


int main(int argc, char const *argv[])
{
    string str = ".R.L";
    Solution sol;
    cout<<sol.pushDominoes(str)<<endl;
    system("pause");
    return 0;
}

