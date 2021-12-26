#include<iostream>
#include<vector>

using namespace std;

/*
给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。

（当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）

示例 1:

输入: N = 10
输出: 9
*/
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strNum = to_string(n);
        int flag = strNum.size();
        for(int i = strNum.size()-1;i>0;i--){
            if(strNum[i-1] > strNum[i]){
                flag = i;
                strNum[i-1]--;
            }
        }
        for (int i = flag; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    cout<<sol.monotoneIncreasingDigits(1984)<<endl;
    system("pause");
    return 0;
}
