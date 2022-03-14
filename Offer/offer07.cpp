#include<iostream>
#include<vector>

using namespace std;

/*
输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。

假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x,TreeNode *l,TreeNode *r) : val(x), left(l), right(r) {}
};
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return nullptr;

        int rootValue = preorder[0];
        TreeNode *root = new TreeNode(rootValue);

        int index = 0;
        for(int i = 0;i<inorder.size();i++){
            if(inorder[i] == rootValue){
                index = i;
                break;
            }

        }

        vector<int> inorderLeft(inorder.begin(),inorder.begin() + index);           // 左闭 右开区间
        vector<int> inorderRight(inorder.begin() + index + 1,inorder.end());

        vector<int> preorderLeft(preorder.begin()+1,preorder.begin()+1+inorderLeft.size());
        vector<int> preorderRight(preorder.end()-inorderRight.size(),preorder.end());

        root->left = buildTree(preorderLeft,inorderLeft);
        root->right = buildTree(preorderRight,inorderRight);

        return root;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> pre = {3,9,20,15,7};
    vector<int> in = {9,3,15,20,7};
    Solution sol;
    TreeNode *node = sol.buildTree(pre,in);
    int a = 0;
    system("pause");
    return 0;
}
