#include<bits/stdc++.h>

using namespace std;

/*
给定一个二叉树的 root ，确定它是否是一个 完全二叉树 。

在一个 完全二叉树 中，除了最后一个关卡外，所有关卡都是完全被填满的，
并且最后一个关卡中的所有节点都是尽可能靠左的。
它可以包含 1 到 2h 节点之间的最后一级 h 。

*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);             //  非空节点 也入队列。
        bool isnull = false;
        while(!que.empty()){
            TreeNode *node = que.front();
            que.pop();
            if(node == nullptr){
                isnull = true;
                continue;
            }else{
                if(isnull){             // 如果找到一个空节点之后还有节点，则为非完全二叉树
                    return false;
                }
                que.push(node->left);
                que.push(node->right);
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
