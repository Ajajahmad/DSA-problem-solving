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
    int distributeCoins(TreeNode* root) {
        int res=0;
        solve(root, root, res);
        return res;
    }
    void solve(TreeNode *parent, TreeNode *child, int &res)
    {
        if(child==NULL) return;
        solve(child , child->left , res);
        solve(child , child->right , res);
        if(child->val>1)
        {
            int extra = child->val -1;
            child->val =1;
            parent->val += extra;
            res+= extra;
        }
        else if(child->val<1)
        {
            int needed= 1+ abs(child->val);
            child->val =1;
            parent->val -= needed;
            res+= needed;
        }
    }
};