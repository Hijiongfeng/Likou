#include <iostream>
#include<thread>
#include<Windows.h>
#include<mutex>
#include<chrono>       // std::chrono::seconds()
using namespace std;

int n = 0;
std::mutex mut;         // 定义一个 mutex 类对象，创建一个互斥锁

void threadFun1(int n) {
    Sleep(5);
    cout << "---thread1 running\n";
    cout << "n=" << n << endl;
    
}
void threadFun2(const char * url) {
    cout << "---thread2 running\n";
    cout << "url=" << url << endl;
}


void threadFun3(){
    while(n<10){
        mut.lock();  // 加锁
        n++;
        cout<<"ID"<<std::this_thread::get_id()<<" n = "<<n<<endl;
        mut.unlock();  // 解锁
        std::this_thread::sleep_for(chrono::seconds(1));
        
    }
}

int main1() {
    //调用第 1 种构造函数
    thread thread1(threadFun1,10);
    //调用移动构造函数
    thread thread2 = std::thread(threadFun2,"666");
    //阻塞主线程，等待 thread1 线程执行完毕

    thread1.join();
    //阻塞主线程，等待 thread2 线程执行完毕
    thread2.join();
    system("pause");
    return 0;
}


int main2() {
    //调用第 1 种构造函数
    thread thread1(threadFun1, 10);
    //输出 thread1 线程的 ID
    cout << "thread1 ID:" << thread1.get_id() << endl;
    //调用移动构造函数
    thread thread2 = std::thread(threadFun2, "http://c.biancheng.net");
    //输出 thread2 线程的 ID
    cout << "thread2 ID:" << thread2.get_id() << endl;
    //将 thread1 与主线程分离开，thread1 线程独立执行。
    thread1.detach();
    //判断 thread2 线程是否可以调用 join() 函数
    if (thread2.joinable()) {
        //阻塞主线程，直至 thread2 线程执行完毕。
        thread2.join();
    }
    cout << "main finished" << endl;
    return 0;
}

int main()
{
    thread th1(threadFun3);
    thread th2(threadFun3);
    th1.join();
    th2.join();
    system("pause");
    return 0;
}