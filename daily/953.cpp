#include<bits/stdc++.h>

using namespace std;

/*
某种外星语也使用英文小写字母，但可能顺序 order 不同。
字母表的顺序（order）是一些小写字母的排列。

给定一组用外星语书写的单词 words，以及其字母表的顺序 order，
只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回 false。

示例 1：

输入：words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
输出：true
解释：在该语言的字母表中，'h' 位于 'l' 之前，所以单词序列是按字典序排列的。

*/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> order_mp;
        for(int i = 0;i<order.size();i++){
            order_mp[order[i]] = i;
        }
        order_mp['\0'] = -1;
        if(words.size() == 1) return true;

        for(int i = 1;i<words.size();i++){
            int index = 0;
            int n = min(words[i-1].size(),words[i].size());
            char pt1 = words[i-1][index];
            char pt2 = words[i][index];
            while(pt1 == pt2 && index < n){
                index++;
                pt1 = words[i-1][index];
                pt2 = words[i][index];
            }
            if(order_mp[pt1] > order_mp[pt2]){
                return false;
            }
        }
        return true;
    }
};


int main(int argc, char const *argv[])
{
    vector<string> words = {"aa","a"};
    string order = "abcdefghijklmnopqrstuvwxyz";
    Solution sol;
    cout<<sol.isAlienSorted(words,order)<<endl;
    system("pause");
    return 0;
}
