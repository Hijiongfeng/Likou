#include<bits/stdc++.h>

using namespace std;

/*
给你一个整数数组 nums，将 nums 中的的所有偶数元素移动到数组的前面，后跟所有奇数元素。

返回满足此条件的 任一数组 作为答案。

示例 1：

输入：nums = [3,1,2,4]
输出：[2,4,3,1]
解释：[4,2,3,1]、[2,4,1,3] 和 [4,2,1,3] 也会被视作正确答案。
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        list<int> li;                       // list 有双向迭代器，可以前后插入，区分奇数偶数。
        for(int a : nums){
            if(a % 2 == 0){
                li.push_front(a);
            }else{
                li.push_back(a);
            }
        }
        return vector<int>(li.begin(),li.end());
    }
    
    vector<int> sortArrayByParity2(vector<int>& nums) {    // 双指针法 原地交换
        int left = 0,right = nums.size() -1;
        while(left < right){
            if(nums[left] % 2 != 0 && nums[right] % 2 == 0){
                swap(nums[left],nums[right]);
                left++;
                right--;
            }
            while(left < right &&nums[left] % 2 == 0){
                left++;
            }
            while(left < right &&nums[right] % 2 != 0){
                right--;
            }
        }
        return nums;
    }

    bool cmp(int i, int j) {            // 自定义比较函数
        return i % 2  < j % 2;
    };
    vector<int> sortArrayByParity3(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        return nums;
    }
};


int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
