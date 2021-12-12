#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    void removeExtraSpace(string &s){   //快慢双指针移除空格   与移除固定的数字  思想一致
        int slowIndex = 0,fastIndex = 0;
        while(s.size()>0 && fastIndex < s.size() && s[fastIndex] == ' '){
            fastIndex++;
        }
        for(;fastIndex < s.size();fastIndex++){   //遇到第一个空格  还是赋值；后面的空格才是  跳过
            if (fastIndex - 1 > 0
                && s[fastIndex - 1] == s[fastIndex]
                && s[fastIndex] == ' ') {
            continue;
        } else {
            s[slowIndex++] = s[fastIndex];
        }
        }
        
        if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') { // 去掉字符串末尾的空格
            s.resize(slowIndex - 1);
        } else {
            s.resize(slowIndex); // 重新设置字符串大小
        }
    }

    string reverseWords(string s) {
        removeExtraSpace(s);
        reverse(s.begin(),s.end());
        //cout<<*s.end()<<endl;
        for(string::iterator it=s.begin();it!=s.end();it++){
            string::iterator dit =it;
            //cout<<*dit<<endl;
            while(dit!=s.end() && (*dit)!=' '){
                dit++;
            }
            reverse(it,dit);
            it=dit;
            if(it == s.end()){ //最后一次 it已经等于s.end() 了  要判断一下
                break;
            }
        }
        return s;
    }
};

int main(int argc, const char** argv) {
    string str = "  Bob    Loves  Alice   ";
    Solution sol;
    cout<<sol.reverseWords(str)<<endl;
    system("pause");
    return 0;
}