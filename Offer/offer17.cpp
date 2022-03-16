#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

/*
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。
比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

示例 1:

输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
*/

class Solution {
public:
    vector<int> printNumbers(int n) {       // 暴力解法 
        long long fl = pow(10,n) - 1;
        vector<int> res;
        for(long long i = 1;i<=fl;++i){
            res.push_back(i);
        }
        return res;
    }
};

class Solution2 {
private:
    vector<string> res;
    string s;
    char nums[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    void backtracking(int x,int len){    // x 表示当前位，len表示长度
        if(x == len){
            res.push_back(s);
            return;
        }
        int start = (x == 0) ? 1 : 0;
        for(int i = start;i<10;i++){
            s.push_back(nums[i]);
            backtracking(x + 1,len);
            s.pop_back();
        }
    }
public:
    vector<int> printNumbers(int n) {       // 大数解法
        for(int i = 1;i<n;i++){
            backtracking(0,i);
        }
        vector<int> ans;
        for(int i = 0;i<res.size();i++){
            ans.push_back(stoi(res[i]));
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    int n = 3;
    Solution2 sol;
    vector<int> vec = sol.printNumbers(n);
    for(int i = 0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    } 
    system("pause");
    return 0;
}
