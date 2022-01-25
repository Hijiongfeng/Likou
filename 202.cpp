#include<iostream>
#include<vector>
#include<set>

using namespace std;

/*
快乐数
编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果 可以变为  1，那么这个数就是快乐数。
如果 n 是快乐数就返回 true ；不是，则返回 false 。
*/

class Solution {
private:
    int getSum(int num){
        int sum = 0;
        while(num){
            int a = num % 10;   //  找到个位上的数
            //num = a;
            num = num / 10;
            sum += a * a;       // 找到除了个位上的数
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        set<int> num_set;
        while(true){
            if(n == 1){
                return true;
            }
            num_set.insert(n);
            n = getSum(n);
            if(num_set.find(n) != num_set.end()){
                return false;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    int n = 2;
    Solution sol;
    cout<<sol.isHappy(n)<<endl;
    system("pause");
    return 0;
}


