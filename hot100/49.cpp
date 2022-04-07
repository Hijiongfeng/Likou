#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。

示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

*/
/*
由于互为字母异位词的两个字符串包含的字母相同，
因此对两个字符串分别进行排序之后得到的字符串一定是相同的，
故可以将排序之后的字符串作为哈希表的键。

*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>> mp;
        vector<vector<string>> ans;
        auto vec = strs;
        for(int i = 0;i<strs.size();i++){
            sort(strs[i].begin(),strs[i].end());    // 排序后的 作为唯一的键 ，索引作为值
            mp[strs[i]].push_back(i);
        }
        for(auto &[a,b] : mp){
            vector<string> temp;
            for(int i:b){
                temp.push_back(vec[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    //vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> strs = {"a"};
    Solution sol;
    vector<vector<string>> ans = sol.groupAnagrams(strs);
    system("pause");
    return 0;
}
