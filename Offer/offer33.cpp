#include<iostream>
#include<vector>

using namespace std;

/*
输入一个整数数组，
判断该数组是不是某二叉搜索树的后序遍历结果。
如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int num,TreeNode *l=nullptr,TreeNode *r = nullptr){
        val = num;
        left = l;
        right = r;
    }
};

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size() <= 2) return true;
        TreeNode *root = nullptr;
        int size = postorder.size();
        root = new TreeNode(postorder[size-1]);
        int root_val = postorder[size-1];           // 节点值 取出来
        postorder.resize(size-1);
        int index = 0;
        //if(postorder[index] < root_val) return false;
        while(postorder[index] < root_val){         // 找到分割点
            index++;
        }
        vector<int> leftpost(postorder.begin(),postorder.begin()+index);    // 左子树
        vector<int> rightpost(postorder.begin()+index,postorder.end());     // 右子树

        bool flag = true;           // 定义一个 flag
        for(auto a : rightpost){
            if(a < root_val)        // 如果右子树 中有一个值小于 根节点，flag就为 false;
                flag = false;
        }

        
        bool right = verifyPostorder(rightpost);        // 判断 左右 子树
        bool left = verifyPostorder(leftpost);

        return flag && right && left;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,5,10,6,9,4,3};
    Solution sol;
    cout<<sol.verifyPostorder(nums)<<endl;
    system("pause");
    return 0;
}
