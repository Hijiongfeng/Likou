#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

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


TreeNode* construct_binary_tree(const vector<int> & vec){
    vector<TreeNode*> vecTree;
    TreeNode *root = nullptr;
    for(int i = 0;i<vec.size();i++){
        TreeNode *node = nullptr;
        if(vec[i] != -1){   // -1 为空
            node = new TreeNode(vec[i]);
        }
        vecTree.push_back(node);
        if(i == 0) root = node;
    }
    for(int i=0;2*i+2<vec.size();i++){
        if(vecTree[i] != nullptr){
            vecTree[i]->left = vecTree[2*i+1];
            vecTree[i]->right = vecTree[2*i+2];
        }
    }
    return root;
}

class Solution {  // 递归
public:
    void travelTree(TreeNode *node,vector<int> &vec){
        if(node == nullptr) return;
        travelTree(node->left,vec);
        travelTree(node->right,vec);
        vec.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        travelTree(root,res);
        return res;
    }
};

class Solution2 {  //迭代
public:

    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> vec;
        if(root == nullptr) return vec;
        st.push(root);
        while(!st.empty()){
            TreeNode *node = st.top();
            st.pop();
            if(node != nullptr){
                vec.push_back(node->val);
            }else{
                continue;
            }
            st.push(node->left);
            st.push(node->right);
        }
        reverse(vec.begin(),vec.end());   
        return vec;
    }
};

int main(int argc, const char** argv) {
    //{6,2,8,1,4,-1,-1,-1,-1,3,7};
    vector<int> num = {5,4,6,2,1,-1,-1};
    auto root = construct_binary_tree(num);
    Solution2 sol;
    auto final = sol.postorderTraversal(root);
    for(auto & x:final){
        std::cout << x << " ";
    }
    cout<<endl;
    system("pause");
    return 0;
}