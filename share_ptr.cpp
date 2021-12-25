#include <iostream>
#include <memory>

void printPtr(int index,int *a){
    std::cout<<index<<" "<<*a<<std::endl;
}

int main(int argc, const char **argv)
{
    //构建三个智能指针
    std::shared_ptr<int> p1(new int(10));
    std::shared_ptr<int> p2(p1);
    std::shared_ptr<int> p3 = p2;

    std::cout << *p3 << std::endl;
    std::cout << p1.use_count() << std::endl;  //判断和p1同指向的智能指针有几个
    p1.reset();  //引用计数器减1 ，p1指向空指针  p1==nullptr
    if (p1)
    {
        std::cout << "p1 is not empty" << std::endl;
    }
    else
    {
        std::cout << "p1 is empty" << std::endl;
    }
    std::cout << *p2 << std::endl;
    std::cout << p2.use_count() << std::endl;  //判断和p2同指向的智能指针有几个

    int *a = new int[3];
    a[0] = 10;
    a[1] = 11;
    a[2] = 33;
    
    for(int i = 0;i<3;i++){
        std::cout<<a[i]<<std::endl;
    }

    std::shared_ptr<int> p4(a);
    
    for(int i = 0;i<3;i++){
        auto ptr = p4.get();
        std::cout<<p4.use_count()<<std::endl;
        printPtr(i,ptr+i);
    }

    std::cout<<*p4<<std::endl;

    system("pause");
    return 0;
}