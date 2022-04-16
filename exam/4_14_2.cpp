#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
using namespace std;

// int main(int argc, char const *argv[])
// {
//     int n;
//     cin >> n;
//     vector<int> nums;
//     string color;
//     for(int i = 0;i<n;i++){
//         int a;
//         cin>>a;
//         nums.push_back(a);
//     }
//     cin>>color;
//     // map<char,vector<int>> mp;
//     // for(int i = 0;i<color.size();i++){
//     //     mp[color[i]].emplace_back(nums[i]);
//     // }

//     // int ans = 0;

//     // auto B_vec = mp['B'];
//     // auto R_vec = mp['R'];
//     // for(int i = 0;i<B_vec.size()&&R_vec.size()!=0;i++){
//     //     for(int j = 0;j<R_vec.size();j++){
//     //         if(B_vec[i] == R_vec[j]){
//     //             ans++;
//     //         }
//     //     }
//     // }

//     map<char,multiset<int>> mp;
//     for(int i = 0;i<color.size();i++){
//         mp[color[i]].insert(nums[i]);
//     }
//     int ans = 0;

//     auto B_vec = mp['B'];
//     auto R_vec = mp['R'];

//     if(B_vec.size() < R_vec.size()){
//         for(auto it = B_vec.begin();it!=B_vec.end();it++){
//             ans += R_vec.count(*it);
//         }
//     }else{
//         for(auto it = R_vec.begin();it!=R_vec.end();it++){
//             ans += B_vec.count(*it);
//         }
//     }

//     cout<<ans<<endl;
//     system("pause");
//     return 0;
// }


int main(int argc, char const *argv[])
{
    int n;
	string colors;
	cin >> n;
	vector<int> nums(n, 0);
	for(int i = 0; i < n; i++) cin >> nums[i];
	cin >> colors;
	unordered_map<int, pair<int,int>> mp;
	for(int i = 0; i < n; i++){
		if(colors[i] == 'R') mp[nums[i]].first++;       // 找到每个数字的不同颜色
		else mp[nums[i]].second++;
	}
	long long ans = 0;
	for(auto &it : mp) ans += it.second.first * it.second.second;
	cout << ans;
	
    system("pause");
    return 0;
}



