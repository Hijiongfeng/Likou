#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution{
public:
    // 插入排序
/*
左边一个排序好的序列，右边未排序的序列    
*/
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
/*
第一轮比较 n-1 次，第二轮 n-2 次，第 n-1 轮比较 1 次；
总的时间复杂度为 n^2;
*/
    void bubble_sort2(vector<int> &nums){
        int n = nums.size();
        for(int i = 0;i < n;i++){
            for(int j = n-1;j>i;j--){
                if(nums[j] < nums[j-1]){
                    swap(nums[j],nums[j-1]);
                }
            }
        }
    }
/*改进的冒泡排序，加一个flag，如果上一轮有交换 则 flag = true；如果没有交换，则说明排序已经完成
*/
    void imp_bubble_sort2(vector<int> &nums){
        int n = nums.size();
        for(int i = 0;i < n;i++){
            bool  flag = false;
            for(int j = n-1;j>i;j--){
                if(nums[j] < nums[j-1]){
                    swap(nums[j],nums[j-1]);
                    flag = true;
                }
            }
            if(flag == false)
                break;
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

/*
堆排序 使用优先级队列,c++ STL优先级队列默认为大根堆，
配置三个参数，实现小根堆，降序排列
时间复杂度O(nlogn);
*/
    vector<int> heap_sort(vector<int> nums){
        priority_queue<int,vector<int>,greater<int>> pri_que;
        int n = nums.size();
        for(int a : nums){
            pri_que.push(a);
        }
        vector<int> ans;
        for(int i = 0;i<n;i++){
            ans.push_back(pri_que.top());
            pri_que.pop();
        }
        return ans;
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
    //sol.quick_sort(num,0,num.size()-1);
    //sol.bubble_sort2(num);
    vector<int> ans = sol.heap_sort(num);
    sol.printNums(num);
    system("pause");
    return 0;
}
