#include<bits/stdc++.h>

using namespace std;

// class Solution {
// public:
    
//     long long minimum(vector<int>& a) {
//         int n = a.size();
//         vector<long long> prefix(a.size(),0);
//         prefix[0] = a[0];
//         for(int i = 1;i<a.size();i++){
//             prefix[i] = prefix[i-1]+a[i];
//         }
//         long long half = prefix.back() / 2;
//         unordered_set<long long> num_set;
//         long long temp = INT_MAX;
//         for(int i = 0;i<n;i++){
//             if(num_set.count(prefix[i] - half)){
//                 return 0;
//             }else{
//                 if(abs(prefix[i] - half))
//             }
//             num_set.insert(prefix[i]);
//         }

        
//     }
// };


class Solution {
public:
    
    long long minimum(vector<int>& a) {
        int n = a.size();
        vector<long long> prefix(a.size(),0);
        prefix[0] = a[0];
        for(int i = 1;i<a.size();i++){
            prefix[i] = prefix[i-1]+a[i];
        }
        long long half = prefix.back() / 2;
        long long ans = INT_MAX;
        long long ans2;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                long long temp = prefix[j] - prefix[i];
                if(abs(half - temp)<ans){
                    ans = abs(half - temp);
                    ans2 = temp;
                }
            }
        }   
        return prefix.back() -ans2 -ans2;
    }
};

class Solution {
public:
    
    long long minimum(vector<int>& a) {
        long long sum = accumulate(a.begin(),a.end(),0);

        long long target = sum / 2;
        int n = a.size();
        vector<vector<long long>> dp(n,vector<long long>(target+1,0));

        for(long long j = a[0];j<=target;j++){
            dp[0][j] = a[0];
        }

        for(long long i = 1;i<n;i++){
            for(long long j = 0;j<=target;j++){
                if(j <a[i]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j],dp[i-1][j-a[i]]+a[i]);
            }
        }
        return sum - dp[n-1][target] - dp[n-1][target] ;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,4,5};
    Solution sol;
    cout<<sol.minimum(nums)<<endl;
    system("pause");
    return 0;
}
