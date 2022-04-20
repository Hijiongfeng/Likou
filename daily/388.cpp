#include<bits/stdc++.h>

using namespace std;

/*

*/

class Solution {
public:
    int lengthLongestPath(string input) {
        int ans = 0;
        vector<int> dir;
        for(int i = 0;i<input.size();i++){
            int tcnt = 0;
            while(i<input.size() && input[i] == '\t'){
                i++;
                tcnt++;
            }
            int len = 0;
            int fi = 0;
            while(i + len < input.size()){
                if(input[i+len] == '\n'){
                    break;
                }
                if(input[i+len] == '.'){
                    fi = 1;
                }
                len++;
            }
            //如果是目录，放入dir或更新dir，如果是文件更新答案
            if (fi) {
                if (tcnt == 0) {
                    ans = max(ans, len);
                } else {
                    int tans = len + tcnt;
                    for (int j = 0; j < tcnt; ++j) {
                        tans += dir[j];
                    }
                    ans = max(ans, tans);
                }
            } else {
                if (dir.size() == tcnt) {   // 新的一层
                    dir.push_back(len);
                } else {                    // 如果还在当前这一层
                    dir[tcnt] = len;
                }
            }
            i += len;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";

    Solution sol;
    cout<<sol.lengthLongestPath(s)<<endl;
    system("pause");
    return 0;
}
