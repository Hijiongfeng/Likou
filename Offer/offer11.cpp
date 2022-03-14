#include<iostream>
#include<vector>

using namespace std;

/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。

给你一个可能存在 重复 元素值的数组 numbers ，
它原来是一个升序排列的数组，并按上述情形进行了一次旋转。
请返回旋转数组的最小元素。例如，
数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一次旋转，该数组的最小值为1。

*/

/*
思路：
算法流程：
初始化： 声明 ii, jj 双指针分别指向 numsnums 数组左右两端；
循环二分： 设 m = (i + j) / 2m=(i+j)/2 为每次二分的中点（ "/" 代表向下取整除法，因此恒有 i \leq m < ji≤m<j ），可分为以下三种情况：
当 nums[m] > nums[j]nums[m]>nums[j] 时： mm 一定在 左排序数组 中，即旋转点 xx 一定在 [m + 1, j][m+1,j] 闭区间内，因此执行 i = m + 1i=m+1；
当 nums[m] < nums[j]nums[m]<nums[j] 时： mm 一定在 右排序数组 中，即旋转点 xx 一定在[i, m][i,m] 闭区间内，因此执行 j = mj=m；
当 nums[m] = nums[j]nums[m]=nums[j] 时： 
无法判断 mm 在哪个排序数组中，即无法判断旋转点 xx 在 [i, m][i,m] 还是 [m + 1, j][m+1,j] 区间中。解决方案： 执行 j = j - 1j=j−1 缩小判断范围，分析见下文。
返回值： 当 i = ji=j 时跳出二分循环，并返回 旋转点的值 nums[i]nums[i] 即可。

*/

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0;
        int right = numbers.size() -1;
        while(left < right){
            int mid = left + (right-left) / 2;
            if(numbers[mid] > numbers[right]){
                left = mid + 1;
            }else if(numbers[mid] < numbers[right]){
                right = mid;
            }else{
                right--;
            }
        }
        return numbers[left];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {3,4,5,1,2};
    Solution sol;
    cout<<sol.minArray(nums)<<endl;
    system("pause");
    return 0;
}
