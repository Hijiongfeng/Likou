#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;
/*翻转一棵二叉树。*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        if(root == nullptr) return root;    // 空节点 不入栈 
        st.push(root);
        while(!st.empty()){
            TreeNode *node = st.top();
            st.pop();
            swap(node->left,node->right);
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        return root;
    }

    // 层序打印一遍
    void printNode(TreeNode* root){
        queue<TreeNode*> que;
        if(root != nullptr) que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i = 0;i<size;i++){
                TreeNode *node = que.front();
                que.pop();
                cout<<node->val<<" ";
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            cout<<endl;
        }

    }
};

int main(int argc, const char** argv) {
    vector<int> num = {4,2,7,1,3,6,9};
    TreeNode *root = construct_binary_node(num);
    Solution sol;
    auto final = sol.invertTree(root);
    sol.printNode(final);
    system("pause");
    return 0;
}