#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if(asteroids.size() == 1){
            return asteroids;
        }
        stack<int> st;
        for(int i = 0;i<asteroids.size();i++){
            if(st.empty()){
                st.push(asteroids[i]);
                continue;
            }
            if(!st.empty() && st.top() < 0 && asteroids[i] > 0){
                st.push(asteroids[i]);
                continue;
            }else if(!st.empty() && st.top() > 0 && asteroids[i] > 0){
                st.push(asteroids[i]);
                continue;
            }else if(!st.empty() && st.top() < 0 && asteroids[i] < 0){
                st.push(asteroids[i]);
                continue;
            }
            int temp = asteroids[i];

            while(!st.empty() && st.top() > 0 && temp < 0){
                int a = st.top();
                st.pop();
                if( a > abs(asteroids[i])){
                    temp = a;
                    st.push(temp);
                    break;
                }else if(a == abs(temp)){
                    //st.pop();
                    break;
                }
            }
            
        }

        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> asteroids = {8,-8};

    Solution sol;
    vector<int> ans = sol.asteroidCollision(asteroids);    
    system("pause");
    return 0;
}


