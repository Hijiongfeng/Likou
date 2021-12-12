#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int num,TreeNode *l=nullptr,TreeNode *r = nullptr){
        val = num;
        left = l;
        right = r;
    }
};

/*给定一个二叉树的根节点 root ，返回它的 中序 遍历。*/  
// 递归算法

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
    void travelTree(TreeNode *node,vector<int> &vec){
        if(node == nullptr) return;
        travelTree(node->left,vec);
        vec.push_back(node->val);
        travelTree(node->right,vec);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        travelTree(root,res);
        return res;
    }
};

class Solution2 {  // 迭代法   中序需要 指针
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> vec;
        TreeNode *cur = root;
        while(cur != nullptr || !st.empty()){
            if(cur != nullptr){
                st.push(cur);
                cur = cur->left;
            }else{
                cur = st.top();
                st.pop();
                vec.push_back(cur->val);
                cur = cur->right;
            }
        }
        return vec;
    }
};

int main(int argc, const char** argv) {
    vector<int> num = {6,2,8,1,4,-1,-1,-1,-1,3,7};
    auto root = construct_binary_tree(num);
    Solution2 sol;
    auto final = sol.postorderTraversal(root);
    for(auto & x:final){
        std::cout << x << " ";
    }
    cout<<endl;
    system("pause");
    return 0;
}