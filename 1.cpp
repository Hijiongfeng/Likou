#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

/*
两数之和
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {     // 双指针 解法
        sort(nums.begin(),nums.end());  
        vector<int> res;
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            if(nums[left] + nums[right] == target){
                res.push_back(left);
                res.push_back(right);
                break;
            }else if(nums[left] + nums[right] > target){
                right--;
            }else if(nums[left] + nums[right] < target){
                left++;
            }
        }
        return res;
    }
};

// 哈希表解法

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {   
        unordered_map<int,int> nums_map;
        for(int i = 0;i<nums.size();i++){
            auto iter = nums_map.find(target - nums[i]);
            if(iter != nums_map.end()){
                return {iter->second, i};
            }
            nums_map.insert(pair<int,int> (nums[i],i));
        }
        return {};
    }
};



int main(int argc, char const *argv[])
{
    vector<int> nums = {2,7,11,15};
    int target = 9;
    Solution2 sol;
    vector<int> res = sol.twoSum(nums,target);
    for(auto x:res){
        cout<<x<<endl;
    }

    system("pause");
    return 0;
}
