#include<iostream>
#include<vector>

using namespace std;
/*

给定一个 n 叉树的根节点  root ，返回 其节点值的 前序遍历 。

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

class Solution {        // 递归法      //  结果正确

private:

    void pertravel(Node* root,vector<int> & vec){
        vec.push_back(root->val);
        for(int i = 0;i<root->children.size();i++){
            pertravel(root->children[i],vec);
        }
    }

public:
    vector<int> preorder(Node* root) {
        vector<int> vec;
        pertravel(root,vec);
        return vec;
    }
};


class Solution2 {        //  迭代法      //  结果正确

public:
    vector<int> preorder(Node* root) {

    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
