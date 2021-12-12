#include<iostream>
#include<vector>
#include<algorithm>
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
/*给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。

判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。

如果存在，返回 true ；否则，返回 false 。

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
    void traversal(TreeNode *root,vector<int>& path,vector<int>& res){
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){  // 遇到 叶子节点  就把结果存下来
            res.push_back(accumulate(path.begin(),path.end(),0));
        }

        if(root->left){
            traversal(root->left,path,res);
            path.pop_back();
        }
        if(root->right){
            traversal(root->right,path,res);
            path.pop_back();
        }
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;
        vector<int> path;
        vector<int> res;
        traversal(root,path,res);
        return find(res.begin(),res.end(),targetSum)==res.end() ? false:true;
    }
};

int main(int argc, const char** argv) {
    vector<int> num = {1,2,3};
    TreeNode *root = construct_binary_tree(num);
    Solution sol;
    cout<<sol.hasPathSum(root,3)<<endl;
    system("pause");
    return 0;
}