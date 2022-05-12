#include<bits/stdc++.h>

using namespace std;

/*

2265. 统计值等于子树平均值的节点数
给你一棵二叉树的根节点 root ，找出并返回满足要求的节点数，
要求节点的值等于其 子树 中值的 平均值 。

注意：

n 个元素的平均值可以由 n 个元素 求和 然后再除以 n ，并 向下舍入 到最近的整数。
root 的 子树 由 root 和它的所有后代组成。

输入：root = [4,8,5,0,1,null,6]
输出：5
解释：
对值为 4 的节点：子树的平均值 (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4 。
对值为 5 的节点：子树的平均值 (5 + 6) / 2 = 11 / 2 = 5 。
对值为 0 的节点：子树的平均值 0 / 1 = 0 。
对值为 1 的节点：子树的平均值 1 / 1 = 1 。
对值为 6 的节点：子树的平均值 6 / 1 = 6 。
**/


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
    void preOrder(TreeNode* node,int& num,int& sum){
        if(node == nullptr)
            return;
        sum += node->val;
        num++;
        preOrder(node->left,num,sum);
        preOrder(node->right,num,sum);
    }
public:
    int averageOfSubtree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        queue<TreeNode*> que;   //层序遍历每一个节点
        que.push(root);
        int ans = 0;
        while(!que.empty()){
            int size = que.size();
            for(int i = 0;i<size;i++){
                TreeNode *node = que.front();
                que.pop();
                int num = 0,sum = 0;
                preOrder(node,num,sum);         // 前序遍历每一个节点的子树
                if(sum / num == node->val){
                    ans++;
                }
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {4,8,5,0,1,-1,6};
    TreeNode *root = construct_binary_tree(nums);
    Solution sol;
    cout<<sol.averageOfSubtree(root)<<endl;

    system("pause");
    return 0;
}
