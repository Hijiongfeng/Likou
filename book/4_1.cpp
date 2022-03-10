#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode
{
    char c;
    TreeNode *left;
    TreeNode *right;
    TreeNode();
    TreeNode(char a,TreeNode *l=nullptr,TreeNode *r = nullptr){
        c = a;
        left = l;
        right = r;
    }
};
/*
利用 stack 的特性
*/
TreeNode* construct_expression_tree(string & str){      // 构造 二叉 表达树
    stack<TreeNode*> st;
    TreeNode *head = nullptr;
    for(auto & c : str){
        if(isalpha(c)){
            TreeNode *node = new TreeNode(c);
            st.push(node);
        }else{
            TreeNode *node = new TreeNode(c);
            TreeNode *node1 = st.top();st.pop();
            TreeNode *node2 = st.top();st.pop();
            node->right = node1;
            node->left = node2;
            st.push(node);
        }
    }
    head = st.top();
    return head;
}


int main(int argc, char const *argv[])
{
    string str = "ab+cde+**";
    TreeNode *head = construct_expression_tree(str);


    system("pause");    
    return 0;
}
