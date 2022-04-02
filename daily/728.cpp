#include<iostream>
#include<vector>

using namespace std;

/*
自除数 是指可以被它包含的每一位数整除的数。

例如，128 是一个 自除数 ，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
自除数 不允许包含 0 。

给定两个整数 left 和 right ，返回一个列表，列表的元素是范围 [left, right] 内所有的 自除数 。

输入：left = 1, right = 22
输出：[1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
*/

class Solution {

public:
    bool check(int num){
        if(num <= 9) return true;
        int new_num = num;
        while(new_num){
            int temp = new_num % 10;
            if(temp == 0 || num % temp != 0)
                return false;
            new_num = new_num / 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left;i<=right;i++){
            if(check(i))
                ans.push_back(i);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int left = 1,right = 22;
    Solution sol;
    vector<int> ans = sol.selfDividingNumbers(left,right);
    system("pause");
    return 0;
}
