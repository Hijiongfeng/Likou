#include<iostream>
#include<vector>

using namespace std;
int a,b;
bool d[101][101]; 
class Solution {
    int fx[4][2] = {{0,  1},
                    {0,  -1},
                    {1,  0},
                    {-1, 0}};//定义方向数组,可移动的方位上下左右
private:
    void dfs(int x,int y,vector<vector<int>> & gird){
        int m = gird.size();
        int n = gird[0].size();
        
        if (x < 0 || x >= m || y < 0 || y >= n) return;     // 判断结束 要放在循环外面，递归结束标志
        if(gird[x][y] == 0) return;
        gird[x][y] = 0;                         // 防止重复搜索
        
        // dfs(x+1,y,gird); 
        // dfs(x,y+1,gird); 
        // dfs(x-1,y,gird); 
        // dfs(x,y-1,gird);

        for(int i = 0;i<4;i++){
            dfs(x+fx[i][0],y+fx[i][1],gird);
        }
    }

public:
    int countIsLet(vector<vector<int>> & gird) {
        int count = 0;
        for(int i = 0;i<gird.size();i++){
            for(int j = 0;j<gird[0].size();j++){
                if (gird[i][j] == 1){
                    ++count;
                    dfs(i,j,gird);
                }

            }
        }
        return count;
    }
};


int main(int argc, char const *argv[])
{
    vector<vector<int>> gird = {{1,1,0,0,1},
                                {1,1,0,0,1},
                                {0,0,1,0,0},
                                {0,0,1,0,0}};
    
    // cin>>a>>b;           // 输入部分
    // char c;
    // for(int i = 0;i<a;i++){
    //     for(int j = 0;j<b;j++){
    //         cin >> c;
    //         if(c == 'w'){
    //             d[i][j] = 1;
    //         }
    //     }
    // }

    Solution sol;
    cout<<sol.countIsLet(gird)<<endl;
    system("pause");
    return 0;
}
