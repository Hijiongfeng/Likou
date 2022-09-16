#include<bits/stdc++.h>

using namespace std;

int findStr(string str, string mod) {
        // write code here

    if(str.size() < mod.size()){
        return -1;
    }

    int n1 = str.size();
    int n2 = mod.size();
    int i = n1 - 1;
    int j = 0;

    int res = INT_MAX;
    while(i >= 0){
        if(str[i] != mod[j] && mod[j] != '*'){
            i--;
        }else{
            int temp = i;
            int jj = j;
            while(jj < n2){
                i--;
                jj++;
                if(str[i] != mod[jj] && mod[jj] != '*'){
                    break;
                }
            }

            if(jj == n2){
                j = 0;
                res =min(res, i + n2);
            }
            i = temp - 1;
            j = 0;
        } 
    }
    return res;
}


int main(int argc, char const *argv[])
{

    string str = "Hello world";
    string mod = "*";

    cout<<findStr(str,mod)<<endl;

    system("pause");
    return 0;
}
