#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

/*

十进制 转 7 进制
*/

class Solution {
public:
    string convertToBase7(int num) {
        string s;
        if(num == 0) return to_string(num);
        int new_num = abs(num);
        while(new_num){
            int a = new_num % 7;
            s += to_string(a);
            new_num = new_num / 7;
        }
        if(num < 0){
            s += "-";
        }
        reverse(s.begin(),s.end());
        return s;
    }
};


int main(int argc, char const *argv[])
{
    int num = 0;
    Solution sol;
    cout<<sol.convertToBase7(num)<<endl;
    system("pause");
    return 0;
}
