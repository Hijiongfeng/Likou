#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*
我们要把给定的字符串 S 从左到右写到每一行上，
每一行的最大宽度为100个单位，如果我们在写某个字母的时候会使这行超过了100 个单位，
那么我们应该把这个字母写到下一行。我们给定了一个数组 widths ，
这个数组 widths[0] 代表 'a' 需要的单位， widths[1] 代表 'b'
 需要的单位，...， widths[25] 代表 'z' 需要的单位。

现在回答两个问题：至少多少行能放下S，以及最后一行使用的宽度是多少个单位？
将你的答案作为长度为2的整数列表返回。

示例 1:
输入: 
widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S = "abcdefghijklmnopqrstuvwxyz"
输出: [3, 60]
解释: 
所有的字符拥有相同的占用单位10。所以书写所有的26个字母，
我们需要2个整行和占用60个单位的一行。
*/

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int line = 1;
        int bit = 0;
        vector<int> ans;
        for(int i = 0;i<s.size()-1;i++){
            bit += widths[s[i] - 'a'];                  // 累加 
            if(bit + widths[s[i+1] - 'a'] > 100){       // 如果加上下一个 大于 100 ，这下一个就要从新的一行开始
                bit = 0;
                line++; 
            }
        }
        ans.emplace_back(line);
        ans.emplace_back(bit+widths[s[s.size()-1]-'a']);    // 加上最后一个
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> width = {4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    //string s = "abcdefghijklmnopqrstuvwxyz";
    string s = "bbbcccdddaaa";
    Solution sol;
    vector<int> ans = sol.numberOfLines(width,s);
    system("pause");
    return 0;
}
