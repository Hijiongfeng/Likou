#include <iostream>
#include <vector>
#include <queue>

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
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，
最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
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

TreeNode *findNode(TreeNode *root, int val)
{
    if (root == nullptr)
        return nullptr;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = que.front();
            que.pop();
            if (node->val == val)
                return node;
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
    }
    return nullptr;
}

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)   // 迭代算法
    {
        if (root == nullptr)
            return nullptr;
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->val < p->val && cur->val < q->val)
            {
                cur = cur->right;
            }
            else if (cur->val > p->val && cur->val > q->val)
            {
                cur = cur->left;
            }
            else
            {
                return cur;
            }
        }
        return nullptr;
    }

private:
    TreeNode* traversal(TreeNode *cur,TreeNode *p, TreeNode *q){
        if(cur == nullptr) return nullptr;
        if(cur->val < p->val && cur->val < q->val){
            TreeNode *right = traversal(cur->right,p,q);
            if(right != nullptr)
                return right;
        }
        if(cur->val > p->val && cur->val > q->val){
            TreeNode *left = traversal(cur->left,p,q);
            if(left != nullptr)
                return left;
        }
        return cur;
    }

public:
    TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q)  // 递归算法
    {
        if(root == nullptr) return nullptr;
        return traversal(root,p,q);
    }
};

int main(int argc, const char **argv)
{
    vector<int> num = {6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5, -1, -1, -1, -1};
    TreeNode *root = construct_binary_tree(num);
    TreeNode *p = findNode(root, 3);
    TreeNode *q = findNode(root, 5);
    Solution sol;
    TreeNode *fin = sol.lowestCommonAncestor2(root, p, q);
    system("pause");
    return 0;
}