#include<bits/stdc++.h>

using namespace std;

/*
给定一个长度为 n 的整数数组 nums 。

假设 arrk 是数组 nums 顺时针旋转 k 个位置后的数组，我们定义 nums 的 旋转函数  F 为：

F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1]
返回 F(0), F(1), ..., F(n-1)中的最大值 。

生成的测试用例让答案符合 32 位 整数。
输入: nums = [4,3,2,6]
输出: 26
解释:
F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
所以 F(0), F(1), F(2), F(3) 中的最大值是 F(3) = 26 。
*/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {      // 模拟方法 超出时间限制
        vector<pair<int,int>> vec(nums.size());
        for(int i = 0;i<nums.size();i++){
            vec[i].first = nums[i];
            vec[i].second = i;
        }
        int N = nums.size();
        int max = INT_MIN;

        for(int i = 0;i<nums.size();i++){
            int temp = 0;
            for(int j = 0;j<vec.size();j++){
                temp += (vec[j].first * vec[j].second);
                //vec[j].second = vec[j].second + 1 == N ?  vec[j].second + 1 : 0;
                if(vec[j].second + 1 != N){
                    vec[j].second += 1;
                }else{
                    vec[j].second = 0;
                }
            }

            max = temp > max ? temp : max;
        }
        return max;
    }

////轮转一次 增加 num[0]~num[n-2] 减少（n-1）* num[n-1]  == 增加 sum 减去 n * num[n-1]
// f1 - f0 就能推导出公式
    int maxRotateFunction2(vector<int>& nums) {      // 推导数学公式
        int numSum = accumulate(nums.begin(),nums.end(),0);
        int f0 = 0;
        for(int i = 0;i<nums.size();i++){
            f0 += nums[i] * i;
        }
        int fn;
        int max = f0,N = nums.size();
        for(int i = 1;i<nums.size();i++){
            fn = f0 + numSum - N * nums[N - i];
            max = fn > f0 ? fn : f0;
            f0 = fn;
        }
        return max;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {4,3,2,6};
    Solution sol;
    cout<<sol.maxRotateFunction2(nums)<<endl;
    system("pause");
    return 0;
}
