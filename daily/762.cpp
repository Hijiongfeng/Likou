#include<iostream>
#include<vector>
#include<set>

using namespace std;

/*
给你两个整数 left 和 right ，在闭区间 [left, right] 范围内，统计并返回 计算置位位数为质数 的整数个数。

计算置位位数 就是二进制表示中 1 的个数。

例如， 21 的二进制表示 10101 有 3 个计算置位。
*/

class Solution {
private:
    set<int> st = {2 ,3 ,5 ,7 ,11 ,13 ,17 ,19 ,23 ,29 ,31 };
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left;i<=right;i++){
            int num = 0;
            for(int j = 31;j>=0;j--){
                if(i >> j & 1)
                    num++;
            }
            if(st.find(num) != st.end())
                ans++;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int left = 10,right = 15;
    int a = __builtin_popcount(10);
    Solution sol;
    cout<<sol.countPrimeSetBits(left,right)<<endl;
    system("pause");
    return 0;
}
