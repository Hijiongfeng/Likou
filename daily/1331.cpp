#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size() == 0) return {};
        vector<int> new_arr = arr;
        vector<int> vec(arr.size(),0);
        sort(new_arr.begin(),new_arr.end());
        map<int,int> mp;
        int idx = 1;
        for(int i = 0;i<new_arr.size();i++){
            if(i > 0 && new_arr[i] == new_arr[i - 1]){
                continue;
            }else{
                mp[new_arr[i]] = idx;
                idx++;
            }
        }
        for(int i = 0;i<arr.size();i++){
            vec[i] = mp[arr[i]];
        }
        return vec;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> arr  = {40,10,20,30};
    Solution sol;
    vector<int> ans = sol.arrayRankTransform(arr);

    
    system("pause");
    return 0;
}
