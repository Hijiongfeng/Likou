#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include <stdio.h>  
using namespace std;
/*
registration complete
illegal length
acount existed
illegal charactor
*/
void printInput(vector<string> & input){
    unordered_set<string> set;
    
    for(auto & a : input){
        bool flag = true;
        if(a.size() > 12 || a.size() < 6){
            cout<<"illegal length"<<endl;
            continue;
        }
        for(auto & c : a){
            if(!isalpha(c)){
                cout<<"illegal charactor"<<endl;
                flag = false;
                //break;
            }
            if(flag == true){
                continue;
            }else{
                break;
            }

        }

        if(set.find(a) != set.end() && flag == true){
            cout<<"acount existed"<<endl;
        }
        if(set.find(a) == set.end() && flag == true){
            cout<<"registration complete"<<endl;
            set.insert(a);
        }
    }
}

int main(int argc, char const *argv[])
{
    int row;
    cin >> row;
    vector<string> input;
    // while(row){
    //     string str;
    //     getline(cin,str);
    //     input.push_back(str);
    //     row--;
    // }
    string str;             // 也可以在用一个getline() 把缓冲区内的字符接收出来，再开始接收
    getline(cin,str);
    //setbuf(stdin,NULL); // 清除缓冲区内的 字符 C语言
    for(int i = 0;i<row;i++){
        string str1;
        getline(cin,str1);
        input.push_back(str1);
    }

    //vector<string> input = {"abcdef","abc","abcdef","abcd2f"};
    printInput(input);
    int a = 0;
    system("pause");
    return 0;
}
