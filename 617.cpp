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
/*
给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，
否则不为 NULL 的节点将直接作为新二叉树的节点。

示例 1:

输入: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
输出: 
合并后的树:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7

*/
TreeNode* construct_binary_tree(const vector<int>& vec){
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {   //  迭代法
        if(root2 == nullptr) return root1;
        if(root1 == nullptr) return root2;
        if(root1 == nullptr && root2 == nullptr) return nullptr;

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left,root2->left);
        root1->right = mergeTrees(root1->right,root2->right);

        return root1;
    }

    TreeNode* mergeTrees2(TreeNode* root1, TreeNode* root2) {   //  层序遍历
        if(root2 == nullptr) return root1;
        if(root1 == nullptr) return root2;
        if(root1 == nullptr && root2 == nullptr) return nullptr;
        queue<TreeNode*> que;
        que.push(root1);
        que.push(root2);
        while (!que.empty())
        {
            TreeNode *node1 = que.front();
            que.pop();
            TreeNode *node2 = que.front();
            que.pop();

            node1->val += node2->val;
            if(node1->left != nullptr && node2->left != nullptr){
                que.push(node1->left);
                que.push(node2->left);
            }
            if(node1->right != nullptr && node2->right != nullptr){
                que.push(node1->right);
                que.push(node2->right);
            }
            if(node1->left == nullptr && node2->left != nullptr){
                node1->left = node2->left;
            }
            if(node1->right == nullptr && node2->right != nullptr){
                node1->right = node2->right;
            }
            // 是在 root1 上操作的，不用管 root1不为空 root2 为空的情况
        }
        
        return root1;
    }

    
};

int main(int argc, const char** argv) {
    vector<int> num1 = {1,3,2,5,-1,-1,-1};
    vector<int> num2 = {2,1,3,-1,4,-1,7};
    TreeNode *root1 = construct_binary_tree(num1);
    TreeNode *root2 = construct_binary_tree(num2);
    Solution sol;
    TreeNode *root = sol.mergeTrees2(root1,root2);
    system("pause");
    return 0;
}