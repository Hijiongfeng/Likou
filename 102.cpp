#include<iostream>
#include<vector>
#include<queue>  // 队列

using namespace std;

/*给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int num,TreeNode *l = nullptr,TreeNode *r = nullptr){
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
        if(vec[i] != -1){   // -1 为空
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if(root != nullptr) que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> vec;
            for(int i = 0;i<size ;i++){
                TreeNode *node = que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if(root != nullptr) que.push(root);
        vector<int> vec;
        while(!que.empty()){
            
            TreeNode *node = que.front();
            que.pop();
            if(node != nullptr){
                vec.push_back(node->val);
            
                que.push(node->left);
                que.push(node->right);
            }
        }
        return vec;
    }
};

int main(int argc, const char** argv) {
    vector<int> num = {3,9,20,-1,-1,15,7};
    TreeNode *root = construct_binary_tree(num);
    Solution sol;
    auto final = sol.levelOrder(root);
    for(auto & x:final){
        for(auto & y:x){
            cout<<y<<" ";
        }
        //cout<<x<<" ";
        cout<<endl;
    }
    //cout<<endl;
    system("pause");
    return 0;
}