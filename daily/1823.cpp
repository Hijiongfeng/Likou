#include<bits/stdc++.h>

using namespace std;

/*
共有 n 名小伙伴一起做游戏。小伙伴们围成一圈，按 顺时针顺序 从 1 到 n 编号。
确切地说，从第 i 名小伙伴顺时针移动一位会到达第 (i+1) 名小伙伴的位置，
其中 1 <= i < n ，从第 n 名小伙伴顺时针移动一位会回到第 1 名小伙伴的位置。

游戏遵循如下规则：

从第 1 名小伙伴所在位置 开始 。
沿着顺时针方向数 k 名小伙伴，计数时需要 包含 起始时的那位小伙伴。逐个绕圈进行计数，
一些小伙伴可能会被数过不止一次。
你数到的最后一名小伙伴需要离开圈子，并视作输掉游戏。
如果圈子中仍然有不止一名小伙伴，从刚刚输掉的小伙伴的 顺时针下一位 小伙伴 开始，回到步骤 2 继续执行。
否则，圈子中最后一名小伙伴赢得游戏。
给你参与游戏的小伙伴总数 n ，和一个整数 k ，返回游戏的获胜者。
*/

class Solution {
public:
    int findTheWinner(int n, int k) {   // list 暴力模拟
        list<int> num;
        for(int i = 1;i<=n;i++){
            num.push_back(i);
        }
        list<int>::iterator it = num.begin();
        while(num.size() != 1){
            int temp = k-1;
            while(temp--){
                it++;
                if(it == num.end()){
                    it = num.begin();
                }
            }
            it = num.erase(it);         // erase删除后 指向下一个迭代器
            if(it == num.end()){
                it = num.begin();
            }
        }
        return num.front();
    }



    int findTheWinner2(int n, int k) {   //队列 模拟
        queue<int> que;
        for(int i = 1;i<=n;i++){
            que.emplace(i);
        }
        while(que.size() != 1){
            for(int i = 1;i<k;i++){
                que.emplace(que.front());   // 把队首元素 添加到队尾；
                que.pop();
            }
            que.pop();
        }
        return que.front();
    }
//https://blog.csdn.net/u011500062/article/details/72855826
    int findTheWinner3(int n, int k) {
        int winner = 1;
        for (int i = 2; i <= n; i++) {
            winner = (k + winner - 1) % i + 1;      // 超出边界 要取模
        }
        return winner;
    }
};

int main(int argc, char const *argv[])
{
    int n = 5,k = 2;
    Solution sol;
    cout<<sol.findTheWinner3(n,k)<<endl;
    system("pause");
    return 0;
}
