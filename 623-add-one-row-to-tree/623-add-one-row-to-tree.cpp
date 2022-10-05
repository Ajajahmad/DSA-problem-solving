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
    void solve(TreeNode *root , int val , int curDepth , int depth)
    {
        if(!root) return ;
        if(curDepth==depth-1)
        {
            TreeNode *a = root->left;
            TreeNode *b = root->right;
            root->left = new TreeNode(val);
            root->left->left = a;
            root->right = new TreeNode(val);
            root->right->right = b;
            return;
        }
        solve(root->left , val ,curDepth+1, depth);
        solve(root->right , val ,curDepth+1, depth);
    }
        
        
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return root;
        if(depth==1) 
        {
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;
        }
        solve(root , val , 1, depth);
        return root;
    }
};