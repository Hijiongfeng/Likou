#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

/*
给你一个排序后的字符列表 letters ，列表中只包含小写英文字母。
另给出一个目标字母 target，请你寻找在这一有序列表里比目标字母大的最小字母。

在比较时，字母是依序循环出现的。举个例子：

如果目标字母 target = 'z' 并且字符列表为 letters = ['a', 'b']，则答案返回 'a'

示例 1：

输入: letters = ["c", "f", "j"]，target = "a"
输出: "c"
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(char ch :  letters){
            if(ch > target)
                return ch;
        }
        return letters[0];
    }
};

int main(int argc, char const *argv[])
{
    vector<char> letters = {'c','f','g'};
    char  target = 'a';
    Solution sol;
    cout<<sol.nextGreatestLetter(letters,target)<<endl;

    system("pause");
    return 0;
}

