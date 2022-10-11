#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int h = 0,i = citations.size()-1;
        while(i >= 0 && citations[i] > h){
            i--;
            h++;
        }
        return h;
    }
};

int main(int argc, char const *argv[])
{
    
    system("pause");
    return 0;
}
