#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

//typedef false NOT_FOUND ;
/*
binary search
*/
template<typename Comparable>
int binareSearch(const vector<Comparable> & a,const Comparable & x){
    int left = 0,right = a.size()-1;
    while(left <= right){                       // 左闭 右闭
        int mid = left + (right - left)/2;
        if(a[mid] < x){
            left = mid + 1;
        }else if(a[mid] > x){
            right = mid - 1;
        }else{
            return mid;
        }
    }
    return -1;
}

/*
quick 幂
*/

long long pow(long long x,int n){
    if(n == 0)
        return 1;
    if(n == 1)
        return x;
    if(n % 2 == 0){
        return pow(x * x,n / 2);
    }else
        return pow(x * x,n / 2) * x;
}


long long gcd(long long m,long long n){
    while(n != 0){
        long long rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}


int main(int argc, char const *argv[])
{
    vector<int> nums = {4,-3,5,-2,-1,2,6,-2};
    sort(nums.begin(),nums.end());

    long long m = 18,n = 15;
    cout<<gcd(m,n)<<endl;

    system("pause");
    return 0;
}
