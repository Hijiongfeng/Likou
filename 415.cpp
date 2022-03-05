#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。

你不能使用任何內建的用于处理大整数的库（比如 BigInteger），
 也不能直接将输入的字符串转换为整数形式。
 示例 1：

输入：num1 = "11", num2 = "123"
输出："134"
示例 2：

输入：num1 = "456", num2 = "77"
输出："533"
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size() < num2.size())
            swap(num1,num2);
        int N1 = num1.size() - 1;
        int N2 = num2.size() - 1;
        string new_str;
        bool flag = false;
        while(N2 >= 0){
            
            int sum1 = (num1[N1] - '0') + (num2[N2] - '0') + flag;
            if(sum1 >= 10){
                flag = true;
            }else{
                flag = false;
            }
            new_str += to_string(sum1 % 10);
            //num1[N1] = sum1 % 10 + '0';
            N1--;
            N2--;
        }
        while(N1 >= 0){
            int sum2 = (num1[N1] - '0') + flag;
            if(sum2 < 10){
                flag = false;
            }
            new_str += to_string(sum2 % 10);
            N1--;
        }
        if(flag == true){
            new_str += "1";
        }
        reverse(new_str.begin(), new_str.end());
        return new_str;
    }
};


class Solution2 {
public:
    string addStrings(string num1, string num2) {
        int N1 = num1.size() -1,N2 = num2.size() -1,add = 0;
        string new_str;
        while(N1 >= 0 || N2 >= 0 || add != 0){
            int x = N1 >=0 ? num1[N1] - '0' : 0;
            int y = N2 >=0 ? num2[N2] - '0' : 0;
            int result = x + y + add;
            new_str += to_string(result % 10);
            add = result / 10;
            N1--;
            N2--;
        }
        reverse(new_str.begin(),new_str.end());
        return new_str;
    }
};



int main(int argc, char const *argv[])
{
    string num1 = "237",num2 = "284";
    Solution2 sol;
    cout<<sol.addStrings(num1,num2)<<endl;
    system("pause");
    return 0;
}
