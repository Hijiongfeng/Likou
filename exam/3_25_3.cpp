#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*

验证合法字符串
*/

void isValid(string s){
    if(s.size() == 0)
        cout<< "Yes" <<endl;
    
}

int main(int argc, char const *argv[])
{
    int row;
    cin >> row;
    vector<string> input;
    while(row--){
        string str;
        cin>>str;
        input.push_back(str);
    }

    system("pause");
    return 0;
}
