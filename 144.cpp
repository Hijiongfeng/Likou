#include<iostream>
#include<vector>
#include<stack>

using namespace std;
/*给你二叉树的根节点 root ，返回它节点值的 前序 遍历。*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int num,TreeNode *l = nullptr,TreeNode *r=nullptr){
        val = num;
        left = l;
        right = r;
    }
};

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
    for(int i = 0;2*i+2<vec.size();i++){
        if(vecTree[i] != nullptr){
            vecTree[i]->left = vecTree[2*i+1];
            vecTree[i]->right = vecTree[2*i+2];
        }
    }
    return root;
}

class Solution {  // 递归
public:
    void traversal(TreeNode *head,vector<int> & vec){
        if(head == nullptr) return;
        vec.push_back(head->val);
        traversal(head->left,vec);
        traversal(head->right,vec);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root,res);
        return res;
    }
};

class Solution2 {  //迭代
public:

    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> vec;
        if(root == nullptr) return vec;
        st.push(root);
        while(!st.empty()){  //终止条件 栈为空
            TreeNode *node = st.top();
            st.pop();
            if(node != nullptr){
                vec.push_back(node->val);
            }else{
                continue;
            }
            st.push(node->right);
            st.push(node->left);
        }
        return vec;  
    }
};

int main(int argc, const char** argv) {
    vector<int> nums = {5,4,6,2,1,-1,-1};
    auto root = construct_binary_tree(nums);
    Solution2 sol;
    auto final = sol.preorderTraversal(root);
    for(auto &x:final){
        cout<<x<<" ";
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}