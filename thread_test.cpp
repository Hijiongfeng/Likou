#include <iostream>

#include<thread>


int i = 0;
void test(){
    int num = 10000;
    for(int i=0;i<num;i++){
        i++;
    }
}
int main(int argc, const char **argv)
{
    std::cout<<"Start all thread"<<std::endl;

    return 0;
}