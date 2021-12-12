#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
};
/*给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。*/
/*
层序遍历 求出每一层的均值就可
*/
TreeNode* construct_binary_node(const vector<int> & vec){
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
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        vector<double> res;
        if(root == nullptr) return res;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            double sum = 0;
            for(int i=0;i<size;i++){ //每一层的个数  这个要用固定值 注意  不然随着下面的插入会改变大小
                TreeNode *node = que.front();
                que.pop();
                sum += node->val;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(sum/size);
        }
        return res;
    }
};

int main(int argc, const char** argv) {

    vector<int> num = {3,9,20,-1,-1,15,7};
    auto root = construct_binary_node(num);
    Solution sol;
    auto final = sol.averageOfLevels(root);
    for(auto &x:final){
        cout<<x<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}