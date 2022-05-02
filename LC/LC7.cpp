#include<bits/stdc++.h>

using namespace std;

/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。
示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
解释："amanaplanacanalpanama" 是回文串
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0,right = s.size() -1;
        while(left<right){
            while(left<right && !isalnum(s[left])){
                left++;
            }
            while(left<right && !isalnum(s[right])){
                right--;
            }
            if(isalnum(s[left]) && isalnum(s[right])){
                char a = tolower(s[left]);
                char b = towlower(s[right]);
                if(a==b){
                    right--;
                    left++;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    string s = "0P";
    Solution sol;
    cout<<sol.isPalindrome(s)<<endl;
    system("pause");
    return 0;
}
