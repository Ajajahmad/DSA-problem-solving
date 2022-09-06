/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count = 0,pre =0;
    bool flag = true;
   void  solve(TreeNode *root)
    {
         if(!root) return ;
        solve(root->left);
         if(count==0)
        {
            pre = root->val;
            count++;
        }
        else
        {
            if(root->val<=pre) flag = false;
            pre = root->val;
        }
        solve(root->right);
   
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        solve(root);
        return flag;
        

    }
};