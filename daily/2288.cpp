#include<bits/stdc++.h>

using namespace std;

/*
句子 是由若干个单词组成的字符串，单词之间用单个空格分隔，
其中每个单词可以包含数字、小写字母、和美元符号 '$' 。
如果单词的形式为美元符号后跟着一个非负实数，那么这个单词就表示一个价格。

例如 "$100"、"$23" 和 "$6.75" 表示价格，而 "100"、"$" 和 "2$3" 不是。
注意：本题输入中的价格均为整数。

给你一个字符串 sentence  和一个整数 discount 。对于每个表示价格的单词，
都在价格的基础上减免 discount% ，并更新该单词到句子中。所有更新后的价格应该表示为一个 恰好保留小数点后两位 的数字。

返回表示修改后句子的字符串。
*/

class Solution {
    bool check(string& s){
        if(s[0] != '$' || s.size() == 1){
            return false;
        }
        for(int i = 1;i<s.size();i++){
            if(!isdigit(s[i])){
                return false;
            }
        }
        return true;
    }
public:
    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence);
        string res = "",temp;
        while(ss >> temp){
            if(check(temp)){
                long double new_num = stoll(temp.substr(1));
                long double a = ((100 - discount) / 100.0);
                new_num = new_num * a;
                string new_temp = to_string(new_num);
                int index = new_temp.find('.');
                new_temp.resize(index+3);
                temp = temp[0] + new_temp;
            }
            res += temp;
            res += " ";
        }
        res.pop_back();
        return res;
    }

    string discountPrices2(string sentence, int discount) {
        stringstream ss(sentence);
        string res = "",temp;
        while(ss >> temp){
            if(check(temp)){
                long double new_num = stoll(temp.substr(1));
                stringstream sss;
                sss << std::setiosflags(std::ios::fixed) << std::setprecision(2) << (new_num * (100.0 - discount) / 100.0);
                temp = temp[0] + sss.str();
            }
            res += temp;
            res += " ";
        }
        res.pop_back();
        return res;
    }
};

int main(int argc, char const *argv[])
{   
    string sentence = "$99999 $9999999999";
    int discount = 5;
    Solution sol;
    cout<<sol.discountPrices2(sentence,discount)<<endl;
    system("pause");
    return 0;
}
