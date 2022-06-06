#include<bits/stdc++.h>

using namespace std;

/*
给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。

例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。
对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。

返回这些数字之和。题目数据保证答案是一个 32 位
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* construct_binary_tree(const vector<int>& vec){
    vector<TreeNode*> vecTree(vec.size(),nullptr); // 构造二叉树节点数组
    TreeNode *root = nullptr;
    for(int i = 0;i<vec.size();i++){
        TreeNode *node = nullptr;
        if(vec[i] != -1){
            node = new TreeNode(vec[i]);
        }
        vecTree[i] = node;
        if(i == 0) root = node;
    }
    
    for(int i = 0;2 * i + 2 < vec.size();i++){
        if(vecTree[i] != nullptr){
            vecTree[i]->left = vecTree[2*i+1];  //找左右子树
            vecTree[i]->right = vecTree[2*i+2];
        }
    }
    return root;
}

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {         // 前序遍历 + 回溯
        int ans = 0;
        stack<TreeNode*> treeSt;        // 保存遍历的节点
        stack<string> pathSt;           // 遍历的节点值
        treeSt.push(root);
        pathSt.push(to_string(root->val));
        while(!treeSt.empty()){
            TreeNode* node = treeSt.top();treeSt.pop();
            string sPath = pathSt.top();pathSt.pop();
            if(node->left == nullptr && node->right == nullptr){    // 中
                bitset<32> bit(sPath);      // 使用bitset方便保存二进制位
                ans += bit.to_ulong();
            }
            if(node->right){                    // 右
                treeSt.push(node->right);
                pathSt.push(sPath + to_string(node->right->val));
            }
            if(node->left){                    // 左
                treeSt.push(node->left);
                pathSt.push(sPath + to_string(node->left->val));
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vec = {1,0,1,0,1,0,1};
    TreeNode* root = construct_binary_tree(vec);
    Solution sol;
    cout<<sol.sumRootToLeaf(root)<<endl;
    system("puase");
    return 0;
}
