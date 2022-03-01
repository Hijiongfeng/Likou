#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。


输入：s = "PAYPALISHIRING", numRows = 4
输出："PINALSIGYAHRPI"
解释：
P     I    N
A   L S  I G
Y A   H R
P     I
*/

class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        vector<vector<char>> c_Matrix(numRows,vector<char> (s.size(),' '));
        //int N = numRows + numRows - 2;
        int row = 0,col = 0;
        bool flag = true;
        if(numRows == 1) return s;
        for(int i = 0;i<s.size();){  // i += N
            if(flag == true){                       // 如果 flag == true， 证明是在 往下走
                c_Matrix[row][col] = s[i];
                row++;
                i++;
                if(i == s.size()) break;
                if(row == numRows - 1){
                    flag = false;
                    c_Matrix[row][col] = s[i];
                } 
            }
            
            if(flag == false){                      // 如果 flag == false ，证明是在 斜着往上走。
                row--;
                col++;
                i++;
                c_Matrix[row][col] = s[i];
                if(i == s.size()) break;
                if(row == 0) flag = true;
            }
        }
        for(auto & a : c_Matrix){               // 遍历
            for(auto & b : a){
                if(isalpha(b) || b == ',' || b == '.')   // s 由英文字母（小写和大写）、',' 和 '.' 组成
                    res.push_back(b);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{   
    string str = "PAYPALISHIRING";
    //string str = "Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.";
    int n = 4;
    Solution sol;
    cout<<sol.convert(str,n)<<endl;
    system("pause");
    return 0;
}
