#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums){
        int size = nums.size();  // 暴力解法
        for(int i=0;i<size;){
            int j=i+1;
            if(nums[i]==nums[j]){
                i=i+2;
            }else{
                return nums[i];
            }
        }
        return 0;
    }
};

class Solution2
{
public:
    int singleNonDuplicate(vector<int> &nums){
        int size = nums.size();  // 二分查找
        int l=0,r=size-1;
        int mid;
        while(l<=r){
            mid = (l+r)/2;
        }

    }
};

int main(int argc, const char **argv)
{
    cout << "0" << endl;

    vector<int> nums = {3,3,7,7,10,11,11};
    Solution sol;
    cout << sol.singleNonDuplicate(nums) << endl;
    system("pause");
    return 0;
}