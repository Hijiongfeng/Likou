#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

/*
给定两个数组，编写一个函数来计算它们的交集。
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> num1_set;        //  两个set容器；
        unordered_set<int> num1_num2_set;
        vector<int> res;
        for(int i = 0;i<nums1.size();i++){
            num1_set.insert(nums1[i]);
        }
        for(int i = 0;i<nums2.size();i++){
            if(num1_set.find(nums2[i])!=num1_set.end()){
                num1_num2_set.insert(nums2[i]);
            }
        }

        for(auto it = num1_num2_set.begin();it!=num1_num2_set.end();it++){
            res.push_back(*it);
        }

        return res;
        
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num1 = {1,2,2,1};
    vector<int> num2 = {2,2};

    Solution sol;
    vector<int> res = sol.intersection(num1,num2);
    for(auto &x:res){
        cout<<x<<endl;
    }
    system("pause");
    return 0;
}
