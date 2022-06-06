#include<bits/stdc++.h>

using namespace std;

/*
有个内含单词的超大文本文件，给定任意两个不同的单词，找出在这个文件中这两个单词的最短距离(相隔单词数)。如果寻找过程在这个文件中会重复多次，而每次寻找的单词不同，你能对此优化吗?

示例：

输入：words = ["I","am","a","student","from","a","university","in","a","city"], 
word1 = "a", word2 = "student"
输出：1
*/

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        vector<int> word1_index,word2_index;
        for(int i = 0;i<words.size();i++){
            if(words[i] == word1){
                word1_index.push_back(i);
            }
            if(words[i] == word2){
                word2_index.push_back(i);
            }
        }
        int minDistance = INT_MAX;
        for(int i = 0;i<word1_index.size();i++){
            for(int j = 0;j<word2_index.size();j++){
                minDistance = min(minDistance,abs(word1_index[i] - word2_index[j]));
            }
        }
        return minDistance;
    }


    int findClosest2(vector<string>& words, string word1, string word2) {
        vector<int> word1_index,word2_index;
        for(int i = 0;i<words.size();i++){
            if(words[i] == word1){
                word1_index.push_back(i);
            }
            if(words[i] == word2){
                word2_index.push_back(i);
            }
        }
        int minDistance = INT_MAX;

        int l1 = 0,l2 = 0,m = word1_index.size(),n = word2_index.size();        // 双指针
        while(l1 < m && l2 < n){
            minDistance = min(minDistance,abs(word1_index[l1] - word2_index[l2]));
            if(l2 == n-1 || word1_index[l1] < word2_index[l2]){
                ++l1;
            }else{
                ++l2;
            }
        }
        return minDistance;

    }
    
    // 只记录最近的下标；

    int findClosest3(vector<string>& words, string word1, string word2) {
        int index1 = -1 ,index2 = -1;
        int minDistance = INT_MAX;
        for(int i = 0;i<words.size();i++){
            string word = words[i];
            if(word == word1){
                index1 = i;
            }else if(word == word2){
                index2 = i;
            }
            if(index1 >= 0 && index2 >= 0){
                minDistance = min(minDistance,abs(index1-index2));
            }
        }
        return minDistance;

    }
};

int main(int argc, char const *argv[])
{
    vector<string> words = {"I","am","a","student","from","a","university","in","a","city"};
    string word1 = "a", word2 = "student";
    Solution sol;
    cout<<sol.findClosest3(words,word1,word2)<<endl;
    system("pause");
    return 0;
}
