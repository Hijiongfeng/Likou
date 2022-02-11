#include<iostream>
#include<vector>

using namespace std;
/*
计算汉明距离
*/


class Solution {
public:
    int hammingDistance(int x, int y) {
        int s = x ^ y;        // 这是做 位或 运算；
        int ret = 0;
        while(s){
            ret += s & 1;   // 与 1 做位运算，最后一位是1 就加一 ；
            s >>= 1;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    int x = 1;
    int y = 4;
    Solution sol;
    cout<<sol.hammingDistance(x,y)<<endl;
    system("pause");
    return 0;
}
