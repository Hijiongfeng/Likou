#include<iostream>
#include<vector>

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

TreeNode* construct_binary_tree(const vector<int>& vec){
    vector<TreeNode*> vecTree(vec.size(),nullptr); // 构造二叉树节点数组
    TreeNode *root = nullptr;
    for(int i = 0;i<vec.size();i++){
        TreeNode *node = nullptr;
        if(vec[i] != -1){
            node = new TreeNode(vec[i]);
        }
        vecTree[i] = node;
        if(i == 0) root = node;
    }
    
    for(int i = 0;2 * i + 2 < vec.size();i++){
        if(vecTree[i] != nullptr){
            vecTree[i]->left = vecTree[2*i+1];  //找左右子树
            vecTree[i]->right = vecTree[2*i+2];
        }
    }
    return root;
}

class Solution {
public:
    void traversal(TreeNode *head,vector<int> & vec){  // 前序 ：中左右
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

class Solution2 {
public:
    void traversal(TreeNode *head,vector<int> & vec){  // 中
        if(head == nullptr) return;
        traversal(head->left,vec);
        vec.push_back(head->val);
        traversal(head->right,vec);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root,res);
        return res;
    }
};

class Solution3 {
public:
    void traversal(TreeNode *head,vector<int> & vec){  // 后
        if(head == nullptr) return;
        traversal(head->left,vec);
        traversal(head->right,vec);
        vec.push_back(head->val);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root,res);
        return res;
    }
};


int main(int argc, const char** argv) { 
// {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8}
    vector<int> num = {5,4,6,2,1,-1,-1};  // 数组表示二叉树的层序遍历 没值的 为 -1
    TreeNode *root = construct_binary_tree(num);
    Solution3 sol;
    auto final = sol.preorderTraversal(root);
    for(auto & x:final){
        cout<<x<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}