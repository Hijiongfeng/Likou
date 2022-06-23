#include<bits/stdc++.h>

using namespace std;

/*
珂珂喜欢吃香蕉。这里有 n 堆香蕉，第 i 堆中有 piles[i] 根香蕉。
警卫已经离开了，将在 h 小时后回来。

珂珂可以决定她吃香蕉的速度 k （单位：根/小时）。
每个小时，她将会选择一堆香蕉，从中吃掉 k 根。如果这堆香蕉少于 k 根，
她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  

珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。

返回她可以在 h 小时内吃掉所有香蕉的最小速度 k（k 为整数）。

示例 1：

输入：piles = [3,6,7,11], h = 8
输出：4
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {     // 二分查找
        sort(piles.begin(),piles.end());
        int manNum = *max_element(piles.begin(),piles.end());
        int left = 1,right = manNum;
        int k = right;
        while(left < right){
            int middle = left + (right - left) / 2;
            if(getHour(piles,middle) > h){
                left = middle + 1;
            }else if(getHour(piles,middle) <= h){
                right = middle;
                k = middle;
            }
        }
        return k;
    }

    int getHour(vector<int>& piles,int k){
        int res = 0;
        for(int a : piles){
            if(a % k == 0){             // 如果能够整除
                res += (a / k);
            }else{
                res += (a / k + 1);     // 如果不能够整除
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> piles = {3,6,7,11};
    int k = 8;
    Solution sol;
    cout<<sol.minEatingSpeed(piles,k)<<endl;
    system("pause");
    return 0;
}
