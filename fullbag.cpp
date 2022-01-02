#include<iostream>
#include<vector>

using namespace std;

// 完全背包问题

void func(){        // 二维数组 方法
    vector<int> weight{1,3,4};
    vector<int> value{15,20,30};
    int bagweight = 4;

    vector<vector<int>> dp(weight.size(),vector<int> (bagweight+1, 0));

    for(int j = 0;j<=bagweight;j++){            // 初始化 dp 数组
        if(j>=weight[0]) dp[0][j] = max(dp[0][j],dp[0][j-weight[0]]+value[0]);
    }

    for(int i = 1;i<weight.size();i++){     // 先遍历物品，在遍历背包
        for(int j = 0;j<=bagweight;j++){
            if(j >= weight[i]) dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout<<dp[weight.size()-1][bagweight]<<endl;
}

void func2(){       // 一维数组，滚动数组的方法
    vector<int> weight{1,3,4};
    vector<int> value{15,20,30};
    int bagweight = 4;

    vector<int> dp(bagweight+1, 0);
    
    for(int i = 0;i<weight.size();i++){         //  先遍历物品，在遍历背包
        for(int j = weight[i];j<=bagweight;j++){        //  从至少能 装下 的容量开始，能够重复装
            dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    cout<<dp[bagweight]<<endl;
}

void func3(){       // 一维数组，改变 物品背包的遍历顺序
    vector<int> weight{1,3,4};
    vector<int> value{15,20,30};
    int bagweight = 4;

    vector<int> dp(bagweight+1, 0);
    
    for(int j = 0;j<=bagweight;j++){
        for(int i = 0;i<weight.size();i++){
            if(j >= weight[i]) dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }

    cout<<dp[bagweight]<<endl;
}

int main(int argc, char const *argv[])
{
    func3();
    system("pause");
    return 0;
}
