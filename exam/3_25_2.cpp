#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;
/*
registration complete
illegal length
acount existed
illegal charactor
*/



void countOperator(vector<int> & vec){
    
    sort(vec.begin(),vec.end());
    int num = 0;
    while(vec[1] > 0){
        num++;
        for(int i = 1;i<vec.size();i++){
            vec[i] -= 1;
        }
        sort(vec.begin(),vec.end());
    }

    cout<<num<<endl;
    // for(auto & vec : input){
    //     int count = 0;
    //     sort(vec.begin(),vec.end());
    //     if(vec[1] > 0){

    //     }else{
    //         cout<<count<<endl;
    //     }
    // }
}

int main(int argc, char const *argv[])
{
    // int row;
    // cin >> row;
    // vector<vector<int>> input;
    // while(row--){
    //     int a,b,c,d,e;
    //     cin>>a>>b>>c>>d>>e;
    //     input.push_back({a,b,c,d,e});

    // }
    vector<vector<int>> input = {{5,4,3,2,1},{4,8,10,11,12}};
    for(auto & vec:input){
        countOperator(vec);
    }

    int a = 0;
    system("pause");
    return 0;
}
