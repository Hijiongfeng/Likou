#include<iostream>
#include<vector>
#include<queue>

using namespace std;
/*给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
    bool isSymmetric(TreeNode* root) {  // 迭代方法
        queue<TreeNode*> que;
        if(root == nullptr) return true;
        que.push(root->left);
        que.push(root->right);
        while(!que.empty()){
            int size = que.size();
            //for(int i=0;i<size;i++){
                TreeNode *leftNode = que.front();
                que.pop();
                TreeNode *rightNode = que.front();
                que.pop();

                if(leftNode == nullptr && rightNode == nullptr){
                    continue;
                }

                if(!leftNode || !rightNode || (leftNode->val != rightNode->val)) return false;
                
                que.push(leftNode->left);
                que.push(rightNode->right);
                que.push(leftNode->right);
                que.push(rightNode->left);
            //}
        }
        return true;
    }

    bool compare(TreeNode* leftTree,TreeNode* rightTree){   // 递归三部曲
        if(leftTree == nullptr && rightTree == nullptr) return true;
        else if(leftTree == nullptr && rightTree != nullptr) return false;
        else if(leftTree != nullptr && rightTree == nullptr) return false;
        else if(leftTree->val != rightTree->val) return false;

        // 只有左右 不为空 且值相等 才递归 
        bool outside = compare(leftTree->left,rightTree->right);
        bool inside = compare(leftTree->right,rightTree->left);
        bool issame = outside && inside;
        return issame;
    }

    bool isSymmetric2(TreeNode* root) {    // 递归算法
        if(root == nullptr) return true;
        return compare(root->left,root->right);
    }

};

int main(int argc, char const *argv[])
{
    vector<int> num = {1,2,2,3,3,3,3};
    TreeNode *root = construct_binary_node(num);
    Solution sol;
    cout<<sol.isSymmetric2(root)<<endl;
    system("pause");
    return 0;
}
