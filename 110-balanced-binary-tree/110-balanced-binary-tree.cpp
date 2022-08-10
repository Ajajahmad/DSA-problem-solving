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
    bool ans = true;
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        solve(root , 0);
        return ans;
        
    }
    int solve(TreeNode * root, int l)
    {
        if(!root) return l;
        int a = solve(root->left , l+1);
        int b = solve(root->right , l+1);
        if(abs(a-b)>1) ans = false;
        return max(a,b);
    }
};