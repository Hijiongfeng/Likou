#include<iostream>
#include<vector>
#include<stack>
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
给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。

提醒一下，二叉搜索树满足下列约束条件：

节点的左子树仅包含键 小于 节点键的节点。
节点的右子树仅包含键 大于 节点键的节点。
左右子树也必须是二叉搜索树。
*/

TreeNode* construct_binary_tree(const vector<int>& vec){
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
    TreeNode* convertBST(TreeNode* root) {  // 迭代法
        if(root == nullptr) return nullptr;
        stack<TreeNode*> st;
        TreeNode *cur = root;
        int pre = 0;
        while(cur != nullptr || !st.empty()){
            if(cur!= nullptr){
                st.push(cur);
                cur = cur->right;
            }else{
                cur = st.top();
                st.pop();
                cur->val += pre;
                pre = cur->val;
                cur = cur->left;
            }
        }
        return root;
    }

private:
    int pre;
    void traversal(TreeNode* cur){
        if(cur == nullptr) return;
        traversal(cur->right);
        cur->val += pre;
        pre = cur->val;
        traversal(cur->left);
    }

public:
    TreeNode* convertBST2(TreeNode* root) {  // 递归·算法
        if(root == nullptr) return nullptr;
        this->pre = 0;
        traversal(root);
        return root;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> num = {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
    TreeNode *root = construct_binary_tree(num);
    Solution sol;
    TreeNode *newroot = sol.convertBST2(root);
    system("pause");
    return 0;
}
