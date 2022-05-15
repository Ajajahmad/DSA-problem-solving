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
    int res =0 ;
    int mx =-1;
    int deepestLeavesSum(TreeNode* root) {
        solve(root , 0 );
        return res;
    }
    void solve(TreeNode *root , int lv)
    {
        if(!root) return;
        if(lv==mx)
            res+= root->val;
        else if(lv>mx)
        {
            res =0;
            mx = lv;
            res+= root->val;
            
        }
        if(root->left) solve(root->left , lv+1 );
        if(root->right) solve(root->right , lv+1 );
    }
};
