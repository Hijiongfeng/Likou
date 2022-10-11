#include<iostream>
#include<string>
#include<vector>

using namespace std;
/*
在一个由 'L' , 'R' 和 'X' 三个字符组成的字符串（例如"RXXLRXRXL"）中进行移动操作。
一次移动操作指用一个"LX"替换一个"XL"，或者用一个"XR"替换一个"RX"。
现给定起始字符串start和结束字符串end，请编写代码，当且仅当存在一系列移动操作使得start可以转换成end时， 返回True。

2337. 移动片段得到字符串

*/
/*
原始的L一定大于等于新的L
原始的R一定小于等于新的R
*/
class Solution {        // 双指针 
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        int i = 0,j = 0;
        while (i < n && j < n)
        {
            while(i < n && start[i] == 'X'){
                i++;
            }
            while(j < n && end[j] == 'X'){
                j++;
            }
            if(i < n && j < n){
                if(start[i] != end[j]){
                    return false;
                }
                if((start[i] == 'R' && i > j) || (start[i] == 'L' && i < j)){
                    return false;
                }
                i++;
                j++;
            }
        }

        while (i < n) {
            if (start[i] != 'X') {
                return false;
            }
            i++;
        }
        while (j < n) {
            if (end[j] != 'X') {
                return false;
            }
            j++;
        }
        return true;    
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string start = "RXXLRXRXL",end = "XRLXXRRLX";
    cout<<sol.canTransform(start,end)<<endl;

    system("pause");
    return 0;
}
