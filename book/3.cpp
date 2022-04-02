#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    string str1;
    cin >> str1;
    string str2;
    cin >> str2;

    //string str1 = "abcd";
    int ans = 0;
    for(int i = 0;i<str1.length();i++){
        for(int j = i+1;j<str1.length() + 1;j++){
            string temp = str1.substr(i,j-i);
            if(strstr(temp.data(),str2.data())){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
