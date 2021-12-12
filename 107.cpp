#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
};

/*给定一个二叉树，返回其节点值自底向上的层序遍历。 
（即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],
*/

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if(root != nullptr) que.push(root);
        while(!que.empty()){
            vector<int> vec;
            int size = que.size();
            for(int i=0;i<size;i++){
                TreeNode *node = que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(vec);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num = {3,9,20,-1,-1,15,7};
    auto root = construct_binary_node(num);
    Solution sol;
    auto final = sol.levelOrderBottom(root);
    for(auto & x:final){
        for(auto &y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    int *p = new int{10};
    // p[0] = 0;
    // p[1] = 1;
    
    cout<<p[0]<<" "<<p[1]<<endl;
    system("pause");
    return 0;
}
