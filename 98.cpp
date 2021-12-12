#include<iostream>
#include<vector>
#include<queue>
#include<stack>

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
/*给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
 
示例 1：
输入：root = [2,1,3]
输出：true
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
private:
    vector<int> vec;
    void travsal(TreeNode* root){   //  二叉搜索树的 中序遍历  是一个递增的 数组
        if(root == nullptr) return;
        travsal(root->left);  // 左

        vec.push_back(root->val);  //中

        travsal(root->right);      // 右   
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        travsal(root);
        for(int i=0;i<vec.size()-1;i++){
            if(vec[i+1]<=vec[i]){
                return false;
            }
        }
        return true;
    }

    bool isValidBST2(TreeNode* root) {  //迭代法 中序遍历
        if(root == nullptr) return true;
        stack<TreeNode*> st;
        
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        while (cur!= nullptr || !st.empty())
        {
            if(cur != nullptr){
                st.push(cur);
                cur = cur->left;
            }else{
                cur = st.top();
                st.pop();
                if(pre != nullptr && cur->val <= pre->val){
                    return false;
                }
                pre = cur;
                cur = cur->right;
            }
        }
        return true;  
    }
};

int main(int argc, const char** argv) {
    vector<int> num = {5,1,4,-1,-1,3,6};
    TreeNode *root = construct_binary_tree(num);
    Solution sol;
    cout<<sol.isValidBST2(root)<<endl;
    system("pause");
    return 0;
}