#include<iostream>
#include<vector>
#include<algorithm>
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
    // 冒泡排序
    void bubble_sort(vector<int> &nums){
        int n = nums.size();
        for(int i = 0;i < n;i++){
            for(int j = 1;j < n-1-i;j++){
                if(nums[j]<nums[j-1]){
                    swap(nums[j],nums[j-1]);
                }
            }
        }
    }
    // 选择排序
    /*
    1. 算法步骤
    首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置。

    再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。

    重复第二步，直到所有元素均排序完毕。
    */
    void select_sort(vector<int> &nums){
        for(int i = 0;i < nums.size() - 1;i++){
            int min = i;
            for(int j = i+1;j<nums.size();j++){
                if(nums[j] < nums[min])
                    min = j;
            }
            swap(nums[i],nums[min]);
        }
    }

    int Paritition1(vector<int>& vec,int low,int high){
        int pivot = vec[low];
        while(low < high){
            while(low < high && vec[high] >= pivot){
                --high;
            }
            vec[low] = vec[high];
            while(low < high && vec[low] <= pivot){
                ++low;
            }
            vec[high] = vec[low];
        }
        vec[low] = pivot;
        return low;
    }

    void quick_sort(vector<int>& nums,int low,int high){
        if(low < high){
            int pivot = Paritition1(nums,low,high);
            quick_sort(nums,low,pivot-1);
            quick_sort(nums,pivot+1,high);
        }
    }

public:
    // 范围 for 循环
    void printNums(vector<int> &nums){
        for(auto &c:nums){
            cout<<c<<endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num = {1,4,7,2,5,8,3,6,9};
    Solution sol;
    //sol.select_sort(num);
    sol.quick_sort(num,0,num.size()-1);
    sol.printNums(num);
    system("pause");
    return 0;
}
