#include<iostream>
#include<vector>

using namespace std;

/*
有两种特殊字符：

第一种字符可以用一个比特 0 来表示
第二种字符可以用两个比特(10 或 11)来表示、
给定一个以 0 结尾的二进制数组 bits ，如果最后一个字符必须是一位字符，则返回 true 。

输入: bits = [1, 0, 0]
输出: true
解释: 唯一的编码方式是一个两比特字符和一个一比特字符。
所以最后一个字符是一比特字符

思路：遍历数组，遇到 1 时，一定会把下面一个0 或者 1 吃掉，因此递进 2位
               遇到 0 时，就保存下来，递进一位,然后看最后 一个数组 是不是size == 1，而且 元素为 0

*/

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        vector<vector<int>> res;
        for(int i = 0;i<bits.size();    ){
            vector<int> temp;
            if(bits[i] == 1){
                temp.push_back(bits[i]);
                temp.push_back(bits[i+1]);
                res.push_back(temp);
                i=i+2;
            }else{
                temp.push_back(bits[i]);
                res.push_back(temp);
                i=i+1;
            }
        }

        if(res.back().size() == 1 && res.back()[0] == 0)
            return true;
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> bits = {0,1,1,1,0};
    Solution sol;
    cout<<sol.isOneBitCharacter(bits)<<endl;
    system("pause");
    return 0;
}
