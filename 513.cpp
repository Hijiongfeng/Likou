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
/*给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

假设二叉树中至少有一个节点。
*/
TreeNode* construct_binary_tree(const vector<int> & vec){
    vector<TreeNode*> vecTree;
    TreeNode *root = nullptr;
    for(int i = 0;i<vec.size();i++){
        TreeNode *node = nullptr;
        if(vec[i] != -1){
            node = new TreeNode(vec[i]);
        }
        vecTree.push_back(node);       
        if(i == 0) root = node;
    }

    for(int i=0;2*i+2<vec.size();i++){
        if(vecTree[i] != nullptr){
            vecTree[i]->left = vecTree[2*i+1];
            vecTree[i]->right = vecTree[2*i+2];
        }
    }
    return root;
}

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {  // 迭代法
        if(root == nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        vector<int> vec;
        while(!que.empty())
        {
            int size = que.size();
            for(int i = 0;i<size;i++){
                TreeNode *node = que.front();
                que.pop();
                if(i == 0) vec.push_back(node->val);        // 这感觉不对了啊，第一个元素不一定左边的啊；但是好像测试案例都是这样的
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return vec[vec.size()-1];
    }
};

int main(int argc, const char** argv) {
    vector<int> num = {2,-1,3};
    TreeNode *root = construct_binary_tree(num);
    Solution sol;
    cout<<sol.findBottomLeftValue(root)<<endl;
    system("pause");
    return 0;
}