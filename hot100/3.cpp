#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int N = s.size();
        int left = 0,right = 0;
        unordered_set<char> ust;    // 记录出现的字符
        int ans = 1;
        for(; right<N ; right++){
            while(ust.find(s[right]) != ust.end()){     // 有重复的，就找到 删除(erase)
                if(ust.size() >= ans)
                    ans = ust.size();
                ust.erase(s[left]);
                left++;
            }
            ust.insert(s[right]);
        }
        return max<int>(ans,ust.size());    // 防止出现那些 没有重复的，就进不去那个while 导致ans的值不对，返回ust.size()
    }

    int lengthOfLongestSubstring2(string s){

        unordered_set<char> ch;
        int left = 0;
        int right = 0;
        int size = s.size();
        int res = 0;
        while (right < size)
        {
            if(ch.find(s[right]) != ch.end()){
                while (ch.find(s[right]) != ch.end())
                {
                    ch.erase(s[left]);
                    left++;
                }
                
            }
            ch.insert(s[right]);
            res = max(res, right - left + 1);
            right++;
            
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    // string s = "abcabcbb";
    string s = "pwwkew";
    Solution sol;
    cout<<sol.lengthOfLongestSubstring2(s)<<endl;
    return 0;
}
