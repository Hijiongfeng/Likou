#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

vector<int> prime = {2,3,5,7,11,13,17,19,23,29,31};     //11

set<int> st;
vector<int> path;
void backtracking(int n,int k,int startIndex){
    if(path.size() == k){
        st.insert(pow(path[0],2)+pow(path[1],3)+pow(path[2],4));
        st.insert(pow(path[0],2)+pow(path[2],3)+pow(path[1],4));
        st.insert(pow(path[1],2)+pow(path[0],3)+pow(path[2],4));
        st.insert(pow(path[2],2)+pow(path[0],3)+pow(path[1],4));
        st.insert(pow(path[1],2)+pow(path[2],3)+pow(path[0],4));
        st.insert(pow(path[2],2)+pow(path[1],3)+pow(path[0],4));
        return;
    }
    for(int i = startIndex;i<n;i++){
        path.push_back(prime[i]);
        backtracking(n,k,i);
        path.pop_back();
    }
}


int main(int argc, char const *argv[])
{
    backtracking(prime.size(),3,0);

    int N;
    cin>>N;
    vector<int> nums(N);
    for(int i = 0;i<N;i++){
        int a;
        cin>>a;
        nums[i] = a;
    }
    vector<int> result(st.begin(),st.end());
    sort(result.begin(),result.end());
    for(int i = 0;i<nums.size();i++){
       cout<<upper_bound(result.begin(),result.end(),nums[i]) - result.begin()<<endl;  
    }
    system("pause");
    return 0;
}
