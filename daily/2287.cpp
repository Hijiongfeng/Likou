#include<bits/stdc++.h>

using namespace std;

/*
给你两个下标从 0 开始的字符串 s 和 target 。
你可以从 s 取出一些字符并将其重排，得到若干新的字符串。

从 s 中取出字符并重新排列，返回可以形成 target 的 最大 副本数。
*/
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char,int> mp;
        for(char c : target){
            mp[c]++;
        }
        vector<int> vec(target.size(),0);
        for(int i = 0;i<target.size();i++){
            for(char & ch : s){
                if(ch == target[i]){
                    vec[i]++;
                }
            }
        }
        for(int i = 0;i<vec.size();i++){
            vec[i] = vec[i] / mp[target[i]];
        }
        return *min_element(vec.begin(),vec.end());
    }
};

int main(int argc, char const *argv[])
{
    string s = "abbaccaddaeea", target = "aaaaa";
    Solution sol;
    cout<<sol.rearrangeCharacters(s,target)<<endl;
    system("pause");
    return 0;
}
