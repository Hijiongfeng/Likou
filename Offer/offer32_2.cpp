#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
请实现一个函数按照之字形顺序打印二叉树，
即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，
第三行再按照从左到右的顺序打印，其他行以此类推。
*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int num,TreeNode *l=nullptr,TreeNode *r = nullptr){
        val = num;
        left = l;
        right = r;
    }
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> que;
        que.push(root);
        int row = 0;
        while(!que.empty()){
            int size = que.size();
            vector<int> vec;
            for(int i = 0;i<size;i++){
                TreeNode *node= que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);;
            }
            row++;
            if(row % 2 == 0){
                reverse(vec.begin(),vec.end());
            }
            ans.push_back(vec);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {3,9,20,-1,-1,15,7};
    TreeNode* root = construct_binary_tree(nums);
    Solution sol;
    vector<vector<int>> ans = sol.levelOrder(root);
    for(auto a : ans){
        for(auto b : a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}
