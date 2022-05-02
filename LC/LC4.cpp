#include<bits/stdc++.h>

using namespace std;

/*
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1：

输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int flag = 0;
        for(int i = digits.size() -1;i>=0;i--){
            int temp;
            if(i == digits.size()-1){
                temp = digits[i] + 1 + flag;
            }else{
                temp = digits[i] + flag;
            }
            if(temp <= 9){
                ans.push_back(temp);
                flag = 0;
            }else{
                ans.push_back(0);
                flag = 1;
            }
        }
        if(flag){
            ans.push_back(1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> digit = {1,2,3};
    system("pause");
    return 0;
}
