#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(int argc, char const *argv[])
{
    // int n;
    // cin >> n;
    // int r,b;
    // cin >> r >>b;
    // string str;
    // cin>>str;
    
    int r = 2,b = 1;

    int N = str.size();
    for(int i = 1;i<str.size();i++){
        if(str[i] == str[i-1] && str[i] == 'r'){
            b--;
            N++;
        }else if(str[i] == str[i-1] && str[i] == 'b'){
            r--;
            N++;
        }
    }

    if(r >= 0 && b >= 0){
        cout<<N<<endl;
    }else{
        int m;
        int n;
        m = r >= 0 ? 0 : abs(r);
        n = b >= 0 ? 0 : abs(b);
        cout<<m<<" "<<n<<endl;
    }

    int a = 0;

    system("pause");
    return 0;
}
