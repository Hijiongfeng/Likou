#include<bits/stdc++.h>

using namespace std;

string splitStr(string & s){
    int N = s.size();
    int index1 = 0,index2 = 0;
    for(int i = N-1;i>=0;i--){
        if(s[i] == '\\'){
            index1 = i;
            break;
        }
        if(s[i] == ' '){
            index2 = i;
        }
    }
    string s1 = s.substr(index1 + 1,index2 - index1-1);
    string s2 = s.substr(index2 + 1);
    if(s1.size() > 16){
        s1.erase(0,s1.size() - 16);
    }
    return s1 + " " + s2;
}

void mistakeRecode(vector<string>& path){
    deque<string> deq;
    unordered_set<string> set_del;
    unordered_set<string> set_save;
    unordered_map<string,int> mp;
    int n = path.size();
    for(int i = 0;i<n;i++){
        string temp = splitStr(path[i]);
        mp[temp]++;
        deq.emplace_back(temp);
        if(deq.size() > 8 && set_save.count(temp) == 0 && set_del.count(temp) == 0){
            string temp2 = deq.front();
            deq.pop_front();
            set_del.emplace(temp2);
            set_save.erase(temp2);
        }else if(deq.size() > 8 && set_save.count(temp)){
            deq.pop_back();
        }else if(deq.size() > 8 && set_del.count(temp)){
            deq.pop_back();
        }

        if(set_save.count(temp) == 0 && deq.size() <= 8){
            set_save.emplace(temp);
        }else if(set_save.count(temp) && deq.size() <= 8){
            deq.pop_front();
        }
    }
    for(auto &str : deq){
        cout<<str<<" "<<mp[str]<<endl;
    }
}


int main(int argc, char const *argv[])
{
    // vector<string> path = {
    // "D:\\zwtymj\\xccb\\ljj\\cqzlyaszjvlsjmkwoqijggmybr 645",
    // "E:\\je\\rzuwnjvnuz 633",
    // "C:\\km\\tgjwpb\\gy\\atl 637",
    // "F:\\weioj\\hadd\\connsh\\rwyfvzsopsuiqjnr 647",
    // "E:\\ns\\mfwj\\wqkoki\\eez 648",
    // "D:\\cfmwafhhgeyawnool 649",
    // "E:\\czt\\opwip\\osnll\\c 637",
    // "G:\\nt\\f 633",
    // "F:\\fop\\ywzqaop 631",
    // "F:\\yay\\jc\\ywzqaop 631",
    // "D:\\zwtymj\\xccb\\ljj\\cqzlyaszjvlsjmkwoqijggmybr 645"};

    vector<string> path = {
    "a\\b\\ccckkkkkkkkkkkkkkkk 456",
    "a\\b\\uuukkkkkkkkkkkkkkkk 456"};
    mistakeRecode(path);

    system("pause");
    return 0;
}
