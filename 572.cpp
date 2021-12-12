#include<iostream>
#include<vector>
#include<queue>

using namespace std;
/*给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。
如果存在，返回 true ；否则，返回 false 。

二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。
tree 也可以看做它自身的一棵子树。
。
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
    vector<TreeNode*> vecTree(vec.size(),nullptr);
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

    bool issame(TreeNode* p, TreeNode* q) {  // 直接在这里面迭代 写终止条件 单次迭代代码
        if(p == nullptr && q == nullptr) return true;
        else if(p != nullptr && q == nullptr) return false;
        else if(p == nullptr && q != nullptr) return false;
        else if(p->val != q->val) return false;

        // 剩下就是p q都有值 且值相等 进入递归
        bool leftSide = issame(p->left,q->left);
        bool rightSide = issame(p->right,q->right);
        bool is = leftSide && rightSide;
        return is;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr) return true;
        else if(root != nullptr && subRoot == nullptr) return false;
        else if(root == nullptr && subRoot != nullptr) return false;
        
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode *node = que.front();
            que.pop();
            if(node->val != subRoot->val){
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }else{
                return issame(node,subRoot);
            }
            
        }
        return false;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> num1 = {1,1,-1};
    vector<int> num2 = {1};
    TreeNode *root = construct_binary_node(num1);
    TreeNode *subroot = construct_binary_node(num2);
    Solution sol;
    cout<<sol.isSubtree(root,subroot)<<endl;
    system("pause");
    return 0;
}
