#include<bits/stdc++.h>

using namespace std;

/*

*/


class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
private:                    // 递归左上角坐标和右下角坐标
    Node* dfs(const vector<vector<int>> &grid,int tx,int ty,int ux,int uy){
        bool isleaf = true;
        for(int i = tx;i<ux;i++){
            for(int j = ty;j<uy;j++){
                if(grid[i][j] != grid[tx][ty]){         // 与第一个比较即可
                    isleaf = false;
                    break;
                }
            }
            if(!isleaf){
                break;
            }
        }
        // 如果是叶子结点，返回节点
        if(isleaf){ 
            return new Node(grid[tx][ty],true);
        }

        // 不是叶子结点 继续递归 拆成四部分

        int x = (tx + ux) / 2;
        int y = (ty + uy) / 2;

        Node* leftTop = dfs(grid,tx,ty,x,y);
        Node* leftBOttom = dfs(grid,x+1,ty,ux,y);
        Node* rightTop = dfs(grid,tx,y+1,x,uy);
        Node* rightBottom = dfs(grid,x+1,y+1,ux,uy);

        return new Node(true,false,leftTop,rightTop,leftBOttom,rightBottom);
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        return dfs(grid,0,0,rows-1,cols -1);
    }
};

int main(int argc, char const *argv[])
{


    system("pause");
    return 0;
}


