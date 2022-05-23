#include<bits/stdc++.h>

using namespace std;

/*
给定两个整数数组a和b，计算具有最小差绝对值的一对数值（每个数组中取一个值），并返回该对数值的差
示例：

输入：{1, 3, 15, 11, 2}, {23, 127, 235, 19, 8}
输出：3，即数值对(11, 8)
*/
// 排序双指针
class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int i = 0,j = 0;
        int na = a.size();
        int nb = b.size();
        long ans = LONG_MAX;
        while(i < na && j< nb){
            if(a[i] != b[j]){
                ans = min(ans,abs((long)a[i] - (long)b[j]));
                a[i] > b[j] ? j++ : i++;
            }else{
                return 0;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a = {-2147483648,1};
    vector<int> b = {2147483647,0};
    Solution sol;
    cout<<sol.smallestDifference(a,b)<<endl;
    system("pause");
    return 0;
}
