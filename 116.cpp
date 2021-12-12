#include<iostream>
#include<vector>
#include<queue>

using namespace std;
/*给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。
*/

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *next;
    
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* construct_binary_node(const vector<int> & vec){
    vector<Node*> vecTree;
    Node *root = nullptr;
    for(int i=0;i<vec.size();i++){
        Node *node = nullptr;
        if(vec[i] != -1){
            node = new Node(vec[i]);
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
    Node* connect(Node* root) {
        queue<Node*> que;
        if(root == nullptr) return root;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i = 0;i<size;i++){
                Node *node = que.front();
                que.pop();
                if(i == size-1){    // 如果是最后一个节点 就指向 nullptr;  如果不是就 指向下一个节点
                    node->next = nullptr;
                }else{
                    node->next = que.front();
                }
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return root;
    }
};

int main(int argc, const char** argv) {
    vector<int> num = {1,2,3,4,5,6,7};
    Node *root = construct_binary_node(num);
    Solution sol;
    auto final = sol.connect(root);
    return 0;
}