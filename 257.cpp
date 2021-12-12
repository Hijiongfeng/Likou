#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0),left(nullptr),right(nullptr){};
    TreeNode(int x) : val(x),left(nullptr),right(nullptr){};
    TreeNode(int x,TreeNode *left,TreeNode *right) : val(x),left(left),right(right){};
};
/*
给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

叶子节点 是指没有子节点的节点。
*/
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
private:
    void traversal(TreeNode *root,vector<int> &path,vector<string> & result){  // 递归加回溯
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){  
            string sPath;
            for(int i = 0;i<path.size()-1;i++){
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size()-1]);
            result.push_back(sPath);
        }
        if(root->left){
            traversal(root->left,path,result);
            path.pop_back();
        }
        if(root->right){
            traversal(root->right,path,result);
            path.pop_back();
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        if(root == nullptr) return res;
        traversal(root,path,res);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num = {1,2,3,-1,5,-1,-1};
    TreeNode *root = construct_binary_tree(num);
    Solution sol;
    auto final = sol.binaryTreePaths(root);
    for(auto & x:final){
        cout<<x<<endl;
    }
    system("pause");
    return 0;
}
