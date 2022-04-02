#include<iostream>
#include<vector>

using namespace std;

/*
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，
原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

必须在不使用库的sort函数的情况下解决这个问题。
输入：nums = [2,0,2,1,1,0]
输出：[0,0,1,1,2,2]
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 0;i<nums.size()-1;i++){
            int min = i;
            for(int j = i+1;j<nums.size();j++){
                if(nums[j] < nums[min])
                    min = j;
            }
            swap(nums[i],nums[min]);
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {2,0,1};
    Solution sol;
    sol.sortColors(nums);
    system("pause");
    return 0;
}
