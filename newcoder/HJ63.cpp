#include<bits/stdc++.h>

using namespace std;

int countGC(string & s){
    int count = 0;
    for(char & ch : s){
        if(ch == 'G' || ch == 'C')
            count++;
    }
    return count;
}

int main(int argc, char const *argv[])
{

    string s = "AACTGTGCACGACCTGA";
    int k = 5;
    double per = 0;
    string res = "";
    int n = s.size();
    for(int i = 0;i<=n-k;i++){
        string temp = s.substr(i,k);
        int numGC = countGC(temp);
        if(numGC * 1.0 / k > per){
            per = numGC * 1.0 / k;
            res = temp;
        }
    }
    cout<<res<<endl;
    system("pause");
    return 0;
}
