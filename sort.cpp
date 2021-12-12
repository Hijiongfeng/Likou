#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    // 插入排序
    void insert_sort(vector<int> &nums){
        for(int i=1;i<nums.size();i++){
            // int temp =std::move(nums[i]);
            // int j=i;
            for(int j=i;j>0&&nums[j]<nums[j-1];j--){
                swap(nums[j],nums[j-1]);
            }
            //nums[j] = std::move(temp);
        }
    }

    void bubble_sort(vector<int> &nums,int n){
        for(int i=0;i<n;i++){
            for(int j=1;j<n-1-i;j++){
                if(nums[j]<nums[j-1]){
                    swap(nums[j],nums[j-1]);
                }
            }
        }
    }
public:
    // 范围 for 循环
    void printNums(vector<int> &nums){
        for(auto c:nums){
            cout<<c<<endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num = {1,4,7,2,5,8,3,6,9};
    Solution sol;
    sol.insert_sort(num);
    sol.printNums(num);
    system("pause");
    return 0;
}
