#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int search(string &s,char flag,int start,int end){
    int action_num = 0;
    int e = 1;
    for(int i  = start;i < end;++i){
        if(i % 2){
            if(s[i] != 'e'){
                ++action_num;
            }
        }else{
            if(flag == s[i]){
                flag = flag == 'r' ? 'd' : 'r';
            }else{
                ++action_num;
                flag = flag == 'r' ? 'd' : 'r';
            }
        }
    }
    return action_num;
}


int main(int argc, char const *argv[])
{
    string s;
    getline(cin,s);

    int res = INT_MAX;

    if(s.size() % 2){
        res = min(res,search(s,'r',0,s.size()));
        res = min(res,search(s,'d',0,s.size()));
    }else{
        res = min(res,search(s,'r',0,s.size()-1));
        res = min(res,search(s,'d',0,s.size()-1));
        res = min(res,search(s,'r',1,s.size()));
        res = min(res,search(s,'d',1,s.size()));
    }

    cout<<res<<endl;
    system("pause");
    return 0;
}
