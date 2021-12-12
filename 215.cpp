#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        return nums[size-k];
    }
};

int main(int argc, const char** argv) {
    vector<int> num = {3,2,3,1,2,4,5,5,6};
    int k=4;
    Solution sol;
    cout<<sol.findKthLargest(num,k)<<endl;
    system("pause");
    return 0;
}