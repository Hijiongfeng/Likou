#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*

给你一个数组 nums，我们可以将它按一个非负整数 k 进行轮调，这样可以使数组变为 
[nums[k], nums[k + 1], ... nums[nums.length - 1], nums[0], nums[1], ..., nums[k-1]] 的形式。
此后，任何值小于或等于其索引的项都可以记作一分。

例如，数组为 nums = [2,4,1,3,0]，我们按 k = 2 进行轮调后，
它将变成 [1,3,0,2,4]。这将记为 3 分，因为 1 > 0 [不计分]、4 > 1 [不计分]、0 <= 2 [计 1 分]、2 <= 3 [计 1 分]，3 <= 4 [计 1 分]。
在所有可能的轮调中，返回我们所能得到的最高分数对应的轮调下标 k 。如果有多个答案，返回满足条件的最小的下标 k 。

 

示例 1：

输入：nums = [2,3,1,4,0]
输出：3
解释：
下面列出了每个 k 的得分：
k = 0,  nums = [2,3,1,4,0],    score 2
k = 1,  nums = [3,1,4,0,2],    score 3
k = 2,  nums = [1,4,0,2,3],    score 3
k = 3,  nums = [4,0,2,3,1],    score 4
k = 4,  nums = [0,2,3,1,4],    score 3
所以我们应当选择 k = 3，得分最高。
*/

class Solution {
public:
    int bestRotation(vector<int>& nums) {           // 暴力 没有问题 ，超出时间限制  ；时间复杂度太高 n*n
        std::multimap<int,int> mp;
        int maxscore = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] <= i)
                maxscore ++;
        }
        mp.insert({maxscore,0});
        for(int k = 1;k<=nums.size()-1;k++){
            int score = 0;
            int kk = k;
            vector<int> newnums(nums.begin()+k,nums.end());
            while(kk){
                newnums.push_back(nums[k-kk]);
                kk--;
            }
            for(int i = 0;i<newnums.size();i++){
                if(newnums[i] <= i)
                    score++;
            }
            //maxscore = score > maxscore ? score : maxscore;
            mp.insert({score,k});
        }
        
        std::multimap<int,int>::iterator dit = mp.begin();
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->first > dit->first){
                dit = it;
            }
        }
        return dit->second;
    }
};


class Solution2 {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> diffs(n);
        for (int i = 0; i < n; i++) {
            int low = (i + 1) % n;
            int high = (i - nums[i] + n + 1) % n;
            diffs[low]++;
            diffs[high]--;
            if (low >= high) {
                diffs[0]++;
            }
        }
        int bestIndex = 0;
        int maxScore = 0;
        int score = 0;
        for (int i = 0; i < n; i++) {
            score += diffs[i];
            if (score > maxScore) {
                bestIndex = i;
                maxScore = score;
            }
        }
        return bestIndex;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {6,2,8,3,5,2,4,3,7,6};
    //vector<int> nums = {1,3,0,2,4};
    Solution2 sol;
    cout<<sol.bestRotation(nums)<<endl;
    system("pause");
    return 0;
}
