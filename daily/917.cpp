#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*

给你一个字符串 s ，根据下述规则反转字符串：

所有非英文字母保留在原有位置。
所有英文字母（小写或大写）位置反转。
返回反转后的 s 。

示例 1：

输入：s = "ab-cd"
输出："dc-ba"

思路：双指针，遇到不是字母的，跳过即可

*/

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0,right = s.size()-1;
        while(left < right){
            if(isalpha(s[left]) && isalpha(s[right])){
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }

            if(!isalpha(s[left]) && isalpha(s[right])){
                left++;
            }
            if(isalpha(s[left]) && !isalpha(s[right])){
                right--;
            }

            if(!isalpha(s[left]) && !isalpha(s[right])){
                left++;
                right--;
            }

        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    string s = "7_28]";
    Solution sol;
    cout<<sol.reverseOnlyLetters(s)<<endl;

    system("pause");
    return 0;
}
