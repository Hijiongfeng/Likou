#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：

结点左子树中所含结点的值小于等于当前结点的值
结点右子树中所含结点的值大于等于当前结点的值
左子树和右子树都是二叉搜索树
例如：
给定 BST [1,null,2,2],

   1
    \
     2
    /
   2
返回[2].

*/
TreeNode* construct_binary_tree(const vector<int>& vec){
    vector<TreeNode*> vecTree;
    TreeNode *root = nullptr;
    for(int i=0;i<vec.size();i++){
        TreeNode *node = nullptr;
        if(vec[i] != -1){
            node = new TreeNode(vec[i]);
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
private:
    vector<int> vec;
    void traversal(TreeNode *root){   // 左中右  遍历二叉 搜索树
        if(root == nullptr) return;
        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        map<int,int> mp;
        if(root == nullptr) return res;
        traversal(root);
        for(int i = 0;i<vec.size();i++){
            mp[vec[i]]++;
        }
        vector<int> vec1;
        for(map<int,int>::iterator it =mp.begin();it!=mp.end();it++){
            vec1.push_back(it->second);
        }

        int max = vec1[0];
        for(auto & x:vec1){
            if(max<=x) max = x;
        }
        for(map<int,int>::iterator it =mp.begin();it!=mp.end();it++){
            if(it->second == max){
                res.push_back(it->first);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num = {1,-1,2,-1,-1,2,-1};
    TreeNode *root = construct_binary_tree(num);
    Solution sol;
    auto fin = sol.findMode(root);
    for(auto x:fin){
        cout<<x<<endl;
    }
    system("pause");
    return 0;
}
