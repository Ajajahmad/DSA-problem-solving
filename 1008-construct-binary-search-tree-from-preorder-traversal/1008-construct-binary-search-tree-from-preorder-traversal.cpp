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
    int i = 0;
    // take upper bound  as INT_MAX;
    // as if we go left the value should not be greater than ub
    // as we go left, root's value become ub ;
    //if we go in right out ub bound will be previos one
    TreeNode *solve(vector<int>&preorder , int ub)
    {
        if(i==preorder.size() || preorder[i]>ub) return NULL;
        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = solve(preorder , root->val);
        root->right = solve(preorder, ub);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder , INT_MAX);
    }
};