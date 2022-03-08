#include<iostream>
#include<vector>
#include<list>
using namespace std;

class A{
public:
    friend ostream & operator<<(ostream & out,const A & a);

    A(int *a) : a(a){

    }

    int operator*() const{          //  重载 * 号
        return *a;
    }

    int *a;
};

A begin(int *a){
    return a;
}

ostream & operator<<(ostream & out,const A & a){        //  (ostream & out,const A & a),这个顺序
    out<<a.a<<endl;
    return out;
}



int main(int argc, char const *argv[])
{
    int b = 10;
    int * a = &b;
    A temp = begin(a);
    cout<<*temp<<endl;
    int aa = 0;
    return 0;
}
