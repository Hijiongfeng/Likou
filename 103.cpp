#include<bits/stdc++.h>

using namespace std;

/*
给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。
（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

层序遍历 模板
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> ans;
        int level = 0;
        while(!que.empty()){
            int size = que.size();
            vector<int> temp;
            for(int i = 0;i<size;i++){
                TreeNode *node = que.front();
                que.pop();
                temp.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            if(level % 2 == 0){
                ans.push_back(temp);
            }else{
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            level++;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
