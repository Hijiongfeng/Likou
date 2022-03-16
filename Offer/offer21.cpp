#include<iostream>
#include<vector>

using namespace std;

/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。
*/

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {   // 暴力sb解法
        vector<int> le;
        vector<int> ri;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] % 2 == 0){
                ri.push_back(nums[i]);
            }else{
                le.push_back(nums[i]);
            }
        }
        for(int i = 0;i<ri.size();i++){
            le.push_back(ri[i]);
        }
        return le;
    }
};


class Solution2 {
public:
    vector<int> exchange(vector<int>& nums) {   // 双指针
        int left = 0;
        int right = nums.size() -1;
        while(left < right){
            while(left < right &&nums[left] % 2 == 1){
                left++;
            }
            while(left < right && nums[right] % 2 == 0){
                right--;
            }
            swap(nums[left],nums[right]);
            left++;
            right--;
        }
        return nums;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,3,5};
    Solution2 sol;
    vector<int> vec = sol.exchange(nums);
    for(auto & a : vec){
        cout<<a<<endl;
    }
    system("pause");
    return 0;
}
