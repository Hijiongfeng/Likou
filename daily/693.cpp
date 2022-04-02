#include<iostream>
#include<vector>

using namespace std;

/*
给定一个正整数，检查它的二进制表示是否总是 0、1 交替出现：
换句话说，就是二进制表示中相邻两位的数字永不相同。

示例 1：

输入：n = 5
输出：true
解释：5 的二进制表示是：101
*/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> vec;
        bool flag = false;
        for(int i = 31;i>=0;i--){
            int temp = (n >> i) & 1;
            if(temp == 1){
                flag = true;
            }
            if(flag == true){
                vec.push_back(temp);
            }
        }
        for(int i = 0;i<vec.size() -1;i++){
            if(vec[i]==vec[i+1])
                return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    int n = 11;
    Solution sol;
    cout<<sol.hasAlternatingBits(n)<<endl;
    system("pause");
    return 0;
}
