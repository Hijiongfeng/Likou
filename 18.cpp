#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。
请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] 
（若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。*/
//四数之和  两个for循环  加 双指针  关键是去重
//三数之和 一个for循环  加双指针  去重
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> resualt;
        //if(nums.size()==0) return resualt;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if (i > 0 && nums[i] == nums[i - 1]) {      // 去重 a
                continue;
            }
            for(int j=i+1;j<nums.size();j++){
                //if(nums[i]+nums[j]>target) return resualt;
                if(j > i+1 && nums[j] == nums[j-1]){    // 去重 b
                    continue;
                }
                int leftIndex = j+1;
                int rightIndex = nums.size()-1;
                while(leftIndex<rightIndex){
                    if(nums[i]+nums[j]+nums[leftIndex]+nums[rightIndex]>target){
                        rightIndex--;
                    }else if(nums[i]+nums[j]+nums[leftIndex]+nums[rightIndex]<target){
                        leftIndex++;
                    }else{
                        resualt.push_back(vector<int>{nums[i],nums[j],nums[leftIndex],nums[rightIndex]});
                        // 去重逻辑应该放在找到一个三元组之后
                        while (rightIndex > leftIndex && nums[rightIndex] == nums[rightIndex - 1]) rightIndex--;  // 去重 c 
                        while (rightIndex > leftIndex && nums[leftIndex] == nums[leftIndex + 1]) leftIndex++;       // 去重 d
                        leftIndex++;
                        rightIndex--;
                    }
                    
                }
            }
        }
        return resualt;
    }
};

int main(int argc, char const *argv[])
{//{1,0,-1,0,-2,2}
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    Solution sol;
    vector<vector<int>> final = sol.fourSum(nums,target);
    for(auto &x:final){
        for(auto &y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    
    system("pause");
    return 0;
}
