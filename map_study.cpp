#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<string.h>
using namespace std;


void construct_study(){
    //(1)通过调用 map 容器类的默认构造函数，可以创建出一个空的 map 容器，比如：
    map<string,int> muMap1;

    // (2) 当然在创建 map 容器的同时，也可以进行初始化，比如：
    map<string,int> myMap2{{"fengjiong",10}, {"is",20}, {"cool",30}};

    map<string,int> myMap3{ make_pair("fengjiong",40)};

    //(3) 除此之外，在某些场景中，可以利用先前已创建好的 map 容器，再创建一个新的 map 容器。例如：

    map<string,int> myMap4(myMap2);  // 拷贝构造函数
    //C++ 11 标准中，还为 map 容器增添了移动构造函数。

    //(4) map 类模板还支持取已建 map 容器中指定区域内的键值对，创建并初始化新的 map 容器

    map<string,int> myMap5(++myMap2.begin(),myMap2.end());

    //(5) 我们可以改变 map 内部的排序规则

    map<string,int,std::greater<string>> myMap6{ {"fengjiong", 10} ,{"is",20}};

}

void iter_study(){
    map<string,int,std::greater<string>> myMap{{"fengjiong",10},
{"is",20}, {"cool",30}};

/*
is 20
fengjiong 10
cool 30
*/
/*
cool 30
fengjiong 10
is 20
*/
    for(auto it = myMap.cbegin();it != myMap.cend();it++){ // 常量 不允许修改
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<"*******"<<endl;
    auto iter = myMap.find("fengjiong");
    for(;iter != myMap.end();iter++){
        cout<<iter->first<<" "<<iter->second<<endl;
    }

//同时，map 类模板中还提供有 lower_bound(key) 和 upper_bound(key) 成员方法，它们的功能是类似的，唯一的区别在于：
// lower_bound(key) 返回的是指向第一个键不小于 key 的键值对的迭代器；
// upper_bound(key) 返回的是指向第一个键大于 key 的键值对的迭代器；

    auto iter_lower = myMap.lower_bound("fengjiong");
    cout<<"lower: "<<iter_lower->first<<" "<<iter_lower->second<<endl;

    auto iter_upper = myMap.upper_bound("fengjiong");
    cout<<"upper: "<<iter_upper->first<<" "<<iter_upper->second<<endl;
}


void get_value(){
    // 两种方式获取 键 对应的 value 值
    // 1.[]
    // 2.at
    std::map<std::string, std::string>myMap{ {"STL","http://c.biancheng.net/stl/"},
                                             {"C","http://c.biancheng.net/c/"},
                                             {"Java","http://c.biancheng.net/java/"} };
    string cValue = myMap["C"];     // map 里面有C 可以索引到；没有的话 会自动创建
    cout<<"C"<<" "<<cValue<<endl;

    string cValue2 = myMap["Fengjiong"];
    //  没有回自动创建，并不会报错
    for(auto it = myMap.begin();it!=myMap.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    cout<<"*****"<<endl;
    // at 找不到 key 会报错
    cout << myMap.at("C") << endl;
    

}

void insert_study(){

    // [] 插入元素

    map<string,int> myMap{{"fengjiong" , 10}};
    // 获取已经有的 key-value
    cout<<myMap["fengjiong"]<<endl;
    // 添加新的 key-value
    myMap["is"] = 20;
    // 修改已经有的
    myMap["fengjiong"] = 30;

    for(auto it = myMap.cbegin();it!=myMap.cend();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    cout<<endl<<endl;

    // insert 的四种用法

    // 1. 无需指定插入位置，直接将键值对添加到 map 容器中。insert() 方法的语法格式有以下 2 中

    map<string,string> newMap; //创建一个 空的map容器
    
    pair<string,string> STL = {"STL study","fengjiong"};    // 创建一个 pair 对象

    pair<map<string,string>::iterator,bool> ret;    // insert 返回对象

    ret = newMap.insert(STL);  // STL 并不是临时对象，以第一种方式传参 左值引用传递

    cout<<ret.first->first<<" "<<ret.first->second<<" "<<ret.second<<endl;

    // 右值引用 传递

    ret = newMap.insert({"C++ study","500"});

    cout<<ret.first->first<<" "<<ret.first->second<<" "<<ret.second<<endl;

    // 插入失败
    // 对于插入失败的 insert() 方法，
    //同样会返回一个 pair 对象，其中包含一个指向 map 容器中键为 "STL教程" 的键值对和值为 0 的 bool 变量。
    ret = newMap.insert({"STL study","666"});

    cout<<ret.first->first<<" "<<ret.first->second<<" "<<ret.second<<endl;

    // 2. 向指定位置 插入，返回值是一个 迭代器，不是 pair 对象
    



}

void multimap_study(){
    // multimap 可以存储 键相同的 键值对
    // multimap 构造函数可以 仿照 map 基本是相同的
    multimap<string,string> myMultiMap;
    //count(key)	在当前 multimap 容器中，查找键为 key 的键值对的个数并返回。

    // 与map相比，multimap并没有提供 at 函数，也没有重载 [] 运算符
    // 因为multimap容器中指定的键可能对应多个键值对，而不是一个
    
}


int main(int argc, char const *argv[])
{

    //iter_study();
    //get_value();
    insert_study();

    system("pause");
    return 0;
}
