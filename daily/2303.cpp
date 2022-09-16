#include<bits/stdc++.h>

using namespace std;

/*
给你一个下标从 0 开始的二维整数数组 brackets ，其中 brackets[i] = [upperi, percenti] 
，表示第 i 个税级的上限是 upperi ，征收的税率为 percenti 。税级按上限 从低到高排序
（在满足 0 < i < brackets.length 的前提下，upperi-1 < upperi）。

税款计算方式如下：

不超过 upper0 的收入按税率 percent0 缴纳
接着 upper1 - upper0 的部分按税率 percent1 缴纳
然后 upper2 - upper1 的部分按税率 percent2 缴纳
以此类推
给你一个整数 income 表示你的总收入。返回你需要缴纳的税款总额。与标准答案误差不超 10-5 的结果将被视作正确答案。
*/
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        vector<int> upper;
        for(vector<int>& bracket : brackets){
            upper.emplace_back(bracket[0]);
        }
        int index = lower_bound(upper.begin(),upper.end(),income) - upper.begin();
        double ans = 0;
        for(int i = 0;i<=index;i++){
            double temp;
            if(i == 0 && index != 0){
                temp = brackets[i][0] * (brackets[i][1] * 1.0 / 100);
            }else if(i == 0 && index == 0){
                temp = income  * (brackets[i][1] * 1.0 / 100);
            }else if(i > 0 && i != index){
                temp = (brackets[i][0] -brackets[i-1][0])  * (brackets[i][1] * 1.0 / 100);
            }else if(i > 0 && i == index){
                temp = (income -brackets[i-1][0])  * (brackets[i][1] * 1.0 / 100);
            }
            ans += temp;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> brackets = {{3,50},{7,10},{12,25}};
    int income = 0;
    Solution sol;
    cout<<sol.calculateTax(brackets,income)<<endl;
    system("pause");
    return 0;
}
