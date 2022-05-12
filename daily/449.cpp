#include<bits/stdc++.h>

using namespace std;

/*
序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。

设计一个算法来序列化和反序列化 二叉搜索树 。 对序列化/反序列化算法的工作方式没有限制。 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。

编码的字符串应尽可能紧凑。

示例 1：

输入：root = [2,1,3]
输出：[2,1,3]
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

/*
想的是 把二叉树递归遍历成  前序和中序
再根据前序和中序 生成二叉树
由于数据量太大，会越界
*/
class Codec {    
public:
    void inorder(TreeNode* root,string& s){
        if(root == nullptr)
            return;
        inorder(root->left,s);
        s.push_back(root->val + '0');
        inorder(root->right,s);
    }
    void preorder(TreeNode* root,string& s){
        if(root == nullptr)
            return;
        s.push_back(root->val + '0');
        preorder(root->left,s);
        preorder(root->right,s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr){
            return "";
        }
        string s;
        TreeNode* node1 = root;
        TreeNode* node2 = root;
        inorder(node1,s);
        s += "#";               // #分割
        preorder(node2,s);
        return s;
    }

    TreeNode* constructTree(string preorder,string inorder){
        if(preorder.size() == 0)
            return nullptr;
        char root_str = preorder[0];
        TreeNode *node = new TreeNode(root_str - '0');
        if (preorder.size() == 1) return node;

        int index = inorder.find(root_str);
        
        
        string left_inorder = inorder.substr(0,index);
        string right_inorder = inorder.substr(index+1);

        preorder = string(preorder.begin()+1,preorder.end());
        string left_preorder = preorder.substr(0,left_inorder.size());
        string right_preorder = preorder.substr(left_inorder.size());

        node->left = constructTree(left_preorder,left_inorder);
        node->right = constructTree(right_preorder,right_inorder);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0] == '#')
            return nullptr;
        int index = data.find('#');
        string inorder_str = data.substr(0,index);
        string preorder_str = data.substr(index+1,inorder_str.size());

        TreeNode* root = constructTree(preorder_str,inorder_str);
        return root;
    }   
};

/*
解决办法：
只用前序遍历，加上二叉搜索树的特性
*/
class Codec2 {    
public:
    void preorder(TreeNode* root,string& s){
        if(root == nullptr)
            return;
        s.push_back(root->val + '0');
        preorder(root->left,s);
        preorder(root->right,s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr){
            return "";
        }
        string s;
        TreeNode* node2 = root;
        preorder(node2,s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
            return nullptr;
        char root_str = data[0];

        TreeNode* root = new TreeNode(root_str - '0');

        string left_str,right_str;
        for(char c : data){
            if(c > root_str){
                right_str.push_back(c);
            }else if(c < root_str){
                left_str.push_back(c);
            }
        }

        root->left = deserialize(left_str);
        root->right = deserialize(right_str);

        return root;
    }   
};


int main(int argc, char const *argv[])
{
    vector<int> num = {3,2,4,3,-1,-1,-1};
    TreeNode* root = construct_binary_tree(num);
    Codec code;
    string s = code.serialize(root);
    TreeNode* newroot = code.deserialize(s);
    system("pause");
    return 0;
}
