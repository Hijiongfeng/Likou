#include<iostream>
#include<vector>

using namespace std;

void sort1(vector<int> &vec){
    int a,b;
    for(int i=0;i<vec.size();i++){
        a = vec[i];
        cout<<a;
        for(int j=0;j<vec.size();j++){
            if(vec[j] != a){
                b=vec[j];
            }
            for(int k=0;k<vec.size();k++){
                if(vec[k]!=vec[i] && vec[k] != vec[j]){
                    cout<<a<<b<<vec[k];
                }
                cout<<endl;
            }
        }
    }

}


int main(int argc, char const *argv[])
{
    vector<int> num = {1,2,3};
    sort1(num);
    system("pause");
    return 0;
}
