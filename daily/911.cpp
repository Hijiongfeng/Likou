#include<bits/stdc++.h>

using namespace std;

/*
给你两个整数数组 persons 和 times 。在选举中，第 i 张票是在时刻为
 times[i] 时投给候选人 persons[i] 的。

对于发生在时刻 t 的每个查询，需要找出在 t 时刻在选举中领先的候选人的编号。

在 t 时刻投出的选票也将被计入我们的查询之中。在平局的情况下，最近获得投票的候选人将会获胜。

实现 TopVotedCandidate 类：

TopVotedCandidate(int[] persons, int[] times) 使用 persons 和 times 数组初始化对象。
int q(int t) 根据前面描述的规则，返回在时刻 t 在选举中领先的候选人的编号。
*/

class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->persons = persons;
        this->times = times;
        for(int i = 0;i<times.size();i++){
            time_mp[times[i]] = i; 
        }
    }
    
    int q(int t) {
        unordered_map<int,int> num_mp;
        vector<int>::iterator it;
        int index = 0;
        if(t > times.back()){
            it = --times.end();
            index = times.size()-1;
        }else{
            it = lower_bound(times.begin(),times.end(),t);
            if(*it == t){
            index = time_mp[*it];
            }else{
            index = time_mp[*it]-1;
            }
        }
        
        int ans = 0,fre = 0;
        for(int i = 0;i<=index;i++){
            num_mp[persons[i]]++;
            if(num_mp[persons[i]] >= fre){
                ans = persons[i];
                fre = num_mp[persons[i]];
            }
        }
        return ans;
    }
private:
    vector<int> persons;
    vector<int> times;
    map<int,int> time_mp;
};

class TopVotedCandidate2 {
public:
    TopVotedCandidate2(vector<int>& persons, vector<int>& times) {
        this->persons = persons;
        this->times = times;
        map<int,int> tp;
        int mx = 0,index = 0;
        for(int i = 0;i<times.size();i++){
            time_mp[times[i]] = i;
            tp[persons[i]]++;

            if(tp[persons[i]]>=mx){
                mx=tp[persons[i]];
                index=i;
            }
            //更新当前时刻最多得票人的编号
            ans[i]=persons[index];
            //cout<<ans[times[i]]<<endl;
        }
    }
    
    int q(int t) {          // 就是为了得到当前时间的索引
        unordered_map<int,int> num_mp;
        vector<int>::iterator it;
        int index = 0;
        if(t > times.back()){
            it = times.end()-1;
            index = times.size()-1;
        }else{
            it = lower_bound(times.begin(),times.end(),t);
            if(*it == t){
            index = time_mp[*it];
            }else{
            index = time_mp[*it]-1;
            }
        }
        return ans[index];
    }
private:
    vector<int> persons;
    vector<int> times;
    map<int,int> time_mp;       // 用于查找时间的索引
    map<int,int> ans;           // 在当前索引的时候，最高票选的选手
};

int main(int argc, char const *argv[])
{
    vector<int> persons = {0,1,2,2,1};
    vector<int> times = {20,28,29,54,56};
    TopVotedCandidate2 top(persons,times);
    cout<<top.q(57)<<endl;
    system("pause");
    return 0;
}
