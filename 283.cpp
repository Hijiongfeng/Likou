#include <iostream>
#include <vector>

using namespace std;
/*给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。*/
// 数组不能 erase 只能删除
class Solution
{
public:
    void moveZeroes(vector<int> &nums){
        int slow = 0;
        int size = nums.size();
        for(int fast = 0;fast<size;fast++){
            if(nums[fast]!=0){
                nums[slow]=nums[fast];
                slow++;
            }
        }
        for(;slow<size;slow++){
            nums[slow]=0;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 1, 0, 3, 0, 12};
    Solution sol;
    sol.moveZeroes(nums);
    for (auto q : nums)
    {
        cout << q << endl;
    }
    system("pause");
    return 0;
}
