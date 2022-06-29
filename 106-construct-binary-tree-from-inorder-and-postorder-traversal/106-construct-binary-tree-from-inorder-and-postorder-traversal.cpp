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
class Solution 
{
public:
    int s=0;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         s = postorder.size()-1;
         int i=0, j=inorder.size()-1;
        return helper(inorder , postorder , i , j );
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder , int l ,int r )
    {
        if(l>r) return NULL;
        int m=l;
        while(m<=r)
        {
            if(inorder[m] == postorder[s])
                break;
            m++;
        }
        
        TreeNode* root = new TreeNode(inorder[m]);
        s--;
                root->right = helper(inorder , postorder , m+1,r);

        root->left = helper(inorder , postorder , l, m-1);
        return root;
    }
};