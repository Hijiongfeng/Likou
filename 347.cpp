#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){   //map 获取键值对的几种方法
          map[nums[i]]++; 
        }
        

    }
};

int main(int argc, const char** argv) {
    vector<int> num = {1,1,1,2,2,3};
    int k=2;
    Solution sol;
    vector<int> final = sol.topKFrequent(num,k);
    for(int i=0;i<final.size();i++){
        cout<<final[i]<<endl;
    }
    return 0;
}