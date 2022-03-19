#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

/*
你的任务是为一个很受欢迎的银行设计一款程序，
以自动化执行所有传入的交易（转账，存款和取款）。
银行共有 n 个账户，编号从 1 到 n 。
每个账号的初始余额存储在一个下标从 0 开始的整数数组 balance 中，
其中第 (i + 1) 个账户的初始余额是 balance[i] 。

请你执行所有 有效的 交易。如果满足下面全部条件，则交易 有效 ：

指定的账户数量在 1 和 n 之间，且
取款或者转账需要的钱的总数 小于或者等于 账户余额。
实现 Bank 类：

Bank(long[] balance) 使用下标从 0 开始的整数数组 balance 初始化该对象。

boolean transfer(int account1, int account2, long money) 
从编号为 account1 的账户向编号为 account2 的账户转帐 money 美元。如果交易成功，返回 true ，否则，返回 false 。

boolean deposit(int account, long money) 向编号为 account 
的账户存款 money 美元。如果交易成功，返回 true ；否则，返回 false 。

boolean withdraw(int account, long money) 从编号为 account 的账户取款 money 美元。
如果交易成功，返回 true ；否则，返回 false 。

思路：简单模拟即可

*/

class Bank {
private:
    map<int,long long> accounts;
    int _size = 0;
public:
    Bank(vector<long long>& balance) {
        for(int i = 0;i<balance.size();i++){
            accounts[i+1] = balance[i];
            _size++;
        }
    }
    
    bool transfer(int account1, int account2, long long money) {    //转账
        if(account1 <= 0 || account1 > _size ||
            account2 <=0 || account2 >_size)
            return false;
        if(accounts[account1] < money) return false;
        accounts[account1] -= money;
        accounts[account2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {        // 存款
        if(account <= 0 || account > _size){
            return false;
        }
        accounts[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {       // 取钱
        if(account <= 0 || account > _size){
            return false;
        }
        if(accounts[account] < money) return false;
        accounts[account] -= money;
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    system("pause");
    return 0;
}
