#include <iostream>
#include <memory>

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
    system("pause");
    return 0;
}