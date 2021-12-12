#include<iostream>
#include<vector>
#include<queue>

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
/*给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。
*/
TreeNode* construct_binary_node(const vector<int> & vec){
    vector<TreeNode*> vecTree;
    TreeNode *root = nullptr;
    for(int i=0;i<vec.size();i++){
        TreeNode *node = nullptr;
        if(vec[i] != -1){
            node = new TreeNode(vec[i]);
        }
        vecTree.push_back(node);
        if(i == 0) root = node;
    }

    for(int i =0;2*i+2<vec.size();i++){
        if(vecTree[i] != nullptr){
            vecTree[i]->left = vecTree[2*i+1];
            vecTree[i]->right = vecTree[2*i+2];
        }
    }
    return root;
}

class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> que;
        int depth = 0;
        if(root == nullptr) return depth;   // 空节点不入队
        que.push(root);
        while(!que.empty()){
            int size = que.size();  // 有多少层 就有 几个深度
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

    int maxDepth2(TreeNode* root) {   // 左右中  后序
        if(root == nullptr) return 0;
        int leftDepth = maxDepth2(root->left);
        int rightDepth = maxDepth2(root->right);
        return 1+max(leftDepth,rightDepth);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num = {3,9,20,-1,-1,15,7};
    auto root = construct_binary_node(num);
    Solution sol;
    cout<<sol.maxDepth2(root)<<endl;
    system("pause");
    return 0;
}
