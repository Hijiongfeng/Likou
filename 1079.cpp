#include<bits/stdc++.h>

using namespace std;

/*
你有一套活字字模 tiles，其中每个字模上都刻有一个字母 tiles[i]。
返回你可以印出的非空字母序列的数目。

注意：本题中，每个活字字模只能使用一次。

示例 1：

输入："AAB"
输出：8
解释：可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"。
*/
/*
回溯算法：
使用used数组去重，去除本轮已经使用过的字符
使用set去重，去除重复的字符，比如示例中的 "AA"
这里并不需要传入标志位，类似于全排列和子集的结合
*/
class Solution {
    unordered_set<string> result;
    string path;
    void backtracking(string tiles,vector<bool> used){
        if(path.size() <= tiles.size() && !result.count(path)){
            result.insert(path);
        }else{
            return;
        }
        for(int i = 0;i<tiles.size();i++){
            if(used[i] == false){
                used[i] = true;
                path += tiles[i];
                backtracking(tiles,used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        if(tiles.size() == 1)
            return 1;
        sort(tiles.begin(),tiles.end());
        vector<bool> used(tiles.size(),false);
        backtracking(tiles,used);
        return result.size() - 1;       // 传入了空字符，需要减 1
    }
};

int main(int argc, char const *argv[])
{
    string tiles = "AAABBC";
    Solution sol;
    cout<<sol.numTilePossibilities(tiles)<<endl;
    system("pause");
    return 0;
}
