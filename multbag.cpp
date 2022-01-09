#include<iostream>
#include<vector>

using namespace std;

/*
多重背包，相似于 01背包。
把多重背包展开，就是一个01背包

有N种物品和一个容量为V 的背包。
第i种物品最多有Mi件可用，每件耗费的空间是Ci ，价值是Wi 。
求解将哪些物品装入背包可使这些物品的耗费的空间 总和不超过背包容量，且价值总和最大。
*/

void func(){
    vector<int> weight{1,3,4};
    vector<int> value{15,20,30};
    vector<int> nums{2,3,2};

    int bagweight = 10;

    for(int i = 0;i<nums.size();i++){       // 把完全背包分散开来
        while(nums[i] > 1){
            weight.push_back(weight[i]);
            value.push_back(value[i]);
            nums[i]--;
        }
    }

    // 按照 01背包 的遍历方式 进行遍历
    vector<int> dp(bagweight+1,0);

    for(int i = 0;i<weight.size();i++){
        for(int j = bagweight;j>=weight[i];j--){
            dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }

    cout<<dp[bagweight]<<endl;
}


void func2(){
    vector<int> weight{1,3,4};
    vector<int> value{15,20,30};
    vector<int> nums{2,3,2};

    int bagweight = 10;

    for(int i = 0;i<nums.size();i++){       // 把完全背包分散开来
        while(nums[i] > 1){
            weight.push_back(weight[i]);
            value.push_back(value[i]);
            nums[i]--;
        }
    }


    // 按照 01背包 的遍历方式 进行遍历
    vector<vector<int>> dp(weight.size(),vector<int> (bagweight+1,0));

    for(int j = 0;j<=bagweight;j++){        ///  初始化dp 数组
        if(j>=weight[0]) dp[0][j] = value[0];
    }

    for(int i = 1;i<weight.size();i++){
        for(int j = 0;j<=bagweight;j++){
            if(j>=weight[i]) dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout<<dp[weight.size()-1][bagweight]<<endl;
}


int main(int argc, char const *argv[])
{

    func();

    func2();
    system("pause");
    return 0;
}
