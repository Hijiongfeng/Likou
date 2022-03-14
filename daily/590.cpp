#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

/*
给定一个 n 叉树的根节点 root ，返回 其节点值的 后序遍历 。

n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。
*/


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {                // 递归的方法
private:
    void posttravel(Node *root,vector<int> & vec){
        for(int i = 0;i<root->children.size();i++){
            posttravel(root->children[i],vec);
        }
        vec.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(root == nullptr) return res;
        posttravel(root,res);
        return res;
    }
};

class Solution {                // 迭代 的方法

public:
    vector<int> postorder(Node* root) {
        stack<Node*> st;
        vector<int> res;
        if(root == nullptr){
            return res;
        }
        st.push(root);
        while(!st.empty()){
            Node *node = st.top();
            st.pop();
            res.push_back(node->val);
            for(int i = 0;i<node->children.size();i++){
                st.push(node->children[i]);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};



int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
