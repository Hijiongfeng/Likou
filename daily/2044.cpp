#include<iostream>
#include<vector>

using namespace std;

/*
给你一个整数数组 nums ，请你找出 nums 子集 按位或 可能得到的 最大值 ，
并返回按位或能得到最大值的 不同非空子集的数目 。

如果数组 a 可以由数组 b 删除一些元素（或不删除）得到，
则认为数组 a 是数组 b 的一个 子集 。如果选中的元素下标位置不一样，则认为两个子集 不同 。

对数组 a 执行 按位或 ，结果等于 a[0] OR a[1] OR ... OR a[a.length - 1]（下标从 0 开始）。
*/

// 需要理解的是，数组的所有元素进行或运算，返回的肯定是最大值。可以事先计算好，之后每次进行比较即可。

class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(vector<int>& nums,int startIndex){        // 回溯法找 子集；相当于一个模板了
        if(path.size() <= nums.size()){
            res.push_back(path);
        }else{
            return;
        }
        for(int i = startIndex;i<nums.size();i++){
            path.push_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        backtracking(nums,0);
        int count = 0;
        int max = INT_MIN;
        for(int i = 1;i<res.size();i++){            // 第一个是空的,从第二个开始
            int tem = 0;                            // 记录一个 按位或的 初始值；任何数与0做 都是它本身
            for(int j = 0;j<res[i].size();j++){     // 按顺序 按位或
                tem = tem | res[i][j];
            }
            if(tem == max){                 // 先判断相等，跟昨天的题一样，可以排除情况
                max = tem;
                count++;
            }
            if(tem > max){          // 如果 计算的 tem比较大，更新值；count 已经有值的情况下，变为0，
                max = tem;          // 没有值，则直接 ++
                if(count == 0){
                    count++;
                }else{
                    count = 0;
                    count++;
                }
            }
        }
        return count;               // 最后返回 count 即可
    }
};

int main(int argc, char const *argv[])
{

    vector<int> nums = {3,2,1,5};
    Solution sol;
    cout<<sol.countMaxOrSubsets(nums)<<endl;
    system("pause");
    return 0;
}
