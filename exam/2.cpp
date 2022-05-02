#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @param k int整型 
     * @return long长整型
     */
    long long ans(vector<int>& array, int k) {
        // write code here
        sort(array.begin(),array.end());
        long long  ans = 0;
        int N = array.size();
        for(int i = 0;i < N ;i++){
            int a1 = array[i];
            int right = N-1;
            while(i < right && a1 + array[right] > k){
                right--;
            }
            ans += (right - i);
        }
        return ans;

    }
};

int main(int argc, char const *argv[])
{
    vector<int> arry = {1,2,1};
    int k = 2;
    Solution sol;
    cout<<sol.ans(arry,k)<<endl;
    system("pause");
    return 0;
}


