#include<iostream>
#include<vector>
#include<string>

using namespace std;



int main(int argc, char const *argv[])
{
    // int N;
    // cin >> N;
    // vector<int> nums;
    
    // while(N--){
    //     int a;
    //     cin >> a;
    //     nums.push_back(a);
    // }

    vector<int> nums = {1,4,1,7,1};

    if(nums.size() == 1 || nums.size() == 2) 
        return 0;

    int index1 = 0,index2 = nums.size() -1;
    for(int i = 1;i<nums.size();i++){
        if(nums[i] > nums[i-1]){
            continue;
        }else{
            index1 = i-1;
            break;
        }
    }

    for(int i = nums.size() -1;i>=0;i--){
        if(nums[i-1] > nums[i]){
            continue;
        }else{
            index2 = i;
            break;
        }
    }

    int ans = 0;

    if(index1 == 0 && index2 == nums.size() -1){
        int fl = nums.size() / 2;
        int maxnum = max(nums[fl-1],nums[fl+1]);
        ans += maxnum - nums[fl] + 1;
        
    }

    if(index1 + 1 == index2){
        ans = 1;
    }

    for(int i = index1 + 1;i<index2;i++){
        int maxnum = min(nums[i-1],nums[i+1]);
        ans += maxnum - nums[i] + 1;
        nums[i] = maxnum  + 1 ;
    }


    cout<<ans<<endl;

    system("pause");
    return 0;
}
