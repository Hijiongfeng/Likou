#include<iostream>
#include<vector>

using namespace std;

/*
给定四个整数 sx , sy ，tx 和 ty，
如果通过一系列的转换可以从起点 (sx, sy) 到达终点 (tx, ty)，则返回 true，否则返回 false。

从点 (x, y) 可以转换到 (x, x+y)  或者 (x+y, y)。

输入: sx = 1, sy = 1, tx = 3, ty = 5
输出: true
解释:
可以通过以下一系列转换从起点转换到终点：
(1, 1) -> (1, 2)
(1, 2) -> (3, 2)
(3, 2) -> (3, 5)

*/
/*

因为加法不能确定是谁是谁加谁，所以倒推就是减法，
因为都是大于0的，所以肯定是大的减小的，
所以迭代下去就行。再将特殊情况的迭代次数解决就行
用余数的方式就可以了
*/
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx > sx  && ty > sy && tx != ty){
            if(tx > ty){
                tx = tx - ty;
            }else{
                ty = ty - tx;
            }
        }
        
        if(tx == sx && ty == sy){
            return true;
        }else if(tx == sx){
            return ty > sy && (ty -sy) % tx== 0;
        }else if(ty == sy){
            return tx > sx && (tx -sx) % ty == 0;
        }else{
            return false;
        }
    }
};

int main(int argc, char const *argv[])
{
    int a = 1,b = 1,c = 3,d = 5;
    Solution sol;
    cout<<sol.reachingPoints(a,b,c,d)<<endl;
    system("pause");
    return 0;
}
