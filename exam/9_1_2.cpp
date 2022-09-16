#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<int> nums(N);
    for(int i = 0;i<N;i++){
        int a;
        cin >>a;
        nums[i] = a;
    }
    int O;
    cin >> O;
    vector<int> op(O);
    for(int i = 0;i<O;i++){
        int a;
        cin >> a;
        op[i] = a;
    }

    for(int i = 0;i<O;i++){
        long long sum = 0;
        for(int j = 0;j<N;j++){
            nums[j] = nums[j] + op[i];
            //sum += abs(nums[j]);
            sum += nums[j] < 0 ? (-nums[j]):nums[j];
        }
        cout<<sum<<endl;
    }

    system("pause");
    return 0;
}
