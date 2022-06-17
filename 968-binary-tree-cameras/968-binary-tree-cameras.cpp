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
    int minCameraCover(TreeNode* root) {
        int res= 0;
        solve(root , root , res);
        return res;
    }
    void solve(TreeNode *parent , TreeNode *child , int &res)
    {
        if(!child) return;
        solve(child , child->left , res);
        solve(child ,child->right  ,res);
        
        if((child->left!=NULL&&  child->left->val==1) || (child->right!=NULL && child->right->val==1)) res+=0;
        else if(child->val==0 && parent->val==0)
        {
            parent->val =1;
            res++;
        }
    }
};