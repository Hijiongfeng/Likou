#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr) return root;
        
        swap(root->left,root->right);
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};

class Solution2 {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr) return root;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode *node = st.top();
            st.pop();

            swap(node->left,node->right);

            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return root;
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
