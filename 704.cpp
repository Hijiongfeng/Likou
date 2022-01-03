#include<iostream>
#include<vector>

using namespace std;

/*
二分查找
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;  // 定义target在左闭右闭的区间里，[left, right]
        while(left<=right){     // 当left==right，区间[left, right]依然有效，所以用 <=
            int middle =  left + ((right - left) / 2);      // 防止溢出 等同于(left + right)/2
            if(nums[middle] > target) right = middle-1;     // target 在左区间，所以[left, middle - 1]
            if(nums[middle] < target) left = middle+1;      // target 在右区间，所以[middle + 1, right]
            if(nums[middle] == target) return middle;        // 数组中找到目标值，直接返回下标
        }
        return -1;  
    }

    int search2(vector<int>& nums,int target){  // 定义target在左闭右开的区间里，[left, right)
        int left = 0;
        int right = nums.size();

        while(left < right){
            int middle =  left + ((right - left) / 2);   //  防止溢出
            if(nums[middle] > target) right = middle;

            if(nums[middle] < target) left = middle + 1;      // 左边是闭区间

            if(nums[middle] == target) return middle;
        }

        return -1;

    }
};

int main(int argc, char const *argv[])
{
    vector<int> numd{-1,0,3,5,9,12};
    int target = 9;
    Solution sol;
    cout<<sol.search2(numd,target)<<endl;

    system("pause");
    return 0;
}
