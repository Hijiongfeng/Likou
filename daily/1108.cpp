#include<bits/stdc++.h>

using namespace std;

/*
给你一个有效的 IPv4 地址 address，返回这个 IP 地址的无效化版本。

所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."。

 

示例 1：

输入：address = "1.1.1.1"
输出："1[.]1[.]1[.]1"
*/

class Solution {
public:
    string defangIPaddr(string address) {
        string old_value = ".";
        string new_value = "[.]";
        for (string::size_type pos(0); pos != string::npos; pos += new_value.length()) {
		    if ((pos = address.find(old_value, pos)) != string::npos) {
			    address.replace(pos, old_value.length(), new_value);
		    }
		    else break;
	    }   
	    return address;
    }
};

int main(int argc, char const *argv[])
{
    string address = "1.1.1.1";
    Solution sol;
    cout<<sol.defangIPaddr(address)<<endl;

    system("pause");
    return 0;
}
