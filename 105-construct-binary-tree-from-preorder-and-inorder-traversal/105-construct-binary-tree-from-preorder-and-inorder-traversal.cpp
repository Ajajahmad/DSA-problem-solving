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
    int i=0;
    TreeNode *solve(vector<int>& preorder, vector<int>& inorder ,  int l, int h, map<int,int>&mp )
    {
        if(l>h) return  NULL;
        int m = l;
        while(m<=h)
        {
            if(inorder[m] == preorder[i]) break;
            m++;
        }
        TreeNode *root = new TreeNode(preorder[i]);

        i++;
        root->left = solve(preorder , inorder , l , m-1 ,mp);
        root->right = solve(preorder , inorder , m+1 , h, mp);
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size() ; i++)
        {
            mp[inorder[i]]=i;
        }
        return solve(preorder , inorder , 0, inorder.size()-1 , mp);
    }
    

};