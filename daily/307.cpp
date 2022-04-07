#include<iostream>
#include<vector>
#include<math.h>
#include<numeric>

using namespace std;

/*
给你一个数组 nums ，请你完成两类查询。

其中一类查询要求 更新 数组 nums 下标对应的值
另一类查询要求返回数组 nums 中索引 left 和索引 right 之间
（ 包含 ）的nums元素的 和 ，其中 left <= right
实现 NumArray 类：

NumArray(int[] nums) 用整数数组 nums 初始化对象
void update(int index, int val) 将 nums[index] 的值 更新 为 val
int sumRange(int left, int right) 
返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 
（即，nums[left] + nums[left + 1], ..., nums[right]）
*/

class NumArray {        // 暴力超时，遍历的话
public:
    NumArray(vector<int>& nums) {
        for(int a : nums){
            vec.push_back(a);
        }
    }
    
    void update(int index, int val) {
        for(int i = 0;i<vec.size();i++){
            if(i == index)
                vec[i] = val;
        }
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for(int i = left;i<=right;i++){
            sum += vec[i];
        }
        return sum;
    }
private:
    vector<int> vec;
};


class NumArray2 {        // 分块处理
private:
    vector<int> sum;     // 每一块的和
    int size;
    vector<int> & nums;
public:
    NumArray2(vector<int>& nums):nums(nums) {
        int n = nums.size();
        size = sqrt(n);
        sum.resize((n+size-1) / size);
        for(int i = 0;i<n;i++){
            sum[i / size] += nums[i];
        }
    }
    
    void update(int index, int val) {
        sum[index / size] += val - nums[index];
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        int b1 = left / size, i1 = left % size, b2 = right / size, i2 = right % size;
        if (b1 == b2) { // 区间 [left, right] 在同一块中
            return accumulate(nums.begin() + b1 * size + i1, nums.begin() + b1 * size + i2 + 1, 0);
        }
        int sum1 = accumulate(nums.begin() + b1 * size + i1, nums.begin() + b1 * size + size, 0);
        int sum2 = accumulate(nums.begin() + b2 * size, nums.begin() + b2 * size + i2 + 1, 0);
        int sum3 = accumulate(sum.begin() + b1 + 1, sum.begin() + b2, 0);
        return sum1 + sum2 + sum3;
    }
};


class NumArray3 {        // 树状数组
private:
    vector<int> tree;   // 树状数组
    vector<int> & nums;

    int lowBit(int x){
        return x & -x;
    }

    void add(int index,int val){
        while(index < tree.size()){
            tree[index] += val;
            index += lowBit(index);
        }
    }

    int prefixSum(int index){
        int sum = 0;
        while(index > 0){
            sum += tree[index];
            index -= lowBit(index);
        }
        return sum;
    }

public:
    NumArray3(vector<int>& nums):tree(nums.size()+1),nums(nums){
        for(int i = 0;i<nums.size();i++){
            add(i+1,nums[i]);
        }
    }
    
    void update(int index, int val) {
        add(index + 1,val - nums[index]);
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return prefixSum(right + 1) - prefixSum(left);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {0,1,2,3,4};
    NumArray3 np(nums);
    cout<<np.sumRange(1,2)<<endl;
    system("pause");
    return 0;
}
