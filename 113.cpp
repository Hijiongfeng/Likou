#include<iostream>
#include<vector>
#include<numeric>

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
/*给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

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
    void traversal(TreeNode* root,vector<int>& path,vector<vector<int>>& vec){
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){  // 找到最后的 叶子节点
            vec.push_back(path);
        }
        if(root->left){
            traversal(root->left,path,vec);
            path.pop_back();
        }
        if(root->right){
            traversal(root->right,path,vec);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if(root == nullptr) return res; 
        vector<int> path;
        traversal(root,path,res);
        vector<vector<int>> final;
        for(int i=0;i<res.size();i++){
            if(accumulate(res[i].begin(),res[i].end(),0)==targetSum){
                final.push_back(res[i]);
            }
        }
        return final;
    }
};

int main(int argc, const char** argv) {
    vector<int> num = {5,4,8,11,-1,13,4,7,2,-1,-1,-1,-1,5,1};
    TreeNode *root = construct_binary_tree(num);
    Solution sol;
    auto fin = sol.pathSum(root,22);
    for(auto &x:fin){
        for(auto &y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}