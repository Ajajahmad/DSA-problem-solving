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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>> res;
        if(!root) return res;
        vector<int> path;
        solve(root , targetSum , res , path);
        return res;
    }
    void solve(TreeNode *root , int k ,  vector<vector<int>>&res , vector<int> &path)
    {
        if(!root) return;
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            int sum = 0;
            for(int i=0;i<path.size();i++) sum += path[i];
            if(sum==k)
            {
                res.push_back(path);
            }
            
        }
        if(root->left) solve(root->left , k ,res, path);
         if(root->right) solve(root->right , k ,res, path);
        path.pop_back();
    }
};