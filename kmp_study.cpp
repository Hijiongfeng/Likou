#include<iostream>
#include<vector>
#include<string>
#include<string.h>

using namespace std;

/*      28 题
KMP的经典思想就是:当出现字符串不匹配时，可以记录一部分之前已经匹配的文本内容，利用这些信息避免从头再去做匹配。

所以如何记录已经匹配的文本内容，是KMP的重点，也是next数组肩负的重任。

next数组就是一个前缀表（prefix table）。

前缀表是用来回退的，它记录了模式串与主串(文本串)不匹配的时候，模式串应该从哪里开始重新匹配。

next 数组：记录下标i之前（包括i）的字符串中，有多大长度的相同前缀后缀

前缀是指不包含最后一个字符的所有以第一个字符开头的连续子串；
后缀是指不包含第一个字符的所有以最后一个字符结尾的连续子串

*/

void getNext(int *next,const string &s){
    // j 代表 前缀的末尾；也代表 i（包括i）之前最长相等前后缀的长度，也就是 next 数组的值
    // i 代表 后缀的末尾，从后往前 
    /*
    1. 初始化 i，j
    2. 处理前后缀不相等的情况   
    3. 处理前后缀相等的情况
    4. 更新next数组
    */
    int j = 0;

    next[0] = 0;

    for(int i = 1;i<s.size();i++){
        while(j > 0 && s[i] != s[j]){
            j = next[j-1];         // 前后不相等，用前一个进行匹配；要一直更新，用while
        }
        if(s[i] == s[j]){   // 相等的情况
            j++;
        }
        next[i] = j;        // 更新next数组
    }
}


int strStr(string shaystack,string needle){
    if(needle.size() == 0) return 0;
    int *next = new int[needle.size()];
    getNext(next,needle);
    int j = 0;
    for(int i = 0;i < shaystack.size();i++){
        while(j > 0 && shaystack[i] != needle[j]){      //  不相等
            j = next[j - 1];
        }
        if(shaystack[i] == needle[j]){          // 相等
            j++;
        }
        if(j == needle.size()){
            return i-needle.size()+1;
        }
    }
    delete[] next;
    return -1;
}


int main(int argc, char const *argv[])
{   string s = "aabaabaaf"; 
    string t = "aabaaf";
    cout<<strStr(s,t)<<endl;
    cout<<strstr("aabaabaaf","aabaaf")<<endl;       // C 内置函数
    // int *next = new int[t.size()];
    // getNext(next,t);
    // for(int i = 0;i<t.size();i++){
    //     cout<<next[i]<<endl;
    // }
    // delete[] next;
    system("pause");
    return 0;
}
