#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

/*
请实现一个函数，用来判断一棵二叉树是不是对称的。
如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
private:
    bool compare(TreeNode *node1,TreeNode *node2){
        if(node1 == nullptr && node2 == nullptr) return true;
        else if(node1 == nullptr && node2 != nullptr) return false;
        else if(node1 != nullptr && node2 == nullptr) return false;
        else if(node1->val != node2->val) return false;

        bool outside = compare(node1->left,node2->right);
        bool inside = compare(node1->right,node2->left);

        bool isSame = outside && inside;                    // 左子树：中、 右子树：中 （逻辑处理）
        return isSame;

    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;

        bool ans = compare(root->left,root->right);
        return ans;
    }
};

class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while(!que.empty()){
            TreeNode *node1 = que.front();que.pop();
            TreeNode *node2 = que.front();que.pop();

            if (!node1 && !node2) {  // 左节点为空、右节点为空，此时说明是对称的
                continue;
            }

            if(node1 == nullptr && node2 == nullptr) return true;
            else if(node1 == nullptr && node2 != nullptr) return false;
            else if(node1 != nullptr && node2 == nullptr) return false;
            else if(node1->val != node2->val) return false;
            
            que.push(node1->left);
            que.push(node2->right);
            que.push(node1->right);
            que.push(node2->left);
        }
        return true;
    }
};



int main(int argc, char const *argv[])
{
    system("pasue");
    return 0;
}
