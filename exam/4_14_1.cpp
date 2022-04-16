#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<vector<char>> matrix(3*n,vector<char> (4*n,'*'));
    int index = 1;
    for(int i = 0;i<3*n;i++){
        for(int j = n;j<4*n-n;j++){
            matrix[i][j] = '.';
        }
    }
    for(int i=3*n,j = 1,jj = 4*n-2;i<4*n;i++,j++,jj--){
        vector<char> ma(4*n,'.');
        for(int k = j;k<j+n;k++){
            ma[k] = '*';
        }
        for(int k = jj;k>jj-n;k--){
            ma[k] = '*';
        }
        matrix.push_back(ma);
    }

    for(auto& vec:matrix){
        for(auto& ch:vec){
            cout<<ch;
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}


