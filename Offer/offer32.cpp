#include<iostream>
#include<queue>

using namespace std;

/*
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
*/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> vec;
            for(int i = 0;i<size;i++){
                TreeNode *node= que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);;
            }
            ans.push_back(vec);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {3,9,20,-1,-1,15,7};
    TreeNode* root = construct_binary_tree(nums);
    Solution sol;
    vector<vector<int>> ans = sol.levelOrder(root);
    for(auto a : ans){
        for(auto b : a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}
