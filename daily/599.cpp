#include<iostream>
#include<vector>
#include<vector>

using namespace std;

/*
假设 Andy 和 Doris 想在晚餐时选择一家餐厅，
并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。

你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 
如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设答案总是存在。
*/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        int count = INT_MAX;
        for(int i = 0;i<list1.size();i++){           
            for(int j = 0;j<list2.size();j++){
                if(list1[i] == list2[j]){
                    int temp = i + j;
                    //count = temp < count ? temp : count;
                    if(temp == count){          // 先判断，相等 ；就能考虑所有情况
                        count = temp;
                        res.push_back(list1[i]);
                    }
                    if(temp < count){
                        count = temp;
                        if(res.size() == 0){
                            res.push_back(list1[i]);
                        }else{
                            res.pop_back();
                            res.push_back(list1[i]);
                        }
                    }

                }
                
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    // vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    // vector<string> list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    // vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    // vector<string> list2 = {"KFC", "Shogun", "Burger King"};
    // vector<string> list1 = {"Shogun","Piatti","Tapioca Express","Burger King","KFC"};
    // vector<string> list2 = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};

    vector<string> list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
    vector<string> list2 = {"KFC","Burger King","Tapioca Express","Shogun"};

    Solution sol;
    vector<string> vec = sol.findRestaurant(list1,list2);
    for(auto& a : vec){
        cout<<a<<endl;
    }
    system("pause");
    return 0;
}
