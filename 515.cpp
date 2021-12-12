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
// 找到每一层的 最大值
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

    int findMax(const vector<int> & vec){
        int max = vec[0];
        for(int i=0;i<vec.size();i++){
            if(vec[i]>max){
                max = vec[i];
            }
        }
        return max;
    }

    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> res;
        if(root == nullptr) return res;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> vec;
            int max;
            for(int i=0;i<size;i++){
                TreeNode *node = que.front();
                que.pop();
                if(node != nullptr){
                    vec.push_back(node->val);
                }
                max = findMax(vec);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(max);
        }
        return res;
    }
};

int main(int argc, const char** argv) {
    vector<int> num = {1,3,2,5,3,-1,9};
    auto root = construct_binary_node(num);
    Solution sol;
    auto final = sol.largestValues(root);
    for(auto &x:final){
        cout<<x<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}