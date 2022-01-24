#include <iostream>
#include <string>

using namespace std;

//双指针
class Solution
{
public:
    string replaceSpace(string s)
    {
        int oldSize = s.size();
        int count = 0;
        for (int i = 0; i < oldSize; i++)
        {
            if (s[i] == ' ')
            {
                count++;
            }
        }
        int newSize = oldSize + 2 * count;
        s.resize(newSize);
        int left = oldSize - 1;
        int right = newSize - 1;
        for(;left<right;left--,right--){
            if(s[left]!=' '){
                s[right]=s[left];
            }else{
                s[right] = '0';
                s[right-1] = '2';
                s[right-2] = '%';
                right-=2;
            }
        }
        return s;
    }
};

class Solution2 {
public:
    string replaceSpace(string s) {
        int oldSize = s.size();
        int count = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == ' '){
                count++;
            }
        }
        int newSize = oldSize + 2 * count;
        s.resize(newSize);          // resize 重新设置字符串的大小
        int left = oldSize - 1;
        int right = newSize - 1;
        while(left < right){
            if(s[left] == ' '){
                //right--;
                s[right] = '0';
                
                s[right-1] = '2';
                
                s[right-2] = '%';
                left--;
                right-=3;
            }else{
                s[right] = s[left];
                left--;
                right--;
            }
        }
        return s;
    }
};


int main(int argc, const char **argv)
{
    string str = "We are happy .";
    Solution2 sol;
    cout << sol.replaceSpace(str) << endl;
    system("pause");
    return 0;
}