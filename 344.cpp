#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while(left<right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<char> str = {'h','e','l','l','o'};
    Solution sol;
    sol.reverseString(str);
    for(auto s:str){
        cout<<s<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}
