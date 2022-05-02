#include<bits/stdc++.h>

using namespace std;

/*
1305. 两棵二叉搜索树中的所有元素

给你 root1 和 root2 这两棵二叉搜索树。请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。.
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
    void travel(TreeNode* root,vector<int>& list){
        if(root == nullptr) return;
        travel(root->left,list);
        list.push_back(root->val);
        travel(root->right,list);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1,list2;
        travel(root1,list1);
        travel(root2,list2);
        vector<int> ans(list1.size()+list2.size());
        merge(list1.begin(),list1.end(),list2.begin(),list2.end(),ans.begin());
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
