#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
给定一个表示数据的整数数组 data ，返回它是否为有效的 UTF-8 编码。

UTF-8 中的一个字符可能的长度为 1 到 4 字节，遵循以下的规则：

对于 1 字节 的字符，字节的第一位设为 0 ，后面 7 位为这个符号的 unicode 码。
对于 n 字节 的字符 (n > 1)，第一个字节的前 n 位都设为1，第 n+1 位设为 0 ，
后面字节的前两位一律设为 10 。剩下的没有提及的二进制位，全部为这个符号的 unicode 码。
这是 UTF-8 编码的工作方式：

   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
注意：输入是整数数组。只有每个整数的 最低 8 个有效位 用来存储数据。
这意味着每个整数只表示 1 字节的数据。

输入：data = [197,130,1]
输出：true
解释：数据表示字节序列:11000101 10000010 00000001。
这是有效的 utf-8 编码，为一个 2 字节字符，跟着一个 1 字节字符。

*/

class Solution {
private:

    vector<int> conver(int n)
    {
        vector<int> m;
        for(int i =7; i>=0; i--)
        {
            m.push_back( ( (n>>i) & 1) );//与1做位操作，前面位数均为0
        }
        return m;
    }
public:
    bool validUtf8(vector<int>& data) {
        if(data.size() == 0) return false;
        vector<vector<int>> datavec;
        for(int i = 0;i<data.size();i++){
            vector<int> vec = conver(data[i]);
            datavec.push_back(vec);
        }
        for(int i = 0;i<datavec.size();){               // 纯模拟的一个过程
            int bit = 0;
            for(int j = 0;j<datavec[i].size();j++){
                if(datavec[i][j] == 1){
                    bit++;
                    if(bit > 4)
                        return false;
                }
                if(datavec[i][j] == 0)
                    break;
            }
            if(bit == 0 && datavec[i][0] == 0){
                i++;
                continue;
            } 
            if(bit == 1){
                if(datavec[i][0] !=0)
                    return false;
            }
            if(datavec[i][bit] != 0) return false;
            int newbit = bit;
            while(newbit != 0){
                newbit--;
                if(newbit > datavec.size()-1){
                    return false;
                }
                if(newbit == 0) break;
                if(datavec[i+newbit][0] == 1 && datavec[i+newbit][1] == 0){
                    
                    continue;
                }
                else
                    return false;
                
            }
            i += bit;
        }
        return true;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> data = {115,100,102,231,154,132,13,10};
    Solution sol;
    cout<<sol.validUtf8(data)<<endl;
    system("pause");
    return 0;
}
