#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。*/
//左右双指针  取绝对值 比较  大的放入新数组中   然后在翻转整个新数组 返回
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        vector<int> result;
        while(left <= right){
            if(abs(nums[left])<abs(nums[right])){
                result.push_back(nums[right]*nums[right]);
                right--;
            }else{
                result.push_back(nums[left]*nums[left]);
                left++;
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {-4,-1,0,3,10};
    Solution sol;
    vector<int> final = sol.sortedSquares(nums);
    for(auto & x:final){
        cout<<x<<endl;
    }
    system("pause");
    return 0;
}
