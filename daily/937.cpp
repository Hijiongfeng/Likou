#include<bits/stdc++.h>

using namespace std;

/*
给你一个日志数组 logs。每条日志都是以空格分隔的字串，
其第一个字为字母与数字混合的 标识符 。

有两种不同类型的日志：

字母日志：除标识符之外，所有字均由小写字母组成
数字日志：除标识符之外，所有字均由数字组成
请按下述规则将日志重新排序：

所有 字母日志 都排在 数字日志 之前。
字母日志 在内容不同时，忽略标识符后，按内容字母顺序排序；在内容相同时，按标识符排序。
数字日志 应该保留原来的相对顺序。
返回日志的最终顺序。
*/

class Solution {
    static bool cmp(string& s1,string& s2){
        int n1 = s1.size();int n2 = s2.size();
        int i = s1.find(' ');
        int j = s2.find(' ');
        string str1_1 = s1.substr(0,i);string str1_2 = s1.substr(i+1,n1-i);
        string str2_1 = s2.substr(0,j);string str2_2 = s2.substr(j+1,n2-j);
        if(str1_2 == str2_2){
            return s1 < s2;
        }

        return str1_2 < str2_2;
        
    }
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> num_logs;
        vector<string> alp_logs;
        for(string str : logs){                 // 把字母日志和数字日志分开
            int j = str.find(' ',0);
            if(isdigit(str[j+1])){
                num_logs.emplace_back(str);
            }else{
                alp_logs.emplace_back(str);
            }
        }
        sort(alp_logs.begin(),alp_logs.end(),cmp);  // 自定义字母日志排序规则

        for(string s : num_logs){           // 把 数字日志插入到字母日志后面
            alp_logs.emplace_back(s);
        }

        return alp_logs;
    }
    
};

int main(int argc, char const *argv[])
{
    vector<string> logs = {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
    Solution sol;
    auto vec = sol.reorderLogFiles(logs);
    
    system("pause");
    return 0;
}
