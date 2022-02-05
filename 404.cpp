#include<iostream>
#include<vector>
#include<stack>
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
/*计算给定二叉树的所有左叶子之和。

示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
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
/*如果该节点的左节点不为空，该节点的左节点的左节点为空，
该节点的左节点的右节点为空，则找到了一个左叶子，判断代码如下：*/
    int sumOfLeftLeaves(TreeNode* root) {  // 迭代法
        if(root == nullptr) return 0;
        stack<TreeNode*> st;
        st.push(root);
        int res = 0;
        while(!st.empty()){
            TreeNode *node = st.top();
            st.pop();
            if(node->left!=nullptr && node->left->left == nullptr && node->left->right == nullptr){
                res += node->left->val;
            }
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        return res;
    }


    int sumOfLeftLeaves2(TreeNode* root) {  // 递归法   // 理解不了  // 递归还要再好好看看  真的
        if(root == nullptr) return 0;

        int leftnumber = sumOfLeftLeaves2(root->left);
        int rightnumber = sumOfLeftLeaves2(root->right);

        int res = 0;
        if(root->left!=nullptr && root->left->left == nullptr && root->left->right == nullptr){
            res=root->left->val;
        }
        int sum = res + leftnumber + rightnumber;
        return sum;
    }
};


int main(int argc, const char** argv) {
    vector<int> num = {3,9,20,-1,-1,15,7};
    TreeNode *root = construct_binary_tree(num);
    Solution sol;
    cout<<sol.sumOfLeftLeaves(root)<<endl;

    system("pause");
    return 0;
}