#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;
/*给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。
*/  
// 双指针
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> resualt;
        vector<int> a;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) return resualt;
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int leftIndex = i+1;
            int rightIndex = nums.size()-1;
            while(leftIndex<rightIndex){
                if(nums[leftIndex]+nums[rightIndex]>-nums[i]){
                    rightIndex--;
                }else if(nums[leftIndex]+nums[rightIndex]<-nums[i]){
                    leftIndex++;
                }else{
                    a = {nums[i],nums[leftIndex],nums[rightIndex]};
                    resualt.push_back(a);
                    // 去重逻辑应该放在找到一个三元组之后
                    while (rightIndex > leftIndex && nums[rightIndex] == nums[rightIndex - 1]) rightIndex--;
                    while (rightIndex > leftIndex && nums[leftIndex] == nums[leftIndex + 1]) leftIndex++;

                    // 找到答案时，双指针同时收缩
                    rightIndex--;
                    leftIndex++;
                }
            }
        }
        return resualt;
    }
    vector<vector<int>> threeSum2(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i< nums.size();i++)
        {
            if(nums[i]>0) continue;
            // 去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i+1, right = nums.size()-1;
            while (left < right)
            {
                if(nums[left] + nums[right] > -nums[i]){
                    right--;
                }else if (nums[left] + nums[right] < -nums[i])
                {
                    left++;
                }else{
                    ans.push_back({nums[i], nums[left], nums[right]});
                    // 去重
                    while (left <right && nums[left] == nums[left+1])
                    {
                        left++;
                    }

                    while (left <right && nums[right] == nums[right-1])
                    {
                        right--;
                    }   
                    left++;
                    right--;
                }
            }  
        }

        return ans;
    }
};

// 哈希解法
/*
两层for循环就可以确定 a 和 b 的数值了，可以使用哈希法来确定 0-(a+b) 是否在 数组里出现过；
*/
class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++){
            if(nums[i] > 0){
                break;
            }
            if(i > 0 && nums[i] == nums[i-1]){      // 元素 a 去重
                continue;
            }
            unordered_set<int> set;
            for(int j = i+1;j<nums.size();j++){
                if(j > i+2 && nums[j] == nums[j-1] && nums[j-1] == nums[j-2]){      // 元素 b 去重
                    continue;
                }
                int c = 0 - nums[i] - nums[j];
                if(set.find(c) != set.end()){
                    result.push_back({nums[i],nums[j],c});
                    set.erase(c);
                }else{
                    set.insert(nums[j]);
                }
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{   //例子 0,0,0,0
    // -4，-1，-1,0,1,2
    vector<int> nums = {-4,-1,-1,0,1,2}; 
    Solution sol;
    auto final = sol.threeSum2(nums);
    for(auto &x:final){
        for(auto &y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}
