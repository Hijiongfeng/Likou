#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> id;
        stack<string> state;
        stack<int> time;
        vector<int> sum(n,0);
        int timeSum = 0;
        int pre = 0;
        for(string& log : logs){
            int num1 = log.find(':');
            int num2 = log.rfind(':');
            int ID = stoi(log.substr(0,num1));
            string Status = log.substr(num1+1,num2-num1-1);
            int Time = stoi(log.substr(num2+1));

            if(Status == "start"){
                id.push(ID);
                state.push(Status);
                time.push(Time);
            }else if(Status == "end" && state.top() == "start" && id.top() == ID){
                int temp = Time - time.top() + 1;
                sum[ID] += temp;
                id.pop();state.pop();time.pop();
                
                if(!id.empty()){
                    sum[ID] -= temp;
                }
            }

        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{

    int n = 2;
    vector<string> logs = {"0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"};
    Solution sol;
    vector<int> ans = sol.exclusiveTime(n,logs);
    system("pause");
    return 0;
}
