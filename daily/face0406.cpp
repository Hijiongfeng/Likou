#include<bits/stdc++.h>

using namespace std;

/*
面试题 04.06. 后继者
设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。

如果指定节点没有对应的“下一个”节点，则返回null。

示例 1:

输入: root = [2,1,3], p = 1

  2
 / \
1   3

输出: 2
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

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {   // 中序遍历
        if(root == nullptr) return nullptr;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        bool FIND = false;
        while(cur != nullptr || !st.empty()){
            if(cur != nullptr){
                st.push(cur);
                cur = cur->left;
            }else{
                cur = st.top();
                st.pop();
                if(FIND){
                    return cur;
                }
                if(cur == p){
                    FIND = true;
                }
                cur = cur->right;
            }
        }
        if(FIND)
            return nullptr;
        return nullptr;
    }



    TreeNode* inorderSuccessor2(TreeNode* root, TreeNode* p) {   // 中序遍历
        if(root == nullptr) return nullptr;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;                   // 记录前一个节点
        while(cur != nullptr || !st.empty()){
            if(cur != nullptr){
                st.push(cur);
                cur = cur->left;
            }else{
                cur = st.top();
                st.pop();
                if(prev == p){
                    return cur;
                }
                prev = cur;
                cur = cur->right;
            }
        }
        return nullptr;
    }
};


int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
