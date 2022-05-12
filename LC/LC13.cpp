#include<bits/stdc++.h>

using namespace std;

/*
给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。

示例 1：

输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

*/

class Solution {
    bool isPrime(int num){
        for(int i = 2;i <= sqrt(num);i++){      // 这样快一点
            if(num % i == 0){
                return  false;
            }
        }
        return true;
    }
public:
    int countPrimes(int n) {            // 暴力解法
        if(n == 0 || n == 1)
            return 0;
        int ans = 0;
        for(int i = 2;i<n;i++){
            if(isPrime(i)){
                ans++;
            }
        }
        return ans;
    }


    int countPrimes2(int n) {
        int count = 0;
        vector<bool> sings(n,true);     // 首先认为所有的数 都是质数
        for(int i = 2;i<n;i++){
            if(sings[i]){
                count++;
                for(int j = i + i;j<n;j+=i){    // 如果是当前 数的倍数，肯定不是质数，去除掉
                    sings[j] = false;
                }
            }
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    int n = 50000000;
    Solution sol;
    cout<<sol.countPrimes2(n)<<endl;
    system("pause");
    return 0;
}

