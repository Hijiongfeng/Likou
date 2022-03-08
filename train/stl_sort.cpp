#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<queue>
using namespace std;

/*
STL 内的sort
*/
bool mycomp1(int a,int b){      // 普通函数实现 自定义排序规则
    return a > b;               // 降序排列
}

class mycomp2{          //以函数对象的方式自定义排序规则
public:
    bool operator()(int a,int b){
        return a > b;
    }
};


void func(){
    vector<int> nums = {7,4,1,8,5,2,9,6,3};
    sort(nums.begin(),nums.end(),std::greater<int>());
}

void func1(){
    vector<int> nums = {7,4,1,1,8,5,2,9,6,3};
    stable_sort(nums.begin(),nums.end());       // 不改变重复元素的顺序
    //sort(nums.begin(),nums.end(),std::greater());
}

void func2(){        // 部分排序
    vector<int> nums = {7,4,1,8,5,2,9,6,3};         // 对原数组进行修改
    partial_sort(nums.begin(),nums.begin()+3,nums.end());
    int a = 0;
}

/*
partial_sort_copy() 函数的功能和 partial_sort() 类似，唯一的区别在于，
前者不会对原有数据做任何变动，而是先将选定的部分元素拷贝到另外指定的数组或容器中，然后再对这部分元素进行排序。

partial_sort_copy() 函数会将 [first, last) 范围内最小
（或最大）的 result_last-result_first 个元素复制到 [result_first, result_last) 区域中，
并对该区域的元素做升序（或降序）排序。
*/

void func3(){

    //int myints[5] = { 0 };
    vector<int> copy(5);
    std::list<int> mylist{ 7,4,1,8,5,2,9,6,3 };
    //按照默认的排序规则进行部分排序
    std::partial_sort_copy(mylist.begin(), mylist.end(), copy.begin(),copy.end());
    cout << "第一次排序：\n";
    for (int i = 0; i < 5; i++) {
        cout << copy[i] << " ";
    }
}

/*
简单的理解 nth_element() 函数的功能，当采用默认的升序排序规则（std::less<T>）时，
该函数可以从某个序列中找到第 n 小的元素 K，并将 K 移动到序列中第 n 的位置处。
不仅如此，整个序列经过 nth_element() 函数处理后，所有位于 K 之前的元素都比 K 小，所有位于 K 之后的元素都比 K 大。

当然，我们也可以将 nth_element() 函数的排序规则自定义为降序排序，
此时该函数会找到第 n 大的元素 K 并将其移动到第 n 的位置处，
同时所有位于 K 之前的元素都比 K 大，所有位于 K 之后的元素都比 K 小。
*/

void func4(){
    std::vector<int> vec{ 7,4,1,8,5,2,9,6,3 };
    std::nth_element(vec.begin(),vec.begin()+2,vec.end());
    for(auto & a : vec){
        cout<<a<<" ";
    }
}

/*

判断一个数组是否是排序的

判断 [first, last) 区域内的数据是否符合 std::less<T> 排序规则，即是否为升序序列
bool is_sorted (ForwardIterator first, ForwardIterator last);

判断 [first, last) 区域内的数据是否符合 comp 排序规则  
bool is_sorted (ForwardIterator first, ForwardIterator last, Compare comp);
*/

void func5(){
    std::vector<int> vec{ 7,4,1,8,5,2,9,6,3 };
    sort(vec.begin(),vec.end());

    if(std::is_sorted(vec.begin(),vec.end())){
        cout<<"sorted..."<<endl;
    }else{
        cout<<"not sorted..."<<endl;
    }
    
}

int main(int argc, char const *argv[])
{
    //func2();
    // func3();
    // func4();
    func5();
    system("pause");
    return 0;
}
