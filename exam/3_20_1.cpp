#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

/*
米哈游笔试 第一道编程题
*/

void read(vector<vector<int>> input){
    queue<int> que;
    for(int i = 0;i<input.size();i++){
        if(i == 0 && input[i].size() == 1 &&input[i][0] == 2){
            cout<<"no reliquarles"<<endl;
        }
        if(input[i].size() == 3 && input[i][0] == 1){
            que.push(input[i][1]);
            que.push(input[i][2]);
        }
        if(i > 0 && input[i].size() == 1 && input[i][0] == 2 && que.empty()){
            cout<<"no reliquarles"<<endl;
            
        }
        if(i > 0 && input[i].size() == 1 && input[i][0] == 2 && !que.empty()){
            int a = que.front();
            que.pop();
            int b = que.front();
            que.pop();
            cout<<a<<" "<<b<<endl;
        }

    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<vector<int>> input;
    for(int i = 1;i<=n;i++){
        int a;
        vector<int> path;
        cin >> a;
        if(a == 1){
            int c,d;
            cin >> c >> d;
            path.push_back(a);
            path.push_back(c);
            path.push_back(d);
        }
        if(a == 2){
            path.push_back(a);
        }
        input.push_back(path);
    }
    // vector<vector<int>> input{{2},
    //                         {1,2,3},
    //                         {1,3,2},
    //                         {2},
    //                         {2},
    //                         {2},
    //                         {1,1,5},
    //                         {2},
    //                         {2},
    //                         {2}};

    read(input);

    // for(auto aa : input){
    //     for(auto bb : aa){
    //         cout<<bb<<endl;
    //     }
    // }

    system("pause");
    return 0;
}
