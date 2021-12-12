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

/*根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
*/

class Solution {
private:
    TreeNode* traversal(vector<int>& inorder,vector<int>& postorder){
        if(postorder.size() == 0) return nullptr;
        
        int rootValue = postorder[postorder.size()-1];
        TreeNode *root = new TreeNode(rootValue);

        if(postorder.size() == 1) return root;

        int delimiterIndex;
        for(delimiterIndex = 0;delimiterIndex<inorder.size();delimiterIndex++){
            if(inorder[delimiterIndex] == rootValue) break;
        } 
        // 分割中序  左闭 右开 区间
        vector<int> leftInorder(inorder.begin(),inorder.begin()+delimiterIndex);
        vector<int> rightInorder(inorder.begin()+delimiterIndex+1,inorder.end());
        // 分割 后序
        postorder.resize(postorder.size()-1);  // 重新 定义 后序的大小  最后一个值没用了  用过了
        vector<int> leftPostorder(postorder.begin(),postorder.begin()+leftInorder.size());
        vector<int> rightPostorder(postorder.begin()+leftInorder.size(),postorder.end());

        root->left = traversal(leftInorder,leftPostorder);
        root->right = traversal(rightInorder,rightPostorder);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return traversal(inorder,postorder);
    }
};

int main(int argc, const char** argv) {
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    Solution sol;
    TreeNode *root = sol.buildTree(inorder,postorder);
    TreeNode *root2 = new TreeNode(inorder[0]);

    system("pause");
    return 0;
}