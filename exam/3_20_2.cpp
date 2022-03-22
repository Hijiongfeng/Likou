#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

/*
米哈游笔试第二道编程题
*/

bool isSame(vector<int>& ip1,vector<int>& ip2){
    for(int i = 0;i<ip1.size();i++){
        if(ip1[i] == ip2[i])
            continue;
        else
            return false;
    }
    return true;
}

void count(vector<int>& ip1,vector<int>& ip2){
    int in = 0;
    int on = 0;
    vector<int> newip1 = ip1;
    vector<int> newip2 = ip2;
    while( isSame(newip1,ip2) == false){
        int a = newip1[0];
        vector<int> new_ip1(newip1.begin()+1,newip1.end());
        new_ip1.push_back(a);
        newip1 = new_ip1;
        in++;
    }

    while( isSame(ip1,newip2) == false){
        int a = newip2[0];
        vector<int> new_ip2(newip2.begin()+1,newip2.end());
        new_ip2.push_back(a);
        newip2 = new_ip2;
        on++;
    }
    
    cout<<min(in,on)<<endl;
}

int main(int argc, char const *argv[])
{


    vector<int> a = {4,1,3,5,2};
    vector<int> b = {1,3,5,2,4};
    count(a,b);
    // int n;
    // cin >> n;
    // vector<vector<int>> input;
    // for(int i = 1;i<=n;i++){
    //     int a;
    //     cin >> a;
    //     vector<int> path1(a,0);
    //     for(int j = 0;j<a;j++){
    //         int c;
    //         cin >> c;
    //         path1[j] = c;
    //     }
    //     vector<int> path2(a,0);
    //     for(int j = 0;j<a;j++){
    //         int c;
    //         cin >> c;
    //         path2[j] = c;
    //     }
    //     input.push_back(path1);
    //     input.push_back(path2);
    // }
    
    // for(int i = 0;i<input.size();i+=2){
    //     count(input[i],input[i+1]);
    // }

    system("pause");
    return 0;
}
