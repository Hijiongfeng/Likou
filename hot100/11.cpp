#include <iostream>
#include <vector>

using namespace std;

/*
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。
*/

class Solution
{
public:
    int maxArea(vector<int> &height)
    { // 暴力 两次循环遍历 超时
        int ans = 0;
        for (int i = 0; i < height.size() - 1; i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                int tem = 0;
                if (height[j] > height[i])
                {
                    tem = (j - i) * height[i];
                }
                else
                {
                    tem = (j - i) * height[j];
                }
                ans = tem > ans ? tem : ans;
            }
        }
        return ans;
    }
    int maxArea2(vector<int> &height){ // 双指针
        int ans = 0;
        int left = 0, right = height.size() - 1;
        while (left < right){
            int tem = 0;
            if (height[right] > height[left]){
                tem = (right - left) * height[left];
                left++;
            }else{
                tem = (right - left) * height[right];
                right--;
            }
            ans = tem > ans ? tem : ans;
        }
        return ans;
    }
    // 2025.3.4
    int maxArea3(vector<int> &height)
    {
        int ans = 0;
        int left = 0;
        int right = height.size()-1;
        while (left <= right)
        {
            int area = (right-left)*min(height[left], height[right]);
            ans = max(ans, area);
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    // vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> height = {1, 1};
    Solution sol;
    cout << sol.maxArea3(height) << endl;
    system("pause");
    return 0;
}
