#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
/*字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
*/

/*翻转字符串，双指针法  
每隔几个反转  在 for 循环上做文章
先整体翻转，在局部翻转
先局部翻转 在整体翻转*/
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(),s.begin()+n);
        reverse(s.begin()+n,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
};

int main(int argc, char const *argv[])
{
    string str = "abcdefg";
    Solution sol;
    cout<<sol.reverseLeftWords(str,2)<<endl;
    system("pause");
    return 0;
}
