#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 输入参数是每个应用持有WakeLock的起始时间及结束时间，函数返回值是每个应用对总WakeLock时长的贡献值，返回值vector里面的每个元素的数值累加即为手机总的持有WakeLock的时长。
     * @param wakeLock int整型vector<vector<>> vector<vector<int>>的每个元素代表某个应用的持有WakeLock的信息，内部的vector<int>，元素按照奇偶排列，偶数元素代表拿WakeLock的起始时间点，奇数代表释放WakeLock的时间点
     * @return int整型vector
     */
    vector<int> getWakeLockContrib(vector<vector<int> >& wakeLock) {
        // write code here

        

    }
};

int main(int argc, char const *argv[])
{

    Solution sol;
    vector<vector<int>> walkLock = {{1234,1240},{1236,1238,1245,1250}};

    vector<int> res = sol.getWakeLockContrib(walkLock);

    for(int i = 0;i<res.size();i++){
        cout<<res[i]<<endl;
    }

    system("pause");
    return 0;
}




class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * findStr从反方向查找子串，返回最后一次匹配成功时，子串的偏移位置，如果没有匹配成功返回-1
     * @param str string字符串 待匹配的字符串
     * @param mod string字符串 匹配模式字符串
     * @return int整型
     */
    int findStr(string str, string mod) {
        // write code here
            if(str.size() < mod.size()){
        return -1;
    }

    int n1 = str.size();
    int n2 = mod.size();
    int i = n1 - 1;
    int j = 0;

    int res = INT_MAX;
    while(i >= 0){
        if(str[i] != mod[j] && mod[j] != '*'){
            i--;
        }else if(str[i] == mod[j]){
            i--;
            j++;
        }else if(mod[j] == '*'){
            i--;
            j++;
        }

        if(j == n2){
            j = 0;
            res =min(res, i + n2);
        }
        
    } 
    return res;
    }
};