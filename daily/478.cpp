#include<bits/stdc++.h>

using namespace std;

/*
给定圆的半径和圆心的位置，实现函数 randPoint ，在圆中产生均匀随机点。

实现 Solution 类:

Solution(double radius, double x_center, double y_center) 
用圆的半径 radius 和圆心的位置 (x_center, y_center) 初始化对象
randPoint() 返回圆内的一个随机点。圆周上的一点被认为在圆内。答案作为数组返回 [x, y] 。

*/
class Solution {
public:
    Solution(double radius, double x_center, double y_center) 
    : radius(radius) , X0(x_center), Y0(y_center) ,e(random_device{}()){
       srand((unsigned)time(NULL));

    }
    
    void randPoint() {
        double r =  rand() / double(RAND_MAX) * radius * radius;    // 半径1/2 面积并不是1/2 而是1/4；要随机半径的平方
        double angle =rand() / double(RAND_MAX) * 360;
        double x = sqrt(r) * cos(angle * PI / 180);
        double y = sqrt(r) * sin(angle * PI / 180);
        cout<< x << " " << y << endl;
    }

    void randPoint2() {                             // 随机外接正方形        
        uniform_real_distribution<> x1(-radius,radius);
        uniform_real_distribution<> y1(-radius,radius);
        double dx = x1(e),dy = y1(e);
        while(dx * dx + dy * dy >  radius * radius){
            dx = x1(e);
            dy = y1(e);
        }
        cout<<X0 + dx <<" "<<Y0+dy<<endl;     
    }
private:
    double radius;
    double X0;
    double Y0;
    double PI = 3.1415926575;
    default_random_engine e;
};


int main(int argc, char const *argv[])
{
    Solution* obj = new Solution(1.0, 0.0, 0.0);
    obj->randPoint2();
    obj->randPoint2();
    obj->randPoint2();
    obj->randPoint();
    obj->randPoint2();
    obj->randPoint2();
    system("pause");
    return 0;
}
