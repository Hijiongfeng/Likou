#include<iostream>
#include<vector>

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
给定一棵树的前序遍历 preorder 与中序遍历  inorder。请构造二叉树并返回其根节点。
*/

class Solution {
private:
    TreeNode* traversal(vector<int>& preorder,vector<int>& inorder){
        if(preorder.size() == 0) return nullptr;
        int rootValue = preorder[0];
        TreeNode *root = new  TreeNode(rootValue);
        if(preorder.size() == 1) return root;
        // 在中序中找到分割值
        int delimateIndex;
        for(delimateIndex = 0;delimateIndex<inorder.size();delimateIndex++){
            if(inorder[delimateIndex] == rootValue) break;
        }

        //分割后序
        vector<int> leftInorder(inorder.begin(),inorder.begin()+delimateIndex);
        vector<int> rightInorder(inorder.begin()+delimateIndex+1,inorder.end());

        //把前序 第一个元素删除 因为已经用过了
        preorder.erase(preorder.begin());
        //  分割 前序  
        vector<int> leftPreorder(preorder.begin(),preorder.begin()+leftInorder.size());
        vector<int> rightPreorder(preorder.begin()+leftInorder.size(),preorder.end());
        
        root->left = traversal(leftPreorder,leftInorder);
        root->right = traversal(rightPreorder,rightInorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 && inorder.size() == 0) return nullptr;
        return traversal(preorder,inorder);
    }
};


int main(int argc, char const *argv[])
{
    vector<int> preorder = {3,9,20,15,17};
    vector<int> inorder = {9,3,15,20,7};
    Solution sol;
    TreeNode *root = sol.buildTree(preorder,inorder);
    int a= 0;
    system("pause");
    return 0;
}
