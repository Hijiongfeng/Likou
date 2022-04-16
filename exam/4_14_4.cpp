#include<iostream>
#include<vector>
#include<string>
#include<numeric>
using namespace std;

long long ans = 0;
vector<long long> num;
void backtracking(string &s,int startIndex){        // 回溯法 会超时 数据短的情况下可以
    if(accumulate(num.begin(),num.end(),0) % 9 == 0 && num.size()!=0){
        ans++;
    }
    if(num.size() >= s.size()){
        return;
    }
    for(int i = startIndex;i<s.size();i++){
        num.push_back(s[i]-'0');
        backtracking(s,i+1);
        num.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    int mod = 1e9+7;
    string str;
    cin>> str;
    backtracking(str,0);
    cout<<ans % mod<<endl;
    system("pause");
    return 0;
}
