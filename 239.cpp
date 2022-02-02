#include<iostream>
#include<vector>
#include<deque>

using namespace std;
/*
给你一个整数数组 nums，
有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。
*/

class Solution {   // 暴力解法，，测试用例短的情况下，可以通过 时间复杂度（n*n）
private:
    int findMax(vector<int> & nums){
        int max = nums[0];
        for(int i = 0;i<nums.size();i++){
            if(nums[i] > max)
                max = nums[i];
        }
        return max;
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        for(int i = 0;i<=nums.size()-k;i++){
            vector<int> temp(nums.begin() + i,nums.begin()+i+k);
            int a = findMax(temp);
            res.push_back(a);
        }
        return res;
    }
};

class Solution2 {       //  单调队列

private:
    class MyQeque {
    public:
        deque<int> que;
        // 弹出元素，等于 队首 元素，则弹出
        void pop(int value){
            if(!que.empty() && value == que.front()){
                que.pop_front();
            }
        }
        // 如果 push 的元素大于 队列后端的元素，则将 队列后端的元素弹出，把新元素 push 进去
        // 这就操作就 保持了 队列 中的元素 是 从大到小 的 单调队列了；
        void push(int value){
            while(!que.empty() && value > que.back()){
                que.pop_back();
            }
            que.push_back(value);
        }

        // 获取 当前队列的 最大值；直接返回 队列 首 元素
        int front(){
            return que.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQeque que;
        vector<int> result;
        for(int i = 0;i<k;i++){
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for(int i = k;i<nums.size();i++){
            que.pop(nums[i-k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution2 sol;
    auto final = sol.maxSlidingWindow(nums,k);
    for(auto & x:final){
        cout<<x<<endl;
    }
    system("pause"); 
    return 0;
}
