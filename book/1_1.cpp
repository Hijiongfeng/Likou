#include<iostream>
#include<vector>
#include<string>

using namespace std;

class IntCell{
public:
    explicit IntCell(int initialValue = 0){
        storedValue = new int (initialValue);
    }
    ~IntCell(){
        delete storedValue;
    }

    IntCell(const IntCell & rhs){                       // 拷贝构造函数
        storedValue = new int(*rhs.storedValue);
    }

    IntCell(IntCell && rhs):storedValue(rhs.storedValue) {      // 移动构造函数
        rhs.storedValue = nullptr;
    }

    IntCell & operator=(const IntCell & rhs){           // 拷贝赋值
        if(this != &rhs){
            *storedValue = *rhs.storedValue;
        }
        return *this;
    }

    IntCell & operator=(IntCell && rhs){                // 移动赋值
        std::swap(storedValue,rhs.storedValue);
        return *this;
    }

    int read() const{
        return *storedValue;
    }
    void write(int x){
        storedValue = new int(x);
    }


private:
    int *storedValue;               // 带有指针，注意深浅拷贝
};

void f1(){
    IntCell a(2);
    IntCell b = a;
    IntCell c;

    c = a;
    a.write(4);
    cout<<a.read()<<endl<<b.read()<<endl<<c.read()<<endl;
}

// 函数模板

template <typename Comparable>
const Comparable & findMax(const vector<Comparable> & a){
    int maxIndex = 0;

    for(int i = 1;i<a.size();i++){
        if(a[maxIndex] < a[i])
            maxIndex = i;
    }
    
    return a[maxIndex];
}

void f2(){
    vector<int> v1 = {1,2,3,5,10,4,7};
    vector<double> v2 = {1.1,400.5,300.4};

    cout<<findMax(v1)<<endl;
    cout<<findMax(v2)<<endl;
}


// 类模板

template <typename Object>
class MemoryCell{
public:
    explicit MemoryCell(const Object & initialValue = Object{})
    : storedValue(initialValue) {}

    const Object & read() const{
        return storedValue;
    }

    void write(const Object & x){
        storedValue = x;
    }

private:
    Object storedValue;
};



class Square{
public:
    explicit Square(double s = 0): side(s)      // sonstruct 
    {}

    double getSide() const{
        return side;
    }

    double getArea() const{
        return side * side;
    }

    double getPerimeter() const{
        return 4 * side;
    }

    bool operator<(const Square & rhs) const{       // 重载 < 运算符
        return getSide() < rhs.getSide();
    }

    void print(ostream & out = cout) const{
        out<<"(Square " << getSide() << ")";
    } 


private:
    double side;
};

ostream & operator<<(ostream & out,const Square & rhs){     // 重载 << 运算符，能够输出一个类 ；；成员函数实现不了 << 重载
    rhs.print(out);
    return out;
}


int main(int argc, char const *argv[])
{
    vector<Square> v = {Square{3.0},Square{2.0},Square{1.0}};
    cout<<"Large square : "<<findMax(v)<<endl;

    system("pause");
    return 0;
}
