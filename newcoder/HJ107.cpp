#include<bits/stdc++.h>

using namespace std;

/*
计算一个浮点数的立方根，不使用库函数。
保留一位小数。
*/

double getValue(double n){
    double x = 1.0;
    while(fabs(x*x*x - n) > 1e-9) {
        x = x - ((x * x * x - n) / (3 * x * x));
    }
    return x;
}

int main(int argc, char const *argv[])
{
    string s = "1234";
    s = "0" + s;
    int a = 0;
    double n;
    cin >> n;
    double ans = getValue(n);
    cout<<fixed<<setprecision(1)<<ans<<endl;

    system("pause");
    return 0;
}
