/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        TreeNode *a=NULL, *b=NULL, *c=NULL;
        if(root == p || root==q)
        {
            a = root;
        }
        b= lowestCommonAncestor(root->left , p , q);
        c= lowestCommonAncestor(root->right , p , q);
        int count = 0;
        if(a==NULL) count++;
        if(b==NULL) count++;
        if(c==NULL) count++;
        if(count==3) return NULL;
        else if(count==2)
        {
            if(a!=NULL) return a;
            if(b!=NULL) return b;
            if(c!=NULL) return c;
        }
        return root;
    }
};