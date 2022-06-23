#include<bits/stdc++.h>

using namespace std;

/*
输入描述：
输入两个字符串。保证字符串只含有'0'~'9'字符

输出描述：
输出求和后的结果

示例1
输入：
9876543210
1234567890
复制
输出：
11111111100
*/

int main(int argc, char const *argv[])
{
    string s1 = "2078";
    string s2 = "81";
    if(s1.size() < s2.size()){
        swap(s1,s2);
    }
    int N = s1.size() - s2.size();
    s2 = string(N,'0') + s2;
    int falg = 0;
    string ans;
    for(int i = s1.size()-1;i>=0;i--){
        int temp = (s1[i] - '0') + (s2[i] - '0') + falg;
        if(temp >= 10){
            ans += to_string(temp - 10);
            falg = 1;
        }else{
            ans += to_string(temp);
            falg = 0;
        }
    }
    if(falg){
        ans += (falg + '0');
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    system("pause");
    return 0;
}
