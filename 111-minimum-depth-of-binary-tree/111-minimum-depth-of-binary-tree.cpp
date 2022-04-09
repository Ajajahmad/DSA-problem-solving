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
    int solve(TreeNode *root , int ds)
    {
        if(!root) return INT_MAX;
        if(!root->left && !root->right) return ds;
        return min(solve(root->left,ds+1) , solve(root->right , ds+1));
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        return solve(root , 1);
    }
};