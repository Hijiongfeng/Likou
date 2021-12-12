#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*给定一个 N 叉树，找到其最大深度。

最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。

N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）。
*/
// Definition for a Node.
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

class Solution {
public:
    int maxDepth(Node* root) {
        int depth = 0;
        if(root == nullptr) return depth;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            depth++;
            for(int i =0;i<size;i++){
                
                Node *node = que.front();
                que.pop();
                for(int j =0;j<node->children.size();j++){
                    if(node->children[j] != nullptr);
                    que.push(node->children[j]);
                }
            }
        }
        return depth;
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
