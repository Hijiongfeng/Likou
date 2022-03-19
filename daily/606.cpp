#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<unordered_set>

using namespace std;

/*
你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。

空节点则用一对空括号 "()" 表示。
而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。

我们还需要用一个集合存储所有遍历过的节点，

如果当前节点有两个孩子，那么我们先将右孩子入栈，再将左孩子入栈，从而保证前序遍历的顺序；
如果当前节点没有孩子，我们什么都不做；
如果当前节点只有左孩子，那么我们将左孩子入栈；
如果当前节点只有右孩子，那么需要在答案末尾添加一对 \text{`()'}‘()’ 表示空的左孩子，再将右孩子入栈。
注意这四种情况中，我们都不会将当前节点出栈，

原因是我们一开始添加了 \text{`('}‘(’ 表示节点的开始，在以当前节点为根的子树中所有节点遍历完成之后，
我们才会在答案末尾添加 \text{`)'}‘)’ 表示节点的结束。因此我们需要用上面提到的集合来存储遍历过的节点，
如果当前栈顶的元素遍历过，那么就需要在答案末尾添加 \text{`)'}‘)’ ，并将这个节点出栈。

当前节点不能先出栈；因为要在后面添加右括号；
所以需要一个 集合 判断当前节点是否遍历过
如果遍历过，就出栈，添加右括号

思路不好想，想不到用一个set集合来保存是否遍历过当前节点

*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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


class Solution {
public:
    string tree2str(TreeNode* root) {
        string ans = "";
        stack<TreeNode *> st;
        st.push(root);
        unordered_set<TreeNode *> vis;
        while (!st.empty()) {
            auto node = st.top();
            if (vis.count(node)) {
                if (node != root) {
                    ans += ")";
                }
                st.pop();
            } else {
                vis.insert(node);
                if (node != root) {
                    ans += "(";
                }
                ans += to_string(node->val);
                if (node->left == nullptr && node->right != nullptr) {
                    ans += "()";
                }
                if (node->right != nullptr) {
                    st.push(node->right);
                }
                if (node->left != nullptr) {
                    st.push(node->left);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{

    vector<int> nums = {1,2,3,4,-1,-1,-1,-1};
    TreeNode *root = construct_binary_tree(nums);
    Solution  sol;
    cout<<sol.tree2str(root)<<endl;

    system("pause");
    return 0;
}
