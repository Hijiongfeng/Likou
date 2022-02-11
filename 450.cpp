#include<iostream>
#include<vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，
并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。

*/
TreeNode *construct_binary_tree(const vector<int> &vec)
{
    vector<TreeNode *> vecTree;
    TreeNode *root = nullptr;
    for (int i = 0; i < vec.size(); i++)
    {
        TreeNode *node = nullptr;
        if (vec[i] != -1)
        {
            node = new TreeNode(vec[i]);
        }
        vecTree.push_back(node);
        if (i == 0)
            root = node;
    }

    for (int i = 0; 2 * i + 2 < vec.size(); i++)
    {
        if (vecTree[i] != nullptr)
        {
            vecTree[i]->left = vecTree[2 * i + 1];
            vecTree[i]->right = vecTree[2 * i + 2];
        }
    }
    return root;
}

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {  // 这个题好好看看  不懂   递归解法
        // 5种情况
        if(root == nullptr) return root;
        if(root->val == key){
            if(root->left == nullptr && root->right == nullptr){ // 2.左右节点为 空  直接删除
                delete root;
                return nullptr;
            }else if(root->left == nullptr && root->right != nullptr){  // 3.左为空，右不为空
                // TreeNode *retNode = root->right;
                // delete root;
                // return retNode;
                TreeNode *temp = root;
                root = root->right;
                delete temp;
                return root;
            }else if(root->left != nullptr && root->right == nullptr){  // 4. 左不为空，右为空
                // TreeNode *retNode = root->left;
                // delete root;
                // return retNode;
                TreeNode *temp = root;
                root = root->right;
                delete temp;
                return root;
            }else if(root->left != nullptr && root->right != nullptr){  // 5. 左右 都不为空
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

int main(int argc, const char** argv) {

    system("pause");
    return 0;
}