#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size();
        for(int i=0;i<s.size();i+=(2*k)){
            if(i+k<n){
                reverse(s.begin()+i,s.begin()+i+k);
                continue;
            }
            reverse(s.begin()+i,s.end());
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    string str = "abcd";
    Solution sol;
    auto s1 = sol.reverseStr(str,2);
    for(auto s:s1){
        cout<<s<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}
