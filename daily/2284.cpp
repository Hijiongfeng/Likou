#include<bits/stdc++.h>

using namespace std;

/*
给你一个聊天记录，共包含 n 条信息。给你两个字符串数组 messages 和 senders ，
其中 messages[i] 是 senders[i] 发出的一条 信息 。

一条 信息 是若干用单个空格连接的 单词 ，信息开头和结尾不会有多余空格。
发件人的 单词计数 是这个发件人总共发出的 单词数 。注意，一个发件人可能会发出多于一条信息。

请你返回发出单词数 最多 的发件人名字。如果有多个发件人发出最多单词数，
请你返回 字典序 最大的名字。

注意：

字典序里，大写字母小于小写字母。
"Alice" 和 "alice" 是不同的名字。

示例 1：

输入：messages = ["Hello userTwooo","Hi userThree","Wonderful day Alice","Nice day userThree"], senders = ["Alice","userTwo","userThree","Alice"]
输出："Alice"
解释：Alice 总共发出了 2 + 3 = 5 个单词。
userTwo 发出了 2 个单词。
userThree 发出了 3 个单词。
由于 Alice 发出单词数最多，所以我们返回 "Alice" 。
*/

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int> sen_mp;
        for(int i = 0;i<senders.size();i++){
            string str = messages[i];
            stringstream ss(str);
            string temp;
            int count = sen_mp.count(senders[i]) ? sen_mp[senders[i]] : 0;
            while(ss >> temp){
                count++;
            }
            sen_mp[senders[i]] = count;
        }

        multimap<int,string,greater<int>> mul_mp;

        for(auto & [a,b] : sen_mp){
            mul_mp.insert({b,a});
        }
        
        auto it = mul_mp.begin();
        vector<string> ans;
        for(auto & [a,b] : mul_mp){
            if(a == it->first)
                ans.emplace_back(b);
            else
                break;
        }
        sort(ans.begin(),ans.end());
        return ans[ans.size()-1];
    }
};

int main(int argc, char const *argv[])
{
    vector<string> messages = {"Hello userTwooo","Hi userThree","Wonderful day Alice","Nice day userThree"};
    vector<string> senders = {"Alice","userTwo","userThree","Alice"};
    Solution sol;
    cout<<sol.largestWordCount(messages,senders)<<endl;
    system("pause");
    return 0;
}
