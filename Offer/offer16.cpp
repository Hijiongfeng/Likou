#include<iostream>
#include<vector>

using namespace std;

/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。
*/

class Solution {
private:
    double qpow(double x,long n){       // 快速幂
        if(n == 0){
            return 1;
        }else if(n % 2 == 0){
            double temp = qpow(x, n/2);
            return temp * temp;
        }else if(n % 2 == 1){
            return qpow(x,n-1) * x;
        }
        return 0;
    }
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(x == 1) return 1;
        if(x == -1 && n == INT_MAX) return -1;      // 哈哈 考虑特殊情况
        if(x == -1 && n == INT_MIN) return 1;
        bool flag = true;
        if(n < 0) flag = false;
        long p = abs(n);
        double res = qpow(x,p);
        if(flag){
            return res;
        }
        return  res == 0 ? 0 : 1 / res;
    }
};

int main(int argc, char const *argv[])
{
    double x = -1.0;
    int n = -2147483648;
    Solution sol;
    cout<<sol.myPow(x,n)<<endl;
    system("pause");
    return 0;
}
