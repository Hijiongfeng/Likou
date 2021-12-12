#include<iostream>
#include<vector>
#include<queue>

using namespace std;
/*给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
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

class Solution {  // 递归三部曲  
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {  // 直接在这里面迭代 写终止条件 单次迭代代码
        if(p == nullptr && q == nullptr) return true;
        else if(p != nullptr && q == nullptr) return false;
        else if(p == nullptr && q != nullptr) return false;
        else if(p->val != q->val) return false;

        // 剩下就是p q都有值 且值相等 进入递归
        bool leftSide = isSameTree(p->left,q->left);
        bool rightSide = isSameTree(p->right,q->right);
        bool issame = leftSide && rightSide;
        return issame;
    }

    bool isSameTree2(TreeNode* p, TreeNode* q) {  // 迭代的方法
        if(p == nullptr && q == nullptr) return true;
        else if(p != nullptr && q == nullptr) return false;
        else if(p == nullptr && q != nullptr) return false;
        else if(p->val != q->val) return false;

        // p q都有值 且相等 进入下一步 迭代
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        while(!que.empty()){
            int size = que.size();
            TreeNode *node1 = que.front();
            que.pop();
            TreeNode *node2 = que.front();
            que.pop();

            if(node1 == nullptr && node2 ==nullptr) continue;
            else if(node1 != nullptr && node2 == nullptr) return false;
            else if(node1 == nullptr && node2 != nullptr) return false;
            else if(node1->val != node2->val) return false;

            que.push(node1->left);
            que.push(node2->left);
            que.push(node1->right);
            que.push(node2->right);

        } 
        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num1 = {1,2,3};
    vector<int> num2 = {1,2,3};
    auto root1 = construct_binary_node(num1);
    auto root2 = construct_binary_node(num2);
    Solution sol;
    cout<<sol.isSameTree2(root1,root2)<<endl;
    system("pause");
    return 0;
}
