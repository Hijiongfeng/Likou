#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void func1(vector<int> & a){
    for(auto it = begin(a);it != end(a); it++){
        cout<<*it<<endl;
    }
}

/*
拷贝构造函数：输入为 常量的 类对象 引用，返回值为类名
移动构造函数：输入为 类对象 右值，不能是 常量的，要进行移动，移动之后 原来的就要变成临时对象，不能保存，所以要是可变的，不能是常量的，返回值是类名

拷贝赋值函数：输入为 常量的类对象的引用，返回值 是类对象的引用，只进行 拷贝操作；
移动赋值函数：输入为 类对象的右值 ，返回值是 类对象的引用，移动之后 原来的 对象清空了
*/


template<typename Object>
class Vector{
public:
    explicit Vector(int initSize = 0) : theSize(initSize),
        theCapacity(initSize + 10){
            objects = new Object[ theCapacity ];
    }
    Vector(const Vector & rhs) : theSize(rhs.theSize),      // 拷贝构造函数
        theCapacity(rhs.theCapacity),objects(nullptr)
    {
        objects = new Object[theCapacity];
        for(int k = 0;k<theSize;k++){
            objects[k] = rhs.objects[k];
        }
    }

    Vector & operator=(const Vector & rhs){                 // 拷贝赋值
        Vector copy = rhs;
        std::swap(*this,copy);
        return *this;
    }

    ~Vector(){
        delete [] objects;
    }

    Vector (Vector && rhs) : theSize(rhs.theSize),          // 移动构造函数
        theCapacity(rhs.theCapacity),objects(rhs.objects)
    {
        rhs.theSize = 0;
        rhs.theCapacity = 0;
        rhs.objects = nullptr;
    }

    Vector & operator=(Vector && rhs){                  // 移动赋值
        std::swap(theSize,rhs.theSize);
        std::swap(theCapacity,rhs.theCapacity);
        std::swap(objects,rhs.objects);
        
        return *this;
    }

    void resize(int newSize){
        if(newSize > theCapacity){
            reserve(newSize * 2);
        }
        theSize = newSize;
    }

    void reserve(int newCapacity){
        if(newCapacity < theSize)
            return;
        Object *newArray = new Object[newCapacity];
        for(int k = 0; k<theSize;k++){
            newArray[k] = std::move(objects[k]);
        }

        theCapacity = newCapacity;
        std::swap(objects,newArray);
        delete [] newArray;
    }

    Object & operator[](int index){
        return objects[index];
    }

    const Object & operator[](int index) const{
        return objects[index];
    }

    bool empty() const{
        return theSize == 0;
    }

    int size() const{
        return theSize;
    }

    int capacity() const{
        return theCapacity;
    }

    void push_back(const Object & x){
        if(theSize == theCapacity){
            reserve( 2 * theCapacity + 1);
        }
        objects[theSize++] = x;
    }

    void push_back(Object && x){
        if(theSize == theCapacity){
            reserve( 2 * theCapacity + 1);
        }
        objects[theSize++] = std::move(x);
    }

    void pop_back(){
        --theSize;
    }

    const Object & back() const{
        return objects[theSize - 1];
    }

    typedef Object * iterator;                  //  迭代器
    typedef const Object * const_iterator;      // 常量迭代器

    iterator begin(){
        return &objects[0];
    }
    
    const_iterator begin() const{
        return &objects[0];
    }

    iterator end(){
        return &objects[size()];
    }

    const_iterator end() const{
        return &objects[size()];
    }

private:
    int theSize;
    int theCapacity;
    Object *objects;
};



int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,4,5};
    func1(nums);

    Vector<int> vec(3);

    vec[0] = 1;
    vec[1] = 2;
    vec[2] = 3;

    system("pause");
    return 0;
}
