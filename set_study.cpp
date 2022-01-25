#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<unordered_set>


using namespace std;

int main(int argc, char const *argv[])      // set 要求 key 和 value 值相同，容器内只有一中类型的变量
{
    set<int,greater<int>> num_set;      // 有第二个参数 可以控制 set 内部的排序；
    num_set.insert(1);
    num_set.insert(1);
    num_set.insert(0);
    num_set.insert(6);
    num_set.insert(10);
    
    cout<<"num_set size is: "<<num_set.size()<<endl;
    for(auto it = num_set.begin();it != num_set.end();it++){
        cout<<*it<<endl;
    }

    cout<<"******"<<endl;

    set<string> string_set{"fengjiong", "is", "is","cool"};      // 元素不能重复
    
    for(auto it = string_set.begin();it!=string_set.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<"*****"<<endl;
    cout<<"set finish"<<endl;

    multiset<int> mu_set{1,2,3,1,2,3,4,5,6};    // 元素可以重复

    cout<<"mu_set size: "<<mu_set.size()<<endl;

    for(auto it = mu_set.begin();it!=mu_set.end();it++){
        cout<<*it<<" ";
    }

    cout<<endl<<"********"<<endl;

    unordered_set<int> un_set;
    un_set.insert({7,4,1,8,5,2,9,6,3});

    for(auto it = un_set.begin();it!=un_set.end();it++){
        cout<<*it<<" ";
    }
    system("pause");
    return 0;
}
