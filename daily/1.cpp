#include <iostream>
#include <vector>
using namespace std;
int main() {
    //int a;
    //cin >> a;
    
    vector<vector<int>> matrix = {{1,3,5,9},
                                  {8,1,3,4},
                                  {5,0,6,1},
                                  {8,8,4,0}};
    
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m,vector<int>(n));
    dp[0][0] = matrix[0][0];
    for(int i = 1;i<n;i++){
        dp[0][i] = dp[0][i-1] + matrix[0][i];
    }
    for(int i = 1;i<m;i++){
        dp[i][0] = dp[i-1][0] + matrix[i][0];
    }
    for(int i = 1;i<m;i++){
        for(int j = 1;j<n;j++){
            dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + matrix[i][j];
        } 
    }
    cout<<dp[m-1][n-1]<<endl;
    int col = m-1,row = n-1;
    while(col >0 || row >0){
        cout<<matrix[col][row]<<endl;
        int temp = dp[col][row] - matrix[col][row];
        if(col != 0 && dp[col-1][row] == temp){
            col--;
        }
        if(row!= 0 && dp[col][row - 1] == temp){
            row--;
        }
        
    }
    system("pause");
    return 0;
}