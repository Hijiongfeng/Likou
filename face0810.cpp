#include<bits/stdc++.h>

using namespace std;

/*
编写函数，实现许多图片编辑软件都支持的「颜色填充」功能。

待填充的图像用二维数组 image 表示，元素为初始颜色值。
初始坐标点的行坐标为 sr 列坐标为 sc。需要填充的新颜色为 newColor 。

「周围区域」是指颜色相同且在上、下、左、右四个方向上存在相连情况的若干元素。

请用新颜色填充初始坐标点的周围区域，并返回填充后的图像。
*/


class Solution {
private:
    int fx[4][4] = {{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<int>>& img,int x,int y,int oldColor,int newColor){
        int m = img.size();
        int n = img[0].size();
        if(x < 0 || x >= m || y < 0 || y >= n){
            return;
        }
        if(img[x][y] != oldColor){
            return;
        }
        if(img[x][y] == newColor){
            return;
        }
        img[x][y] = newColor;
        for(int i = 0;i<4;i++){
            int newx = x + fx[i][0];
            int newy = y + fx[i][1];
            dfs(img,newx,newy,oldColor,newColor);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        dfs(image,sr,sc,oldColor,newColor);
        return image;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}}; 
    int sr = 1, sc = 1, newColor = 2;
    Solution sol;
    vector<vector<int>> newImage = sol.floodFill(image,sr,sc,newColor);
    for(vector<int> &a:newImage){
        for(int & b : a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}
