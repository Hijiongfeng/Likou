#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
给你一个整数数组 arr ，请使用 煎饼翻转 完成对数组的排序。

一次煎饼翻转的执行过程如下：

选择一个整数 k ，1 <= k <= arr.length
反转子数组 arr[0...k-1]（下标从 0 开始）
例如，arr = [3,2,1,4] ，选择 k = 3 进行一次煎饼翻转，反转子数组 [3,2,1] ，得到 arr = [1,2,3,4] 。

以数组形式返回能使 arr 有序的煎饼翻转操作所对应的 k 值序列。
任何将数组排序且翻转次数在 10 * arr.length 范围内的有效答案都将被判断为正确。
*/

class Solution {
private:
    int findMax(vector<int>& vec){
        int max = vec[0];
        for(auto a : vec){
            if(a > max) max = a;
        }
        return max;
    }

    int findMaxIndex(vector<int>& vec,int max){
        for(int i = 0;i<vec.size();i++){
            if(vec[i] == max) return i;
        }
        return -1;
    }

    bool isOrder(vector<int> & vec){        // 判断是否 有序
        for(int i = 1;i<vec.size();i++){
            if(vec[i] < vec[i-1]) return false;
        }
        return true;
    }
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        while(arr.size() != 0){
            int max = findMax(arr);
            int index = findMaxIndex(arr,max);
            if(index == arr.size()-1){
                arr.resize(index);
                continue;
            }

            if(!isOrder(arr)){
                if(index > 0 ){
                    res.push_back(index + 1);
                    reverse(arr.begin(),arr.begin() + index +1);

                }else{
                    res.push_back(arr.size());
                    reverse(arr.begin(),arr.end());
                }
            }else{
                return res;
            }
            
        }
        return res;

    }
};

int main(int argc, char const *argv[])
{
    vector<int> arr = {1,2};
    Solution sol;
    vector<int> res = sol.pancakeSort(arr);
    for(auto & a : res){
        cout<<a<<endl;
    }
    system("pause");
    return 0;
}
