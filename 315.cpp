#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

/*
老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
评分更高的孩子必须比他两侧的邻位孩子获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？
示例 1：

输入：[1,0,2]
输出：5
解释：你可以分别给这三个孩子分发 2、1、2 颗糖果。
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> canVec(ratings.size(),1);
        for(int i = 0;i<ratings.size()-1;i++){
            if(ratings[i+1] > ratings[i]){
                canVec[i+1] = canVec[i]+1;
            }
        }
        for(int i = ratings.size()-1;i>0;i--){    // 从右边进行遍历的 是否 考虑 之前的 糖果数量大 还是右边加1 的糖果数量大
            if(ratings[i-1] > ratings[i]){
                canVec[i-1] = max(canVec[i-1],canVec[i]+1);
            }
        }
        return accumulate(canVec.begin(),canVec.end(),0);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> rat{1,2,3,1};     // 这个 例子 就是为了满足 上面的特殊情况的。。。
    Solution sol;
    cout<<sol.candy(rat)<<endl;
    system("pause");
    return 0;
}
