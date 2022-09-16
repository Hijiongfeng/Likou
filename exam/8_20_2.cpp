#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // int N;
    // cin >> N;
    // vector<int> nums;
    // for(int i = 0;i<N;i++){
    //     int a;
    //     cin>>a;
    //     nums.push_back(a);
    // }
    vector<int> nums = {2,1,3,2,4};
    
    if(nums.size() < 3){
        cout<< 0 <<endl;
        system("pause");
        return 0;
    }

    vector<int> left,right;
    for(int i = 0;i<nums.size();i+=2){
        left.push_back(nums[i]);
    }
    for(int i =  1;i<nums.size();i+=2){
        right.push_back(nums[i]);
    }

    int max1 = *max_element(left.begin(),left.end());
    int max2 = *max_element(right.begin(),right.end());

    int ans1 = 0,ans2 = 0;
    int count1 = 0,count2 = 0;
    for(int i = 0;i<left.size();i++){

        ans1 += (max1 - left[i]);
        if(left[i] != max1){
            count1++;
        }
    }

    for(int i = 0;i<right.size();i++){
        ans2 += (max2 - right[i]);
        if(right[i] != max2){
            count2++;
        }
    }

    if(max1 == max2 && count1 <= count2){
        ans1 += count1;
    }else if(max1 == max2 && count1 > count2){
        ans2 += count2;
    }

    cout<<ans1 + ans2<<endl;
    system("pause");
    return 0;
}
