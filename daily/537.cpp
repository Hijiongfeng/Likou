#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*
复数 可以用字符串表示，遵循 "实部+虚部i" 的形式，并满足下述条件：

实部 是一个整数，取值范围是 [-100, 100]
虚部 也是一个整数，取值范围是 [-100, 100]
i2 == -1
给你两个字符串表示的复数 num1 和 num2 ，请你遵循复数表示形式，返回表示它们乘积的字符串。

输入：num1 = "1+1i", num2 = "1+1i"
输出："0+2i"
解释：(1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/complex-number-multiplication
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        vector<int> realPart;
        vector<int> imaginaryPart;
        int position = 0;
        for(int i = 0;i<num1.size();i++){               // 提取 num1 

            if(num1[i] == '+'){
                string str1 = num1.substr(0,i);
                position = i+1;
                realPart.push_back(stoi(str1));
            }

            if(num1[i] == 'i'){
                string str2 = num1.substr(position,i-position);
                imaginaryPart.push_back(stoi(str2));
            }
            
        }

        for(int i = 1;i<num2.size();i++){

            if(num2[i] == '+'){
                string str1 = num2.substr(0,i);
                position = i + 1;
                realPart.push_back(stoi(str1));
            }

            if(num2[i] == 'i'){
                string str2 = num2.substr(position,i-position);
                imaginaryPart.push_back(stoi(str2));
            }
        }

        string res = "";

        int a1 = realPart[0] * realPart[1];
        int a2 = realPart[0] * imaginaryPart[1];
        int a3 = imaginaryPart[0] * realPart[1];
        int a4 = -imaginaryPart[0] * imaginaryPart[1];

        int real = a1 + a4;
        int imagin = a2 + a3;

        res += (to_string(real));
        res += "+";
        res += to_string(imagin);
        res += "i";

        return res;

    }
};

int main(int argc, char const *argv[])
{
    // string num1 = "1+1i";
    // string num2 = "1+1i";
    string num1 = "100+-76i";
    string num2 = "50+72i";
    Solution sol;
    cout<<sol.complexNumberMultiply(num1,num2)<<endl;
    system("pause");
    return 0;
}
