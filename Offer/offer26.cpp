#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
给定的树 A:

     3
    / \
   4   5
  / \
 1   2
给定的树 B：

   4 
  /
 1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

解题思路
思路比较直接，对A树逐个找根结点值相等的结点，然后比较以此为根节点的子树是否与B树相同。
对于相同根节点子树是否相同写了judge函数，逐个比较出队的结点值，
不相等则返回false；以B树为参考决定是否入队，当然如果B树有结点要入队，而A树没有则返回false，直到遍历完B树。

*/

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x,TreeNode *l,TreeNode *r) : val(x), left(l), right(r) {}
 };

class Solution {
private:
    bool judge(TreeNode *A_node,TreeNode *B){
        TreeNode *pta;
        TreeNode *ptb;
        queue<TreeNode*> Aq,Bq;
        Aq.push(A_node);
        Bq.push(B);
        while(!Aq.empty() && !Bq.empty()){
            pta = Aq.front(),Aq.pop();
            ptb = Bq.front(),Bq.pop();
            if(pta->val != ptb->val){
                return false;
            }
            if(ptb->left){
                Bq.push(ptb->left);
                if(pta->left){
                    Aq.push(pta->left);
                }else{
                    return false;
                }
            }

            if(ptb->right){
                Bq.push(ptb->right);
                if(pta->right){
                    Aq.push(pta->right);
                }else{
                    return false;
                }
            }
        } 
        return true;
    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B == nullptr || A == nullptr) return false;
        queue<TreeNode*> que;
        que.push(A);
        bool ans = false;
        while(!que.empty()){
            TreeNode *node = que.front();
            que.pop();
            if(node->val == B->val){
                ans =judge(node,B);
            }
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
