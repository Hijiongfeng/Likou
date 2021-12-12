#include<iostream>
#include<vector>
#include<algorithm>

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
};

int main(int argc, char const *argv[])
{   //例子 0,0,0,0
    // -4，-1，-1,0,1,2
    vector<int> nums = {-2,0,0,2,2}; 
    Solution sol;
    auto final = sol.threeSum(nums);
    for(auto &x:final){
        for(auto &y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}
