#include<bits/stdc++.h>

using namespace std;

/*
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。

五种情况讨论
1.没有找到
2.叶子节点
3.有左节点，无右节点
4.无左节点，有右节点
5.有左节点，有右节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        if(root->val == key){
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            else if(root->left == nullptr && root->right != nullptr){
                TreeNode *node = root->right;
                delete root;
                return node;
            }
            else if(root->left != nullptr && root->right == nullptr){
                TreeNode *node = root->left;
                delete root;
                return node;
            }
            else {
                TreeNode *cur = root->right;
                while(cur->left != nullptr){
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode *temp = root;
                root = root->right;
                delete temp;
                return root;
            }
        }

        if(root->val > key) root->left = deleteNode(root->left,key);
        if(root->val < key) root->right = deleteNode(root->right,key);
        return root;
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
