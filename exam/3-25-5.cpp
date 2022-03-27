#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
2022-3-25
地平线面试
让写 求二叉树的最大深度，递归和迭代两种写法
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){}
    TreeNode(int a,TreeNode *le = nullptr,TreeNode *re = nullptr){
        val = a;
        left = le;
        right = re;
    }
};

// 递归
int getdepth(TreeNode *node){
    if(node == nullptr) return 0;
    int leftdepth = getdepth(node->left);
    int rightdepth = getdepth(node->right);
    int depth = 1 + max(leftdepth,rightdepth);
    return depth;
}

int maxdepth(TreeNode *root){
    return getdepth(root);
}

// 迭代方法  

int maxdepth2(TreeNode *root){
    if(root == nullptr) return 0;
    int depth = 0;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        int size = que.size();
        depth++;
        for(int i = 0;i<size;i++){
            TreeNode *node = que.front();
            que.pop();
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
    }
    return depth;
}


int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
