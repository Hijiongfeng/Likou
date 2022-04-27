#include<bits/stdc++.h>

using namespace std;

/*
罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII 
，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，
例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。
同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给你一个整数，将其转为罗马数字。
*/

class Solution {
    unordered_map<int,string> dict ={       // 哈希表找对应
        {1,"I"},
        {4,"IV"},
        {5,"V"},
        {9,"IX"},
        {10,"X"},
        {40,"XL"},
        {50,"L"},
        {90,"XC"},
        {100,"C"},
        {400,"CD"},
        {500,"D"},
        {900,"CM"},
        {1000,"M"},
    };                      
    vector<int> nums_dict = {1,4,5,9,10,40,50,90,100,400,500,900,1000};  // 数组找第一个比目标数组小的数
public:
    string intToRoman(int num) {
        string ans;
        while(num != 0){
            int it = 0;
            for(int a : nums_dict){
                if(a <= num){
                    it = a;
                }else{
                    break;
                }
            }
            ans += dict[it];
            num -= it;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int num = 2934;
    Solution sol;
    cout<<sol.intToRoman(num)<<endl;
    system("pause");
    return 0;
}
