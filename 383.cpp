#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
赎金信
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) { // 确定 magazine 时候包含 ransomNote
        vector<int> recore(26,0);                           // magazine 里面多，最后判断 相应的位置上时候有大于 0 的；
        for(int i = 0;i<ransomNote.size();i++){
            recore[ransomNote[i]-'a']++;
        }
        for(int i = 0;i<magazine.size();i++){
            recore[magazine[i]-'a']--;
        }
        for(int i = 0;i<ransomNote.size();i++){     // 确定  ransomMote 里面的字符 是否都在magazine 里面出现过
            if(recore[ransomNote[i]-'a'] > 0){
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{/*
"bg"
"efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj"
*/
    string str1 = "bg";
    string str2 = "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj";
    Solution sol;
    cout<<sol.canConstruct(str1,str2)<<endl;
    system("pause");
    return 0;
}
