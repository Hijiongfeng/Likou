#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

/*
给定一个长度为偶数的整数数组 arr，
只有对 arr 进行重组后可以满足 “对于每个 0 <= i < len(arr) / 2，
都有 arr[2 * i + 1] = 2 * arr[2 * i]” 时，返回 true；否则，返回 false。


示例 1：

输入：arr = [3,1,3,6]
输出：false

输入：arr = [4,-2,2,-4]
输出：true
解释：可以用 [-2,-4] 和 [2,4] 这两组组成 [-2,-4,2,4] 或是 [2,4,-2,-4]

*/

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int a : arr){
            mp[a]++;
        }
        if(mp[0] % 2){      // 如果有0，且0为奇数，则不能配对
            return false;
        }
        vector<int> ans;
        ans.reserve(mp.size());
        for(auto &[x,_] : mp){
            ans.push_back(x);
        }
        // 按照绝对值排序
        sort(ans.begin(),ans.end(),[](int a, int b) { return abs(a) < abs(b); });
        for(int x : ans){
            if(mp[2*x] < mp[x])
                return false;
            mp[2*x] -= mp[x];
        }
        return true;
        
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {-4,4,2,-2,4};
    Solution sol;
    cout<<sol.canReorderDoubled(nums)<<endl;
    system("pause");
    return 0;
}
