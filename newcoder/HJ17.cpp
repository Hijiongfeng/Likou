#include<bits/stdc++.h>

using namespace std;

/*
开发一个坐标计算工具， A表示向左移动，D表示向右移动，W表示向上移动，S表示向下移动。
从（0,0）点开始移动，从输入字符串里面读取一些坐标，并将最终输入结果输出到输出文件里面。

输入：
合法坐标为A(或者D或者W或者S) + 数字（两位以内）
坐标之间以;分隔。
非法坐标点需要进行丢弃。如AA10;  A1A;  $%$;  YAD; 等。
下面是一个简单的例子 如：
A10;S20;W10;D30;X;A1A;B10A11;;A10;
处理过程：
起点（0,0）
+   A10   =  （-10,0）
+   S20   =  (-10,-20)
+   W10  =  (-10,-10)
+   D30  =  (20,-10)
+   x    =  无效
+   A1A   =  无效
+   B10A11   =  无效
+  一个空 不影响
+   A10  =  (10,-10)
结果 （10， -10）
数据范围：每组输入的字符串长度满足 1\le n \le 10000 \1≤n≤10000  ，坐标保证满足
31
 ≤x,y≤2 
31
 −1  ，且数字部分仅含正数
*/

bool isVaild(string & temp){
    if(temp.size() <= 1){
        return false;
    }
    if(temp[0] != 'W' && temp[0] != 'A' && temp[0] != 'S' && temp[0] != 'D' ){
        return false;
    }
    for(int i = 1;i<temp.size();i++){
        if(!isdigit(temp[i]))
            return false;
    }
    return true;
}

void cordCalculae(string & s){
    int initX = 0,initY = 0;
    int start = 0;
    for(int i = 0;i<s.size();i++){
        if(s[i] != ';'){
            continue;
        }
        string temp = s.substr(start,i - start);
        start = i + 1;
        if(isVaild(temp)){
            int value = stoi(temp.substr(1));
            if(temp[0] == 'W'){
                initY += value;
            }else if(temp[0] == 'A'){
                initX -= value;
            }else if(temp[0] == 'S'){
                initY -= value;
            }else if(temp[0] == 'D'){
                initX += value;
            }
        }
    }
    cout<<initX<<","<<initY<<endl;
}

int main(int argc, char const *argv[])
{
    string s = "A10;S20;W10;D30;X;A1A;B10A11;;A10;";
    cordCalculae(s);
    system("pause");
    return 0;
}
