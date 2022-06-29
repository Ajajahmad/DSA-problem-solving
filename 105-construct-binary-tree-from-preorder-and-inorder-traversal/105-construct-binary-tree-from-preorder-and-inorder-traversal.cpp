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
    int s=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i=0, j=inorder.size()-1;
        
        return helper(preorder , inorder , i, j);
        
    }
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder , int l , int r)
    {
        if(l>r) return NULL;
        int m=l;
        while(m<=r)
        {
            if(inorder[m]==preorder[s])
                break;
            m++;
        }
        TreeNode* root = new TreeNode(inorder[m]);
        s++;
        root->left = helper(preorder , inorder , l, m-1);
        root->right = helper(preorder , inorder , m+1 , r);
        return root;
        
    }
};