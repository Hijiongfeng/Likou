#include<iostream>
#include<vector>
#include<set>

using namespace std;

/*
给定一个二叉搜索树 root 和一个目标结果 k，
如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

输入: root = [5,3,6,2,4,null,7], k = 9
输出: true

*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

 // 二叉搜索树，转化为 中序遍历为 有序数组，采用双指针 进行判断

class Solution {       
private:
    vector<int> vec;
    void inorder(TreeNode *root){
        if(root == nullptr){
            return;
        }

        inorder(root->left);
        vec.emplace_back(root->val);
        inorder(root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;
        inorder(root);
        
        int left = 0;
        int right = vec.size() - 1;

        while(left < right){
            int sum = vec[left] + vec[right];
            if(sum > k){
                right--;
            }else if(sum < k){
                left++;
            }else if(sum == k){
                return true;
            }
        }

        return false;
    }
};

// set 加遍历 整个树 ：哈希表 + 树的搜索
/*
在递归搜索过程中记录下相应的节点值（使用 Set 集合），
如果在遍历某个节点 x时发现集合中存在 k - x.val说明存在两个节点之和等于 k，
返回 True，若搜索完整棵树都没有则返回 False。
*/

class Solution2 {       
private:
    set<int> st;
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;
        if(st.find(k - root->val)!=st.end()) return false;
        st.insert(root->val);
        return findTarget(root->left,k) | findTarget(root->right,k);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {5,3,6,2,4,-1,7};

    system("pause");
    return 0;
}
