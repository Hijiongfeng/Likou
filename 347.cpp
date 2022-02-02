#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>

using namespace std;

class Solution {
public:
    /*
    要统计元素出现频率
    对频率排序
    找出前K个高频元素
    */

    vector<int> topKFrequent(vector<int>& nums, int k) {    // 暴力解法 
        //sort(nums.begin(),nums.end());
        map<int,int> umap;
        for(int i=0;i<nums.size();i++){   //map 获取键值对的几种方法
          umap[nums[i]]++; 
        }
        // auto dit = umap.begin();
        // cout<<dit->first<<"  "<<dit->second<<endl;
        multimap<int,int,std::greater<int>> num_map;  // 要有排序 类型  ;因为频率 可能会 重复；这样用multimap 好
        
        for(auto it = umap.begin();it!=umap.end();it++){
            //pair<int,int> stl = {it->second,it->first};
            int a = it->second;
            int b = it->first;
            num_map.insert({a,b});
        }
        vector<int> result;
        auto dit = num_map.begin();
        int index = 0;
        while(true){
            result.push_back(dit->second);
            dit++;
            index++;
            if(index == k) break;
        }
       return result;
    }
};

int main(int argc, const char** argv) {
    vector<int> num = {1,2};
    int k=2;
    Solution sol;
    vector<int> final = sol.topKFrequent(num,k);
    for(int i=0;i<final.size();i++){
        cout<<final[i]<<endl;
    }
    system("pause");
    return 0;
}