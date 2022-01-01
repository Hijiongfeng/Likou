#include<iostream>
#include<vector>

using namespace std;

void func(){            //      二维数组 写法
    vector<int> weight{1,3,4};
    vector<int> value{15,20,30};
    int bagWeight = 4;

    vector<vector<int>> dp(weight.size(),vector<int> (bagWeight+1,0));

    for(int j = weight[0];j<=bagWeight;j++){
        dp[0][j] = value[0];
    }

    for(int i =1;i<weight.size();i++){
        for(int j = 0;j<=bagWeight;j++){
            if(j < weight[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
        }
    }
    cout<<dp[weight.size()-1][bagWeight]<<endl;
}


void func2(){                   //  增加 一维数组 解法；
    vector<int> weight{1,3,4};
    vector<int> value{15,20,30};
    int bagweight = 4;

    vector<int> dp(bagweight+1,0);

    for(int i = 0;i<weight.size();i++){
        for(int j = bagweight;j>=weight[i];j--){
            dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    cout<<dp[bagweight]<<endl;
}

int main(int argc, char const *argv[])
{
    func2();
    system("pause");
    return 0;
}
