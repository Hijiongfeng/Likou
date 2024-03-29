#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
在柠檬水摊上，每一杯柠檬水的售价为 5 美元。

顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。

每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。

注意，一开始你手头没有任何零钱。

如果你能给每位顾客正确找零，返回 true ，否则返回 false 。
示例 1：

输入：[5,5,5,10,20]
输出：true
解释：
前 3 位顾客那里，我们按顺序收取 3 张 5 美元的钞票。
第 4 位顾客那里，我们收取一张 10 美元的钞票，并返还 5 美元。
第 5 位顾客那里，我们找还一张 10 美元的钞票和一张 5 美元的钞票。
由于所有客户都得到了正确的找零，所以我们输出 true。
*/
class Solution {
public:

    
    bool lemonadeChange(vector<int>& bills) {
        vector<int> earned;
        for(int i = 0;i<bills.size();i++){
            if(bills[i] == 5){                          // 收到5美元 就留下  不用找零
                earned.push_back(bills[i]);
            }
            if(bills[i] == 10){
                if(find(earned.begin(),earned.end(),5) != earned.end()){    // 收到10美元  找5美元的
                    earned.erase(find(earned.begin(),earned.end(),5));
                    earned.push_back(bills[i]);
                }else return false;
                
            }
            if(bills[i] == 20){                     // 收到20 美元的   找10美元+5美元  或者 3 张 5 美元的
                if(find(earned.begin(),earned.end(),10) != earned.end() && find(earned.begin(),earned.end(),5) != earned.end()){
                    earned.erase(find(earned.begin(),earned.end(),10));
                    earned.erase(find(earned.begin(),earned.end(),5));
                    earned.push_back(bills[i]);
                }else if(find(earned.begin(),earned.end(),5) != earned.end()){
                    earned.erase(find(earned.begin(),earned.end(),5));
                    if(find(earned.begin(),earned.end(),5) != earned.end()) earned.erase(find(earned.begin(),earned.end(),5));
                    else return false;
                    if(find(earned.begin(),earned.end(),5) != earned.end()) earned.erase(find(earned.begin(),earned.end(),5));
                    else return false;
                }else return false;   
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> bills{5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5};
    Solution sol;
    cout<<sol.lemonadeChange(bills)<<endl;
    system("pause");
    return 0;
}
