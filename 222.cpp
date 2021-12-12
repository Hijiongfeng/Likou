#include<iostream>
#include<vector>
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

TreeNode* construct_binary_tree(const vector<int> & vec){
    vector<TreeNode*> vecTree(vec.size(),nullptr);
    TreeNode *root = nullptr;
    for(int i = 0;i<vec.size();i++){
        TreeNode *node = nullptr;
        if(vec[i] != -1){
            node = new TreeNode(vec[i]);
        }
        //vecTree.push_back(node);
        vecTree[i] = node;
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
    int countNodes(TreeNode* root) {  //层序遍历求 任意二叉树节点 数量
        if(root == nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int count = 0;
        while(!que.empty()){
            int size = que.size();
            for(int i = 0;i<size;i++){
                TreeNode *node = que.front();
                que.pop();
                count++;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return count;
    }


    int countNodes2(TreeNode* root) {  // 递归  还是普通二叉树的 求法 
        if(root == nullptr) return 0;

        int leftCount = countNodes2(root->left);
        int rightCount = countNodes2(root->right);

        return 1+leftCount+rightCount;
    }
};


int main(int argc, const char** argv) {
    vector<int> num = {1,2,3,4,5,6,-1};
    TreeNode *root = construct_binary_tree(num);
    Solution sol;
    cout<<sol.countNodes2(root)<<endl;
    system("pause");
    return 0;
}