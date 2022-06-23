#include<bits/stdc++.h>

using namespace std;

/*
给定一个由非重叠的轴对齐矩形的数组 rects ，其中 rects[i] = [ai, bi, xi, yi] 
表示 (ai, bi) 是第 i 个矩形的左下角点，(xi, yi) 是第 i 个矩形的右上角点。
设计一个算法来随机挑选一个被某一矩形覆盖的整数点。矩形周长上的点也算做是被矩形覆盖。
所有满足要求的点必须等概率被返回。

在给定的矩形覆盖的空间内的任何整数点都有可能被返回。

请注意 ，整数点是具有整数坐标的点。

实现 Solution 类:

Solution(int[][] rects) 用给定的矩形数组 rects 初始化对象。
int[] pick() 返回一个随机的整数点 [u, v] 在给定的矩形所覆盖的空间内。
*/

class Solution {            // 带权重的随机抽样  前缀和 + 二分查找
public:
    Solution(vector<vector<int>>& rects): rects{rects} {
        this->arr.emplace_back(0);
        for(vector<int>& rect : rects){
            this->arr.emplace_back(arr.back() + (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1));
        }
    }
    
    vector<int> pick() {
        uniform_int_distribution<int> dis(1,arr.back());        // 
        int k = dis(gen);
        int rectIndex = lower_bound(arr.begin(), arr.end(), k) - arr.begin() -1;
        vector<int> rect = rects[rectIndex];
        uniform_int_distribution<int> x(rect[0],rect[2]),y(rect[1],rect[3]);
        return {x(gen),y(gen)};
        
    }
private:
    vector<int> arr;
    vector<vector<int>>& rects;
    mt19937 gen{random_device{}()};         // 随机引擎
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> rects =  {{-2, -2, 1, 1}, {2, 2, 4, 6}};
    Solution sol(rects);
    vector<int> res = sol.pick();
    system("pause");
    return 0;
}
