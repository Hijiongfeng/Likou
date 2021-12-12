#include <iostream>
#include <string>

using namespace std;
/*KMP算法*/
class Solution
{
public:
    /*  获取next数组的三个步骤
1.初始化 2.前后缀不相等 3. 前后缀相等 4. 更新next数组的值*/
    void getNext(int *next, const string &needle) // 只读取字符串的值，并不需要改变，常量引用
    {
        int j = 0;
        next[0] = j;
        for (int i = 1; i < needle.size(); i++)
        {
            while (j > 0 && needle[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (needle[i] == needle[j])
            {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
            return 0;
        int *next = new int;
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j])
            {
                j++;
            }
            if (j == (needle.size()))
            { // 文本串s里出现了模式串t
                return (i - needle.size()+1);
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    string str1 = "aabaabaafa";
    string str2 = "aabaaf";
    Solution sol;
    int *next = new int;
    sol.getNext(next, str2);
    for (int i = 0; i < 6; i++)
    {
        cout << next[i] << endl;
    }
    cout << sol.strStr(str1, str2) << endl;
    
    system("pause");
    return 0;
}
