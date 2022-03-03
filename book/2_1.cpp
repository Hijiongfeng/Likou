#include<iostream>
#include<vector>

using namespace std;

/*
最大相连子序列和 平方级算法
*/
int maxSubSum2(const vector<int> & nums){
    int maxSum = 0;
    for(int i = 0;i<nums.size();i++){
        int tempSum = 0;

        for(int j = i;j<nums.size();j++){
            tempSum += nums[j];

            if(tempSum > maxSum)
                maxSum = tempSum;
        }
    }
    return maxSum;
}

/*
最大相连子序列和 线性时间
*/

int maxSubSum4(const vector<int> & nums){
    int maxSum = 0;
    int thisSum = 0;
    for(int i = 0;i<nums.size();i++){
        thisSum += nums[i];
        
        if(thisSum > maxSum)
            maxSum = thisSum;
        else if (thisSum < 0)
            thisSum = 0;
    }
    return maxSum;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {4,-3,5,-2,-1,2,6,-2};
    cout<<maxSubSum2(nums)<<endl;
    cout<<maxSubSum4(nums)<<endl;
    system("pause");
    return 0;
}
