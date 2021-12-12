#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
};

/*给定一个二叉树的 根节点 root，想象自己站在它的右侧，
按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
输入: [1,2,3,null,5,null,4]
输出: [1,3,4]*/

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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> res;
        if(root == nullptr) return res;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i = 0;i<size;i++){  // 每一层的个数
                TreeNode *node = que.front();
                que.pop();
                if(i == size-1) res.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right); 
            }
        }
        return res;
    }
};

int main(int argc, const char** argv) {
    vector<int> num = {1,2,3,-1,5,-1,4};
    auto root = construct_binary_node(num);
    Solution sol;
    auto final = sol.rightSideView(root);
    for(const auto &x:final){
        cout<<x<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}