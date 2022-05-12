#include<bits/stdc++.h>

using namespace std;

/*
基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。

假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。
一次基因变化就意味着这个基因序列中的一个字符发生了变化。

例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。
另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。

给你两个基因序列 start 和 end ，以及一个基因库 bank ，
请你找出并返回能够使 start 变化为 end 所需的最少变化次数。如果无法完成此基因变化，返回 -1 。

注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。

 

示例 1：

输入：start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
输出：1
*/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> cnt;
        unordered_set<string> vsited;
        char key[4] = {'A','C','G','T'};
        for(auto & w:bank){
            cnt.emplace(w);
        }
        if(start == end){
            return 0;
        }
        if(!cnt.count(end)){
            return -1;
        }

        queue<string> que;          //深度优先搜索
        que.emplace(start);
        vsited.emplace(start);
        int step = 1;
        while(!que.empty()){
            int sz = que.size();
            for(int i = 0;i<sz;i++){
                string cur = que.front();
                que.pop();
                for(int j = 0;j<8;j++){         // 8个位置的每一个进行替换
                    for(int k = 0;k<4;k++){
                        if(key[k] != cur[j]){
                            string next = cur;
                            next[j] = key[k];
                            if(!vsited.count(next) && cnt.count(next)){ // 如果没有遍历过 而且cnt 中有
                                if(next == end){
                                    return step;
                                }
                                que.emplace(next);
                                vsited.emplace(next);
                            }
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
