#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    
    int n;
    cin >> n;
    int a;
    vector<int> arr(n,0);
    int m = 0;

    while(cin >> a){
        arr[m] = a;
        ++m;
    }

    int res = 0;

    for(int i = 0;i<n-2;++i){
        queue<int> index;
        for(int k = i + 2;k<n;++k){
            if(arr[i] == arr[k]){
                index.push(k);
            }
        }

        for(int j = i + 1;j<n-1;++j){
            if(index.empty()) break;
            if(arr[j] > arr[i]) continue;
            else{
                while(!index.empty()){
                    if(index.front() > j){
                        res += index.size();
                        break;
                    }else{
                        index.pop();
                    }
                }
            }
        }
    }
    cout<<res<<endl;

    system("pause");
    return 0;
}
