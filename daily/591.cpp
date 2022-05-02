#include<bits/stdc++.h>

using namespace std;

/*
给定一个表示代码片段的字符串，你需要实现一个验证器来解析这段代码，并返回它是否合法。
合法的代码片段需要遵守以下的所有规则：

代码必须被合法的闭合标签包围。否则，代码是无效的。
闭合标签（不一定合法）要严格符合格式：<TAG_NAME>TAG_CONTENT</TAG_NAME>。其中，
<TAG_NAME>是起始标签，</TAG_NAME>是结束标签。起始和结束标签中的 TAG_NAME 应当相同。
当且仅当 TAG_NAME 和 TAG_CONTENT 都是合法的，闭合标签才是合法的。
合法的 TAG_NAME 仅含有大写字母，长度在范围 [1,9] 之间。否则，该 TAG_NAME 是不合法的。
合法的 TAG_CONTENT 可以包含其他合法的闭合标签，cdata （请参考规则7）和任意字符
（注意参考规则1）除了不匹配的<、不匹配的起始和结束标签、不匹配的或带有不合法 TAG_NAME
 的闭合标签。否则，TAG_CONTENT 是不合法的。
一个起始标签，如果没有具有相同 TAG_NAME 的结束标签与之匹配，是不合法的。
反之亦然。不过，你也需要考虑标签嵌套的问题。
一个<，如果你找不到一个后续的>与之匹配，是不合法的。并且当你找到一个<或</时，
所有直到下一个>的前的字符，都应当被解析为 TAG_NAME（不一定合法）。
cdata 有如下格式：<![CDATA[CDATA_CONTENT]]>。CDATA_CONTENT 的范围被定义成 
<![CDATA[ 和后续的第一个 ]]>之间的字符。
CDATA_CONTENT 可以包含任意字符。cdata 的功能是阻止验证器解析CDATA_CONTENT
，所以即使其中有一些字符可以被解析为标签（无论合法还是不合法），也应该将它们视为常规字符。
*/

class Solution {
public:
    bool isValid(string code) {
        int n = code.size();
        stack<string> tags;

        int i = 0;
        while (i < n) {
            if (code[i] == '<') {   //  开始第一个 <
                if (i == n - 1) {
                    return false;
                }
                if (code[i + 1] == '/') {       // 如果下一个是 '/' 则为结束标签
                    int j = code.find('>', i);
                    if (j == string::npos) {
                        return false;
                    }
                    string tagname = code.substr(i + 2, j - (i + 2));
                    if (tags.empty() || tags.top() != tagname) {
                        return false;
                    }
                    tags.pop();
                    i = j + 1;
                    if (tags.empty() && i != n) {
                        return false;
                    }
                }
                else if (code[i + 1] == '!') {      // 如果是 '!' 则为CDATA
                    if (tags.empty()) {
                        return false;
                    }
                    string cdata = code.substr(i + 2, 7);
                    if (cdata != "[CDATA[") {
                        return false;
                    }
                    int j = code.find("]]>", i);
                    if (j == string::npos) {
                        return false;
                    }
                    i = j + 1;
                }
                else {  
                    int j = code.find('>', i);
                    if (j == string::npos) {
                        return false;
                    }
                    string tagname = code.substr(i + 1, j - (i + 1));
                    if (tagname.size() < 1 || tagname.size() > 9) {
                        return false;
                    }
                    if (!all_of(tagname.begin(), tagname.end(), [](unsigned char c) { return isupper(c); })) {  //看内容是否正确
                        return false;
                    }
                    tags.push(move(tagname));
                    i = j + 1;
                }
            }
            else {
                if (tags.empty()) {
                    return false;
                }
                ++i;
            }
        }

        return tags.empty();
    }
};

int main(int argc, char const *argv[])
{unordered_set<int> num_set;
    string code = "<DIV>This is the first line <![CDATA[<div>]]></DIV>";
    Solution sol;
    cout<<sol.isValid(code)<<endl;
    system("pause");
    return 0;
}
