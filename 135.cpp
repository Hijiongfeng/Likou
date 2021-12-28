#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

/*
老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻的孩子中，评分高的孩子必须获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

示例 1:

输入: [1,0,2]
输出: 5
解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> vec(ratings.size(),1);
        for(int i = 1;i<ratings.size();i++){    // 从前往后
            if(ratings[i] > ratings[i-1]){
                vec[i] = vec[i-1]+1;
            }
        }

        for(int i = ratings.size()-1;i>0;i--){
            if(ratings[i-1] > ratings[i]){
                vec[i-1] = max(vec[i-1],vec[i]+1);      //  当前结果与 根据 大小比出来的结果，进行比较，取最大
            }
        }
        return accumulate(vec.begin(),vec.end(),0);

    }
};

int main(int argc, char const *argv[])
{
    vector<int> num{1,0,2};
    Solution sol;
    cout<<sol.candy(num)<<endl;
    system("pause");
    return 0;
}
